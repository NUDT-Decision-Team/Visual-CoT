# Copyright 2024, LLM-PySC2 Contributors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS-IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# import google.generativeai as genai
import os,base64
from llamaapi import LlamaAPI
from zhipuai import ZhipuAI
import openai

from loguru import logger
import threading
import random
import time
import json


def gpt_query_runtime(self, ):
  self.llm_response = openai.ChatCompletion.create(
    model=self.model_name,
    messages=self.messages,
    temperature=self.temperature
  )["choices"][0]["message"]["content"]

def claude_query_runtime(self, ):
  self.llm_response = openai.ChatCompletion.create(
                    model=self.model_name,
                    messages=self.messages,
                    temperature=self.temperature
                ).choices[0].message.content

def llama_query_runtime(self, ):
  self.llm_response = json.dumps(self.client.run({
      'model': self.model_name,
      'messages': self.messages,
      'temperature': self.temperature,
    }
  ).json(), indent=2)
  print(self.llm_response)

def glm_query_runtime(self, ):
  self.llm_response = self.client.chat.completions.create(
                    model=self.model_name,  # 填写需要调用的模型名称
                    messages=self.messages,
                    temperature=self.temperature
                ).choices[0].message

def glm4v_query_runtime(self, ):
  self.llm_response = self.client.chat.completions.create(
                    model=self.model_name,  # 填写需要调用的模型名称
                    messages=self.messages,
                    temperature=self.temperature
                ).choices[0].message.content

# def gemini_query_runtime(self, ):
#   self.llm_response = self.model.generate_content(
#     messages=self.messages, generation_config=genai.types.GenerationConfig(temperature=self.temperature)).text

def qwen2_query_runtime(self, ):
  self.llm_response = openai.ChatCompletion.create(
                    model=self.model_name,  # 填写需要调用的模型名称
                    messages=self.messages,
                    temperature=self.temperature
                ).choices[0].message.content

class GptClient:

  def __init__(self, name, log_id, config):
    # 初始化模型名称、API 基础 URL 和密钥
    self.model_name = config.AGENTS[name]['llm']['model_name']
    self.api_base = config.AGENTS[name]['llm']['api_base']
    self.api_key = config.AGENTS[name]['llm']['api_key']
    self.temperature = config.temperature

    # 设置 OpenAI 的 API 配置
    openai.api_base = self.api_base
    openai.api_key = self.api_key

    self.agent_name = name
    self.log_id = log_id
    self.config = config
    self.system_prompt = ''
    self.example_i_prompt = ''
    self.example_o_prompt = ''
    self.messages = []
    self.llm_response = None
    self.query_runtime = gpt_query_runtime

    # 添加缺失的属性定义
    # 设置 screen_rgb_prompt，若配置中未指定则使用默认值
    self.screen_rgb_prompt = config.AGENTS[name]['llm'].get('screen_rgb_prompt', 'Screen RGB image:')

    if 'gpt' in self.model_name or self.model_name == 'default':
      logger.info(f"[ID {self.log_id}] {self.agent_name} {self.model_name} GptClient initialized")

  def wrap_message(self, obs_prompt, base64_image):

    if (base64_image is not None) and (self.model_name not in vision_model_names):
      logger.warning(f"[ID {self.log_id}] {self.agent_name} {self.model_name}: Model do not accept img, img discarded")
    if (base64_image is None) and (self.model_name in vision_model_names):
      logger.warning(f"[ID {self.log_id}] {self.agent_name} {self.model_name}: Vision available but img disabled")

    if (base64_image is None) or (self.model_name not in vision_model_names):
      # 不包含图像的消息
      self.messages = [
        {"role": "system", "content": self.system_prompt},
        {"role": "user", "content": self.example_i_prompt},
        {"role": "assistant", "content": self.example_o_prompt},
        {"role": "user", "content": obs_prompt}
      ]
    else:
      # 包含图像的消息，按照指定格式
      self.messages = [
        {"role": "system", "content": self.system_prompt},
        {"role": "user", "content": self.example_i_prompt},
        {"role": "assistant", "content": self.example_o_prompt},

        {"role": "user", "content": [
          {"type": "text", "text": self.screen_rgb_prompt},   # obs_prompt
          {"type": "image_url", "image_url": {
            "url": f"data:image/png;base64,{base64_image}"
          }}
        ]},
        # {"role": "user", "content": [
        #   {"type": "text", "text": self.minimap_rgb_prompt},  # obs_prompt
        #   {"type": "image_url", "image_url": {
        #     "url": f"data:image/png;base64,{base64_image}"
        #   }}
        # ]},
        {"role": "user", "content": obs_prompt},
      ]

