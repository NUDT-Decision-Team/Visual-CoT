// Copyright 2021 DeepMind Technologies Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS-IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "pysc2/env/converter/cc/game_data/raw_actions.h"

#include <vector>

namespace pysc2 {

const std::vector<RawFunction>& RawFunctions() {
  static const std::vector<RawFunction>* functions =
      new std::vector<RawFunction>({
          {"no_op", NO_OP},
          {"Smart_pt", RAW_CMD_PT, 1},
          {"Attack_pt", RAW_CMD_PT, 3674},
          {"Attack_unit", RAW_CMD_UNIT, 3674},
          {"Attack_Attack_pt", RAW_CMD_PT, 23, 3674},
          {"Attack_Attack_unit", RAW_CMD_UNIT, 23, 3674},
          {"Attack_AttackBuilding_pt", RAW_CMD_PT, 2048, 3674},
          {"Attack_AttackBuilding_unit", RAW_CMD_UNIT, 2048, 3674},
          {"Attack_Redirect_pt", RAW_CMD_PT, 1682, 3674},
          {"Attack_Redirect_unit", RAW_CMD_UNIT, 1682, 3674},
          {"Scan_Move_pt", RAW_CMD_PT, 19, 3674},
          {"Scan_Move_unit", RAW_CMD_UNIT, 19, 3674},
          {"Smart_unit", RAW_CMD_UNIT, 1},
          {"Move_pt", RAW_CMD_PT, 3794},
          {"Move_unit", RAW_CMD_UNIT, 3794},
          {"Patrol_pt", RAW_CMD_PT, 3795},
          {"Patrol_unit", RAW_CMD_UNIT, 3795},
          {"HoldPosition_quick", RAW_CMD, 3793},
          {"Research_InterceptorGravitonCatapult_quick", RAW_CMD, 44},
          {"Research_PhoenixAnionPulseCrystals_quick", RAW_CMD, 46},
          {"Effect_GuardianShield_quick", RAW_CMD, 76},
          {"Train_Mothership_quick", RAW_CMD, 110},
          {"Hallucination_Archon_quick", RAW_CMD, 146},
          {"Hallucination_Colossus_quick", RAW_CMD, 148},
          {"Hallucination_HighTemplar_quick", RAW_CMD, 150},
          {"Hallucination_Immortal_quick", RAW_CMD, 152},
          {"Hallucination_Phoenix_quick", RAW_CMD, 154},
          {"Hallucination_Probe_quick", RAW_CMD, 156},
          {"Hallucination_Stalker_quick", RAW_CMD, 158},
          {"Hallucination_VoidRay_quick", RAW_CMD, 160},
          {"Hallucination_WarpPrism_quick", RAW_CMD, 162},
          {"Hallucination_Zealot_quick", RAW_CMD, 164},
          {"Effect_GravitonBeam_unit", RAW_CMD_UNIT, 173},
          {"Effect_ChronoBoost_unit", RAW_CMD_UNIT, 261},
          {"Build_Nexus_pt", RAW_CMD_PT, 880},
          {"Build_Pylon_pt", RAW_CMD_PT, 881},
          {"Build_Assimilator_unit", RAW_CMD_UNIT, 882},
          {"Build_Gateway_pt", RAW_CMD_PT, 883},
          {"Build_Forge_pt", RAW_CMD_PT, 884},
          {"Build_FleetBeacon_pt", RAW_CMD_PT, 885},
          {"Build_TwilightCouncil_pt", RAW_CMD_PT, 886},
          {"Build_PhotonCannon_pt", RAW_CMD_PT, 887},
          {"Build_Stargate_pt", RAW_CMD_PT, 889},
          {"Build_TemplarArchive_pt", RAW_CMD_PT, 890},
          {"Build_DarkShrine_pt", RAW_CMD_PT, 891},
          {"Build_RoboticsBay_pt", RAW_CMD_PT, 892},
          {"Build_RoboticsFacility_pt", RAW_CMD_PT, 893},
          {"Build_CyberneticsCore_pt", RAW_CMD_PT, 894},
          {"Build_ShieldBattery_pt", RAW_CMD_PT, 895},
          {"Train_Zealot_quick", RAW_CMD, 916},
          {"Train_Stalker_quick", RAW_CMD, 917},
          {"Train_HighTemplar_quick", RAW_CMD, 919},
          {"Train_DarkTemplar_quick", RAW_CMD, 920},
          {"Train_Sentry_quick", RAW_CMD, 921},
          {"Train_Adept_quick", RAW_CMD, 922},
          {"Train_Phoenix_quick", RAW_CMD, 946},
          {"Train_Carrier_quick", RAW_CMD, 948},
          {"Train_VoidRay_quick", RAW_CMD, 950},
          {"Train_Oracle_quick", RAW_CMD, 954},
          {"Train_Tempest_quick", RAW_CMD, 955},
          {"Train_WarpPrism_quick", RAW_CMD, 976},
          {"Train_Observer_quick", RAW_CMD, 977},
          {"Train_Colossus_quick", RAW_CMD, 978},
          {"Train_Immortal_quick", RAW_CMD, 979},
          {"Train_Probe_quick", RAW_CMD, 1006},
          {"Effect_PsiStorm_pt", RAW_CMD_PT, 1036},
          {"Build_Interceptors_quick", RAW_CMD, 1042},
          {"Research_GraviticBooster_quick", RAW_CMD, 1093},
          {"Research_GraviticDrive_quick", RAW_CMD, 1094},
          {"Research_ExtendedThermalLance_quick", RAW_CMD, 1097},
          {"Research_PsiStorm_quick", RAW_CMD, 1126},
          {"TrainWarp_Zealot_pt", RAW_CMD_PT, 1413},
          {"TrainWarp_Stalker_pt", RAW_CMD_PT, 1414},
          {"TrainWarp_HighTemplar_pt", RAW_CMD_PT, 1416},
          {"TrainWarp_DarkTemplar_pt", RAW_CMD_PT, 1417},
          {"TrainWarp_Sentry_pt", RAW_CMD_PT, 1418},
          {"TrainWarp_Adept_pt", RAW_CMD_PT, 1419},
          {"Morph_WarpGate_quick", RAW_CMD, 1518},
          {"Morph_Gateway_quick", RAW_CMD, 1520},
          {"Effect_ForceField_pt", RAW_CMD_PT, 1526},
          {"Morph_WarpPrismPhasingMode_quick", RAW_CMD, 1528},
          {"Morph_WarpPrismTransportMode_quick", RAW_CMD, 1530},
          {"Research_WarpGate_quick", RAW_CMD, 1568},
          {"Research_Charge_quick", RAW_CMD, 1592},
          {"Research_Blink_quick", RAW_CMD, 1593},
          {"Research_AdeptResonatingGlaives_quick", RAW_CMD, 1594},
          {"Morph_Archon_quick", RAW_CMD, 1766},
          {"Behavior_BuildingAttackOn_quick", RAW_CMD, 2081},
          {"Behavior_BuildingAttackOff_quick", RAW_CMD, 2082},
          {"Hallucination_Oracle_quick", RAW_CMD, 2114},
          {"Effect_OracleRevelation_pt", RAW_CMD_PT, 2146},
          {"Effect_ImmortalBarrier_quick", RAW_CMD, 2328},
          {"Hallucination_Disruptor_quick", RAW_CMD, 2389},
          {"Hallucination_Adept_quick", RAW_CMD, 2391},
          {"Effect_VoidRayPrismaticAlignment_quick", RAW_CMD, 2393},
          {"Build_StasisTrap_pt", RAW_CMD_PT, 2505},
          {"Effect_AdeptPhaseShift_pt", RAW_CMD_PT, 2544},
          {"Research_ShadowStrike_quick", RAW_CMD, 2720},
          {"Cancel_quick", RAW_CMD, 3659},
          {"Halt_quick", RAW_CMD, 3660},
          {"UnloadAll_quick", RAW_CMD, 3664},
          {"Stop_quick", RAW_CMD, 3665},
          {"Harvest_Gather_unit", RAW_CMD_UNIT, 3666},
          {"Harvest_Return_quick", RAW_CMD, 3667},
          {"Load_unit", RAW_CMD_UNIT, 3668},
          {"UnloadAllAt_pt", RAW_CMD_PT, 3669},
          {"Rally_Units_pt", RAW_CMD_PT, 3673},
          {"Rally_Units_unit", RAW_CMD_UNIT, 3673},
          {"Effect_Repair_pt", RAW_CMD_PT, 3685},
          {"Effect_Repair_unit", RAW_CMD_UNIT, 3685},
          {"Effect_MassRecall_pt", RAW_CMD_PT, 3686},
          {"Effect_Blink_pt", RAW_CMD_PT, 3687},
          {"Effect_Blink_unit", RAW_CMD_UNIT, 3687},
          {"Effect_ShadowStride_pt", RAW_CMD_PT, 2700, 3687},
          {"Rally_Workers_pt", RAW_CMD_PT, 3690},
          {"Rally_Workers_unit", RAW_CMD_UNIT, 3690},
          {"Research_ProtossAirArmor_quick", RAW_CMD, 3692},
          {"Research_ProtossAirWeapons_quick", RAW_CMD, 3693},
          {"Research_ProtossGroundArmor_quick", RAW_CMD, 3694},
          {"Research_ProtossGroundWeapons_quick", RAW_CMD, 3695},
          {"Research_ProtossShields_quick", RAW_CMD, 3696},
          {"Morph_ObserverMode_quick", RAW_CMD, 3739},
          {"Effect_ChronoBoostEnergyCost_unit", RAW_CMD_UNIT, 3755},
          {"Cancel_AdeptPhaseShift_quick", RAW_CMD, 2594, 3659},
          {"Cancel_AdeptShadePhaseShift_quick", RAW_CMD, 2596, 3659},
          {"Cancel_BuildInProgress_quick", RAW_CMD, 314, 3659},
          {"Cancel_GravitonBeam_quick", RAW_CMD, 174, 3659},
          {"Cancel_StasisTrap_quick", RAW_CMD, 2535, 3659},
          {"Cancel_VoidRayPrismaticAlignment_quick", RAW_CMD, 3707, 3659},
          {"Cancel_Last_quick", RAW_CMD, 3671},
          {"Cancel_Queue1_quick", RAW_CMD, 304, 3671},
          {"Cancel_Queue5_quick", RAW_CMD, 306, 3671},
          {"Cancel_QueueCancelToSelection_quick", RAW_CMD, 308, 3671},
          {"Cancel_QueuePassive_quick", RAW_CMD, 1831, 3671},
          {"Cancel_QueuePassiveCancelToSelection_quick", RAW_CMD, 1833, 3671},
          {"Effect_Blink_Stalker_pt", RAW_CMD_PT, 1442, 3687},
          {"Effect_MassRecall_Mothership_pt", RAW_CMD_PT, 2368, 3686},
          {"Effect_MassRecall_StrategicRecall_pt", RAW_CMD_PT, 142},
          {"Rally_Nexus_pt", RAW_CMD_PT, 207, 3690},
          {"Research_ProtossAirArmorLevel1_quick", RAW_CMD, 1565, 3692},
          {"Research_ProtossAirArmorLevel2_quick", RAW_CMD, 1566, 3692},
          {"Research_ProtossAirArmorLevel3_quick", RAW_CMD, 1567, 3692},
          {"Research_ProtossAirWeaponsLevel1_quick", RAW_CMD, 1562, 3693},
          {"Research_ProtossAirWeaponsLevel2_quick", RAW_CMD, 1563, 3693},
          {"Research_ProtossAirWeaponsLevel3_quick", RAW_CMD, 1564, 3693},
          {"Research_ProtossGroundArmorLevel1_quick", RAW_CMD, 1065, 3694},
          {"Research_ProtossGroundArmorLevel2_quick", RAW_CMD, 1066, 3694},
          {"Research_ProtossGroundArmorLevel3_quick", RAW_CMD, 1067, 3694},
          {"Research_ProtossGroundWeaponsLevel1_quick", RAW_CMD, 1062, 3695},
          {"Research_ProtossGroundWeaponsLevel2_quick", RAW_CMD, 1063, 3695},
          {"Research_ProtossGroundWeaponsLevel3_quick", RAW_CMD, 1064, 3695},
          {"Research_ProtossShieldsLevel1_quick", RAW_CMD, 1068, 3696},
          {"Research_ProtossShieldsLevel2_quick", RAW_CMD, 1069, 3696},
          {"Research_ProtossShieldsLevel3_quick", RAW_CMD, 1070, 3696},
          {"Harvest_Return_Probe_quick", RAW_CMD, 299, 3667},
          {"Stop_Stop_quick", RAW_CMD, 4, 3665},
          {"UnloadAllAt_WarpPrism_pt", RAW_CMD_PT, 913, 3669},
          {"Effect_Feedback_unit", RAW_CMD_UNIT, 140},
          {"Behavior_PulsarBeamOff_quick", RAW_CMD, 2376},
          {"Behavior_PulsarBeamOn_quick", RAW_CMD, 2375},
          {"Morph_SurveillanceMode_quick", RAW_CMD, 3741},
          {"Effect_Restore_unit", RAW_CMD_UNIT, 3765},
          {"Effect_MassRecall_Nexus_pt", RAW_CMD_PT, 3757, 3686},
          {"UnloadAllAt_WarpPrism_unit", RAW_CMD_UNIT, 913, 3669},
          {"UnloadAllAt_unit", RAW_CMD_UNIT, 3669},
          {"Rally_Nexus_unit", RAW_CMD_UNIT, 207, 3690},
          {"Train_Disruptor_quick", RAW_CMD, 994},
          {"Effect_PurificationNova_pt", RAW_CMD_PT, 2346},
          {"raw_move_camera", RAW_MOVE_CAMERA},
          {"Behavior_CloakOff_quick", RAW_CMD, 3677},
          {"Behavior_CloakOff_Banshee_quick", RAW_CMD, 393, 3677},
          {"Behavior_CloakOff_Ghost_quick", RAW_CMD, 383, 3677},
          {"Behavior_CloakOn_quick", RAW_CMD, 3676},
          {"Behavior_CloakOn_Banshee_quick", RAW_CMD, 392, 3676},
          {"Behavior_CloakOn_Ghost_quick", RAW_CMD, 382, 3676},
          {"Behavior_GenerateCreepOff_quick", RAW_CMD, 1693},
          {"Behavior_GenerateCreepOn_quick", RAW_CMD, 1692},
          {"Behavior_HoldFireOff_quick", RAW_CMD, 3689},
          {"Behavior_HoldFireOff_Ghost_quick", RAW_CMD, 38, 3689},
          {"Behavior_HoldFireOff_Lurker_quick", RAW_CMD, 2552, 3689},
          {"Behavior_HoldFireOn_quick", RAW_CMD, 3688},
          {"Behavior_HoldFireOn_Ghost_quick", RAW_CMD, 36, 3688},
          {"Behavior_HoldFireOn_Lurker_quick", RAW_CMD, 2550, 3688},
          {"Build_Armory_pt", RAW_CMD_PT, 331},
          {"Build_BanelingNest_pt", RAW_CMD_PT, 1162},
          {"Build_Barracks_pt", RAW_CMD_PT, 321},
          {"Build_Bunker_pt", RAW_CMD_PT, 324},
          {"Build_CommandCenter_pt", RAW_CMD_PT, 318},
          {"Build_CreepTumor_pt", RAW_CMD_PT, 3691},
          {"Build_CreepTumor_Queen_pt", RAW_CMD_PT, 1694, 3691},
          {"Build_CreepTumor_Tumor_pt", RAW_CMD_PT, 1733, 3691},
          {"Build_EngineeringBay_pt", RAW_CMD_PT, 322},
          {"Build_EvolutionChamber_pt", RAW_CMD_PT, 1156},
          {"Build_Extractor_unit", RAW_CMD_UNIT, 1154},
          {"Build_Factory_pt", RAW_CMD_PT, 328},
          {"Build_FusionCore_pt", RAW_CMD_PT, 333},
          {"Build_GhostAcademy_pt", RAW_CMD_PT, 327},
          {"Build_Hatchery_pt", RAW_CMD_PT, 1152},
          {"Build_HydraliskDen_pt", RAW_CMD_PT, 1157},
          {"Build_InfestationPit_pt", RAW_CMD_PT, 1160},
          {"Build_Interceptors_autocast", RAW_AUTOCAST, 1042},
          {"Build_LurkerDen_pt", RAW_CMD_PT, 1163},
          {"Build_MissileTurret_pt", RAW_CMD_PT, 323},
          {"Build_Nuke_quick", RAW_CMD, 710},
          {"Build_NydusNetwork_pt", RAW_CMD_PT, 1161},
          {"Build_NydusWorm_pt", RAW_CMD_PT, 1768},
          {"Build_Reactor_quick", RAW_CMD, 3683},
          {"Build_Reactor_pt", RAW_CMD_PT, 3683},
          {"Build_Reactor_Barracks_quick", RAW_CMD, 422, 3683},
          {"Build_Reactor_Barracks_pt", RAW_CMD_PT, 422, 3683},
          {"Build_Reactor_Factory_quick", RAW_CMD, 455, 3683},
          {"Build_Reactor_Factory_pt", RAW_CMD_PT, 455, 3683},
          {"Build_Reactor_Starport_quick", RAW_CMD, 488, 3683},
          {"Build_Reactor_Starport_pt", RAW_CMD_PT, 488, 3683},
          {"Build_Refinery_pt", RAW_CMD_UNIT, 320},
          {"Build_RoachWarren_pt", RAW_CMD_PT, 1165},
          {"Build_SensorTower_pt", RAW_CMD_PT, 326},
          {"Build_SpawningPool_pt", RAW_CMD_PT, 1155},
          {"Build_SpineCrawler_pt", RAW_CMD_PT, 1166},
          {"Build_Spire_pt", RAW_CMD_PT, 1158},
          {"Build_SporeCrawler_pt", RAW_CMD_PT, 1167},
          {"Build_Starport_pt", RAW_CMD_PT, 329},
          {"Build_SupplyDepot_pt", RAW_CMD_PT, 319},
          {"Build_TechLab_quick", RAW_CMD, 3682},
          {"Build_TechLab_pt", RAW_CMD_PT, 3682},
          {"Build_TechLab_Barracks_quick", RAW_CMD, 421, 3682},
          {"Build_TechLab_Barracks_pt", RAW_CMD_PT, 421, 3682},
          {"Build_TechLab_Factory_quick", RAW_CMD, 454, 3682},
          {"Build_TechLab_Factory_pt", RAW_CMD_PT, 454, 3682},
          {"Build_TechLab_Starport_quick", RAW_CMD, 487, 3682},
          {"Build_TechLab_Starport_pt", RAW_CMD_PT, 487, 3682},
          {"Build_UltraliskCavern_pt", RAW_CMD_PT, 1159},
          {"BurrowDown_quick", RAW_CMD, 3661},
          {"BurrowDown_Baneling_quick", RAW_CMD, 1374, 3661},
          {"BurrowDown_Drone_quick", RAW_CMD, 1378, 3661},
          {"BurrowDown_Hydralisk_quick", RAW_CMD, 1382, 3661},
          {"BurrowDown_Infestor_quick", RAW_CMD, 1444, 3661},
          {"BurrowDown_InfestorTerran_quick", RAW_CMD, 1394, 3661},
          {"BurrowDown_Lurker_quick", RAW_CMD, 2108, 3661},
          {"BurrowDown_Queen_quick", RAW_CMD, 1433, 3661},
          {"BurrowDown_Ravager_quick", RAW_CMD, 2340, 3661},
          {"BurrowDown_Roach_quick", RAW_CMD, 1386, 3661},
          {"BurrowDown_SwarmHost_quick", RAW_CMD, 2014, 3661},
          {"BurrowDown_Ultralisk_quick", RAW_CMD, 1512, 3661},
          {"BurrowDown_WidowMine_quick", RAW_CMD, 2095, 3661},
          {"BurrowDown_Zergling_quick", RAW_CMD, 1390, 3661},
          {"BurrowUp_quick", RAW_CMD, 3662},
          {"BurrowUp_autocast", RAW_AUTOCAST, 3662},
          {"BurrowUp_Baneling_quick", RAW_CMD, 1376, 3662},
          {"BurrowUp_Baneling_autocast", RAW_AUTOCAST, 1376, 3662},
          {"BurrowUp_Drone_quick", RAW_CMD, 1380, 3662},
          {"BurrowUp_Hydralisk_quick", RAW_CMD, 1384, 3662},
          {"BurrowUp_Hydralisk_autocast", RAW_AUTOCAST, 1384, 3662},
          {"BurrowUp_Infestor_quick", RAW_CMD, 1446, 3662},
          {"BurrowUp_InfestorTerran_quick", RAW_CMD, 1396, 3662},
          {"BurrowUp_InfestorTerran_autocast", RAW_AUTOCAST, 1396, 3662},
          {"BurrowUp_Lurker_quick", RAW_CMD, 2110, 3662},
          {"BurrowUp_Queen_quick", RAW_CMD, 1435, 3662},
          {"BurrowUp_Queen_autocast", RAW_AUTOCAST, 1435, 3662},
          {"BurrowUp_Ravager_quick", RAW_CMD, 2342, 3662},
          {"BurrowUp_Ravager_autocast", RAW_AUTOCAST, 2342, 3662},
          {"BurrowUp_Roach_quick", RAW_CMD, 1388, 3662},
          {"BurrowUp_Roach_autocast", RAW_AUTOCAST, 1388, 3662},
          {"BurrowUp_SwarmHost_quick", RAW_CMD, 2016, 3662},
          {"BurrowUp_Ultralisk_quick", RAW_CMD, 1514, 3662},
          {"BurrowUp_Ultralisk_autocast", RAW_AUTOCAST, 1514, 3662},
          {"BurrowUp_WidowMine_quick", RAW_CMD, 2097, 3662},
          {"BurrowUp_Zergling_quick", RAW_CMD, 1392, 3662},
          {"BurrowUp_Zergling_autocast", RAW_AUTOCAST, 1392, 3662},
          {"Cancel_BarracksAddOn_quick", RAW_CMD, 451, 3659},
          {"Cancel_CreepTumor_quick", RAW_CMD, 1763, 3659},
          {"Cancel_FactoryAddOn_quick", RAW_CMD, 484, 3659},
          {"Cancel_HangarQueue5_quick", RAW_CMD, 1038, 3671},
          {"Cancel_LockOn_quick", RAW_CMD, 2354, 3659},
          {"Cancel_MorphBroodlord_quick", RAW_CMD, 1373, 3659},
          {"Cancel_MorphGreaterSpire_quick", RAW_CMD, 1221, 3659},
          {"Cancel_MorphHive_quick", RAW_CMD, 1219, 3659},
          {"Cancel_MorphLair_quick", RAW_CMD, 1217, 3659},
          {"Cancel_MorphLurker_quick", RAW_CMD, 2333, 3659},
          {"Cancel_MorphLurkerDen_quick", RAW_CMD, 2113, 3659},
          {"Cancel_MorphMothership_quick", RAW_CMD, 1848, 3659},
          {"Cancel_MorphOrbital_quick", RAW_CMD, 1517, 3659},
          {"Cancel_MorphOverlordTransport_quick", RAW_CMD, 2709, 3659},
          {"Cancel_MorphOverseer_quick", RAW_CMD, 1449, 3659},
          {"Cancel_MorphPlanetaryFortress_quick", RAW_CMD, 1451, 3659},
          {"Cancel_MorphRavager_quick", RAW_CMD, 2331, 3659},
          {"Cancel_MorphThorExplosiveMode_quick", RAW_CMD, 2365, 3659},
          {"Cancel_NeuralParasite_quick", RAW_CMD, 250, 3659},
          {"Cancel_Nuke_quick", RAW_CMD, 1623, 3659},
          {"Cancel_QueueAddOn_quick", RAW_CMD, 312, 3671},
          {"Cancel_SpineCrawlerRoot_quick", RAW_CMD, 1730, 3659},
          {"Cancel_SporeCrawlerRoot_quick", RAW_CMD, 1732, 3659},
          {"Cancel_StarportAddOn_quick", RAW_CMD, 517, 3659},
          {"Effect_Abduct_unit", RAW_CMD_UNIT, 2067},
          {"Effect_AntiArmorMissile_unit", RAW_CMD_UNIT, 3753},
          {"Effect_AutoTurret_pt", RAW_CMD_PT, 1764},
          {"Effect_BlindingCloud_pt", RAW_CMD_PT, 2063},
          {"Effect_CalldownMULE_pt", RAW_CMD_PT, 171},
          {"Effect_CalldownMULE_unit", RAW_CMD_UNIT, 171},
          {"Effect_CausticSpray_unit", RAW_CMD_UNIT, 2324},
          {"Effect_Charge_pt", RAW_CMD_PT, 1819},
          {"Effect_Charge_unit", RAW_CMD_UNIT, 1819},
          {"Effect_Charge_autocast", RAW_AUTOCAST, 1819},
          {"Effect_Contaminate_unit", RAW_CMD_UNIT, 1825},
          {"Effect_CorrosiveBile_pt", RAW_CMD_PT, 2338},
          {"Effect_EMP_pt", RAW_CMD_PT, 1628},
          {"Effect_EMP_unit", RAW_CMD_UNIT, 1628},
          {"Effect_Explode_quick", RAW_CMD, 42},
          {"Effect_FungalGrowth_pt", RAW_CMD_PT, 74},
          {"Effect_FungalGrowth_unit", RAW_CMD_UNIT, 74},
          {"Effect_GhostSnipe_unit", RAW_CMD_UNIT, 2714},
          {"Effect_Heal_unit", RAW_CMD_UNIT, 386},
          {"Effect_Heal_autocast", RAW_AUTOCAST, 386},
          {"Effect_ImmortalBarrier_autocast", RAW_AUTOCAST, 2328},
          {"Effect_InfestedTerrans_pt", RAW_CMD_PT, 247},
          {"Effect_InjectLarva_unit", RAW_CMD_UNIT, 251},
          {"Effect_InterferenceMatrix_unit", RAW_CMD_UNIT, 3747},
          {"Effect_KD8Charge_pt", RAW_CMD_PT, 2588},
          {"Effect_LockOn_unit", RAW_CMD_UNIT, 2350},
          {"Effect_LocustSwoop_pt", RAW_CMD_PT, 2387},
          {"Effect_MedivacIgniteAfterburners_quick", RAW_CMD, 2116},
          {"Effect_NeuralParasite_unit", RAW_CMD_UNIT, 249},
          {"Effect_NukeCalldown_pt", RAW_CMD_PT, 1622},
          {"Effect_ParasiticBomb_unit", RAW_CMD_UNIT, 2542},
          {"Effect_Repair_autocast", RAW_AUTOCAST, 3685},
          {"Effect_Repair_Mule_unit", RAW_CMD_UNIT, 78, 3685},
          {"Effect_Repair_Mule_autocast", RAW_AUTOCAST, 78, 3685},
          {"Effect_Repair_RepairDrone_unit", RAW_CMD_UNIT, 3751, 3685},
          {"Effect_Repair_RepairDrone_autocast", RAW_AUTOCAST, 3751, 3685},
          {"Effect_Repair_SCV_unit", RAW_CMD_UNIT, 316, 3685},
          {"Effect_Repair_SCV_autocast", RAW_AUTOCAST, 316, 3685},
          {"Effect_Restore_autocast", RAW_AUTOCAST, 3765},
          {"Effect_Salvage_quick", RAW_CMD, 32},
          {"Effect_Scan_pt", RAW_CMD_PT, 399},
          {"Effect_SpawnChangeling_quick", RAW_CMD, 181},
          {"Effect_SpawnLocusts_pt", RAW_CMD_PT, 2704},
          {"Effect_SpawnLocusts_unit", RAW_CMD_UNIT, 2704},
          {"Effect_Spray_pt", RAW_CMD_PT, 3684},
          {"Effect_Spray_Protoss_pt", RAW_CMD_PT, 30, 3684},
          {"Effect_Spray_Terran_pt", RAW_CMD_PT, 26, 3684},
          {"Effect_Spray_Zerg_pt", RAW_CMD_PT, 28, 3684},
          {"Effect_Stim_quick", RAW_CMD, 3675},
          {"Effect_Stim_Marauder_quick", RAW_CMD, 253, 3675},
          {"Effect_Stim_Marauder_Redirect_quick", RAW_CMD, 1684, 3675},
          {"Effect_Stim_Marine_quick", RAW_CMD, 380, 3675},
          {"Effect_Stim_Marine_Redirect_quick", RAW_CMD, 1683, 3675},
          {"Effect_SupplyDrop_unit", RAW_CMD_UNIT, 255},
          {"Effect_TacticalJump_pt", RAW_CMD_PT, 2358},
          {"Effect_TimeWarp_pt", RAW_CMD_PT, 2244},
          {"Effect_Transfusion_unit", RAW_CMD_UNIT, 1664},
          {"Effect_ViperConsume_unit", RAW_CMD_UNIT, 2073},
          {"Effect_WidowMineAttack_pt", RAW_CMD_PT, 2099},
          {"Effect_WidowMineAttack_unit", RAW_CMD_UNIT, 2099},
          {"Effect_WidowMineAttack_autocast", RAW_AUTOCAST, 2099},
          {"Halt_Building_quick", RAW_CMD, 315, 3660},
          {"Halt_TerranBuild_quick", RAW_CMD, 348, 3660},
          {"Harvest_Gather_Drone_unit", RAW_CMD_UNIT, 1183, 3666},
          {"Harvest_Gather_Mule_unit", RAW_CMD_UNIT, 166, 3666},
          {"Harvest_Gather_Probe_unit", RAW_CMD_UNIT, 298, 3666},
          {"Harvest_Gather_SCV_unit", RAW_CMD_UNIT, 295, 3666},
          {"Harvest_Return_Drone_quick", RAW_CMD, 1184, 3667},
          {"Harvest_Return_Mule_quick", RAW_CMD, 167, 3667},
          {"Harvest_Return_SCV_quick", RAW_CMD, 296, 3667},
          {"Land_pt", RAW_CMD_PT, 3678},
          {"Land_Barracks_pt", RAW_CMD_PT, 554, 3678},
          {"Land_CommandCenter_pt", RAW_CMD_PT, 419, 3678},
          {"Land_Factory_pt", RAW_CMD_PT, 520, 3678},
          {"Land_OrbitalCommand_pt", RAW_CMD_PT, 1524, 3678},
          {"Land_Starport_pt", RAW_CMD_PT, 522, 3678},
          {"Lift_quick", RAW_CMD, 3679},
          {"Lift_Barracks_quick", RAW_CMD, 452, 3679},
          {"Lift_CommandCenter_quick", RAW_CMD, 417, 3679},
          {"Lift_Factory_quick", RAW_CMD, 485, 3679},
          {"Lift_OrbitalCommand_quick", RAW_CMD, 1522, 3679},
          {"Lift_Starport_quick", RAW_CMD, 518, 3679},
          {"LoadAll_quick", RAW_CMD, 3663},
          {"LoadAll_CommandCenter_quick", RAW_CMD, 416, 3663},
          {"Load_Bunker_unit", RAW_CMD_UNIT, 407, 3668},
          {"Load_Medivac_unit", RAW_CMD_UNIT, 394, 3668},
          {"Load_NydusNetwork_unit", RAW_CMD_UNIT, 1437, 3668},
          {"Load_NydusWorm_unit", RAW_CMD_UNIT, 2370, 3668},
          {"Load_Overlord_unit", RAW_CMD_UNIT, 1406, 3668},
          {"Load_WarpPrism_unit", RAW_CMD_UNIT, 911, 3668},
          {"Morph_BroodLord_quick", RAW_CMD, 1372},
          {"Morph_GreaterSpire_quick", RAW_CMD, 1220},
          {"Morph_Hellbat_quick", RAW_CMD, 1998},
          {"Morph_Hellion_quick", RAW_CMD, 1978},
          {"Morph_Hive_quick", RAW_CMD, 1218},
          {"Morph_Lair_quick", RAW_CMD, 1216},
          {"Morph_LiberatorAAMode_quick", RAW_CMD, 2560},
          {"Morph_LiberatorAGMode_pt", RAW_CMD_PT, 2558},
          {"Morph_Lurker_quick", RAW_CMD, 2332},
          {"Morph_LurkerDen_quick", RAW_CMD, 2112},
          {"Morph_Mothership_quick", RAW_CMD, 1847},
          {"Morph_OrbitalCommand_quick", RAW_CMD, 1516},
          {"Morph_OverlordTransport_quick", RAW_CMD, 2708},
          {"Morph_Overseer_quick", RAW_CMD, 1448},
          {"Morph_OverseerMode_quick", RAW_CMD, 3745},
          {"Morph_OversightMode_quick", RAW_CMD, 3743},
          {"Morph_PlanetaryFortress_quick", RAW_CMD, 1450},
          {"Morph_Ravager_quick", RAW_CMD, 2330},
          {"Morph_Root_pt", RAW_CMD_PT, 3680},
          {"Morph_SiegeMode_quick", RAW_CMD, 388},
          {"Morph_SpineCrawlerRoot_pt", RAW_CMD_PT, 1729, 3680},
          {"Morph_SpineCrawlerUproot_quick", RAW_CMD, 1725, 3681},
          {"Morph_SporeCrawlerRoot_pt", RAW_CMD_PT, 1731, 3680},
          {"Morph_SporeCrawlerUproot_quick", RAW_CMD, 1727, 3681},
          {"Morph_SupplyDepot_Lower_quick", RAW_CMD, 556},
          {"Morph_SupplyDepot_Raise_quick", RAW_CMD, 558},
          {"Morph_ThorExplosiveMode_quick", RAW_CMD, 2364},
          {"Morph_ThorHighImpactMode_quick", RAW_CMD, 2362},
          {"Morph_Unsiege_quick", RAW_CMD, 390},
          {"Morph_Uproot_quick", RAW_CMD, 3681},
          {"Morph_VikingAssaultMode_quick", RAW_CMD, 403},
          {"Morph_VikingFighterMode_quick", RAW_CMD, 405},
          {"Rally_Building_pt", RAW_CMD_PT, 195, 3673},
          {"Rally_Building_unit", RAW_CMD_UNIT, 195, 3673},
          {"Rally_CommandCenter_pt", RAW_CMD_PT, 203, 3690},
          {"Rally_CommandCenter_unit", RAW_CMD_UNIT, 203, 3690},
          {"Rally_Hatchery_Units_pt", RAW_CMD_PT, 211, 3673},
          {"Rally_Hatchery_Units_unit", RAW_CMD_UNIT, 211, 3673},
          {"Rally_Hatchery_Workers_pt", RAW_CMD_PT, 212, 3690},
          {"Rally_Hatchery_Workers_unit", RAW_CMD_UNIT, 212, 3690},
          {"Rally_Morphing_Unit_pt", RAW_CMD_PT, 199, 3673},
          {"Rally_Morphing_Unit_unit", RAW_CMD_UNIT, 199, 3673},
          {"Research_AdaptiveTalons_quick", RAW_CMD, 3709},
          {"Research_AdvancedBallistics_quick", RAW_CMD, 805},
          {"Research_BansheeCloakingField_quick", RAW_CMD, 790},
          {"Research_BansheeHyperflightRotors_quick", RAW_CMD, 799},
          {"Research_BattlecruiserWeaponRefit_quick", RAW_CMD, 1532},
          {"Research_Burrow_quick", RAW_CMD, 1225},
          {"Research_CentrifugalHooks_quick", RAW_CMD, 1482},
          {"Research_ChitinousPlating_quick", RAW_CMD, 265},
          {"Research_CombatShield_quick", RAW_CMD, 731},
          {"Research_ConcussiveShells_quick", RAW_CMD, 732},
          {"Research_CycloneRapidFireLaunchers_quick", RAW_CMD, 768},
          {"Research_DrillingClaws_quick", RAW_CMD, 764},
          {"Research_GlialRegeneration_quick", RAW_CMD, 216},
          {"Research_GroovedSpines_quick", RAW_CMD, 1282},
          {"Research_HiSecAutoTracking_quick", RAW_CMD, 650},
          {"Research_HighCapacityFuelTanks_quick", RAW_CMD, 804},
          {"Research_InfernalPreigniter_quick", RAW_CMD, 761},
          {"Research_MuscularAugments_quick", RAW_CMD, 1283},
          {"Research_NeosteelFrame_quick", RAW_CMD, 655},
          {"Research_NeuralParasite_quick", RAW_CMD, 1455},
          {"Research_PathogenGlands_quick", RAW_CMD, 1454},
          {"Research_PersonalCloaking_quick", RAW_CMD, 820},
          {"Research_PneumatizedCarapace_quick", RAW_CMD, 1223},
          {"Research_RavenCorvidReactor_quick", RAW_CMD, 793},
          {"Research_RavenRecalibratedExplosives_quick", RAW_CMD, 803},
          {"Research_SmartServos_quick", RAW_CMD, 766},
          {"Research_Stimpack_quick", RAW_CMD, 730},
          {"Research_TerranInfantryArmor_quick", RAW_CMD, 3697},
          {"Research_TerranInfantryArmorLevel1_quick", RAW_CMD, 656, 3697},
          {"Research_TerranInfantryArmorLevel2_quick", RAW_CMD, 657, 3697},
          {"Research_TerranInfantryArmorLevel3_quick", RAW_CMD, 658, 3697},
          {"Research_TerranInfantryWeapons_quick", RAW_CMD, 3698},
          {"Research_TerranInfantryWeaponsLevel1_quick", RAW_CMD, 652, 3698},
          {"Research_TerranInfantryWeaponsLevel2_quick", RAW_CMD, 653, 3698},
          {"Research_TerranInfantryWeaponsLevel3_quick", RAW_CMD, 654, 3698},
          {"Research_TerranShipWeapons_quick", RAW_CMD, 3699},
          {"Research_TerranShipWeaponsLevel1_quick", RAW_CMD, 861, 3699},
          {"Research_TerranShipWeaponsLevel2_quick", RAW_CMD, 862, 3699},
          {"Research_TerranShipWeaponsLevel3_quick", RAW_CMD, 863, 3699},
          {"Research_TerranStructureArmorUpgrade_quick", RAW_CMD, 651},
          {"Research_TerranVehicleAndShipPlating_quick", RAW_CMD, 3700},
          {"Research_TerranVehicleAndShipPlatingLevel1_quick", RAW_CMD, 864,
           3700},
          {"Research_TerranVehicleAndShipPlatingLevel2_quick", RAW_CMD, 865,
           3700},
          {"Research_TerranVehicleAndShipPlatingLevel3_quick", RAW_CMD, 866,
           3700},
          {"Research_TerranVehicleWeapons_quick", RAW_CMD, 3701},
          {"Research_TerranVehicleWeaponsLevel1_quick", RAW_CMD, 855, 3701},
          {"Research_TerranVehicleWeaponsLevel2_quick", RAW_CMD, 856, 3701},
          {"Research_TerranVehicleWeaponsLevel3_quick", RAW_CMD, 857, 3701},
          {"Research_TunnelingClaws_quick", RAW_CMD, 217},
          {"Research_ZergFlyerArmor_quick", RAW_CMD, 3702},
          {"Research_ZergFlyerArmorLevel1_quick", RAW_CMD, 1315, 3702},
          {"Research_ZergFlyerArmorLevel2_quick", RAW_CMD, 1316, 3702},
          {"Research_ZergFlyerArmorLevel3_quick", RAW_CMD, 1317, 3702},
          {"Research_ZergFlyerAttack_quick", RAW_CMD, 3703},
          {"Research_ZergFlyerAttackLevel1_quick", RAW_CMD, 1312, 3703},
          {"Research_ZergFlyerAttackLevel2_quick", RAW_CMD, 1313, 3703},
          {"Research_ZergFlyerAttackLevel3_quick", RAW_CMD, 1314, 3703},
          {"Research_ZergGroundArmor_quick", RAW_CMD, 3704},
          {"Research_ZergGroundArmorLevel1_quick", RAW_CMD, 1189, 3704},
          {"Research_ZergGroundArmorLevel2_quick", RAW_CMD, 1190, 3704},
          {"Research_ZergGroundArmorLevel3_quick", RAW_CMD, 1191, 3704},
          {"Research_ZergMeleeWeapons_quick", RAW_CMD, 3705},
          {"Research_ZergMeleeWeaponsLevel1_quick", RAW_CMD, 1186, 3705},
          {"Research_ZergMeleeWeaponsLevel2_quick", RAW_CMD, 1187, 3705},
          {"Research_ZergMeleeWeaponsLevel3_quick", RAW_CMD, 1188, 3705},
          {"Research_ZergMissileWeapons_quick", RAW_CMD, 3706},
          {"Research_ZergMissileWeaponsLevel1_quick", RAW_CMD, 1192, 3706},
          {"Research_ZergMissileWeaponsLevel2_quick", RAW_CMD, 1193, 3706},
          {"Research_ZergMissileWeaponsLevel3_quick", RAW_CMD, 1194, 3706},
          {"Research_ZerglingAdrenalGlands_quick", RAW_CMD, 1252},
          {"Research_ZerglingMetabolicBoost_quick", RAW_CMD, 1253},
          {"Stop_Building_quick", RAW_CMD, 2057, 3665},
          {"Stop_Redirect_quick", RAW_CMD, 1691, 3665},
          {"Train_Baneling_quick", RAW_CMD, 80},
          {"Train_Banshee_quick", RAW_CMD, 621},
          {"Train_Battlecruiser_quick", RAW_CMD, 623},
          {"Train_Corruptor_quick", RAW_CMD, 1353},
          {"Train_Cyclone_quick", RAW_CMD, 597},
          {"Train_Drone_quick", RAW_CMD, 1342},
          {"Train_Ghost_quick", RAW_CMD, 562},
          {"Train_Hellbat_quick", RAW_CMD, 596},
          {"Train_Hellion_quick", RAW_CMD, 595},
          {"Train_Hydralisk_quick", RAW_CMD, 1345},
          {"Train_Infestor_quick", RAW_CMD, 1352},
          {"Train_Liberator_quick", RAW_CMD, 626},
          {"Train_Marauder_quick", RAW_CMD, 563},
          {"Train_Marine_quick", RAW_CMD, 560},
          {"Train_Medivac_quick", RAW_CMD, 620},
          {"Train_MothershipCore_quick", RAW_CMD, 1853},
          {"Train_Mutalisk_quick", RAW_CMD, 1346},
          {"Train_Overlord_quick", RAW_CMD, 1344},
          {"Train_Queen_quick", RAW_CMD, 1632},
          {"Train_Raven_quick", RAW_CMD, 622},
          {"Train_Reaper_quick", RAW_CMD, 561},
          {"Train_Roach_quick", RAW_CMD, 1351},
          {"Train_SCV_quick", RAW_CMD, 524},
          {"Train_SiegeTank_quick", RAW_CMD, 591},
          {"Train_SwarmHost_quick", RAW_CMD, 1356},
          {"Train_Thor_quick", RAW_CMD, 594},
          {"Train_Ultralisk_quick", RAW_CMD, 1348},
          {"Train_VikingFighter_quick", RAW_CMD, 624},
          {"Train_Viper_quick", RAW_CMD, 1354},
          {"Train_WidowMine_quick", RAW_CMD, 614},
          {"Train_Zergling_quick", RAW_CMD, 1343},
          {"UnloadAllAt_Medivac_pt", RAW_CMD_PT, 396, 3669},
          {"UnloadAllAt_Medivac_unit", RAW_CMD_UNIT, 396, 3669},
          {"UnloadAllAt_Overlord_pt", RAW_CMD_PT, 1408, 3669},
          {"UnloadAllAt_Overlord_unit", RAW_CMD_UNIT, 1408, 3669},
          {"UnloadAll_Bunker_quick", RAW_CMD, 408, 3664},
          {"UnloadAll_CommandCenter_quick", RAW_CMD, 413, 3664},
          {"UnloadAll_NydusNetwork_quick", RAW_CMD, 1438, 3664},
          {"UnloadAll_NydusWorm_quick", RAW_CMD, 2371, 3664},
          {"Effect_YamatoGun_unit", RAW_CMD_UNIT, 401},
          {"Effect_KD8Charge_unit", RAW_CMD_UNIT, 2588},
          {"Attack_Battlecruiser_pt", RAW_CMD_PT, 3771, 3674},
          {"Attack_Battlecruiser_unit", RAW_CMD_UNIT, 3771, 3674},
          {"Effect_LockOn_autocast", RAW_AUTOCAST, 2350},
          {"HoldPosition_Battlecruiser_quick", RAW_CMD, 3778, 3793},
          {"HoldPosition_Hold_quick", RAW_CMD, 18, 3793},
          {"Morph_WarpGate_autocast", RAW_AUTOCAST, 1518},
          {"Move_Battlecruiser_pt", RAW_CMD_PT, 3776, 3794},
          {"Move_Battlecruiser_unit", RAW_CMD_UNIT, 3776, 3794},
          {"Move_Move_pt", RAW_CMD_PT, 16, 3794},
          {"Move_Move_unit", RAW_CMD_UNIT, 16, 3794},
          {"Patrol_Battlecruiser_pt", RAW_CMD_PT, 3777, 3795},
          {"Patrol_Battlecruiser_unit", RAW_CMD_UNIT, 3777, 3795},
          {"Patrol_Patrol_pt", RAW_CMD_PT, 17, 3795},
          {"Patrol_Patrol_unit", RAW_CMD_UNIT, 17, 3795},
          {"Research_AnabolicSynthesis_quick", RAW_CMD, 263},
          {"Research_CycloneLockOnDamage_quick", RAW_CMD, 769},
          {"Stop_Battlecruiser_quick", RAW_CMD, 3783, 3665},
          {"UnloadUnit_quick", RAW_CMD, 3796},
          {"UnloadUnit_Bunker_quick", RAW_CMD, 410, 3796},
          {"UnloadUnit_CommandCenter_quick", RAW_CMD, 415, 3796},
          {"UnloadUnit_Medivac_quick", RAW_CMD, 397, 3796},
          {"UnloadUnit_NydusNetwork_quick", RAW_CMD, 1440, 3796},
          {"UnloadUnit_Overlord_quick", RAW_CMD, 1409, 3796},
          {"UnloadUnit_WarpPrism_quick", RAW_CMD, 914, 3796},
          {"Research_EnhancedShockwaves_quick", RAW_CMD, 822},
      });
  return *functions;
}

}  // namespace pysc2