#   def wrap_message(self, obs_prompt, base64_image):
#
#     # 定义两张示例图片的路径
#     example_image_path = r"E:\code\llm-pysc2-develop 09242320\llm-pysc2-develop 10092340\llm-pysc2-develop\example_image\rgb_screen_example.png"
#     example_image1_path = r"E:\code\llm-pysc2-develop 09242320\llm-pysc2-develop 10092340\llm-pysc2-develop\example_image\rgb_screen_example1.png"
#
#     imageinfo = """
#
# This is an RGB sample image extracted from a game, designed to label different terrain types and their characteristics. The image includes the following key regions:
#
# - Green Area (Highland): A passable area representing elevated terrain in the map.
# - Dark Gray Area (Lowland): Another passable area representing lower terrain in the map.
# - Black Area (Impassable Region): An area that cannot be accessed, usually marked as a boundary.
# - Red Lines (Impassable Boundaries): Mark the position of the map's boundaries, indicating areas outside these lines are inaccessible.
#
# Cliff Definition:
#
# - A cliff specifically refers to the vertical material transition between the highland (green area) and the lowland (dark gray area), forming a connection and height difference between two passable regions. It is important to note that the boundary between the highland and the impassable region, as well as the boundary between the lowland and the impassable region, does not qualify as a cliff.
#
# Position of the Colossus:
#
# - The Colossus in the image is near the red boundary line, indicating it is close to the edge of the map's impassable region. Since the Colossus is located in the green highland, it is near the "boundary between the highland and the impassable region," not a "cliff."
#
# """
#     # 加载示例图片1
#     if os.path.exists(example_image_path):
#       with open(example_image_path, "rb") as image_file:
#         base64_example_image = base64.b64encode(image_file.read()).decode("utf-8")
#     else:
#       logger.warning(f"[ID {self.log_id}] Example image not found at {example_image_path}")
#       base64_example_image = None
#
#     # 加载示例图片2
#     if os.path.exists(example_image1_path):
#       with open(example_image1_path, "rb") as image_file:
#         base64_example1_image = base64.b64encode(image_file.read()).decode("utf-8")
#     else:
#       logger.warning(f"[ID {self.log_id}] Example image 1 not found at {example_image1_path}")
#       base64_example1_image = None
#
#     # 图像处理与模型能力检查
#     if (base64_image is not None) and (self.model_name not in vision_model_names):
#       logger.warning(
#         f"[ID {self.log_id}] {self.agent_name} {self.model_name}: Model does not accept img, img discarded")
#     if (base64_image is None) and (self.model_name in vision_model_names):
#       logger.warning(f"[ID {self.log_id}] {self.agent_name} {self.model_name}: Vision available but img disabled")
#
#     # 构造消息
#     if (base64_image is None) or (self.model_name not in vision_model_names):
#       # 不包含图像的消息
#       self.messages = [
#         {"role": "system", "content": self.system_prompt},
#         {"role": "user", "content": self.example_i_prompt},
#         {"role": "assistant", "content": self.example_o_prompt},
#         {"role": "user", "content": obs_prompt}
#       ]
#     else:
#       # 包含图像的消息
#       self.messages = [
#         {"role": "system", "content": self.system_prompt},
#         # 示例 1：图片和提示词
#         {"role": "user", "content": [
#           {"type": "text", "text": imageinfo},
#           {"type": "image_url", "image_url": {
#             "url": f"data:image/png;base64,{base64_example_image}"  # 示例图片 1 部分
#           }}
#         ]},
#         # 示例 2：第二张图片和提示词
#         {"role": "user", "content": [
#           {"type": "text", "text": "This is the RGB image corresponding to the Example Input Prompt."},
#           {"type": "image_url", "image_url": {
#             "url": f"data:image/png;base64,{base64_example1_image}"  # 示例图片 2 部分
#           }}
#         ]},
#         {"role": "assistant", "content": self.example_o_prompt},
#         {"role": "user", "content": [
#           {"type": "text", "text": self.screen_rgb_prompt},
#           {"type": "image_url", "image_url": {
#             "url": f"data:image/png;base64,{base64_image}"  # 用户输入的图片部分
#           }}
#         ]},
#         {"role": "user", "content": obs_prompt}
#       ]

  def query(self, obs_prompt, base64_image=None):

    # 重置 messages 列表
    self.wrap_message(obs_prompt, base64_image)

    # 尝试发送请求并获取回复
    max_retries = self.config.MAX_LLM_QUERY_TIMES
    for retries in range(max_retries):
      try:
        # tracemalloc.start()
        logger.success(f"[ID {self.log_id}] {self.agent_name} Start calling llm api!")
        logger.debug(f"[ID {self.log_id}] {self.agent_name} input prompt: \n{obs_prompt}")

        self.thread = threading.Thread(target=self.query_runtime, args=(self,))#保留“，”
        self.thread.start()

        # 超时错误
        query_start_time = float(time.time())
        while not isinstance(self.llm_response, str):
          time.sleep(0.1)
          if float(time.time()) - query_start_time > self.config.MAX_LLM_RUNTIME_ERROR_TIME:
            logger.error(f"[ID {self.log_id}] {self.agent_name} LLM query runtime error")
            raise RuntimeError(f"{self.agent_name} LLM query runtime error")

        answer = self.llm_response
        logger.success(f"[ID {self.log_id}] {self.agent_name} Get llm response!")
        logger.debug(f"[ID {self.log_id}] {self.agent_name} llm response: \n{answer}")
        self.llm_response = None

        return answer
      except Exception as e:
        # 输出错误信息
        logger.error(f"[ID {self.log_id}] {self.agent_name} Error when calling the OpenAI API: {e}")
        # print(f"Error when calling the OpenAI API: {e}")

        # 如果达到最大尝试次数，返回一个特定的回复
        if retries >= max_retries - 1:
          logger.error \
            (f"[ID {self.log_id}] {self.agent_name} Maximum number of retries reached. The OpenAI API is not responding.")
          return "I'm sorry, but I am unable to provide a response at this time due to technical difficulties."

        # 重试前等待一段时间，使用 exponential backoff 策略
        sleep_time = min((2 ** retries) + random.random(), 8 + random.random())
        logger.info(f"[ID {self.log_id}] {self.agent_name} Waiting for {sleep_time} seconds before retrying...")
        time.sleep(sleep_time)

    logger.error(f"[ID {self.log_id}] {self.agent_name} Can not get llm response after try {max_retries} times!")
    return f'[ID {self.log_id}] {self.agent_name} Can not get llm response after try {max_retries} times!'

class ClaudeClient(GptClient):
  def __init__(self, name, log_id, config):
    super(ClaudeClient, self).__init__(name, log_id, config)
    self.query_runtime = claude_query_runtime
    self.client = openai
    logger.info(f"[ID {self.log_id}] {self.agent_name} {self.model_name} ClaudeClient initialized")

class LlamaClient(GptClient):
  def __init__(self, name, log_id, config):
    super(LlamaClient, self).__init__(name, log_id, config)
    self.query_runtime = llama_query_runtime
    self.client = LlamaAPI(self.api_key, hostname=self.api_base)
    logger.info(f"[ID {self.log_id}] {self.agent_name} {self.model_name} LlamaClient initialized")

class GlmClient(GptClient):
  def __init__(self, name, log_id, config):
    super(GlmClient, self).__init__(name, log_id, config)
    self.query_runtime = glm_query_runtime
    self.client = ZhipuAI(api_key=self.api_key)
    logger.info(f"[ID {self.log_id}] {self.agent_name} {self.model_name} GlmClient initialized")

# class GeminiClient(GptClient):
#   def __init__(self, name, log_id, config):
#     super(GeminiClient).__init__(self, name, log_id, config)
#     self.query_runtime = gemini_query_runtime
#     self.model = genai.GenerativeModel(config.model_name)

# class QWen2Client(GptClient):
#   def __init__(self, name, log_id, config):
#     super(QWen2Client, self).__init__(name, log_id, config)
#     self.query_runtime = qwen2_query_runtime
#     self.client = openai

# for config's auto check
vision_model_names = [
  'gpt-4o', 'gpt-4-1106-vision-preview', 'gpt-4v-1106', 'gpt-4v-0409',
  'glm-4v', 'glm-4v-plus','gpt-4-turbo','gpt-4'
]
video_model_names = []

FACTORY = {
  'default': GptClient,
  'gpt-3.5-turbo': GptClient,

  'gpt-4o': GptClient,
  'gpt-4o-mini': GptClient,
  'gpt-4-turbo': GptClient,

  'gpt-4': GptClient,
  # 'gpt-4v-1106': GptClient,
  # 'gpt-4v-0409': GptClient,

  # 'o1-mini': GptClient,
  # 'o1-preview': GptClient,

  'claude-3-opus': ClaudeClient,
  'claude-3-haiku': ClaudeClient,
  'claude-3-sonnet': ClaudeClient,

  'llama3-8b': LlamaClient,
  'llama3-70b': LlamaClient,
  'llama3.1-8b': LlamaClient,
  'llama3.1-70b': LlamaClient,
  'llama3.1-405b': LlamaClient,

  'glm-4': GlmClient,
  'glm-4-plus': GlmClient,
  'glm-4-air': GlmClient,
  'glm-4-airx': GlmClient,
  'glm-4-flash': GlmClient,
  'glm-4-flashx': GlmClient,

  # 'glm-4v': GlmClient,
  # 'glm-4v-plus': GlmClient,

  # 'qwen2.5-7b-instruct': QWen2Client,
  # 'gemini': GeminiClient,
}
