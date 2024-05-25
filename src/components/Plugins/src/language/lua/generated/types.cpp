#include "../../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

void SetupLuaGeneratedTypes(luacpp::LuaState *state, Plugin *plugin)
{
    auto PropDoorRotatingOpenDirection_eTable = state->CreateTable("PropDoorRotatingOpenDirection_e");
    PropDoorRotatingOpenDirection_eTable.SetInteger("DOOR_ROTATING_OPEN_BOTH_WAYS", 0x0);
    PropDoorRotatingOpenDirection_eTable.SetInteger("DOOR_ROTATING_OPEN_FORWARD", 0x1);
    PropDoorRotatingOpenDirection_eTable.SetInteger("DOOR_ROTATING_OPEN_BACKWARD", 0x2);


    auto SceneOnPlayerDeath_tTable = state->CreateTable("SceneOnPlayerDeath_t");
    SceneOnPlayerDeath_tTable.SetInteger("SCENE_ONPLAYERDEATH_DO_NOTHING", 0x0);
    SceneOnPlayerDeath_tTable.SetInteger("SCENE_ONPLAYERDEATH_CANCEL", 0x1);


    auto LessonPanelLayoutFileTypes_tTable = state->CreateTable("LessonPanelLayoutFileTypes_t");
    LessonPanelLayoutFileTypes_tTable.SetInteger("LAYOUT_HAND_DEFAULT", 0x0);
    LessonPanelLayoutFileTypes_tTable.SetInteger("LAYOUT_WORLD_DEFAULT", 0x1);
    LessonPanelLayoutFileTypes_tTable.SetInteger("LAYOUT_CUSTOM", 0x2);


    auto TimelineCompression_tTable = state->CreateTable("TimelineCompression_t");
    TimelineCompression_tTable.SetInteger("TIMELINE_COMPRESSION_SUM", 0x0);
    TimelineCompression_tTable.SetInteger("TIMELINE_COMPRESSION_COUNT_PER_INTERVAL", 0x1);
    TimelineCompression_tTable.SetInteger("TIMELINE_COMPRESSION_AVERAGE", 0x2);
    TimelineCompression_tTable.SetInteger("TIMELINE_COMPRESSION_AVERAGE_BLEND", 0x3);
    TimelineCompression_tTable.SetInteger("TIMELINE_COMPRESSION_TOTAL", 0x4);


    auto SubclassVDataChangeType_tTable = state->CreateTable("SubclassVDataChangeType_t");
    SubclassVDataChangeType_tTable.SetInteger("SUBCLASS_VDATA_CREATED", 0x0);
    SubclassVDataChangeType_tTable.SetInteger("SUBCLASS_VDATA_SUBCLASS_CHANGED", 0x1);
    SubclassVDataChangeType_tTable.SetInteger("SUBCLASS_VDATA_RELOADED", 0x2);


    auto C4LightEffect_tTable = state->CreateTable("C4LightEffect_t");
    C4LightEffect_tTable.SetInteger("eLightEffectNone", 0x0);
    C4LightEffect_tTable.SetInteger("eLightEffectDropped", 0x1);
    C4LightEffect_tTable.SetInteger("eLightEffectThirdPersonHeld", 0x2);


    auto StanceType_tTable = state->CreateTable("StanceType_t");
    StanceType_tTable.SetInteger("STANCE_CURRENT", 0xffffffffffffffff);
    StanceType_tTable.SetInteger("STANCE_DEFAULT", 0x0);
    StanceType_tTable.SetInteger("STANCE_CROUCHING", 0x1);
    StanceType_tTable.SetInteger("STANCE_PRONE", 0x2);
    StanceType_tTable.SetInteger("NUM_STANCES", 0x3);


    auto ExplosionsTable = state->CreateTable("Explosions");
    ExplosionsTable.SetInteger("expRandom", 0x0);
    ExplosionsTable.SetInteger("expDirected", 0x1);
    ExplosionsTable.SetInteger("expUsePrecise", 0x2);


    auto PreviewCharacterModeTable = state->CreateTable("PreviewCharacterMode");
    PreviewCharacterModeTable.SetInteger("DIORAMA", 0x0);
    PreviewCharacterModeTable.SetInteger("MAIN_MENU", 0x1);
    PreviewCharacterModeTable.SetInteger("BUY_MENU", 0x2);
    PreviewCharacterModeTable.SetInteger("TEAM_SELECT", 0x3);
    PreviewCharacterModeTable.SetInteger("END_OF_MATCH", 0x4);
    PreviewCharacterModeTable.SetInteger("INVENTORY_INSPECT", 0x5);
    PreviewCharacterModeTable.SetInteger("WALKING", 0x6);
    PreviewCharacterModeTable.SetInteger("TEAM_INTRO", 0x7);
    PreviewCharacterModeTable.SetInteger("WINGMAN_INTRO", 0x8);


    auto ObserverInterpState_tTable = state->CreateTable("ObserverInterpState_t");
    ObserverInterpState_tTable.SetInteger("OBSERVER_INTERP_NONE", 0x0);
    ObserverInterpState_tTable.SetInteger("OBSERVER_INTERP_TRAVELING", 0x1);
    ObserverInterpState_tTable.SetInteger("OBSERVER_INTERP_SETTLING", 0x2);


    auto WorldTextPanelOrientation_tTable = state->CreateTable("WorldTextPanelOrientation_t");
    WorldTextPanelOrientation_tTable.SetInteger("WORLDTEXT_ORIENTATION_DEFAULT", 0x0);
    WorldTextPanelOrientation_tTable.SetInteger("WORLDTEXT_ORIENTATION_FACEUSER", 0x1);
    WorldTextPanelOrientation_tTable.SetInteger("WORLDTEXT_ORIENTATION_FACEUSER_UPRIGHT", 0x2);


    auto WorldTextPanelHorizontalAlign_tTable = state->CreateTable("WorldTextPanelHorizontalAlign_t");
    WorldTextPanelHorizontalAlign_tTable.SetInteger("WORLDTEXT_HORIZONTAL_ALIGN_LEFT", 0x0);
    WorldTextPanelHorizontalAlign_tTable.SetInteger("WORLDTEXT_HORIZONTAL_ALIGN_CENTER", 0x1);
    WorldTextPanelHorizontalAlign_tTable.SetInteger("WORLDTEXT_HORIZONTAL_ALIGN_RIGHT", 0x2);


    auto SequenceFinishNotifyState_tTable = state->CreateTable("SequenceFinishNotifyState_t");
    SequenceFinishNotifyState_tTable.SetInteger("eDoNotNotify", 0x0);
    SequenceFinishNotifyState_tTable.SetInteger("eNotifyWhenFinished", 0x1);
    SequenceFinishNotifyState_tTable.SetInteger("eNotifyTriggered", 0x2);


    auto SoundEventStartType_tTable = state->CreateTable("SoundEventStartType_t");
    SoundEventStartType_tTable.SetInteger("SOUNDEVENT_START_PLAYER", 0x0);
    SoundEventStartType_tTable.SetInteger("SOUNDEVENT_START_WORLD", 0x1);
    SoundEventStartType_tTable.SetInteger("SOUNDEVENT_START_ENTITY", 0x2);


    auto TrainOrientationType_tTable = state->CreateTable("TrainOrientationType_t");
    TrainOrientationType_tTable.SetInteger("TrainOrientation_Fixed", 0x0);
    TrainOrientationType_tTable.SetInteger("TrainOrientation_AtPathTracks", 0x1);
    TrainOrientationType_tTable.SetInteger("TrainOrientation_LinearBlend", 0x2);
    TrainOrientationType_tTable.SetInteger("TrainOrientation_EaseInEaseOut", 0x3);


    auto CSWeaponCategoryTable = state->CreateTable("CSWeaponCategory");
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_OTHER", 0x0);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_MELEE", 0x1);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_SECONDARY", 0x2);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_SMG", 0x3);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_RIFLE", 0x4);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_HEAVY", 0x5);
    CSWeaponCategoryTable.SetInteger("WEAPONCATEGORY_COUNT", 0x6);


    auto BeginDeathLifeStateTransition_tTable = state->CreateTable("BeginDeathLifeStateTransition_t");
    BeginDeathLifeStateTransition_tTable.SetInteger("NO_CHANGE_IN_LIFESTATE", 0x0);
    BeginDeathLifeStateTransition_tTable.SetInteger("TRANSITION_TO_LIFESTATE_DYING", 0x1);
    BeginDeathLifeStateTransition_tTable.SetInteger("TRANSITION_TO_LIFESTATE_DEAD", 0x2);


    auto PlayerAnimEvent_tTable = state->CreateTable("PlayerAnimEvent_t");
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_FIRE_GUN_PRIMARY", 0x0);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_FIRE_GUN_SECONDARY", 0x1);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_GRENADE_PULL_PIN", 0x2);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_THROW_GRENADE", 0x3);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_JUMP", 0x4);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_RELOAD", 0x5);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_CLEAR_FIRING", 0x6);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_DEPLOY", 0x7);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_SILENCER_STATE", 0x8);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_SILENCER_TOGGLE", 0x9);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_THROW_GRENADE_UNDERHAND", 0xa);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_CATCH_WEAPON", 0xb);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_LOOKATWEAPON_REQUEST", 0xc);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_RELOAD_CANCEL_LOOKATWEAPON", 0xd);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_HAULBACK", 0xe);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_IDLE", 0xf);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_STRIKE_HIT", 0x10);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_STRIKE_MISS", 0x11);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_BACKSTAB", 0x12);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_DRYFIRE", 0x13);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_FIDGET", 0x14);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_RELEASE", 0x15);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_TAUNT", 0x16);
    PlayerAnimEvent_tTable.SetInteger("PLAYERANIMEVENT_COUNT", 0x17);


    auto ItemFlagTypes_tTable = state->CreateTable("ItemFlagTypes_t");
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_NONE", 0x0);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_CAN_SELECT_WITHOUT_AMMO", 0x1);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_NOAUTORELOAD", 0x2);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_NOAUTOSWITCHEMPTY", 0x4);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_LIMITINWORLD", 0x8);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_EXHAUSTIBLE", 0x10);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_DOHITLOCATIONDMG", 0x20);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_NOAMMOPICKUPS", 0x40);
    ItemFlagTypes_tTable.SetInteger("ITEM_FLAG_NOITEMPICKUP", 0x80);


    auto ShatterPanelModeTable = state->CreateTable("ShatterPanelMode");
    ShatterPanelModeTable.SetInteger("SHATTER_GLASS", 0x0);
    ShatterPanelModeTable.SetInteger("SHATTER_DRYWALL", 0x1);


    auto SurroundingBoundsType_tTable = state->CreateTable("SurroundingBoundsType_t");
    SurroundingBoundsType_tTable.SetInteger("USE_OBB_COLLISION_BOUNDS", 0x0);
    SurroundingBoundsType_tTable.SetInteger("USE_BEST_COLLISION_BOUNDS", 0x1);
    SurroundingBoundsType_tTable.SetInteger("USE_HITBOXES", 0x2);
    SurroundingBoundsType_tTable.SetInteger("USE_SPECIFIED_BOUNDS", 0x3);
    SurroundingBoundsType_tTable.SetInteger("USE_GAME_CODE", 0x4);
    SurroundingBoundsType_tTable.SetInteger("USE_ROTATION_EXPANDED_BOUNDS", 0x5);
    SurroundingBoundsType_tTable.SetInteger("USE_ROTATION_EXPANDED_ORIENTED_BOUNDS", 0x6);
    SurroundingBoundsType_tTable.SetInteger("USE_COLLISION_BOUNDS_NEVER_VPHYSICS", 0x7);
    SurroundingBoundsType_tTable.SetInteger("USE_ROTATION_EXPANDED_SEQUENCE_BOUNDS", 0x8);
    SurroundingBoundsType_tTable.SetInteger("SURROUNDING_TYPE_BIT_COUNT", 0x3);


    auto LifeState_tTable = state->CreateTable("LifeState_t");
    LifeState_tTable.SetInteger("LIFE_ALIVE", 0x0);
    LifeState_tTable.SetInteger("LIFE_DYING", 0x1);
    LifeState_tTable.SetInteger("LIFE_DEAD", 0x2);
    LifeState_tTable.SetInteger("LIFE_RESPAWNABLE", 0x3);
    LifeState_tTable.SetInteger("LIFE_RESPAWNING", 0x4);


    auto NPCFollowFormation_tTable = state->CreateTable("NPCFollowFormation_t");
    NPCFollowFormation_tTable.SetInteger("Default", 0xffffffffffffffff);
    NPCFollowFormation_tTable.SetInteger("CloseCircle", 0x0);
    NPCFollowFormation_tTable.SetInteger("WideCircle", 0x1);
    NPCFollowFormation_tTable.SetInteger("MediumCircle", 0x5);
    NPCFollowFormation_tTable.SetInteger("Sidekick", 0x6);


    auto CSWeaponModeTable = state->CreateTable("CSWeaponMode");
    CSWeaponModeTable.SetInteger("Primary_Mode", 0x0);
    CSWeaponModeTable.SetInteger("Secondary_Mode", 0x1);
    CSWeaponModeTable.SetInteger("WeaponMode_MAX", 0x2);


    auto OnFrameTable = state->CreateTable("OnFrame");
    OnFrameTable.SetInteger("ONFRAME_UNKNOWN", 0x0);
    OnFrameTable.SetInteger("ONFRAME_TRUE", 0x1);
    OnFrameTable.SetInteger("ONFRAME_FALSE", 0x2);


    auto MaterialsTable = state->CreateTable("Materials");
    MaterialsTable.SetInteger("matGlass", 0x0);
    MaterialsTable.SetInteger("matWood", 0x1);
    MaterialsTable.SetInteger("matMetal", 0x2);
    MaterialsTable.SetInteger("matFlesh", 0x3);
    MaterialsTable.SetInteger("matCinderBlock", 0x4);
    MaterialsTable.SetInteger("matCeilingTile", 0x5);
    MaterialsTable.SetInteger("matComputer", 0x6);
    MaterialsTable.SetInteger("matUnbreakableGlass", 0x7);
    MaterialsTable.SetInteger("matRocks", 0x8);
    MaterialsTable.SetInteger("matWeb", 0x9);
    MaterialsTable.SetInteger("matNone", 0xa);
    MaterialsTable.SetInteger("matLastMaterial", 0xb);


    auto ScriptedMoveTo_tTable = state->CreateTable("ScriptedMoveTo_t");
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_WAIT", 0x0);
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_WALK", 0x1);
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_RUN", 0x2);
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_CUSTOM", 0x3);
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_TELEPORT", 0x4);
    ScriptedMoveTo_tTable.SetInteger("CINE_MOVETO_WAIT_FACING", 0x5);


    auto AnimLoopMode_tTable = state->CreateTable("AnimLoopMode_t");
    AnimLoopMode_tTable.SetInteger("ANIM_LOOP_MODE_INVALID", 0xffffffffffffffff);
    AnimLoopMode_tTable.SetInteger("ANIM_LOOP_MODE_NOT_LOOPING", 0x0);
    AnimLoopMode_tTable.SetInteger("ANIM_LOOP_MODE_LOOPING", 0x1);
    AnimLoopMode_tTable.SetInteger("ANIM_LOOP_MODE_USE_SEQUENCE_SETTINGS", 0x2);
    AnimLoopMode_tTable.SetInteger("ANIM_LOOP_MODE_COUNT", 0x3);


    auto SoundFlags_tTable = state->CreateTable("SoundFlags_t");
    SoundFlags_tTable.SetInteger("SOUND_NONE", 0x0);
    SoundFlags_tTable.SetInteger("SOUND_COMBAT", 0x1);
    SoundFlags_tTable.SetInteger("SOUND_WORLD", 0x2);
    SoundFlags_tTable.SetInteger("SOUND_PLAYER", 0x4);
    SoundFlags_tTable.SetInteger("SOUND_DANGER", 0x8);
    SoundFlags_tTable.SetInteger("SOUND_BULLET_IMPACT", 0x10);
    SoundFlags_tTable.SetInteger("SOUND_THUMPER", 0x20);
    SoundFlags_tTable.SetInteger("SOUND_PHYSICS_DANGER", 0x40);
    SoundFlags_tTable.SetInteger("SOUND_MOVE_AWAY", 0x80);
    SoundFlags_tTable.SetInteger("SOUND_PLAYER_VEHICLE", 0x100);
    SoundFlags_tTable.SetInteger("SOUND_GLASS_BREAK", 0x200);
    SoundFlags_tTable.SetInteger("SOUND_PHYSICS_OBJECT", 0x400);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_GUNFIRE", 0x100000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_COMBINE_ONLY", 0x200000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_REACT_TO_SOURCE", 0x400000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_EXPLOSION", 0x800000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_EXCLUDE_COMBINE", 0x1000000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_DANGER_APPROACH", 0x2000000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_ALLIES_ONLY", 0x4000000);
    SoundFlags_tTable.SetInteger("SOUND_CONTEXT_PANIC_NPCS", 0x8000000);
    SoundFlags_tTable.SetInteger("ALL_CONTEXTS", 0xfffffffffff00000);
    SoundFlags_tTable.SetInteger("ALL_SCENTS", 0x0);
    SoundFlags_tTable.SetInteger("ALL_SOUNDS", 0xfffff);


    auto Class_TTable = state->CreateTable("Class_T");
    Class_TTable.SetInteger("CLASS_NONE", 0x0);
    Class_TTable.SetInteger("CLASS_PLAYER", 0x1);
    Class_TTable.SetInteger("CLASS_PLAYER_ALLY", 0x2);
    Class_TTable.SetInteger("CLASS_BOMB", 0x3);
    Class_TTable.SetInteger("CLASS_FOOT_CONTACT_SHADOW", 0x4);
    Class_TTable.SetInteger("CLASS_WEAPON", 0x5);
    Class_TTable.SetInteger("CLASS_WATER_SPLASHER", 0x6);
    Class_TTable.SetInteger("CLASS_WEAPON_VIEWMODEL", 0x7);
    Class_TTable.SetInteger("CLASS_DOOR", 0x8);
    Class_TTable.SetInteger("NUM_CLASSIFY_CLASSES", 0x9);


    auto filter_tTable = state->CreateTable("filter_t");
    filter_tTable.SetInteger("FILTER_AND", 0x0);
    filter_tTable.SetInteger("FILTER_OR", 0x1);


    auto CSWeaponSilencerTypeTable = state->CreateTable("CSWeaponSilencerType");
    CSWeaponSilencerTypeTable.SetInteger("WEAPONSILENCER_NONE", 0x0);
    CSWeaponSilencerTypeTable.SetInteger("WEAPONSILENCER_DETACHABLE", 0x1);
    CSWeaponSilencerTypeTable.SetInteger("WEAPONSILENCER_INTEGRATED", 0x2);


    auto BaseExplosionTypes_tTable = state->CreateTable("BaseExplosionTypes_t");
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_DEFAULT", 0x0);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_GRENADE", 0x1);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_MOLOTOV", 0x2);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_FIREWORKS", 0x3);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_GASCAN", 0x4);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_GASCYLINDER", 0x5);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_EXPLOSIVEBARREL", 0x6);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_ELECTRICAL", 0x7);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_EMP", 0x8);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_SHRAPNEL", 0x9);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_SMOKEGRENADE", 0xa);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_FLASHBANG", 0xb);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_TRIPMINE", 0xc);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_ICE", 0xd);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_NONE", 0xe);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_CUSTOM", 0xf);
    BaseExplosionTypes_tTable.SetInteger("EXPLOSION_TYPE_COUNT", 0x10);


    auto GameAnimEventIndex_tTable = state->CreateTable("GameAnimEventIndex_t");
    GameAnimEventIndex_tTable.SetInteger("AE_EMPTY", 0x0);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_PLAYSOUND", 0x1);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_PLAYSOUND_ATTACHMENT", 0x2);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_PLAYSOUND_POSITION", 0x3);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_PLAYSOUND", 0x4);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_STOPSOUND", 0x5);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_PLAYSOUND_LOOPING", 0x6);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CREATE_PARTICLE_EFFECT", 0x7);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_STOP_PARTICLE_EFFECT", 0x8);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CREATE_PARTICLE_EFFECT_CFG", 0x9);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_CREATE_PARTICLE_EFFECT_CFG", 0xa);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_STOP_PARTICLE_EFFECT", 0xb);
    GameAnimEventIndex_tTable.SetInteger("AE_FOOTSTEP", 0xc);
    GameAnimEventIndex_tTable.SetInteger("AE_RAGDOLL", 0xd);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_STOP_RAGDOLL_CONTROL", 0xe);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_ENABLE_BODYGROUP", 0xf);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_DISABLE_BODYGROUP", 0x10);
    GameAnimEventIndex_tTable.SetInteger("AE_BODYGROUP_SET_VALUE", 0x11);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_BODYGROUP_SET_VALUE_CMODEL_WPN", 0x12);
    GameAnimEventIndex_tTable.SetInteger("AE_WEAPON_PERFORM_ATTACK", 0x13);
    GameAnimEventIndex_tTable.SetInteger("AE_FIRE_INPUT", 0x14);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CLOTH_ATTR", 0x15);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CLOTH_GROUND_OFFSET", 0x16);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CLOTH_STIFFEN", 0x17);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CLOTH_EFFECT", 0x18);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_CREATE_ANIM_SCOPE_PROP", 0x19);
    GameAnimEventIndex_tTable.SetInteger("AE_PULSE_GRAPH", 0x1a);
    GameAnimEventIndex_tTable.SetInteger("AE_PULSE_GRAPH_LOOKAT", 0x1b);
    GameAnimEventIndex_tTable.SetInteger("AE_PULSE_GRAPH_AIMAT", 0x1c);
    GameAnimEventIndex_tTable.SetInteger("AE_PULSE_GRAPH_IKLOCKLEFTARM", 0x1d);
    GameAnimEventIndex_tTable.SetInteger("AE_PULSE_GRAPH_IKLOCKRIGHTARM", 0x1e);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_WEAPON_TRANSITION_INTO_HAND", 0x1f);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_BODYGROUP_SET_TO_CLIP", 0x20);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_BODYGROUP_SET_TO_NEXTCLIP", 0x21);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_SHOW_SILENCER", 0x22);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_ATTACH_SILENCER_COMPLETE", 0x23);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_HIDE_SILENCER", 0x24);
    GameAnimEventIndex_tTable.SetInteger("AE_SV_DETACH_SILENCER_COMPLETE", 0x25);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_EJECT_MAG", 0x26);
    GameAnimEventIndex_tTable.SetInteger("AE_WPN_COMPLETE_RELOAD", 0x27);
    GameAnimEventIndex_tTable.SetInteger("AE_WPN_HEALTHSHOT_INJECT", 0x28);
    GameAnimEventIndex_tTable.SetInteger("AE_CL_C4_SCREEN_TEXT", 0x29);
    GameAnimEventIndex_tTable.SetInteger("AE_GRENADE_THROW_COMPLETE", 0x2a);


    auto FixAngleSet_tTable = state->CreateTable("FixAngleSet_t");
    FixAngleSet_tTable.SetInteger("None", 0x0);
    FixAngleSet_tTable.SetInteger("Absolute", 0x1);
    FixAngleSet_tTable.SetInteger("Relative", 0x2);


    auto IChoreoServices__ScriptState_tTable = state->CreateTable("IChoreoServices__ScriptState_t");
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_PLAYING", 0x0);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_WAIT", 0x1);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_POST_IDLE", 0x2);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_CLEANUP", 0x3);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_WALK_TO_MARK", 0x4);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_RUN_TO_MARK", 0x5);
    IChoreoServices__ScriptState_tTable.SetInteger("SCRIPT_CUSTOM_MOVE_TO_MARK", 0x6);


    auto CommandEntitySpecType_tTable = state->CreateTable("CommandEntitySpecType_t");
    CommandEntitySpecType_tTable.SetInteger("SPEC_SEARCH", 0x0);
    CommandEntitySpecType_tTable.SetInteger("SPEC_TYPES_COUNT", 0x1);


    auto Touch_tTable = state->CreateTable("Touch_t");
    Touch_tTable.SetInteger("touch_none", 0x0);
    Touch_tTable.SetInteger("touch_player_only", 0x1);
    Touch_tTable.SetInteger("touch_npc_only", 0x2);
    Touch_tTable.SetInteger("touch_player_or_npc", 0x3);
    Touch_tTable.SetInteger("touch_player_or_npc_or_physicsprop", 0x4);


    auto TrainVelocityType_tTable = state->CreateTable("TrainVelocityType_t");
    TrainVelocityType_tTable.SetInteger("TrainVelocity_Instantaneous", 0x0);
    TrainVelocityType_tTable.SetInteger("TrainVelocity_LinearBlend", 0x1);
    TrainVelocityType_tTable.SetInteger("TrainVelocity_EaseInEaseOut", 0x2);


    auto CSWeaponTypeTable = state->CreateTable("CSWeaponType");
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_KNIFE", 0x0);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_PISTOL", 0x1);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_SUBMACHINEGUN", 0x2);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_RIFLE", 0x3);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_SHOTGUN", 0x4);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_SNIPER_RIFLE", 0x5);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_MACHINEGUN", 0x6);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_C4", 0x7);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_TASER", 0x8);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_GRENADE", 0x9);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_EQUIPMENT", 0xa);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_STACKABLEITEM", 0xb);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_FISTS", 0xc);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_BREACHCHARGE", 0xd);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_BUMPMINE", 0xe);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_TABLET", 0xf);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_MELEE", 0x10);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_SHIELD", 0x11);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_ZONE_REPULSOR", 0x12);
    CSWeaponTypeTable.SetInteger("WEAPONTYPE_UNKNOWN", 0x13);


    auto EntFinderMethod_tTable = state->CreateTable("EntFinderMethod_t");
    EntFinderMethod_tTable.SetInteger("ENT_FIND_METHOD_NEAREST", 0x0);
    EntFinderMethod_tTable.SetInteger("ENT_FIND_METHOD_FARTHEST", 0x1);
    EntFinderMethod_tTable.SetInteger("ENT_FIND_METHOD_RANDOM", 0x2);


    auto PropDoorRotatingSpawnPos_tTable = state->CreateTable("PropDoorRotatingSpawnPos_t");
    PropDoorRotatingSpawnPos_tTable.SetInteger("DOOR_SPAWN_CLOSED", 0x0);
    PropDoorRotatingSpawnPos_tTable.SetInteger("DOOR_SPAWN_OPEN_FORWARD", 0x1);
    PropDoorRotatingSpawnPos_tTable.SetInteger("DOOR_SPAWN_OPEN_BACK", 0x2);
    PropDoorRotatingSpawnPos_tTable.SetInteger("DOOR_SPAWN_AJAR", 0x3);


    auto ShardSolid_tTable = state->CreateTable("ShardSolid_t");
    ShardSolid_tTable.SetInteger("SHARD_SOLID", 0x0);
    ShardSolid_tTable.SetInteger("SHARD_DEBRIS", 0x1);


    auto RenderMode_tTable = state->CreateTable("RenderMode_t");
    RenderMode_tTable.SetInteger("kRenderNormal", 0x0);
    RenderMode_tTable.SetInteger("kRenderTransColor", 0x1);
    RenderMode_tTable.SetInteger("kRenderTransTexture", 0x2);
    RenderMode_tTable.SetInteger("kRenderGlow", 0x3);
    RenderMode_tTable.SetInteger("kRenderTransAlpha", 0x4);
    RenderMode_tTable.SetInteger("kRenderTransAdd", 0x5);
    RenderMode_tTable.SetInteger("kRenderEnvironmental", 0x6);
    RenderMode_tTable.SetInteger("kRenderTransAddFrameBlend", 0x7);
    RenderMode_tTable.SetInteger("kRenderTransAlphaAdd", 0x8);
    RenderMode_tTable.SetInteger("kRenderWorldGlow", 0x9);
    RenderMode_tTable.SetInteger("kRenderNone", 0xa);
    RenderMode_tTable.SetInteger("kRenderDevVisualizer", 0xb);
    RenderMode_tTable.SetInteger("kRenderModeCount", 0xc);


    auto ForcedCrouchState_tTable = state->CreateTable("ForcedCrouchState_t");
    ForcedCrouchState_tTable.SetInteger("FORCEDCROUCH_NONE", 0x0);
    ForcedCrouchState_tTable.SetInteger("FORCEDCROUCH_CROUCHED", 0x1);
    ForcedCrouchState_tTable.SetInteger("FORCEDCROUCH_UNCROUCHED", 0x2);


    auto PerformanceMode_tTable = state->CreateTable("PerformanceMode_t");
    PerformanceMode_tTable.SetInteger("PM_NORMAL", 0x0);
    PerformanceMode_tTable.SetInteger("PM_NO_GIBS", 0x1);
    PerformanceMode_tTable.SetInteger("PM_FULL_GIBS", 0x2);
    PerformanceMode_tTable.SetInteger("PM_REDUCED_GIBS", 0x3);


    auto TOGGLE_STATETable = state->CreateTable("TOGGLE_STATE");
    TOGGLE_STATETable.SetInteger("TS_AT_TOP", 0x0);
    TOGGLE_STATETable.SetInteger("TS_AT_BOTTOM", 0x1);
    TOGGLE_STATETable.SetInteger("TS_GOING_UP", 0x2);
    TOGGLE_STATETable.SetInteger("TS_GOING_DOWN", 0x3);
    TOGGLE_STATETable.SetInteger("DOOR_OPEN", 0x0);
    TOGGLE_STATETable.SetInteger("DOOR_CLOSED", 0x1);
    TOGGLE_STATETable.SetInteger("DOOR_OPENING", 0x2);
    TOGGLE_STATETable.SetInteger("DOOR_CLOSING", 0x3);


    auto loadout_slot_tTable = state->CreateTable("loadout_slot_t");
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_PROMOTED", 0xfffffffffffffffe);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_INVALID", 0xffffffffffffffff);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MELEE", 0x0);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_C4", 0x1);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_AUTO_BUY_WEAPON", 0x0);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_AUTO_BUY_WEAPON", 0x1);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY0", 0x2);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY1", 0x3);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY2", 0x4);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY3", 0x5);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY4", 0x6);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SECONDARY5", 0x7);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG0", 0x8);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG1", 0x9);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG2", 0xa);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG3", 0xb);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG4", 0xc);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SMG5", 0xd);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE0", 0xe);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE1", 0xf);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE2", 0x10);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE3", 0x11);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE4", 0x12);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_RIFLE5", 0x13);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY0", 0x14);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY1", 0x15);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY2", 0x16);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY3", 0x17);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY4", 0x18);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_HEAVY5", 0x19);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_WHEEL_WEAPON", 0x2);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_WHEEL_WEAPON", 0x19);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_PRIMARY_WEAPON", 0x8);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_PRIMARY_WEAPON", 0x19);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_WHEEL_GRENADE", 0x1a);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE0", 0x1a);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE1", 0x1b);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE2", 0x1c);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE3", 0x1d);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE4", 0x1e);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_GRENADE5", 0x1f);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_WHEEL_GRENADE", 0x1f);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT0", 0x20);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT1", 0x21);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT2", 0x22);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT3", 0x23);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT4", 0x24);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_EQUIPMENT5", 0x25);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_WHEEL_EQUIPMENT", 0x20);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_WHEEL_EQUIPMENT", 0x25);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_CUSTOMPLAYER", 0x26);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_PET", 0x27);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_FACEMASK", 0x28);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_HANDS", 0x29);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_COSMETIC", 0x29);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_COSMETIC", 0x29);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_EYEWEAR", 0x2a);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_HAT", 0x2b);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_LOWERBODY", 0x2c);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_TORSO", 0x2d);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_CLOTHING_APPEARANCE", 0x2e);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC0", 0x2f);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC1", 0x30);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC2", 0x31);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC3", 0x32);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC4", 0x33);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC5", 0x34);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MISC6", 0x35);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_MUSICKIT", 0x36);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FLAIR0", 0x37);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_SPRAY0", 0x38);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_FIRST_ALL_CHARACTER", 0x36);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_LAST_ALL_CHARACTER", 0x38);
    loadout_slot_tTable.SetInteger("LOADOUT_SLOT_COUNT", 0x39);


    auto NavAttributeEnumTable = state->CreateTable("NavAttributeEnum");
    NavAttributeEnumTable.SetInteger("NAV_MESH_AVOID", 0x80);
    NavAttributeEnumTable.SetInteger("NAV_MESH_STAIRS", 0x1000);
    NavAttributeEnumTable.SetInteger("NAV_MESH_NON_ZUP", 0x8000);
    NavAttributeEnumTable.SetInteger("NAV_MESH_SHORT_HEIGHT", 0x10000);
    NavAttributeEnumTable.SetInteger("NAV_MESH_CROUCH", 0x10000);
    NavAttributeEnumTable.SetInteger("NAV_MESH_JUMP", 0x2);
    NavAttributeEnumTable.SetInteger("NAV_MESH_PRECISE", 0x4);
    NavAttributeEnumTable.SetInteger("NAV_MESH_NO_JUMP", 0x8);
    NavAttributeEnumTable.SetInteger("NAV_MESH_STOP", 0x10);
    NavAttributeEnumTable.SetInteger("NAV_MESH_RUN", 0x20);
    NavAttributeEnumTable.SetInteger("NAV_MESH_WALK", 0x40);
    NavAttributeEnumTable.SetInteger("NAV_MESH_TRANSIENT", 0x100);
    NavAttributeEnumTable.SetInteger("NAV_MESH_DONT_HIDE", 0x200);
    NavAttributeEnumTable.SetInteger("NAV_MESH_STAND", 0x400);
    NavAttributeEnumTable.SetInteger("NAV_MESH_NO_HOSTAGES", 0x800);
    NavAttributeEnumTable.SetInteger("NAV_MESH_NO_MERGE", 0x2000);
    NavAttributeEnumTable.SetInteger("NAV_MESH_OBSTACLE_TOP", 0x4000);
    NavAttributeEnumTable.SetInteger("NAV_ATTR_FIRST_GAME_INDEX", 0x13);
    NavAttributeEnumTable.SetInteger("NAV_ATTR_LAST_INDEX", 0x1f);


    auto MoveLinearAuthoredPos_tTable = state->CreateTable("MoveLinearAuthoredPos_t");
    MoveLinearAuthoredPos_tTable.SetInteger("MOVELINEAR_AUTHORED_AT_START_POSITION", 0x0);
    MoveLinearAuthoredPos_tTable.SetInteger("MOVELINEAR_AUTHORED_AT_OPEN_POSITION", 0x1);
    MoveLinearAuthoredPos_tTable.SetInteger("MOVELINEAR_AUTHORED_AT_CLOSED_POSITION", 0x2);


    auto ValueRemapperMomentumType_tTable = state->CreateTable("ValueRemapperMomentumType_t");
    ValueRemapperMomentumType_tTable.SetInteger("MomentumType_None", 0x0);
    ValueRemapperMomentumType_tTable.SetInteger("MomentumType_Friction", 0x1);
    ValueRemapperMomentumType_tTable.SetInteger("MomentumType_SpringTowardSnapValue", 0x2);
    ValueRemapperMomentumType_tTable.SetInteger("MomentumType_SpringAwayFromSnapValue", 0x3);


    auto Hull_tTable = state->CreateTable("Hull_t");
    Hull_tTable.SetInteger("HULL_HUMAN", 0x0);
    Hull_tTable.SetInteger("HULL_SMALL_CENTERED", 0x1);
    Hull_tTable.SetInteger("HULL_WIDE_HUMAN", 0x2);
    Hull_tTable.SetInteger("HULL_TINY", 0x3);
    Hull_tTable.SetInteger("HULL_MEDIUM", 0x4);
    Hull_tTable.SetInteger("HULL_TINY_CENTERED", 0x5);
    Hull_tTable.SetInteger("HULL_LARGE", 0x6);
    Hull_tTable.SetInteger("HULL_LARGE_CENTERED", 0x7);
    Hull_tTable.SetInteger("HULL_MEDIUM_TALL", 0x8);
    Hull_tTable.SetInteger("HULL_SMALL", 0x9);
    Hull_tTable.SetInteger("NUM_HULLS", 0xa);
    Hull_tTable.SetInteger("HULL_NONE", 0xb);


    auto PreviewWeaponStateTable = state->CreateTable("PreviewWeaponState");
    PreviewWeaponStateTable.SetInteger("DROPPED", 0x0);
    PreviewWeaponStateTable.SetInteger("HOLSTERED", 0x1);
    PreviewWeaponStateTable.SetInteger("DEPLOYED", 0x2);
    PreviewWeaponStateTable.SetInteger("PLANTED", 0x3);
    PreviewWeaponStateTable.SetInteger("INSPECT", 0x4);
    PreviewWeaponStateTable.SetInteger("ICON", 0x5);


    auto EInButtonStateTable = state->CreateTable("EInButtonState");
    EInButtonStateTable.SetInteger("IN_BUTTON_UP", 0x0);
    EInButtonStateTable.SetInteger("IN_BUTTON_DOWN", 0x1);
    EInButtonStateTable.SetInteger("IN_BUTTON_DOWN_UP", 0x2);
    EInButtonStateTable.SetInteger("IN_BUTTON_UP_DOWN", 0x3);
    EInButtonStateTable.SetInteger("IN_BUTTON_UP_DOWN_UP", 0x4);
    EInButtonStateTable.SetInteger("IN_BUTTON_DOWN_UP_DOWN", 0x5);
    EInButtonStateTable.SetInteger("IN_BUTTON_DOWN_UP_DOWN_UP", 0x6);
    EInButtonStateTable.SetInteger("IN_BUTTON_UP_DOWN_UP_DOWN", 0x7);
    EInButtonStateTable.SetInteger("IN_BUTTON_STATE_COUNT", 0x8);


    auto BeamClipStyle_tTable = state->CreateTable("BeamClipStyle_t");
    BeamClipStyle_tTable.SetInteger("kNOCLIP", 0x0);
    BeamClipStyle_tTable.SetInteger("kGEOCLIP", 0x1);
    BeamClipStyle_tTable.SetInteger("kMODELCLIP", 0x2);
    BeamClipStyle_tTable.SetInteger("kBEAMCLIPSTYLE_NUMBITS", 0x2);


    auto WeaponAttackType_tTable = state->CreateTable("WeaponAttackType_t");
    WeaponAttackType_tTable.SetInteger("eInvalid", 0xffffffffffffffff);
    WeaponAttackType_tTable.SetInteger("ePrimary", 0x0);
    WeaponAttackType_tTable.SetInteger("eSecondary", 0x1);
    WeaponAttackType_tTable.SetInteger("eCount", 0x2);


    auto CSPlayerBlockingUseAction_tTable = state->CreateTable("CSPlayerBlockingUseAction_t");
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_None", 0x0);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_DefusingDefault", 0x1);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_DefusingWithKit", 0x2);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_HostageGrabbing", 0x3);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_HostageDropping", 0x4);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_OpeningSafe", 0x5);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_EquippingParachute", 0x6);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_EquippingHeavyArmor", 0x7);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_EquippingContract", 0x8);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_EquippingTabletUpgrade", 0x9);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_TakingOffHeavyArmor", 0xa);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_PayingToOpenDoor", 0xb);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_CancelingSpawnRappelling", 0xc);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_EquippingExoJump", 0xd);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_PickingUpBumpMine", 0xe);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_MapLongUseEntity_Pickup", 0xf);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_MapLongUseEntity_Place", 0x10);
    CSPlayerBlockingUseAction_tTable.SetInteger("k_CSPlayerBlockingUseAction_MaxCount", 0x11);


    auto CSWeaponState_tTable = state->CreateTable("CSWeaponState_t");
    CSWeaponState_tTable.SetInteger("WEAPON_NOT_CARRIED", 0x0);
    CSWeaponState_tTable.SetInteger("WEAPON_IS_CARRIED_BY_PLAYER", 0x1);
    CSWeaponState_tTable.SetInteger("WEAPON_IS_ACTIVE", 0x2);


    auto CommandExecMode_tTable = state->CreateTable("CommandExecMode_t");
    CommandExecMode_tTable.SetInteger("EXEC_MANUAL", 0x0);
    CommandExecMode_tTable.SetInteger("EXEC_LEVELSTART", 0x1);
    CommandExecMode_tTable.SetInteger("EXEC_PERIODIC", 0x2);
    CommandExecMode_tTable.SetInteger("EXEC_MODES_COUNT", 0x3);


    auto ShatterDamageCauseTable = state->CreateTable("ShatterDamageCause");
    ShatterDamageCauseTable.SetInteger("SHATTERDAMAGE_BULLET", 0x0);
    ShatterDamageCauseTable.SetInteger("SHATTERDAMAGE_MELEE", 0x1);
    ShatterDamageCauseTable.SetInteger("SHATTERDAMAGE_THROWN", 0x2);
    ShatterDamageCauseTable.SetInteger("SHATTERDAMAGE_SCRIPT", 0x3);
    ShatterDamageCauseTable.SetInteger("SHATTERDAMAGE_EXPLOSIVE", 0x4);


    auto ScriptedOnDeath_tTable = state->CreateTable("ScriptedOnDeath_t");
    ScriptedOnDeath_tTable.SetInteger("SS_ONDEATH_NOT_APPLICABLE", 0xffffffffffffffff);
    ScriptedOnDeath_tTable.SetInteger("SS_ONDEATH_UNDEFINED", 0x0);
    ScriptedOnDeath_tTable.SetInteger("SS_ONDEATH_RAGDOLL", 0x1);
    ScriptedOnDeath_tTable.SetInteger("SS_ONDEATH_ANIMATED_DEATH", 0x2);


    auto ScriptedMoveType_tTable = state->CreateTable("ScriptedMoveType_t");
    ScriptedMoveType_tTable.SetInteger("SCRIPTED_MOVETYPE_NONE", 0x0);
    ScriptedMoveType_tTable.SetInteger("SCRIPTED_MOVETYPE_TO_WITH_DURATION", 0x1);
    ScriptedMoveType_tTable.SetInteger("SCRIPTED_MOVETYPE_TO_WITH_MOVESPEED", 0x2);
    ScriptedMoveType_tTable.SetInteger("SCRIPTED_MOVETYPE_SWEEP_TO_AT_MOVEMENT_SPEED", 0x3);


    auto NPCLookType_tTable = state->CreateTable("NPCLookType_t");
    NPCLookType_tTable.SetInteger("Chest", 0x0);
    NPCLookType_tTable.SetInteger("Head", 0x1);
    NPCLookType_tTable.SetInteger("Eyes", 0x2);


    auto gear_slot_tTable = state->CreateTable("gear_slot_t");
    gear_slot_tTable.SetInteger("GEAR_SLOT_INVALID", 0xffffffffffffffff);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RIFLE", 0x0);
    gear_slot_tTable.SetInteger("GEAR_SLOT_PISTOL", 0x1);
    gear_slot_tTable.SetInteger("GEAR_SLOT_KNIFE", 0x2);
    gear_slot_tTable.SetInteger("GEAR_SLOT_GRENADES", 0x3);
    gear_slot_tTable.SetInteger("GEAR_SLOT_C4", 0x4);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT6", 0x5);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT7", 0x6);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT8", 0x7);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT9", 0x8);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT10", 0x9);
    gear_slot_tTable.SetInteger("GEAR_SLOT_RESERVED_SLOT11", 0xa);
    gear_slot_tTable.SetInteger("GEAR_SLOT_BOOSTS", 0xb);
    gear_slot_tTable.SetInteger("GEAR_SLOT_UTILITY", 0xc);
    gear_slot_tTable.SetInteger("GEAR_SLOT_COUNT", 0xd);
    gear_slot_tTable.SetInteger("GEAR_SLOT_FIRST", 0x0);
    gear_slot_tTable.SetInteger("GEAR_SLOT_LAST", 0xc);


    auto CSPlayerStateTable = state->CreateTable("CSPlayerState");
    CSPlayerStateTable.SetInteger("STATE_ACTIVE", 0x0);
    CSPlayerStateTable.SetInteger("STATE_WELCOME", 0x1);
    CSPlayerStateTable.SetInteger("STATE_PICKINGTEAM", 0x2);
    CSPlayerStateTable.SetInteger("STATE_PICKINGCLASS", 0x3);
    CSPlayerStateTable.SetInteger("STATE_DEATH_ANIM", 0x4);
    CSPlayerStateTable.SetInteger("STATE_DEATH_WAIT_FOR_KEY", 0x5);
    CSPlayerStateTable.SetInteger("STATE_OBSERVER_MODE", 0x6);
    CSPlayerStateTable.SetInteger("STATE_GUNGAME_RESPAWN", 0x7);
    CSPlayerStateTable.SetInteger("STATE_DORMANT", 0x8);
    CSPlayerStateTable.SetInteger("NUM_PLAYER_STATES", 0x9);


    auto ScriptedConflictResponse_tTable = state->CreateTable("ScriptedConflictResponse_t");
    ScriptedConflictResponse_tTable.SetInteger("SS_CONFLICT_ENQUEUE", 0x0);
    ScriptedConflictResponse_tTable.SetInteger("SS_CONFLICT_INTERRUPT", 0x1);


    auto WaterLevel_tTable = state->CreateTable("WaterLevel_t");
    WaterLevel_tTable.SetInteger("WL_NotInWater", 0x0);
    WaterLevel_tTable.SetInteger("WL_Feet", 0x1);
    WaterLevel_tTable.SetInteger("WL_Knees", 0x2);
    WaterLevel_tTable.SetInteger("WL_Waist", 0x3);
    WaterLevel_tTable.SetInteger("WL_Chest", 0x4);
    WaterLevel_tTable.SetInteger("WL_FullyUnderwater", 0x5);
    WaterLevel_tTable.SetInteger("WL_Count", 0x6);


    auto WorldTextPanelVerticalAlign_tTable = state->CreateTable("WorldTextPanelVerticalAlign_t");
    WorldTextPanelVerticalAlign_tTable.SetInteger("WORLDTEXT_VERTICAL_ALIGN_TOP", 0x0);
    WorldTextPanelVerticalAlign_tTable.SetInteger("WORLDTEXT_VERTICAL_ALIGN_CENTER", 0x1);
    WorldTextPanelVerticalAlign_tTable.SetInteger("WORLDTEXT_VERTICAL_ALIGN_BOTTOM", 0x2);


    auto AmmoPosition_tTable = state->CreateTable("AmmoPosition_t");
    AmmoPosition_tTable.SetInteger("AMMO_POSITION_INVALID", 0xffffffffffffffff);
    AmmoPosition_tTable.SetInteger("AMMO_POSITION_PRIMARY", 0x0);
    AmmoPosition_tTable.SetInteger("AMMO_POSITION_SECONDARY", 0x1);
    AmmoPosition_tTable.SetInteger("AMMO_POSITION_COUNT", 0x2);


    auto PreviewEOMCelebrationTable = state->CreateTable("PreviewEOMCelebration");
    PreviewEOMCelebrationTable.SetInteger("WALKUP", 0x0);
    PreviewEOMCelebrationTable.SetInteger("PUNCHING", 0x1);
    PreviewEOMCelebrationTable.SetInteger("SWAGGER", 0x2);
    PreviewEOMCelebrationTable.SetInteger("DROPDOWN", 0x3);
    PreviewEOMCelebrationTable.SetInteger("STRETCH", 0x4);
    PreviewEOMCelebrationTable.SetInteger("SWAT_FEMALE", 0x5);
    PreviewEOMCelebrationTable.SetInteger("MASK_F", 0x6);
    PreviewEOMCelebrationTable.SetInteger("GUERILLA", 0x7);
    PreviewEOMCelebrationTable.SetInteger("GUERILLA02", 0x8);
    PreviewEOMCelebrationTable.SetInteger("GENDARMERIE", 0x9);
    PreviewEOMCelebrationTable.SetInteger("SCUBA_FEMALE", 0xa);
    PreviewEOMCelebrationTable.SetInteger("SCUBA_MALE", 0xb);
    PreviewEOMCelebrationTable.SetInteger("AVA_DEFEAT", 0xc);
    PreviewEOMCelebrationTable.SetInteger("GENDARMERIE_DEFEAT", 0xd);
    PreviewEOMCelebrationTable.SetInteger("MAE_DEFEAT", 0xe);
    PreviewEOMCelebrationTable.SetInteger("RICKSAW_DEFEAT", 0xf);
    PreviewEOMCelebrationTable.SetInteger("SCUBA_FEMALE_DEFEAT", 0x10);
    PreviewEOMCelebrationTable.SetInteger("SCUBA_MALE_DEFEAT", 0x11);
    PreviewEOMCelebrationTable.SetInteger("CRASSWATER_DEFEAT", 0x12);
    PreviewEOMCelebrationTable.SetInteger("DARRYL_DEFEAT", 0x13);
    PreviewEOMCelebrationTable.SetInteger("DOCTOR_DEFEAT", 0x14);
    PreviewEOMCelebrationTable.SetInteger("MUHLIK_DEFEAT", 0x15);
    PreviewEOMCelebrationTable.SetInteger("VYPA_DEFEAT", 0x16);


    auto EntityDisolveType_tTable = state->CreateTable("EntityDisolveType_t");
    EntityDisolveType_tTable.SetInteger("ENTITY_DISSOLVE_INVALID", 0xffffffffffffffff);
    EntityDisolveType_tTable.SetInteger("ENTITY_DISSOLVE_NORMAL", 0x0);
    EntityDisolveType_tTable.SetInteger("ENTITY_DISSOLVE_ELECTRICAL", 0x1);
    EntityDisolveType_tTable.SetInteger("ENTITY_DISSOLVE_ELECTRICAL_LIGHT", 0x2);
    EntityDisolveType_tTable.SetInteger("ENTITY_DISSOLVE_CORE", 0x3);


    auto InputBitMask_tTable = state->CreateTable("InputBitMask_t");
    InputBitMask_tTable.SetInteger("IN_NONE", 0x0);
    InputBitMask_tTable.SetInteger("IN_ALL", 0xffffffffffffffff);
    InputBitMask_tTable.SetInteger("IN_ATTACK", 0x1);
    InputBitMask_tTable.SetInteger("IN_JUMP", 0x2);
    InputBitMask_tTable.SetInteger("IN_DUCK", 0x4);
    InputBitMask_tTable.SetInteger("IN_FORWARD", 0x8);
    InputBitMask_tTable.SetInteger("IN_BACK", 0x10);
    InputBitMask_tTable.SetInteger("IN_USE", 0x20);
    InputBitMask_tTable.SetInteger("IN_TURNLEFT", 0x80);
    InputBitMask_tTable.SetInteger("IN_TURNRIGHT", 0x100);
    InputBitMask_tTable.SetInteger("IN_MOVELEFT", 0x200);
    InputBitMask_tTable.SetInteger("IN_MOVERIGHT", 0x400);
    InputBitMask_tTable.SetInteger("IN_ATTACK2", 0x800);
    InputBitMask_tTable.SetInteger("IN_RELOAD", 0x2000);
    InputBitMask_tTable.SetInteger("IN_SPEED", 0x10000);
    InputBitMask_tTable.SetInteger("IN_JOYAUTOSPRINT", 0x20000);
    InputBitMask_tTable.SetInteger("IN_FIRST_MOD_SPECIFIC_BIT", 0x100000000);
    InputBitMask_tTable.SetInteger("IN_USEORRELOAD", 0x100000000);
    InputBitMask_tTable.SetInteger("IN_SCORE", 0x200000000);
    InputBitMask_tTable.SetInteger("IN_ZOOM", 0x400000000);
    InputBitMask_tTable.SetInteger("IN_LOOK_AT_WEAPON", 0x800000000);


    auto HitGroup_tTable = state->CreateTable("HitGroup_t");
    HitGroup_tTable.SetInteger("HITGROUP_INVALID", 0xffffffffffffffff);
    HitGroup_tTable.SetInteger("HITGROUP_GENERIC", 0x0);
    HitGroup_tTable.SetInteger("HITGROUP_HEAD", 0x1);
    HitGroup_tTable.SetInteger("HITGROUP_CHEST", 0x2);
    HitGroup_tTable.SetInteger("HITGROUP_STOMACH", 0x3);
    HitGroup_tTable.SetInteger("HITGROUP_LEFTARM", 0x4);
    HitGroup_tTable.SetInteger("HITGROUP_RIGHTARM", 0x5);
    HitGroup_tTable.SetInteger("HITGROUP_LEFTLEG", 0x6);
    HitGroup_tTable.SetInteger("HITGROUP_RIGHTLEG", 0x7);
    HitGroup_tTable.SetInteger("HITGROUP_NECK", 0x8);
    HitGroup_tTable.SetInteger("HITGROUP_UNUSED", 0x9);
    HitGroup_tTable.SetInteger("HITGROUP_GEAR", 0xa);
    HitGroup_tTable.SetInteger("HITGROUP_SPECIAL", 0xb);
    HitGroup_tTable.SetInteger("HITGROUP_COUNT", 0xc);


    auto ChickenActivityTable = state->CreateTable("ChickenActivity");
    ChickenActivityTable.SetInteger("IDLE", 0x0);
    ChickenActivityTable.SetInteger("WALK", 0x1);
    ChickenActivityTable.SetInteger("RUN", 0x2);
    ChickenActivityTable.SetInteger("HOP", 0x3);
    ChickenActivityTable.SetInteger("JUMP", 0x4);
    ChickenActivityTable.SetInteger("GLIDE", 0x5);
    ChickenActivityTable.SetInteger("LAND", 0x6);


    auto PointWorldTextReorientMode_tTable = state->CreateTable("PointWorldTextReorientMode_t");
    PointWorldTextReorientMode_tTable.SetInteger("POINT_WORLD_TEXT_REORIENT_NONE", 0x0);
    PointWorldTextReorientMode_tTable.SetInteger("POINT_WORLD_TEXT_REORIENT_AROUND_UP", 0x1);


    auto DebugOverlayBits_tTable = state->CreateTable("DebugOverlayBits_t");
    DebugOverlayBits_tTable.SetInteger("OVERLAY_TEXT_BIT", 0x1);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NAME_BIT", 0x2);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_BBOX_BIT", 0x4);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_PIVOT_BIT", 0x8);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_MESSAGE_BIT", 0x10);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_ABSBOX_BIT", 0x20);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_RBOX_BIT", 0x40);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_SHOW_BLOCKSLOS", 0x80);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_ATTACHMENTS_BIT", 0x100);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_INTERPOLATED_ATTACHMENTS_BIT", 0x200);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_INTERPOLATED_PIVOT_BIT", 0x400);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_SKELETON_BIT", 0x800);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_INTERPOLATED_SKELETON_BIT", 0x1000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_TRIGGER_BOUNDS_BIT", 0x2000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_HITBOX_BIT", 0x4000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_INTERPOLATED_HITBOX_BIT", 0x8000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_AUTOAIM_BIT", 0x10000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_SELECTED_BIT", 0x20000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_JOINT_INFO_BIT", 0x40000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_ROUTE_BIT", 0x80000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_VISIBILITY_TRACES_BIT", 0x100000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_ENEMIES_BIT", 0x400000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_CONDITIONS_BIT", 0x800000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_COMBAT_BIT", 0x1000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_TASK_BIT", 0x2000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_BODYLOCATIONS", 0x4000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_VIEWCONE_BIT", 0x8000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_KILL_BIT", 0x10000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_WC_CHANGE_ENTITY", 0x20000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_BUDDHA_MODE", 0x40000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_STEERING_REGULATIONS", 0x80000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_TASK_TEXT_BIT", 0x100000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_PROP_DEBUG", 0x200000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_RELATION_BIT", 0x400000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_VIEWOFFSET", 0x800000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_VCOLLIDE_WIREFRAME_BIT", 0x1000000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_ACTORNAME_BIT", 0x4000000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_CONDITIONS_TEXT_BIT", 0x8000000000);
    DebugOverlayBits_tTable.SetInteger("OVERLAY_NPC_ABILITY_RANGE_DEBUG_BIT", 0x10000000000);


    auto AmmoFlags_tTable = state->CreateTable("AmmoFlags_t");
    AmmoFlags_tTable.SetInteger("AMMO_FORCE_DROP_IF_CARRIED", 0x1);
    AmmoFlags_tTable.SetInteger("AMMO_RESERVE_STAYS_WITH_WEAPON", 0x2);
    AmmoFlags_tTable.SetInteger("AMMO_FLAG_MAX", 0x2);


    auto HierarchyType_tTable = state->CreateTable("HierarchyType_t");
    HierarchyType_tTable.SetInteger("HIERARCHY_NONE", 0x0);
    HierarchyType_tTable.SetInteger("HIERARCHY_BONE_MERGE", 0x1);
    HierarchyType_tTable.SetInteger("HIERARCHY_ATTACHMENT", 0x2);
    HierarchyType_tTable.SetInteger("HIERARCHY_ABSORIGIN", 0x3);
    HierarchyType_tTable.SetInteger("HIERARCHY_BONE", 0x4);
    HierarchyType_tTable.SetInteger("HIERARCHY_TYPE_COUNT", 0x5);


    auto doorCheck_eTable = state->CreateTable("doorCheck_e");
    doorCheck_eTable.SetInteger("DOOR_CHECK_FORWARD", 0x0);
    doorCheck_eTable.SetInteger("DOOR_CHECK_BACKWARD", 0x1);
    doorCheck_eTable.SetInteger("DOOR_CHECK_FULL", 0x2);


    auto BeamType_tTable = state->CreateTable("BeamType_t");
    BeamType_tTable.SetInteger("BEAM_INVALID", 0x0);
    BeamType_tTable.SetInteger("BEAM_POINTS", 0x1);
    BeamType_tTable.SetInteger("BEAM_ENTPOINT", 0x2);
    BeamType_tTable.SetInteger("BEAM_ENTS", 0x3);
    BeamType_tTable.SetInteger("BEAM_HOSE", 0x4);
    BeamType_tTable.SetInteger("BEAM_SPLINE", 0x5);
    BeamType_tTable.SetInteger("BEAM_LASER", 0x6);


    auto EntitySubclassScope_tTable = state->CreateTable("EntitySubclassScope_t");
    EntitySubclassScope_tTable.SetInteger("SUBCLASS_SCOPE_NONE", 0xffffffffffffffff);
    EntitySubclassScope_tTable.SetInteger("SUBCLASS_SCOPE_PRECIPITATION", 0x0);
    EntitySubclassScope_tTable.SetInteger("SUBCLASS_SCOPE_PLAYER_WEAPONS", 0x1);
    EntitySubclassScope_tTable.SetInteger("SUBCLASS_SCOPE_COUNT", 0x2);


    auto PointTemplateClientOnlyEntityBehavior_tTable = state->CreateTable("PointTemplateClientOnlyEntityBehavior_t");
    PointTemplateClientOnlyEntityBehavior_tTable.SetInteger("CREATE_FOR_CURRENTLY_CONNECTED_CLIENTS_ONLY", 0x0);
    PointTemplateClientOnlyEntityBehavior_tTable.SetInteger("CREATE_FOR_CLIENTS_WHO_CONNECT_LATER", 0x1);


    auto ShatterGlassStressTypeTable = state->CreateTable("ShatterGlassStressType");
    ShatterGlassStressTypeTable.SetInteger("SHATTERGLASS_BLUNT", 0x0);
    ShatterGlassStressTypeTable.SetInteger("SHATTERGLASS_BALLISTIC", 0x1);
    ShatterGlassStressTypeTable.SetInteger("SHATTERGLASS_PULSE", 0x2);
    ShatterGlassStressTypeTable.SetInteger("SHATTERDRYWALL_CHUNKS", 0x3);
    ShatterGlassStressTypeTable.SetInteger("SHATTERGLASS_EXPLOSIVE", 0x4);


    auto TrackOrientationType_tTable = state->CreateTable("TrackOrientationType_t");
    TrackOrientationType_tTable.SetInteger("TrackOrientation_Fixed", 0x0);
    TrackOrientationType_tTable.SetInteger("TrackOrientation_FacePath", 0x1);
    TrackOrientationType_tTable.SetInteger("TrackOrientation_FacePathAngles", 0x2);


    auto WeaponSwitchReason_tTable = state->CreateTable("WeaponSwitchReason_t");
    WeaponSwitchReason_tTable.SetInteger("eDrawn", 0x0);
    WeaponSwitchReason_tTable.SetInteger("eEquipped", 0x1);
    WeaponSwitchReason_tTable.SetInteger("eUserInitiatedSwitchToLast", 0x2);
    WeaponSwitchReason_tTable.SetInteger("eUserInitiatedSwitchHands", 0x3);


    auto ValueRemapperRatchetType_tTable = state->CreateTable("ValueRemapperRatchetType_t");
    ValueRemapperRatchetType_tTable.SetInteger("RatchetType_Absolute", 0x0);
    ValueRemapperRatchetType_tTable.SetInteger("RatchetType_EachEngage", 0x1);


    auto NavDirTypeTable = state->CreateTable("NavDirType");
    NavDirTypeTable.SetInteger("NORTH", 0x0);
    NavDirTypeTable.SetInteger("EAST", 0x1);
    NavDirTypeTable.SetInteger("SOUTH", 0x2);
    NavDirTypeTable.SetInteger("WEST", 0x3);
    NavDirTypeTable.SetInteger("NUM_NAV_DIR_TYPE_DIRECTIONS", 0x4);


    auto CRR_Response__ResponseEnum_tTable = state->CreateTable("CRR_Response__ResponseEnum_t");
    CRR_Response__ResponseEnum_tTable.SetInteger("MAX_RESPONSE_NAME", 0xc0);
    CRR_Response__ResponseEnum_tTable.SetInteger("MAX_RULE_NAME", 0x80);


    auto MoveMountingAmount_tTable = state->CreateTable("MoveMountingAmount_t");
    MoveMountingAmount_tTable.SetInteger("MOVE_MOUNT_NONE", 0x0);
    MoveMountingAmount_tTable.SetInteger("MOVE_MOUNT_LOW", 0x1);
    MoveMountingAmount_tTable.SetInteger("MOVE_MOUNT_HIGH", 0x2);
    MoveMountingAmount_tTable.SetInteger("MOVE_MOUNT_MAXCOUNT", 0x3);


    auto RenderFx_tTable = state->CreateTable("RenderFx_t");
    RenderFx_tTable.SetInteger("kRenderFxNone", 0x0);
    RenderFx_tTable.SetInteger("kRenderFxPulseSlow", 0x1);
    RenderFx_tTable.SetInteger("kRenderFxPulseFast", 0x2);
    RenderFx_tTable.SetInteger("kRenderFxPulseSlowWide", 0x3);
    RenderFx_tTable.SetInteger("kRenderFxPulseFastWide", 0x4);
    RenderFx_tTable.SetInteger("kRenderFxFadeSlow", 0x5);
    RenderFx_tTable.SetInteger("kRenderFxFadeFast", 0x6);
    RenderFx_tTable.SetInteger("kRenderFxSolidSlow", 0x7);
    RenderFx_tTable.SetInteger("kRenderFxSolidFast", 0x8);
    RenderFx_tTable.SetInteger("kRenderFxStrobeSlow", 0x9);
    RenderFx_tTable.SetInteger("kRenderFxStrobeFast", 0xa);
    RenderFx_tTable.SetInteger("kRenderFxStrobeFaster", 0xb);
    RenderFx_tTable.SetInteger("kRenderFxFlickerSlow", 0xc);
    RenderFx_tTable.SetInteger("kRenderFxFlickerFast", 0xd);
    RenderFx_tTable.SetInteger("kRenderFxNoDissipation", 0xe);
    RenderFx_tTable.SetInteger("kRenderFxFadeOut", 0xf);
    RenderFx_tTable.SetInteger("kRenderFxFadeIn", 0x10);
    RenderFx_tTable.SetInteger("kRenderFxPulseFastWider", 0x11);
    RenderFx_tTable.SetInteger("kRenderFxGlowShell", 0x12);
    RenderFx_tTable.SetInteger("kRenderFxMax", 0x13);


    auto vote_create_failed_tTable = state->CreateTable("vote_create_failed_t");
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_GENERIC", 0x0);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TRANSITIONING_PLAYERS", 0x1);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_RATE_EXCEEDED", 0x2);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_YES_MUST_EXCEED_NO", 0x3);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_QUORUM_FAILURE", 0x4);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_ISSUE_DISABLED", 0x5);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_MAP_NOT_FOUND", 0x6);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_MAP_NAME_REQUIRED", 0x7);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENTLY", 0x8);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TEAM_CANT_CALL", 0x9);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_WAITINGFORPLAYERS", 0xa);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_PLAYERNOTFOUND", 0xb);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_CANNOT_KICK_ADMIN", 0xc);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_SCRAMBLE_IN_PROGRESS", 0xd);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_SPECTATOR", 0xe);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENT_KICK", 0xf);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENT_CHANGEMAP", 0x10);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENT_SWAPTEAMS", 0x11);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENT_SCRAMBLETEAMS", 0x12);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_FAILED_RECENT_RESTART", 0x13);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_SWAP_IN_PROGRESS", 0x14);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_DISABLED", 0x15);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_NEXTLEVEL_SET", 0x16);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TOO_EARLY_SURRENDER", 0x17);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_MATCH_PAUSED", 0x18);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_MATCH_NOT_PAUSED", 0x19);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_NOT_IN_WARMUP", 0x1a);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_NOT_10_PLAYERS", 0x1b);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TIMEOUT_ACTIVE", 0x1c);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TIMEOUT_INACTIVE", 0x1d);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_TIMEOUT_EXHAUSTED", 0x1e);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_CANT_ROUND_END", 0x1f);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_REMATCH", 0x20);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_CONTINUE", 0x21);
    vote_create_failed_tTable.SetInteger("VOTE_FAILED_MAX", 0x22);


    auto RumbleEffect_tTable = state->CreateTable("RumbleEffect_t");
    RumbleEffect_tTable.SetInteger("RUMBLE_INVALID", 0xffffffffffffffff);
    RumbleEffect_tTable.SetInteger("RUMBLE_STOP_ALL", 0x0);
    RumbleEffect_tTable.SetInteger("RUMBLE_PISTOL", 0x1);
    RumbleEffect_tTable.SetInteger("RUMBLE_357", 0x2);
    RumbleEffect_tTable.SetInteger("RUMBLE_SMG1", 0x3);
    RumbleEffect_tTable.SetInteger("RUMBLE_AR2", 0x4);
    RumbleEffect_tTable.SetInteger("RUMBLE_SHOTGUN_SINGLE", 0x5);
    RumbleEffect_tTable.SetInteger("RUMBLE_SHOTGUN_DOUBLE", 0x6);
    RumbleEffect_tTable.SetInteger("RUMBLE_AR2_ALT_FIRE", 0x7);
    RumbleEffect_tTable.SetInteger("RUMBLE_RPG_MISSILE", 0x8);
    RumbleEffect_tTable.SetInteger("RUMBLE_CROWBAR_SWING", 0x9);
    RumbleEffect_tTable.SetInteger("RUMBLE_AIRBOAT_GUN", 0xa);
    RumbleEffect_tTable.SetInteger("RUMBLE_JEEP_ENGINE_LOOP", 0xb);
    RumbleEffect_tTable.SetInteger("RUMBLE_FLAT_LEFT", 0xc);
    RumbleEffect_tTable.SetInteger("RUMBLE_FLAT_RIGHT", 0xd);
    RumbleEffect_tTable.SetInteger("RUMBLE_FLAT_BOTH", 0xe);
    RumbleEffect_tTable.SetInteger("RUMBLE_DMG_LOW", 0xf);
    RumbleEffect_tTable.SetInteger("RUMBLE_DMG_MED", 0x10);
    RumbleEffect_tTable.SetInteger("RUMBLE_DMG_HIGH", 0x11);
    RumbleEffect_tTable.SetInteger("RUMBLE_FALL_LONG", 0x12);
    RumbleEffect_tTable.SetInteger("RUMBLE_FALL_SHORT", 0x13);
    RumbleEffect_tTable.SetInteger("RUMBLE_PHYSCANNON_OPEN", 0x14);
    RumbleEffect_tTable.SetInteger("RUMBLE_PHYSCANNON_PUNT", 0x15);
    RumbleEffect_tTable.SetInteger("RUMBLE_PHYSCANNON_LOW", 0x16);
    RumbleEffect_tTable.SetInteger("RUMBLE_PHYSCANNON_MEDIUM", 0x17);
    RumbleEffect_tTable.SetInteger("RUMBLE_PHYSCANNON_HIGH", 0x18);
    RumbleEffect_tTable.SetInteger("NUM_RUMBLE_EFFECTS", 0x19);


    auto LatchDirtyPermission_tTable = state->CreateTable("LatchDirtyPermission_t");
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_DISALLOW", 0x0);
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_SERVER_CONTROLLED", 0x1);
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_CLIENT_SIMULATED", 0x2);
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_PREDICTION", 0x3);
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_FRAMESIMULATE", 0x4);
    LatchDirtyPermission_tTable.SetInteger("LATCH_DIRTY_PARTICLE_SIMULATE", 0x5);


    auto DoorState_tTable = state->CreateTable("DoorState_t");
    DoorState_tTable.SetInteger("DOOR_STATE_CLOSED", 0x0);
    DoorState_tTable.SetInteger("DOOR_STATE_OPENING", 0x1);
    DoorState_tTable.SetInteger("DOOR_STATE_OPEN", 0x2);
    DoorState_tTable.SetInteger("DOOR_STATE_CLOSING", 0x3);
    DoorState_tTable.SetInteger("DOOR_STATE_AJAR", 0x4);


    auto ChatIgnoreType_tTable = state->CreateTable("ChatIgnoreType_t");
    ChatIgnoreType_tTable.SetInteger("CHAT_IGNORE_NONE", 0x0);
    ChatIgnoreType_tTable.SetInteger("CHAT_IGNORE_ALL", 0x1);
    ChatIgnoreType_tTable.SetInteger("CHAT_IGNORE_TEAM", 0x2);


    auto PlayerConnectedStateTable = state->CreateTable("PlayerConnectedState");
    PlayerConnectedStateTable.SetInteger("PlayerNeverConnected", 0xffffffffffffffff);
    PlayerConnectedStateTable.SetInteger("PlayerConnected", 0x0);
    PlayerConnectedStateTable.SetInteger("PlayerConnecting", 0x1);
    PlayerConnectedStateTable.SetInteger("PlayerReconnecting", 0x2);
    PlayerConnectedStateTable.SetInteger("PlayerDisconnecting", 0x3);
    PlayerConnectedStateTable.SetInteger("PlayerDisconnected", 0x4);
    PlayerConnectedStateTable.SetInteger("PlayerReserved", 0x5);


    auto SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_tTable = state->CreateTable("SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_t");
    SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_tTable.SetInteger("kMIN_THRESHOLD", 0x0);
    SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_tTable.SetInteger("kMIN_FULL", 0x1);
    SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_tTable.SetInteger("kHIGHWATER", 0x2);


    auto navproperties_tTable = state->CreateTable("navproperties_t");
    navproperties_tTable.SetInteger("NAV_IGNORE", 0x1);


    auto SolidType_tTable = state->CreateTable("SolidType_t");
    SolidType_tTable.SetInteger("SOLID_NONE", 0x0);
    SolidType_tTable.SetInteger("SOLID_BSP", 0x1);
    SolidType_tTable.SetInteger("SOLID_BBOX", 0x2);
    SolidType_tTable.SetInteger("SOLID_OBB", 0x3);
    SolidType_tTable.SetInteger("SOLID_SPHERE", 0x4);
    SolidType_tTable.SetInteger("SOLID_POINT", 0x5);
    SolidType_tTable.SetInteger("SOLID_VPHYSICS", 0x6);
    SolidType_tTable.SetInteger("SOLID_CAPSULE", 0x7);
    SolidType_tTable.SetInteger("SOLID_LAST", 0x8);


    auto DamageTypes_tTable = state->CreateTable("DamageTypes_t");
    DamageTypes_tTable.SetInteger("DMG_GENERIC", 0x0);
    DamageTypes_tTable.SetInteger("DMG_CRUSH", 0x1);
    DamageTypes_tTable.SetInteger("DMG_BULLET", 0x2);
    DamageTypes_tTable.SetInteger("DMG_SLASH", 0x4);
    DamageTypes_tTable.SetInteger("DMG_BURN", 0x8);
    DamageTypes_tTable.SetInteger("DMG_VEHICLE", 0x10);
    DamageTypes_tTable.SetInteger("DMG_FALL", 0x20);
    DamageTypes_tTable.SetInteger("DMG_BLAST", 0x40);
    DamageTypes_tTable.SetInteger("DMG_CLUB", 0x80);
    DamageTypes_tTable.SetInteger("DMG_SHOCK", 0x100);
    DamageTypes_tTable.SetInteger("DMG_SONIC", 0x200);
    DamageTypes_tTable.SetInteger("DMG_ENERGYBEAM", 0x400);
    DamageTypes_tTable.SetInteger("DMG_DROWN", 0x4000);
    DamageTypes_tTable.SetInteger("DMG_POISON", 0x8000);
    DamageTypes_tTable.SetInteger("DMG_RADIATION", 0x10000);
    DamageTypes_tTable.SetInteger("DMG_DROWNRECOVER", 0x20000);
    DamageTypes_tTable.SetInteger("DMG_ACID", 0x40000);
    DamageTypes_tTable.SetInteger("DMG_PHYSGUN", 0x100000);
    DamageTypes_tTable.SetInteger("DMG_DISSOLVE", 0x200000);
    DamageTypes_tTable.SetInteger("DMG_BLAST_SURFACE", 0x400000);
    DamageTypes_tTable.SetInteger("DMG_BUCKSHOT", 0x1000000);
    DamageTypes_tTable.SetInteger("DMG_LASTGENERICFLAG", 0x1000000);
    DamageTypes_tTable.SetInteger("DMG_HEADSHOT", 0x2000000);
    DamageTypes_tTable.SetInteger("DMG_DANGERZONE", 0x4000000);


    auto PointWorldTextJustifyVertical_tTable = state->CreateTable("PointWorldTextJustifyVertical_t");
    PointWorldTextJustifyVertical_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_VERTICAL_BOTTOM", 0x0);
    PointWorldTextJustifyVertical_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_VERTICAL_CENTER", 0x1);
    PointWorldTextJustifyVertical_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_VERTICAL_TOP", 0x2);


    auto attributeprovidertypes_tTable = state->CreateTable("attributeprovidertypes_t");
    attributeprovidertypes_tTable.SetInteger("PROVIDER_GENERIC", 0x0);
    attributeprovidertypes_tTable.SetInteger("PROVIDER_WEAPON", 0x1);


    auto MoveCollide_tTable = state->CreateTable("MoveCollide_t");
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_DEFAULT", 0x0);
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_FLY_BOUNCE", 0x1);
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_FLY_CUSTOM", 0x2);
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_FLY_SLIDE", 0x3);
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_COUNT", 0x4);
    MoveCollide_tTable.SetInteger("MOVECOLLIDE_MAX_BITS", 0x3);


    auto IChoreoServices__ChoreoState_tTable = state->CreateTable("IChoreoServices__ChoreoState_t");
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_PRE_SCRIPT", 0x0);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_WAIT_FOR_SCRIPT", 0x1);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_WALK_TO_MARK", 0x2);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_SYNCHRONIZE_SCRIPT", 0x3);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_PLAY_SCRIPT", 0x4);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_PLAY_SCRIPT_POST_IDLE", 0x5);
    IChoreoServices__ChoreoState_tTable.SetInteger("STATE_PLAY_SCRIPT_POST_IDLE_DONE", 0x6);


    auto ValueRemapperOutputType_tTable = state->CreateTable("ValueRemapperOutputType_t");
    ValueRemapperOutputType_tTable.SetInteger("OutputType_AnimationCycle", 0x0);
    ValueRemapperOutputType_tTable.SetInteger("OutputType_RotationX", 0x1);
    ValueRemapperOutputType_tTable.SetInteger("OutputType_RotationY", 0x2);
    ValueRemapperOutputType_tTable.SetInteger("OutputType_RotationZ", 0x3);


    auto PointTemplateOwnerSpawnGroupType_tTable = state->CreateTable("PointTemplateOwnerSpawnGroupType_t");
    PointTemplateOwnerSpawnGroupType_tTable.SetInteger("INSERT_INTO_POINT_TEMPLATE_SPAWN_GROUP", 0x0);
    PointTemplateOwnerSpawnGroupType_tTable.SetInteger("INSERT_INTO_CURRENTLY_ACTIVE_SPAWN_GROUP", 0x1);
    PointTemplateOwnerSpawnGroupType_tTable.SetInteger("INSERT_INTO_NEWLY_CREATED_SPAWN_GROUP", 0x2);


    auto PointWorldTextJustifyHorizontal_tTable = state->CreateTable("PointWorldTextJustifyHorizontal_t");
    PointWorldTextJustifyHorizontal_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_LEFT", 0x0);
    PointWorldTextJustifyHorizontal_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_CENTER", 0x1);
    PointWorldTextJustifyHorizontal_tTable.SetInteger("POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_RIGHT", 0x2);


    auto ShakeCommand_tTable = state->CreateTable("ShakeCommand_t");
    ShakeCommand_tTable.SetInteger("SHAKE_START", 0x0);
    ShakeCommand_tTable.SetInteger("SHAKE_STOP", 0x1);
    ShakeCommand_tTable.SetInteger("SHAKE_AMPLITUDE", 0x2);
    ShakeCommand_tTable.SetInteger("SHAKE_FREQUENCY", 0x3);
    ShakeCommand_tTable.SetInteger("SHAKE_START_RUMBLEONLY", 0x4);
    ShakeCommand_tTable.SetInteger("SHAKE_START_NORUMBLE", 0x5);


    auto TRAIN_CODETable = state->CreateTable("TRAIN_CODE");
    TRAIN_CODETable.SetInteger("TRAIN_SAFE", 0x0);
    TRAIN_CODETable.SetInteger("TRAIN_BLOCKING", 0x1);
    TRAIN_CODETable.SetInteger("TRAIN_FOLLOWING", 0x2);


    auto BrushSolidities_eTable = state->CreateTable("BrushSolidities_e");
    BrushSolidities_eTable.SetInteger("BRUSHSOLID_TOGGLE", 0x0);
    BrushSolidities_eTable.SetInteger("BRUSHSOLID_NEVER", 0x1);
    BrushSolidities_eTable.SetInteger("BRUSHSOLID_ALWAYS", 0x2);


    auto QuestProgress__ReasonTable = state->CreateTable("QuestProgress__Reason");
    QuestProgress__ReasonTable.SetInteger("QUEST_NONINITIALIZED", 0x0);
    QuestProgress__ReasonTable.SetInteger("QUEST_OK", 0x1);
    QuestProgress__ReasonTable.SetInteger("QUEST_NOT_ENOUGH_PLAYERS", 0x2);
    QuestProgress__ReasonTable.SetInteger("QUEST_WARMUP", 0x3);
    QuestProgress__ReasonTable.SetInteger("QUEST_NOT_CONNECTED_TO_STEAM", 0x4);
    QuestProgress__ReasonTable.SetInteger("QUEST_NONOFFICIAL_SERVER", 0x5);
    QuestProgress__ReasonTable.SetInteger("QUEST_NO_ENTITLEMENT", 0x6);
    QuestProgress__ReasonTable.SetInteger("QUEST_NO_QUEST", 0x7);
    QuestProgress__ReasonTable.SetInteger("QUEST_PLAYER_IS_BOT", 0x8);
    QuestProgress__ReasonTable.SetInteger("QUEST_WRONG_MAP", 0x9);
    QuestProgress__ReasonTable.SetInteger("QUEST_WRONG_MODE", 0xa);
    QuestProgress__ReasonTable.SetInteger("QUEST_NOT_SYNCED_WITH_SERVER", 0xb);
    QuestProgress__ReasonTable.SetInteger("QUEST_REASON_MAX", 0xc);


    auto ModifyDamageReturn_tTable = state->CreateTable("ModifyDamageReturn_t");
    ModifyDamageReturn_tTable.SetInteger("CONTINUE_TO_APPLY_DAMAGE", 0x0);
    ModifyDamageReturn_tTable.SetInteger("ABORT_DO_NOT_APPLY_DAMAGE", 0x1);


    auto ShadowType_tTable = state->CreateTable("ShadowType_t");
    ShadowType_tTable.SetInteger("SHADOWS_NONE", 0x0);
    ShadowType_tTable.SetInteger("SHADOWS_SIMPLE", 0x1);


    auto GrenadeType_tTable = state->CreateTable("GrenadeType_t");
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_EXPLOSIVE", 0x0);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_FLASH", 0x1);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_FIRE", 0x2);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_DECOY", 0x3);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_SMOKE", 0x4);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_SENSOR", 0x5);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_SNOWBALL", 0x6);
    GrenadeType_tTable.SetInteger("GRENADE_TYPE_TOTAL", 0x7);


    auto ValueRemapperInputType_tTable = state->CreateTable("ValueRemapperInputType_t");
    ValueRemapperInputType_tTable.SetInteger("InputType_PlayerShootPosition", 0x0);
    ValueRemapperInputType_tTable.SetInteger("InputType_PlayerShootPositionAroundAxis", 0x1);


    auto EKillTypes_tTable = state->CreateTable("EKillTypes_t");
    EKillTypes_tTable.SetInteger("KILL_NONE", 0x0);
    EKillTypes_tTable.SetInteger("KILL_DEFAULT", 0x1);
    EKillTypes_tTable.SetInteger("KILL_HEADSHOT", 0x2);
    EKillTypes_tTable.SetInteger("KILL_BLAST", 0x3);
    EKillTypes_tTable.SetInteger("KILL_BURN", 0x4);
    EKillTypes_tTable.SetInteger("KILL_SLASH", 0x5);
    EKillTypes_tTable.SetInteger("KILL_SHOCK", 0x6);
    EKillTypes_tTable.SetInteger("KILLTYPE_COUNT", 0x7);


    auto WeaponSound_tTable = state->CreateTable("WeaponSound_t");
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_EMPTY", 0x0);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SECONDARY_EMPTY", 0x1);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SINGLE", 0x2);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SECONDARY_ATTACK", 0x3);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MELEE_MISS", 0x4);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MELEE_HIT", 0x5);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MELEE_HIT_WORLD", 0x6);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MELEE_HIT_PLAYER", 0x7);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MELEE_HIT_NPC", 0x8);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SPECIAL1", 0x9);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SPECIAL2", 0xa);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SPECIAL3", 0xb);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_NEARLYEMPTY", 0xc);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_IMPACT", 0xd);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_REFLECT", 0xe);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SECONDARY_IMPACT", 0xf);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SECONDARY_REFLECT", 0x10);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_RELOAD", 0x11);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_SINGLE_ACCURATE", 0x12);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_ZOOM_IN", 0x13);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_ZOOM_OUT", 0x14);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_MOUSE_PRESSED", 0x15);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_DROP", 0x16);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_RADIO_USE", 0x17);
    WeaponSound_tTable.SetInteger("WEAPON_SOUND_NUM_TYPES", 0x18);


    auto TakeDamageFlags_tTable = state->CreateTable("TakeDamageFlags_t");
    TakeDamageFlags_tTable.SetInteger("DFLAG_NONE", 0x0);
    TakeDamageFlags_tTable.SetInteger("DFLAG_SUPPRESS_HEALTH_CHANGES", 0x1);
    TakeDamageFlags_tTable.SetInteger("DFLAG_SUPPRESS_PHYSICS_FORCE", 0x2);
    TakeDamageFlags_tTable.SetInteger("DFLAG_SUPPRESS_EFFECTS", 0x4);
    TakeDamageFlags_tTable.SetInteger("DFLAG_PREVENT_DEATH", 0x8);
    TakeDamageFlags_tTable.SetInteger("DFLAG_FORCE_DEATH", 0x10);
    TakeDamageFlags_tTable.SetInteger("DFLAG_ALWAYS_GIB", 0x20);
    TakeDamageFlags_tTable.SetInteger("DFLAG_NEVER_GIB", 0x40);
    TakeDamageFlags_tTable.SetInteger("DFLAG_REMOVE_NO_RAGDOLL", 0x80);
    TakeDamageFlags_tTable.SetInteger("DFLAG_SUPPRESS_DAMAGE_MODIFICATION", 0x100);
    TakeDamageFlags_tTable.SetInteger("DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS", 0x200);
    TakeDamageFlags_tTable.SetInteger("DFLAG_RADIUS_DMG", 0x400);
    TakeDamageFlags_tTable.SetInteger("DMG_LASTDFLAG", 0x400);
    TakeDamageFlags_tTable.SetInteger("DFLAG_IGNORE_ARMOR", 0x800);
    TakeDamageFlags_tTable.SetInteger("DFLAG_SUPPRESS_UTILREMOVE", 0x1000);


    auto ValueRemapperHapticsType_tTable = state->CreateTable("ValueRemapperHapticsType_t");
    ValueRemapperHapticsType_tTable.SetInteger("HaticsType_Default", 0x0);
    ValueRemapperHapticsType_tTable.SetInteger("HaticsType_None", 0x1);


    auto Disposition_tTable = state->CreateTable("Disposition_t");
    Disposition_tTable.SetInteger("D_ER", 0x0);
    Disposition_tTable.SetInteger("D_HT", 0x1);
    Disposition_tTable.SetInteger("D_FR", 0x2);
    Disposition_tTable.SetInteger("D_LI", 0x3);
    Disposition_tTable.SetInteger("D_NU", 0x4);
    Disposition_tTable.SetInteger("D_ERROR", 0x0);
    Disposition_tTable.SetInteger("D_HATE", 0x1);
    Disposition_tTable.SetInteger("D_FEAR", 0x2);
    Disposition_tTable.SetInteger("D_LIKE", 0x3);
    Disposition_tTable.SetInteger("D_NEUTRAL", 0x4);


    auto CanPlaySequence_tTable = state->CreateTable("CanPlaySequence_t");
    CanPlaySequence_tTable.SetInteger("CANNOT_PLAY", 0x0);
    CanPlaySequence_tTable.SetInteger("CAN_PLAY_NOW", 0x1);
    CanPlaySequence_tTable.SetInteger("CAN_PLAY_ENQUEUED", 0x2);


    auto MedalRank_tTable = state->CreateTable("MedalRank_t");
    MedalRank_tTable.SetInteger("MEDAL_RANK_NONE", 0x0);
    MedalRank_tTable.SetInteger("MEDAL_RANK_BRONZE", 0x1);
    MedalRank_tTable.SetInteger("MEDAL_RANK_SILVER", 0x2);
    MedalRank_tTable.SetInteger("MEDAL_RANK_GOLD", 0x3);
    MedalRank_tTable.SetInteger("MEDAL_RANK_COUNT", 0x4);


    auto ObserverMode_tTable = state->CreateTable("ObserverMode_t");
    ObserverMode_tTable.SetInteger("OBS_MODE_NONE", 0x0);
    ObserverMode_tTable.SetInteger("OBS_MODE_FIXED", 0x1);
    ObserverMode_tTable.SetInteger("OBS_MODE_IN_EYE", 0x2);
    ObserverMode_tTable.SetInteger("OBS_MODE_CHASE", 0x3);
    ObserverMode_tTable.SetInteger("OBS_MODE_ROAMING", 0x4);
    ObserverMode_tTable.SetInteger("OBS_MODE_DIRECTED", 0x5);
    ObserverMode_tTable.SetInteger("NUM_OBSERVER_MODES", 0x6);


    auto FuncDoorSpawnPos_tTable = state->CreateTable("FuncDoorSpawnPos_t");
    FuncDoorSpawnPos_tTable.SetInteger("FUNC_DOOR_SPAWN_CLOSED", 0x0);
    FuncDoorSpawnPos_tTable.SetInteger("FUNC_DOOR_SPAWN_OPEN", 0x1);


    auto EOverrideBlockLOS_tTable = state->CreateTable("EOverrideBlockLOS_t");
    EOverrideBlockLOS_tTable.SetInteger("BLOCK_LOS_DEFAULT", 0x0);
    EOverrideBlockLOS_tTable.SetInteger("BLOCK_LOS_FORCE_FALSE", 0x1);
    EOverrideBlockLOS_tTable.SetInteger("BLOCK_LOS_FORCE_TRUE", 0x2);


    auto MoveType_tTable = state->CreateTable("MoveType_t");
    MoveType_tTable.SetInteger("MOVETYPE_NONE", 0x0);
    MoveType_tTable.SetInteger("MOVETYPE_OBSOLETE", 0x1);
    MoveType_tTable.SetInteger("MOVETYPE_WALK", 0x2);
    MoveType_tTable.SetInteger("MOVETYPE_FLY", 0x3);
    MoveType_tTable.SetInteger("MOVETYPE_FLYGRAVITY", 0x4);
    MoveType_tTable.SetInteger("MOVETYPE_VPHYSICS", 0x5);
    MoveType_tTable.SetInteger("MOVETYPE_PUSH", 0x6);
    MoveType_tTable.SetInteger("MOVETYPE_NOCLIP", 0x7);
    MoveType_tTable.SetInteger("MOVETYPE_OBSERVER", 0x8);
    MoveType_tTable.SetInteger("MOVETYPE_LADDER", 0x9);
    MoveType_tTable.SetInteger("MOVETYPE_CUSTOM", 0xa);
    MoveType_tTable.SetInteger("MOVETYPE_LAST", 0xb);
    MoveType_tTable.SetInteger("MOVETYPE_INVALID", 0xb);
    MoveType_tTable.SetInteger("MOVETYPE_MAX_BITS", 0x5);


    auto ParticleTextureLayerBlendType_tTable = state->CreateTable("ParticleTextureLayerBlendType_t");
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_MULTIPLY", 0x0);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_MOD2X", 0x1);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_REPLACE", 0x2);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_ADD", 0x3);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_SUBTRACT", 0x4);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_AVERAGE", 0x5);
    ParticleTextureLayerBlendType_tTable.SetInteger("SPRITECARD_TEXTURE_BLEND_LUMINANCE", 0x6);


    auto AnimationProcessingType_tTable = state->CreateTable("AnimationProcessingType_t");
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_SERVER_SIMULATION", 0x0);
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_CLIENT_SIMULATION", 0x1);
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_CLIENT_PREDICTION", 0x2);
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_CLIENT_INTERPOLATION", 0x3);
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_CLIENT_RENDER", 0x4);
    AnimationProcessingType_tTable.SetInteger("ANIMATION_PROCESSING_MAX", 0x5);


    auto RenderPrimitiveType_tTable = state->CreateTable("RenderPrimitiveType_t");
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_POINTS", 0x0);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_LINES", 0x1);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_LINES_WITH_ADJACENCY", 0x2);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_LINE_STRIP", 0x3);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_LINE_STRIP_WITH_ADJACENCY", 0x4);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_TRIANGLES", 0x5);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_TRIANGLES_WITH_ADJACENCY", 0x6);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_TRIANGLE_STRIP", 0x7);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_TRIANGLE_STRIP_WITH_ADJACENCY", 0x8);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_INSTANCED_QUADS", 0x9);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_HETEROGENOUS", 0xa);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_COMPUTE_SHADER", 0xb);
    RenderPrimitiveType_tTable.SetInteger("RENDER_PRIM_TYPE_COUNT", 0xc);


    auto ObjectTypeFlags_tTable = state->CreateTable("ObjectTypeFlags_t");
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_NONE", 0x0);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_MODEL", 0x8);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_BLOCK_LIGHT", 0x10);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_NO_SHADOWS", 0x20);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_WORLDSPACE_TEXURE_BLEND", 0x40);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_DISABLED_IN_LOW_QUALITY", 0x80);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_NO_SUN_SHADOWS", 0x100);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_RENDER_WITH_DYNAMIC", 0x200);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_RENDER_TO_CUBEMAPS", 0x400);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_MODEL_HAS_LODS", 0x800);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_OVERLAY", 0x2000);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_PRECOMPUTED_VISMEMBERS", 0x4000);
    ObjectTypeFlags_tTable.SetInteger("OBJECT_TYPE_STATIC_CUBE_MAP", 0x8000);


    auto ParticleModelType_tTable = state->CreateTable("ParticleModelType_t");
    ParticleModelType_tTable.SetInteger("PM_TYPE_INVALID", 0x0);
    ParticleModelType_tTable.SetInteger("PM_TYPE_NAMED_VALUE_MODEL", 0x1);
    ParticleModelType_tTable.SetInteger("PM_TYPE_NAMED_VALUE_EHANDLE", 0x2);
    ParticleModelType_tTable.SetInteger("PM_TYPE_CONTROL_POINT", 0x3);
    ParticleModelType_tTable.SetInteger("PM_TYPE_COUNT", 0x4);


    auto PulseInstructionCode_tTable = state->CreateTable("PulseInstructionCode_t");
    PulseInstructionCode_tTable.SetInteger("INVALID", 0x0);
    PulseInstructionCode_tTable.SetInteger("IMMEDIATE_HALT", 0x1);
    PulseInstructionCode_tTable.SetInteger("RETURN_VOID", 0x2);
    PulseInstructionCode_tTable.SetInteger("RETURN_VALUE", 0x3);
    PulseInstructionCode_tTable.SetInteger("NOP", 0x4);
    PulseInstructionCode_tTable.SetInteger("JUMP", 0x5);
    PulseInstructionCode_tTable.SetInteger("JUMP_COND", 0x6);
    PulseInstructionCode_tTable.SetInteger("CHUNK_LEAP", 0x7);
    PulseInstructionCode_tTable.SetInteger("CHUNK_LEAP_COND", 0x8);
    PulseInstructionCode_tTable.SetInteger("PULSE_CALL_SYNC", 0x9);
    PulseInstructionCode_tTable.SetInteger("PULSE_CALL_ASYNC_FIRE", 0xa);
    PulseInstructionCode_tTable.SetInteger("CELL_INVOKE", 0xb);
    PulseInstructionCode_tTable.SetInteger("LIBRARY_INVOKE", 0xc);
    PulseInstructionCode_tTable.SetInteger("SET_VAR", 0xd);
    PulseInstructionCode_tTable.SetInteger("GET_VAR", 0xe);
    PulseInstructionCode_tTable.SetInteger("GET_CONST", 0xf);
    PulseInstructionCode_tTable.SetInteger("SET_REGISTER_DOMAIN_VALUE", 0x10);
    PulseInstructionCode_tTable.SetInteger("COPY", 0x11);
    PulseInstructionCode_tTable.SetInteger("NOT", 0x12);
    PulseInstructionCode_tTable.SetInteger("NEGATE", 0x13);
    PulseInstructionCode_tTable.SetInteger("ADD", 0x14);
    PulseInstructionCode_tTable.SetInteger("SUB", 0x15);
    PulseInstructionCode_tTable.SetInteger("MUL", 0x16);
    PulseInstructionCode_tTable.SetInteger("DIV", 0x17);
    PulseInstructionCode_tTable.SetInteger("MOD", 0x18);
    PulseInstructionCode_tTable.SetInteger("LT", 0x19);
    PulseInstructionCode_tTable.SetInteger("LTE", 0x1a);
    PulseInstructionCode_tTable.SetInteger("EQ", 0x1b);
    PulseInstructionCode_tTable.SetInteger("NE", 0x1c);
    PulseInstructionCode_tTable.SetInteger("AND", 0x1d);
    PulseInstructionCode_tTable.SetInteger("OR", 0x1e);
    PulseInstructionCode_tTable.SetInteger("CONVERT_VALUE", 0x1f);
    PulseInstructionCode_tTable.SetInteger("LAST_SERIALIZED_CODE", 0x20);
    PulseInstructionCode_tTable.SetInteger("NEGATE_INT", 0x21);
    PulseInstructionCode_tTable.SetInteger("NEGATE_FLOAT", 0x22);
    PulseInstructionCode_tTable.SetInteger("ADD_INT", 0x23);
    PulseInstructionCode_tTable.SetInteger("ADD_FLOAT", 0x24);
    PulseInstructionCode_tTable.SetInteger("ADD_STRING", 0x25);
    PulseInstructionCode_tTable.SetInteger("SUB_INT", 0x26);
    PulseInstructionCode_tTable.SetInteger("SUB_FLOAT", 0x27);
    PulseInstructionCode_tTable.SetInteger("MUL_INT", 0x28);
    PulseInstructionCode_tTable.SetInteger("MUL_FLOAT", 0x29);
    PulseInstructionCode_tTable.SetInteger("DIV_INT", 0x2a);
    PulseInstructionCode_tTable.SetInteger("DIV_FLOAT", 0x2b);
    PulseInstructionCode_tTable.SetInteger("MOD_INT", 0x2c);
    PulseInstructionCode_tTable.SetInteger("MOD_FLOAT", 0x2d);
    PulseInstructionCode_tTable.SetInteger("LT_INT", 0x2e);
    PulseInstructionCode_tTable.SetInteger("LT_FLOAT", 0x2f);
    PulseInstructionCode_tTable.SetInteger("LTE_INT", 0x30);
    PulseInstructionCode_tTable.SetInteger("LTE_FLOAT", 0x31);
    PulseInstructionCode_tTable.SetInteger("EQ_BOOL", 0x32);
    PulseInstructionCode_tTable.SetInteger("EQ_INT", 0x33);
    PulseInstructionCode_tTable.SetInteger("EQ_FLOAT", 0x34);
    PulseInstructionCode_tTable.SetInteger("EQ_STRING", 0x35);
    PulseInstructionCode_tTable.SetInteger("EQ_ENTITY_NAME", 0x36);
    PulseInstructionCode_tTable.SetInteger("NE_BOOL", 0x37);
    PulseInstructionCode_tTable.SetInteger("NE_INT", 0x38);
    PulseInstructionCode_tTable.SetInteger("NE_FLOAT", 0x39);
    PulseInstructionCode_tTable.SetInteger("NE_STRING", 0x3a);
    PulseInstructionCode_tTable.SetInteger("NE_ENTITY_NAME", 0x3b);
    PulseInstructionCode_tTable.SetInteger("GET_CONST_INLINE_STORAGE", 0x3c);


    auto StateActionBehaviorTable = state->CreateTable("StateActionBehavior");
    StateActionBehaviorTable.SetInteger("STATETAGBEHAVIOR_ACTIVE_WHILE_CURRENT", 0x0);
    StateActionBehaviorTable.SetInteger("STATETAGBEHAVIOR_FIRE_ON_ENTER", 0x1);
    StateActionBehaviorTable.SetInteger("STATETAGBEHAVIOR_FIRE_ON_EXIT", 0x2);
    StateActionBehaviorTable.SetInteger("STATETAGBEHAVIOR_FIRE_ON_ENTER_AND_EXIT", 0x3);


    auto Blend2DModeTable = state->CreateTable("Blend2DMode");
    Blend2DModeTable.SetInteger("Blend2DMode_General", 0x0);
    Blend2DModeTable.SetInteger("Blend2DMode_Directional", 0x1);


    auto ParticleOrientationSetMode_tTable = state->CreateTable("ParticleOrientationSetMode_t");
    ParticleOrientationSetMode_tTable.SetInteger("PARTICLE_ORIENTATION_SET_FROM_VELOCITY", 0x0);
    ParticleOrientationSetMode_tTable.SetInteger("PARTICLE_ORIENTATION_SET_FROM_ROTATIONS", 0x1);


    auto ParticleVRHandChoiceList_tTable = state->CreateTable("ParticleVRHandChoiceList_t");
    ParticleVRHandChoiceList_tTable.SetInteger("PARTICLE_VRHAND_LEFT", 0x0);
    ParticleVRHandChoiceList_tTable.SetInteger("PARTICLE_VRHAND_RIGHT", 0x1);
    ParticleVRHandChoiceList_tTable.SetInteger("PARTICLE_VRHAND_CP", 0x2);
    ParticleVRHandChoiceList_tTable.SetInteger("PARTICLE_VRHAND_CP_OBJECT", 0x3);


    auto SpawnDebugRestrictionOverrideState_tTable = state->CreateTable("SpawnDebugRestrictionOverrideState_t");
    SpawnDebugRestrictionOverrideState_tTable.SetInteger("SPAWN_DEBUG_RESTRICT_NONE", 0x0);
    SpawnDebugRestrictionOverrideState_tTable.SetInteger("SPAWN_DEBUG_RESTRICT_IGNORE_MANAGER_DISTANCE_REQS", 0x1);
    SpawnDebugRestrictionOverrideState_tTable.SetInteger("SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_DISTANCE_LOS_REQS", 0x2);
    SpawnDebugRestrictionOverrideState_tTable.SetInteger("SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_COOLDOWN_LIMITS", 0x4);
    SpawnDebugRestrictionOverrideState_tTable.SetInteger("SPAWN_DEBUG_RESTRICT_IGNORE_TARGET_COOLDOWN_LIMITS", 0x8);


    auto JointMotion_tTable = state->CreateTable("JointMotion_t");
    JointMotion_tTable.SetInteger("JOINT_MOTION_FREE", 0x0);
    JointMotion_tTable.SetInteger("JOINT_MOTION_LOCKED", 0x1);
    JointMotion_tTable.SetInteger("JOINT_MOTION_COUNT", 0x2);


    auto ParticleLightingQuality_tTable = state->CreateTable("ParticleLightingQuality_t");
    ParticleLightingQuality_tTable.SetInteger("PARTICLE_LIGHTING_PER_PARTICLE", 0x0);
    ParticleLightingQuality_tTable.SetInteger("PARTICLE_LIGHTING_PER_VERTEX", 0x1);
    ParticleLightingQuality_tTable.SetInteger("PARTICLE_LIGHTING_PER_PIXEL", 0xffffffffffffffff);


    auto SnapshotIndexType_tTable = state->CreateTable("SnapshotIndexType_t");
    SnapshotIndexType_tTable.SetInteger("SNAPSHOT_INDEX_INCREMENT", 0x0);
    SnapshotIndexType_tTable.SetInteger("SNAPSHOT_INDEX_DIRECT", 0x1);


    auto RagdollPoseControlTable = state->CreateTable("RagdollPoseControl");
    RagdollPoseControlTable.SetInteger("Absolute", 0x0);
    RagdollPoseControlTable.SetInteger("Relative", 0x1);


    auto ParticleOutputBlendMode_tTable = state->CreateTable("ParticleOutputBlendMode_t");
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_ALPHA", 0x0);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_ADD", 0x1);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_BLEND_ADD", 0x2);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_HALF_BLEND_ADD", 0x3);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_NEG_HALF_BLEND_ADD", 0x4);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_MOD2X", 0x5);
    ParticleOutputBlendMode_tTable.SetInteger("PARTICLE_OUTPUT_BLEND_MODE_LIGHTEN", 0x6);


    auto PulseMethodCallMode_tTable = state->CreateTable("PulseMethodCallMode_t");
    PulseMethodCallMode_tTable.SetInteger("SYNC_WAIT_FOR_COMPLETION", 0x0);
    PulseMethodCallMode_tTable.SetInteger("ASYNC_FIRE_AND_FORGET", 0x1);


    auto VMixFilterSlope_tTable = state->CreateTable("VMixFilterSlope_t");
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_1POLE_6dB", 0x0);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_1POLE_12dB", 0x1);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_1POLE_18dB", 0x2);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_1POLE_24dB", 0x3);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_12dB", 0x4);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_24dB", 0x5);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_36dB", 0x6);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_48dB", 0x7);
    VMixFilterSlope_tTable.SetInteger("FILTER_SLOPE_MAX", 0x7);


    auto ViewFadeMode_tTable = state->CreateTable("ViewFadeMode_t");
    ViewFadeMode_tTable.SetInteger("VIEW_FADE_CONSTANT_COLOR", 0x0);
    ViewFadeMode_tTable.SetInteger("VIEW_FADE_MODULATE", 0x1);
    ViewFadeMode_tTable.SetInteger("VIEW_FADE_MOD2X", 0x2);


    auto PulseCursorExecResult_tTable = state->CreateTable("PulseCursorExecResult_t");
    PulseCursorExecResult_tTable.SetInteger("Succeeded", 0x0);
    PulseCursorExecResult_tTable.SetInteger("Canceled", 0x1);
    PulseCursorExecResult_tTable.SetInteger("Failed", 0x2);


    auto CNmBoneMask__WeightInfo_tTable = state->CreateTable("CNmBoneMask__WeightInfo_t");
    CNmBoneMask__WeightInfo_tTable.SetInteger("Zero", 0x0);
    CNmBoneMask__WeightInfo_tTable.SetInteger("Mixed", 0x1);
    CNmBoneMask__WeightInfo_tTable.SetInteger("One", 0x2);


    auto NmTransitionRuleCondition_tTable = state->CreateTable("NmTransitionRuleCondition_t");
    NmTransitionRuleCondition_tTable.SetInteger("AnyAllowed", 0x0);
    NmTransitionRuleCondition_tTable.SetInteger("FullyAllowed", 0x1);
    NmTransitionRuleCondition_tTable.SetInteger("ConditionallyAllowed", 0x2);
    NmTransitionRuleCondition_tTable.SetInteger("Blocked", 0x3);


    auto FlexOpCode_tTable = state->CreateTable("FlexOpCode_t");
    FlexOpCode_tTable.SetInteger("FLEX_OP_CONST", 0x1);
    FlexOpCode_tTable.SetInteger("FLEX_OP_FETCH1", 0x2);
    FlexOpCode_tTable.SetInteger("FLEX_OP_FETCH2", 0x3);
    FlexOpCode_tTable.SetInteger("FLEX_OP_ADD", 0x4);
    FlexOpCode_tTable.SetInteger("FLEX_OP_SUB", 0x5);
    FlexOpCode_tTable.SetInteger("FLEX_OP_MUL", 0x6);
    FlexOpCode_tTable.SetInteger("FLEX_OP_DIV", 0x7);
    FlexOpCode_tTable.SetInteger("FLEX_OP_NEG", 0x8);
    FlexOpCode_tTable.SetInteger("FLEX_OP_EXP", 0x9);
    FlexOpCode_tTable.SetInteger("FLEX_OP_OPEN", 0xa);
    FlexOpCode_tTable.SetInteger("FLEX_OP_CLOSE", 0xb);
    FlexOpCode_tTable.SetInteger("FLEX_OP_COMMA", 0xc);
    FlexOpCode_tTable.SetInteger("FLEX_OP_MAX", 0xd);
    FlexOpCode_tTable.SetInteger("FLEX_OP_MIN", 0xe);
    FlexOpCode_tTable.SetInteger("FLEX_OP_2WAY_0", 0xf);
    FlexOpCode_tTable.SetInteger("FLEX_OP_2WAY_1", 0x10);
    FlexOpCode_tTable.SetInteger("FLEX_OP_NWAY", 0x11);
    FlexOpCode_tTable.SetInteger("FLEX_OP_COMBO", 0x12);
    FlexOpCode_tTable.SetInteger("FLEX_OP_DOMINATE", 0x13);
    FlexOpCode_tTable.SetInteger("FLEX_OP_DME_LOWER_EYELID", 0x14);
    FlexOpCode_tTable.SetInteger("FLEX_OP_DME_UPPER_EYELID", 0x15);
    FlexOpCode_tTable.SetInteger("FLEX_OP_SQRT", 0x16);
    FlexOpCode_tTable.SetInteger("FLEX_OP_REMAPVALCLAMPED", 0x17);
    FlexOpCode_tTable.SetInteger("FLEX_OP_SIN", 0x18);
    FlexOpCode_tTable.SetInteger("FLEX_OP_COS", 0x19);
    FlexOpCode_tTable.SetInteger("FLEX_OP_ABS", 0x1a);


    auto RenderMultisampleType_tTable = state->CreateTable("RenderMultisampleType_t");
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_INVALID", 0xffffffffffffffff);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_NONE", 0x0);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_2X", 0x1);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_4X", 0x2);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_6X", 0x3);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_8X", 0x4);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_16X", 0x5);
    RenderMultisampleType_tTable.SetInteger("RENDER_MULTISAMPLE_TYPE_COUNT", 0x6);


    auto ParticleLightTypeChoiceList_tTable = state->CreateTable("ParticleLightTypeChoiceList_t");
    ParticleLightTypeChoiceList_tTable.SetInteger("PARTICLE_LIGHT_TYPE_POINT", 0x0);
    ParticleLightTypeChoiceList_tTable.SetInteger("PARTICLE_LIGHT_TYPE_SPOT", 0x1);
    ParticleLightTypeChoiceList_tTable.SetInteger("PARTICLE_LIGHT_TYPE_FX", 0x2);
    ParticleLightTypeChoiceList_tTable.SetInteger("PARTICLE_LIGHT_TYPE_CAPSULE", 0x3);


    auto IKSolverTypeTable = state->CreateTable("IKSolverType");
    IKSolverTypeTable.SetInteger("IKSOLVER_Perlin", 0x0);
    IKSolverTypeTable.SetInteger("IKSOLVER_TwoBone", 0x1);
    IKSolverTypeTable.SetInteger("IKSOLVER_Fabrik", 0x2);
    IKSolverTypeTable.SetInteger("IKSOLVER_DogLeg3Bone", 0x3);
    IKSolverTypeTable.SetInteger("IKSOLVER_CCD", 0x4);
    IKSolverTypeTable.SetInteger("IKSOLVER_COUNT", 0x5);


    auto SolveIKChainAnimNodeDebugSettingTable = state->CreateTable("SolveIKChainAnimNodeDebugSetting");
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_None", 0x0);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_X_Axis_Circle", 0x1);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_Y_Axis_Circle", 0x2);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_Z_Axis_Circle", 0x3);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_Forward", 0x4);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_Up", 0x5);
    SolveIKChainAnimNodeDebugSettingTable.SetInteger("SOLVEIKCHAINANIMNODEDEBUGSETTING_Left", 0x6);


    auto PulseCursorCancelPriority_tTable = state->CreateTable("PulseCursorCancelPriority_t");
    PulseCursorCancelPriority_tTable.SetInteger("None", 0x0);
    PulseCursorCancelPriority_tTable.SetInteger("CancelOnSucceeded", 0x1);
    PulseCursorCancelPriority_tTable.SetInteger("SoftCancel", 0x2);
    PulseCursorCancelPriority_tTable.SetInteger("HardCancel", 0x3);


    auto MaterialProxyType_tTable = state->CreateTable("MaterialProxyType_t");
    MaterialProxyType_tTable.SetInteger("MATERIAL_PROXY_STATUS_EFFECT", 0x0);
    MaterialProxyType_tTable.SetInteger("MATERIAL_PROXY_TINT", 0x1);


    auto PFuncVisualizationType_tTable = state->CreateTable("PFuncVisualizationType_t");
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_SPHERE_WIREFRAME", 0x0);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_SPHERE_SOLID", 0x1);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_BOX", 0x2);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_RING", 0x3);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_PLANE", 0x4);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_LINE", 0x5);
    PFuncVisualizationType_tTable.SetInteger("PFUNC_VISUALIZATION_CYLINDER", 0x6);


    auto VPhysXJoint_t__Flags_tTable = state->CreateTable("VPhysXJoint_t__Flags_t");
    VPhysXJoint_t__Flags_tTable.SetInteger("JOINT_FLAGS_NONE", 0x0);
    VPhysXJoint_t__Flags_tTable.SetInteger("JOINT_FLAGS_BODY1_FIXED", 0x1);
    VPhysXJoint_t__Flags_tTable.SetInteger("JOINT_FLAGS_USE_BLOCK_SOLVER", 0x2);


    auto ParticlePostProcessPriorityGroup_tTable = state->CreateTable("ParticlePostProcessPriorityGroup_t");
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_LEVEL_VOLUME", 0x0);
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_LEVEL_OVERRIDE", 0x1);
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_EFFECT", 0x2);
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_LOW", 0x3);
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_HIGH", 0x4);
    ParticlePostProcessPriorityGroup_tTable.SetInteger("PARTICLE_POST_PROCESS_PRIORITY_GLOBAL_UI", 0x5);


    auto VMixPannerType_tTable = state->CreateTable("VMixPannerType_t");
    VMixPannerType_tTable.SetInteger("PANNER_TYPE_LINEAR", 0x0);
    VMixPannerType_tTable.SetInteger("PANNER_TYPE_EQUAL_POWER", 0x1);


    auto LayoutPositionType_eTable = state->CreateTable("LayoutPositionType_e");
    LayoutPositionType_eTable.SetInteger("LAYOUTPOSITIONTYPE_VIEWPORT_RELATIVE", 0x0);
    LayoutPositionType_eTable.SetInteger("LAYOUTPOSITIONTYPE_FRACTIONAL", 0x1);
    LayoutPositionType_eTable.SetInteger("LAYOUTPOSITIONTYPE_NONE", 0x2);


    auto AnimParamNetworkSettingTable = state->CreateTable("AnimParamNetworkSetting");
    AnimParamNetworkSettingTable.SetInteger("Auto", 0x0);
    AnimParamNetworkSettingTable.SetInteger("AlwaysNetwork", 0x1);
    AnimParamNetworkSettingTable.SetInteger("NeverNetwork", 0x2);


    auto JointAxis_tTable = state->CreateTable("JointAxis_t");
    JointAxis_tTable.SetInteger("JOINT_AXIS_X", 0x0);
    JointAxis_tTable.SetInteger("JOINT_AXIS_Y", 0x1);
    JointAxis_tTable.SetInteger("JOINT_AXIS_Z", 0x2);
    JointAxis_tTable.SetInteger("JOINT_AXIS_COUNT", 0x3);


    auto MovementGait_tTable = state->CreateTable("MovementGait_t");
    MovementGait_tTable.SetInteger("eInvalid", 0xffffffffffffffff);
    MovementGait_tTable.SetInteger("eWalk", 0x0);
    MovementGait_tTable.SetInteger("eJog", 0x1);
    MovementGait_tTable.SetInteger("eRun", 0x2);
    MovementGait_tTable.SetInteger("eSprint", 0x3);


    auto ParticleRotationLockType_tTable = state->CreateTable("ParticleRotationLockType_t");
    ParticleRotationLockType_tTable.SetInteger("PARTICLE_ROTATION_LOCK_NONE", 0x0);
    ParticleRotationLockType_tTable.SetInteger("PARTICLE_ROTATION_LOCK_ROTATIONS", 0x1);
    ParticleRotationLockType_tTable.SetInteger("PARTICLE_ROTATION_LOCK_NORMAL", 0x2);


    auto ParticleFloatInputMode_tTable = state->CreateTable("ParticleFloatInputMode_t");
    ParticleFloatInputMode_tTable.SetInteger("PF_INPUT_MODE_INVALID", 0xffffffffffffffff);
    ParticleFloatInputMode_tTable.SetInteger("PF_INPUT_MODE_CLAMPED", 0x0);
    ParticleFloatInputMode_tTable.SetInteger("PF_INPUT_MODE_LOOPED", 0x1);
    ParticleFloatInputMode_tTable.SetInteger("PF_INPUT_MODE_COUNT", 0x2);


    auto AimMatrixBlendModeTable = state->CreateTable("AimMatrixBlendMode");
    AimMatrixBlendModeTable.SetInteger("AimMatrixBlendMode_None", 0x0);
    AimMatrixBlendModeTable.SetInteger("AimMatrixBlendMode_Additive", 0x1);
    AimMatrixBlendModeTable.SetInteger("AimMatrixBlendMode_ModelSpaceAdditive", 0x2);
    AimMatrixBlendModeTable.SetInteger("AimMatrixBlendMode_BoneMask", 0x3);


    auto ParticleHitboxBiasType_tTable = state->CreateTable("ParticleHitboxBiasType_t");
    ParticleHitboxBiasType_tTable.SetInteger("PARTICLE_HITBOX_BIAS_ENTITY", 0x0);
    ParticleHitboxBiasType_tTable.SetInteger("PARTICLE_HITBOX_BIAS_HITBOX", 0x1);


    auto CompositeMaterialInputLooseVariableType_tTable = state->CreateTable("CompositeMaterialInputLooseVariableType_t");
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_BOOLEAN", 0x0);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_INTEGER1", 0x1);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_INTEGER2", 0x2);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_INTEGER3", 0x3);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_INTEGER4", 0x4);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_FLOAT1", 0x5);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_FLOAT2", 0x6);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_FLOAT3", 0x7);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_FLOAT4", 0x8);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_COLOR4", 0x9);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_STRING", 0xa);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_SYSTEMVAR", 0xb);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_RESOURCE_MATERIAL", 0xc);
    CompositeMaterialInputLooseVariableType_tTable.SetInteger("LOOSE_VARIABLE_TYPE_RESOURCE_TEXTURE", 0xd);


    auto BlurFilterType_tTable = state->CreateTable("BlurFilterType_t");
    BlurFilterType_tTable.SetInteger("BLURFILTER_GAUSSIAN", 0x0);
    BlurFilterType_tTable.SetInteger("BLURFILTER_BOX", 0x1);


    auto StanceOverrideModeTable = state->CreateTable("StanceOverrideMode");
    StanceOverrideModeTable.SetInteger("Sequence", 0x0);
    StanceOverrideModeTable.SetInteger("Node", 0x1);


    auto MeshDrawPrimitiveFlags_tTable = state->CreateTable("MeshDrawPrimitiveFlags_t");
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_NONE", 0x0);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_USE_SHADOW_FAST_PATH", 0x1);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_USE_COMPRESSED_NORMAL_TANGENT", 0x2);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_INPUT_LAYOUT_IS_NOT_MATCHED_TO_MATERIAL", 0x8);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_USE_COMPRESSED_PER_VERTEX_LIGHTING", 0x10);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_USE_UNCOMPRESSED_PER_VERTEX_LIGHTING", 0x20);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_CAN_BATCH_WITH_DYNAMIC_SHADER_CONSTANTS", 0x40);
    MeshDrawPrimitiveFlags_tTable.SetInteger("MESH_DRAW_FLAGS_DRAW_LAST", 0x80);


    auto ParticleFloatType_tTable = state->CreateTable("ParticleFloatType_t");
    ParticleFloatType_tTable.SetInteger("PF_TYPE_INVALID", 0xffffffffffffffff);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_LITERAL", 0x0);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_NAMED_VALUE", 0x1);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_RANDOM_UNIFORM", 0x2);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_RANDOM_BIASED", 0x3);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_COLLECTION_AGE", 0x4);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_ENDCAP_AGE", 0x5);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_CONTROL_POINT_COMPONENT", 0x6);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_CONTROL_POINT_CHANGE_AGE", 0x7);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_CONTROL_POINT_SPEED", 0x8);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_DETAIL_LEVEL", 0x9);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_CONCURRENT_DEF_COUNT", 0xa);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_CLOSEST_CAMERA_DISTANCE", 0xb);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_RENDERER_CAMERA_DISTANCE", 0xc);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_RENDERER_CAMERA_DOT_PRODUCT", 0xd);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_NOISE", 0xe);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_AGE", 0xf);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_AGE_NORMALIZED", 0x10);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_FLOAT", 0x11);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_VECTOR_COMPONENT", 0x12);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_SPEED", 0x13);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_NUMBER", 0x14);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_PARTICLE_NUMBER_NORMALIZED", 0x15);
    ParticleFloatType_tTable.SetInteger("PF_TYPE_COUNT", 0x16);


    auto NmTransitionRule_tTable = state->CreateTable("NmTransitionRule_t");
    NmTransitionRule_tTable.SetInteger("AllowTransition", 0x0);
    NmTransitionRule_tTable.SetInteger("ConditionallyAllowTransition", 0x1);
    NmTransitionRule_tTable.SetInteger("BlockTransition", 0x2);


    auto SpriteCardTextureType_tTable = state->CreateTable("SpriteCardTextureType_t");
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_DIFFUSE", 0x0);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_ZOOM", 0x1);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_1D_COLOR_LOOKUP", 0x2);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_UVDISTORTION", 0x3);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_UVDISTORTION_ZOOM", 0x4);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_NORMALMAP", 0x5);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_ANIMMOTIONVEC", 0x6);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_A", 0x7);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_B", 0x8);
    SpriteCardTextureType_tTable.SetInteger("SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_C", 0x9);


    auto SelectorTagBehavior_tTable = state->CreateTable("SelectorTagBehavior_t");
    SelectorTagBehavior_tTable.SetInteger("SelectorTagBehavior_OnWhileCurrent", 0x0);
    SelectorTagBehavior_tTable.SetInteger("SelectorTagBehavior_OffWhenFinished", 0x1);
    SelectorTagBehavior_tTable.SetInteger("SelectorTagBehavior_OffBeforeFinished", 0x2);


    auto ParticleFloatMapType_tTable = state->CreateTable("ParticleFloatMapType_t");
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_INVALID", 0xffffffffffffffff);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_DIRECT", 0x0);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_MULT", 0x1);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_REMAP", 0x2);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_REMAP_BIASED", 0x3);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_CURVE", 0x4);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_NOTCHED", 0x5);
    ParticleFloatMapType_tTable.SetInteger("PF_MAP_TYPE_COUNT", 0x6);


    auto VMixFilterType_tTable = state->CreateTable("VMixFilterType_t");
    VMixFilterType_tTable.SetInteger("FILTER_UNKNOWN", 0xffffffffffffffff);
    VMixFilterType_tTable.SetInteger("FILTER_LOWPASS", 0x0);
    VMixFilterType_tTable.SetInteger("FILTER_HIGHPASS", 0x1);
    VMixFilterType_tTable.SetInteger("FILTER_BANDPASS", 0x2);
    VMixFilterType_tTable.SetInteger("FILTER_NOTCH", 0x3);
    VMixFilterType_tTable.SetInteger("FILTER_PEAKING_EQ", 0x4);
    VMixFilterType_tTable.SetInteger("FILTER_LOW_SHELF", 0x5);
    VMixFilterType_tTable.SetInteger("FILTER_HIGH_SHELF", 0x6);
    VMixFilterType_tTable.SetInteger("FILTER_ALLPASS", 0x7);
    VMixFilterType_tTable.SetInteger("FILTER_PASSTHROUGH", 0x8);


    auto ParticleAttrBoxFlags_tTable = state->CreateTable("ParticleAttrBoxFlags_t");
    ParticleAttrBoxFlags_tTable.SetInteger("PARTICLE_ATTR_BOX_FLAGS_NONE", 0x0);
    ParticleAttrBoxFlags_tTable.SetInteger("PARTICLE_ATTR_BOX_FLAGS_WATER", 0x1);


    auto SosGroupType_tTable = state->CreateTable("SosGroupType_t");
    SosGroupType_tTable.SetInteger("SOS_GROUPTYPE_DYNAMIC", 0x0);
    SosGroupType_tTable.SetInteger("SOS_GROUPTYPE_STATIC", 0x1);


    auto PFNoiseTurbulence_tTable = state->CreateTable("PFNoiseTurbulence_t");
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_NONE", 0x0);
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_HIGHLIGHT", 0x1);
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_FEEDBACK", 0x2);
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_LOOPY", 0x3);
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_CONTRAST", 0x4);
    PFNoiseTurbulence_tTable.SetInteger("PF_NOISE_TURB_ALTERNATE", 0x5);


    auto MissingParentInheritBehavior_tTable = state->CreateTable("MissingParentInheritBehavior_t");
    MissingParentInheritBehavior_tTable.SetInteger("MISSING_PARENT_DO_NOTHING", 0xffffffffffffffff);
    MissingParentInheritBehavior_tTable.SetInteger("MISSING_PARENT_KILL", 0x0);
    MissingParentInheritBehavior_tTable.SetInteger("MISSING_PARENT_FIND_NEW", 0x1);
    MissingParentInheritBehavior_tTable.SetInteger("MISSING_PARENT_SAME_INDEX", 0x2);


    auto AnimationType_tTable = state->CreateTable("AnimationType_t");
    AnimationType_tTable.SetInteger("ANIMATION_TYPE_FIXED_RATE", 0x0);
    AnimationType_tTable.SetInteger("ANIMATION_TYPE_FIT_LIFETIME", 0x1);
    AnimationType_tTable.SetInteger("ANIMATION_TYPE_MANUAL_FRAMES", 0x2);


    auto AnimParamButton_tTable = state->CreateTable("AnimParamButton_t");
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_NONE", 0x0);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_DPAD_UP", 0x1);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_DPAD_RIGHT", 0x2);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_DPAD_DOWN", 0x3);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_DPAD_LEFT", 0x4);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_A", 0x5);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_B", 0x6);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_X", 0x7);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_Y", 0x8);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_LEFT_SHOULDER", 0x9);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_RIGHT_SHOULDER", 0xa);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_LTRIGGER", 0xb);
    AnimParamButton_tTable.SetInteger("ANIMPARAM_BUTTON_RTRIGGER", 0xc);


    auto BloomBlendMode_tTable = state->CreateTable("BloomBlendMode_t");
    BloomBlendMode_tTable.SetInteger("BLOOM_BLEND_ADD", 0x0);
    BloomBlendMode_tTable.SetInteger("BLOOM_BLEND_SCREEN", 0x1);
    BloomBlendMode_tTable.SetInteger("BLOOM_BLEND_BLUR", 0x2);


    auto CompMatPropertyMutatorConditionType_tTable = state->CreateTable("CompMatPropertyMutatorConditionType_t");
    CompMatPropertyMutatorConditionType_tTable.SetInteger("COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_EXISTS", 0x0);
    CompMatPropertyMutatorConditionType_tTable.SetInteger("COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EXISTS", 0x1);
    CompMatPropertyMutatorConditionType_tTable.SetInteger("COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EQUALS", 0x2);


    auto ParticleSetMethod_tTable = state->CreateTable("ParticleSetMethod_t");
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_REPLACE_VALUE", 0x0);
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_SCALE_INITIAL_VALUE", 0x1);
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_ADD_TO_INITIAL_VALUE", 0x2);
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_RAMP_CURRENT_VALUE", 0x3);
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_SCALE_CURRENT_VALUE", 0x4);
    ParticleSetMethod_tTable.SetInteger("PARTICLE_SET_ADD_TO_CURRENT_VALUE", 0x5);


    auto VectorFloatExpressionType_tTable = state->CreateTable("VectorFloatExpressionType_t");
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_UNINITIALIZED", 0xffffffffffffffff);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_DOTPRODUCT", 0x0);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_DISTANCE", 0x1);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_DISTANCESQR", 0x2);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTH", 0x3);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTHSQR", 0x4);
    VectorFloatExpressionType_tTable.SetInteger("VECTOR_FLOAT_EXPRESSION_INPUT1_NOISE", 0x5);


    auto ChoiceMethodTable = state->CreateTable("ChoiceMethod");
    ChoiceMethodTable.SetInteger("WeightedRandom", 0x0);
    ChoiceMethodTable.SetInteger("WeightedRandomNoRepeat", 0x1);
    ChoiceMethodTable.SetInteger("Iterate", 0x2);
    ChoiceMethodTable.SetInteger("IterateRandom", 0x3);


    auto NmFootPhaseCondition_tTable = state->CreateTable("NmFootPhaseCondition_t");
    NmFootPhaseCondition_tTable.SetInteger("LeftFootDown", 0x0);
    NmFootPhaseCondition_tTable.SetInteger("LeftFootPassing", 0x1);
    NmFootPhaseCondition_tTable.SetInteger("LeftPhase", 0x4);
    NmFootPhaseCondition_tTable.SetInteger("RightFootDown", 0x2);
    NmFootPhaseCondition_tTable.SetInteger("RightFootPassing", 0x3);
    NmFootPhaseCondition_tTable.SetInteger("RightPhase", 0x5);


    auto CompositeMaterialVarSystemVar_tTable = state->CreateTable("CompositeMaterialVarSystemVar_t");
    CompositeMaterialVarSystemVar_tTable.SetInteger("COMPMATSYSVAR_COMPOSITETIME", 0x0);
    CompositeMaterialVarSystemVar_tTable.SetInteger("COMPMATSYSVAR_EMPTY_RESOURCE_SPACER", 0x1);


    auto VectorExpressionType_tTable = state->CreateTable("VectorExpressionType_t");
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_UNINITIALIZED", 0xffffffffffffffff);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_ADD", 0x0);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_SUBTRACT", 0x1);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_MUL", 0x2);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_DIVIDE", 0x3);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_INPUT_1", 0x4);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_MIN", 0x5);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_MAX", 0x6);
    VectorExpressionType_tTable.SetInteger("VECTOR_EXPRESSION_CROSSPRODUCT", 0x7);


    auto ParticleSelection_tTable = state->CreateTable("ParticleSelection_t");
    ParticleSelection_tTable.SetInteger("PARTICLE_SELECTION_FIRST", 0x0);
    ParticleSelection_tTable.SetInteger("PARTICLE_SELECTION_LAST", 0x1);
    ParticleSelection_tTable.SetInteger("PARTICLE_SELECTION_NUMBER", 0x2);


    auto DisableShadows_tTable = state->CreateTable("DisableShadows_t");
    DisableShadows_tTable.SetInteger("kDisableShadows_None", 0x0);
    DisableShadows_tTable.SetInteger("kDisableShadows_All", 0x1);
    DisableShadows_tTable.SetInteger("kDisableShadows_Baked", 0x2);
    DisableShadows_tTable.SetInteger("kDisableShadows_Realtime", 0x3);


    auto ParticleFogType_tTable = state->CreateTable("ParticleFogType_t");
    ParticleFogType_tTable.SetInteger("PARTICLE_FOG_GAME_DEFAULT", 0x0);
    ParticleFogType_tTable.SetInteger("PARTICLE_FOG_ENABLED", 0x1);
    ParticleFogType_tTable.SetInteger("PARTICLE_FOG_DISABLED", 0x2);


    auto Detail2Combo_tTable = state->CreateTable("Detail2Combo_t");
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_UNINITIALIZED", 0xffffffffffffffff);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_OFF", 0x0);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_ADD", 0x1);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_ADD_SELF_ILLUM", 0x2);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_MOD2X", 0x3);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_MUL", 0x4);
    Detail2Combo_tTable.SetInteger("DETAIL_2_COMBO_CROSSFADE", 0x5);


    auto ParticleAlphaReferenceType_tTable = state->CreateTable("ParticleAlphaReferenceType_t");
    ParticleAlphaReferenceType_tTable.SetInteger("PARTICLE_ALPHA_REFERENCE_ALPHA_ALPHA", 0x0);
    ParticleAlphaReferenceType_tTable.SetInteger("PARTICLE_ALPHA_REFERENCE_OPAQUE_ALPHA", 0x1);
    ParticleAlphaReferenceType_tTable.SetInteger("PARTICLE_ALPHA_REFERENCE_ALPHA_OPAQUE", 0x2);
    ParticleAlphaReferenceType_tTable.SetInteger("PARTICLE_ALPHA_REFERENCE_OPAQUE_OPAQUE", 0x3);


    auto ParticleVecType_tTable = state->CreateTable("ParticleVecType_t");
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_INVALID", 0xffffffffffffffff);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_LITERAL", 0x0);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_LITERAL_COLOR", 0x1);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_NAMED_VALUE", 0x2);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_PARTICLE_VECTOR", 0x3);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_PARTICLE_VELOCITY", 0x4);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CP_VALUE", 0x5);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CP_RELATIVE_POSITION", 0x6);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CP_RELATIVE_DIR", 0x7);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CP_RELATIVE_RANDOM_DIR", 0x8);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_FLOAT_COMPONENTS", 0x9);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_FLOAT_INTERP_CLAMPED", 0xa);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_FLOAT_INTERP_OPEN", 0xb);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_FLOAT_INTERP_GRADIENT", 0xc);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_RANDOM_UNIFORM", 0xd);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_RANDOM_UNIFORM_OFFSET", 0xe);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CP_DELTA", 0xf);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_CLOSEST_CAMERA_POSITION", 0x10);
    ParticleVecType_tTable.SetInteger("PVEC_TYPE_COUNT", 0x11);


    auto ThreeState_tTable = state->CreateTable("ThreeState_t");
    ThreeState_tTable.SetInteger("TRS_FALSE", 0x0);
    ThreeState_tTable.SetInteger("TRS_TRUE", 0x1);
    ThreeState_tTable.SetInteger("TRS_NONE", 0x2);


    auto PFNoiseModifier_tTable = state->CreateTable("PFNoiseModifier_t");
    PFNoiseModifier_tTable.SetInteger("PF_NOISE_MODIFIER_NONE", 0x0);
    PFNoiseModifier_tTable.SetInteger("PF_NOISE_MODIFIER_LINES", 0x1);
    PFNoiseModifier_tTable.SetInteger("PF_NOISE_MODIFIER_CLUMPS", 0x2);
    PFNoiseModifier_tTable.SetInteger("PF_NOISE_MODIFIER_RINGS", 0x3);


    auto ParticleImpulseType_tTable = state->CreateTable("ParticleImpulseType_t");
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_NONE", 0x0);
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_GENERIC", 0x1);
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_ROPE", 0x2);
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_EXPLOSION", 0x4);
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_EXPLOSION_UNDERWATER", 0x8);
    ParticleImpulseType_tTable.SetInteger("IMPULSE_TYPE_PARTICLE_SYSTEM", 0x10);


    auto VPhysXAggregateData_t__VPhysXFlagEnum_tTable = state->CreateTable("VPhysXAggregateData_t__VPhysXFlagEnum_t");
    VPhysXAggregateData_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_IS_POLYSOUP_GEOMETRY", 0x1);
    VPhysXAggregateData_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_LEVEL_COLLISION", 0x10);
    VPhysXAggregateData_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_IGNORE_SCALE_OBSOLETE_DO_NOT_USE", 0x20);


    auto ParticleFloatRandomMode_tTable = state->CreateTable("ParticleFloatRandomMode_t");
    ParticleFloatRandomMode_tTable.SetInteger("PF_RANDOM_MODE_INVALID", 0xffffffffffffffff);
    ParticleFloatRandomMode_tTable.SetInteger("PF_RANDOM_MODE_CONSTANT", 0x0);
    ParticleFloatRandomMode_tTable.SetInteger("PF_RANDOM_MODE_VARYING", 0x1);
    ParticleFloatRandomMode_tTable.SetInteger("PF_RANDOM_MODE_COUNT", 0x2);


    auto AnimNodeNetworkModeTable = state->CreateTable("AnimNodeNetworkMode");
    AnimNodeNetworkModeTable.SetInteger("ServerAuthoritative", 0x0);
    AnimNodeNetworkModeTable.SetInteger("ClientSimulate", 0x1);


    auto CompositeMaterialMatchFilterType_tTable = state->CreateTable("CompositeMaterialMatchFilterType_t");
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_ATTRIBUTE_EXISTS", 0x0);
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_SHADER", 0x1);
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_NAME_SUBSTR", 0x2);
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_ATTRIBUTE_EQUALS", 0x3);
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_PROPERTY_EXISTS", 0x4);
    CompositeMaterialMatchFilterType_tTable.SetInteger("MATCH_FILTER_MATERIAL_PROPERTY_EQUALS", 0x5);


    auto AnimPoseControlTable = state->CreateTable("AnimPoseControl");
    AnimPoseControlTable.SetInteger("NoPoseControl", 0x0);
    AnimPoseControlTable.SetInteger("AbsolutePoseControl", 0x1);
    AnimPoseControlTable.SetInteger("RelativePoseControl", 0x2);


    auto FootLockSubVisualizationTable = state->CreateTable("FootLockSubVisualization");
    FootLockSubVisualizationTable.SetInteger("FOOTLOCKSUBVISUALIZATION_ReachabilityAnalysis", 0x0);
    FootLockSubVisualizationTable.SetInteger("FOOTLOCKSUBVISUALIZATION_IKSolve", 0x1);


    auto PulseValueType_tTable = state->CreateTable("PulseValueType_t");
    PulseValueType_tTable.SetInteger("PVAL_INVALID", 0xffffffffffffffff);
    PulseValueType_tTable.SetInteger("PVAL_BOOL", 0x0);
    PulseValueType_tTable.SetInteger("PVAL_INT", 0x1);
    PulseValueType_tTable.SetInteger("PVAL_FLOAT", 0x2);
    PulseValueType_tTable.SetInteger("PVAL_STRING", 0x3);
    PulseValueType_tTable.SetInteger("PVAL_VEC3", 0x4);
    PulseValueType_tTable.SetInteger("PVAL_TRANSFORM", 0x5);
    PulseValueType_tTable.SetInteger("PVAL_COLOR_RGB", 0x6);
    PulseValueType_tTable.SetInteger("PVAL_EHANDLE", 0x7);
    PulseValueType_tTable.SetInteger("PVAL_RESOURCE", 0x8);
    PulseValueType_tTable.SetInteger("PVAL_SNDEVT_GUID", 0x9);
    PulseValueType_tTable.SetInteger("PVAL_ENTITY_NAME", 0xa);
    PulseValueType_tTable.SetInteger("PVAL_SCHEMA_PTR", 0xb);
    PulseValueType_tTable.SetInteger("PVAL_TYPESAFE_INT", 0xc);
    PulseValueType_tTable.SetInteger("PVAL_CURSOR_FLOW", 0xd);
    PulseValueType_tTable.SetInteger("PVAL_ANY", 0xe);
    PulseValueType_tTable.SetInteger("PVAL_SCHEMA_ENUM", 0xf);
    PulseValueType_tTable.SetInteger("PVAL_PANORAMA_PANEL_HANDLE", 0x10);
    PulseValueType_tTable.SetInteger("PVAL_COUNT", 0x11);


    auto FacingModeTable = state->CreateTable("FacingMode");
    FacingModeTable.SetInteger("FacingMode_Manual", 0x0);
    FacingModeTable.SetInteger("FacingMode_Path", 0x1);
    FacingModeTable.SetInteger("FacingMode_LookTarget", 0x2);


    auto SeqCmd_tTable = state->CreateTable("SeqCmd_t");
    SeqCmd_tTable.SetInteger("SeqCmd_Nop", 0x0);
    SeqCmd_tTable.SetInteger("SeqCmd_LinearDelta", 0x1);
    SeqCmd_tTable.SetInteger("SeqCmd_FetchFrameRange", 0x2);
    SeqCmd_tTable.SetInteger("SeqCmd_Slerp", 0x3);
    SeqCmd_tTable.SetInteger("SeqCmd_Add", 0x4);
    SeqCmd_tTable.SetInteger("SeqCmd_Subtract", 0x5);
    SeqCmd_tTable.SetInteger("SeqCmd_Scale", 0x6);
    SeqCmd_tTable.SetInteger("SeqCmd_Copy", 0x7);
    SeqCmd_tTable.SetInteger("SeqCmd_Blend", 0x8);
    SeqCmd_tTable.SetInteger("SeqCmd_Worldspace", 0x9);
    SeqCmd_tTable.SetInteger("SeqCmd_Sequence", 0xa);
    SeqCmd_tTable.SetInteger("SeqCmd_FetchCycle", 0xb);
    SeqCmd_tTable.SetInteger("SeqCmd_FetchFrame", 0xc);
    SeqCmd_tTable.SetInteger("SeqCmd_IKLockInPlace", 0xd);
    SeqCmd_tTable.SetInteger("SeqCmd_IKRestoreAll", 0xe);
    SeqCmd_tTable.SetInteger("SeqCmd_ReverseSequence", 0xf);
    SeqCmd_tTable.SetInteger("SeqCmd_Transform", 0x10);


    auto ChoiceBlendMethodTable = state->CreateTable("ChoiceBlendMethod");
    ChoiceBlendMethodTable.SetInteger("SingleBlendTime", 0x0);
    ChoiceBlendMethodTable.SetInteger("PerChoiceBlendTimes", 0x1);


    auto ParticleParentSetMode_tTable = state->CreateTable("ParticleParentSetMode_t");
    ParticleParentSetMode_tTable.SetInteger("PARTICLE_SET_PARENT_NO", 0x0);
    ParticleParentSetMode_tTable.SetInteger("PARTICLE_SET_PARENT_IMMEDIATE", 0x1);
    ParticleParentSetMode_tTable.SetInteger("PARTICLE_SET_PARENT_ROOT", 0x1);


    auto VMixProcessorType_tTable = state->CreateTable("VMixProcessorType_t");
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_UNKNOWN", 0x0);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_STEAMAUDIO_REVERB", 0x1);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_RT_PITCH", 0x2);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_STEAMAUDIO_HRTF", 0x3);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_DYNAMICS", 0x4);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_PRESETDSP", 0x5);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_DELAY", 0x6);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_MOD_DELAY", 0x7);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_DIFFUSOR", 0x8);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_BOXVERB", 0x9);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_FREEVERB", 0xa);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_PLATEVERB", 0xb);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_FULLWAVE_INTEGRATOR", 0xc);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_FILTER", 0xd);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_STEAMAUDIO_PATHING", 0xe);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_EQ8", 0xf);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_ENVELOPE", 0x10);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_VOCODER", 0x11);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_CONVOLUTION", 0x12);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_DYNAMICS_3BAND", 0x13);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_DYNAMICS_COMPRESSOR", 0x14);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_SHAPER", 0x15);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_PANNER", 0x16);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_UTILITY", 0x17);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_AUTOFILTER", 0x18);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_OSC", 0x19);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_STEREODELAY", 0x1a);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_EFFECT_CHAIN", 0x1b);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_SUBGRAPH_SWITCH", 0x1c);
    VMixProcessorType_tTable.SetInteger("VPROCESSOR_STEAMAUDIO_DIRECT", 0x1d);


    auto ChoiceChangeMethodTable = state->CreateTable("ChoiceChangeMethod");
    ChoiceChangeMethodTable.SetInteger("OnReset", 0x0);
    ChoiceChangeMethodTable.SetInteger("OnCycleEnd", 0x1);
    ChoiceChangeMethodTable.SetInteger("OnResetOrCycleEnd", 0x2);


    auto BinaryNodeChildOptionTable = state->CreateTable("BinaryNodeChildOption");
    BinaryNodeChildOptionTable.SetInteger("Child1", 0x0);
    BinaryNodeChildOptionTable.SetInteger("Child2", 0x1);


    auto CompositeMaterialInputTextureType_tTable = state->CreateTable("CompositeMaterialInputTextureType_t");
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_DEFAULT", 0x0);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_NORMALMAP", 0x1);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_COLOR", 0x2);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_MASKS", 0x3);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_ROUGHNESS", 0x4);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_PEARLESCENCE_MASK", 0x5);
    CompositeMaterialInputTextureType_tTable.SetInteger("INPUT_TEXTURE_TYPE_AO", 0x6);


    auto BoneMaskBlendSpaceTable = state->CreateTable("BoneMaskBlendSpace");
    BoneMaskBlendSpaceTable.SetInteger("BlendSpace_Parent", 0x0);
    BoneMaskBlendSpaceTable.SetInteger("BlendSpace_Model", 0x1);
    BoneMaskBlendSpaceTable.SetInteger("BlendSpace_Model_RotationOnly", 0x2);
    BoneMaskBlendSpaceTable.SetInteger("BlendSpace_Model_TranslationOnly", 0x3);


    auto AnimScriptTypeTable = state->CreateTable("AnimScriptType");
    AnimScriptTypeTable.SetInteger("ANIMSCRIPT_TYPE_INVALID", 0xffffffffffffffff);
    AnimScriptTypeTable.SetInteger("ANIMSCRIPT_FUSE_GENERAL", 0x0);
    AnimScriptTypeTable.SetInteger("ANIMSCRIPT_FUSE_STATEMACHINE", 0x1);


    auto FuseVariableAccess_tTable = state->CreateTable("FuseVariableAccess_t");
    FuseVariableAccess_tTable.SetInteger("WRITABLE", 0x0);
    FuseVariableAccess_tTable.SetInteger("READ_ONLY", 0x1);


    auto DetailCombo_tTable = state->CreateTable("DetailCombo_t");
    DetailCombo_tTable.SetInteger("DETAIL_COMBO_OFF", 0x0);
    DetailCombo_tTable.SetInteger("DETAIL_COMBO_ADD", 0x1);
    DetailCombo_tTable.SetInteger("DETAIL_COMBO_ADD_SELF_ILLUM", 0x2);
    DetailCombo_tTable.SetInteger("DETAIL_COMBO_MOD2X", 0x3);


    auto InheritableBoolType_tTable = state->CreateTable("InheritableBoolType_t");
    InheritableBoolType_tTable.SetInteger("INHERITABLE_BOOL_INHERIT", 0x0);
    InheritableBoolType_tTable.SetInteger("INHERITABLE_BOOL_FALSE", 0x1);
    InheritableBoolType_tTable.SetInteger("INHERITABLE_BOOL_TRUE", 0x2);


    auto ParticleTransformType_tTable = state->CreateTable("ParticleTransformType_t");
    ParticleTransformType_tTable.SetInteger("PT_TYPE_INVALID", 0x0);
    ParticleTransformType_tTable.SetInteger("PT_TYPE_NAMED_VALUE", 0x1);
    ParticleTransformType_tTable.SetInteger("PT_TYPE_CONTROL_POINT", 0x2);
    ParticleTransformType_tTable.SetInteger("PT_TYPE_CONTROL_POINT_RANGE", 0x3);
    ParticleTransformType_tTable.SetInteger("PT_TYPE_COUNT", 0x4);


    auto ParticleHitboxDataSelection_tTable = state->CreateTable("ParticleHitboxDataSelection_t");
    ParticleHitboxDataSelection_tTable.SetInteger("PARTICLE_HITBOX_AVERAGE_SPEED", 0x0);
    ParticleHitboxDataSelection_tTable.SetInteger("PARTICLE_HITBOX_COUNT", 0x1);


    auto AnimVectorSourceTable = state->CreateTable("AnimVectorSource");
    AnimVectorSourceTable.SetInteger("MoveDirection", 0x0);
    AnimVectorSourceTable.SetInteger("FacingDirection", 0x1);
    AnimVectorSourceTable.SetInteger("LookDirection", 0x2);
    AnimVectorSourceTable.SetInteger("VectorParameter", 0x3);
    AnimVectorSourceTable.SetInteger("WayPointDirection", 0x4);
    AnimVectorSourceTable.SetInteger("Acceleration", 0x5);
    AnimVectorSourceTable.SetInteger("SlopeNormal", 0x6);
    AnimVectorSourceTable.SetInteger("SlopeNormal_WorldSpace", 0x7);
    AnimVectorSourceTable.SetInteger("LookTarget", 0x8);
    AnimVectorSourceTable.SetInteger("LookTarget_WorldSpace", 0x9);
    AnimVectorSourceTable.SetInteger("WayPointPosition", 0xa);
    AnimVectorSourceTable.SetInteger("GoalPosition", 0xb);
    AnimVectorSourceTable.SetInteger("RootMotionVelocity", 0xc);


    auto TextureRepetitionMode_tTable = state->CreateTable("TextureRepetitionMode_t");
    TextureRepetitionMode_tTable.SetInteger("TEXTURE_REPETITION_PARTICLE", 0x0);
    TextureRepetitionMode_tTable.SetInteger("TEXTURE_REPETITION_PATH", 0x1);


    auto fieldtype_tTable = state->CreateTable("fieldtype_t");
    fieldtype_tTable.SetInteger("FIELD_VOID", 0x0);
    fieldtype_tTable.SetInteger("FIELD_FLOAT32", 0x1);
    fieldtype_tTable.SetInteger("FIELD_STRING", 0x2);
    fieldtype_tTable.SetInteger("FIELD_VECTOR", 0x3);
    fieldtype_tTable.SetInteger("FIELD_QUATERNION", 0x4);
    fieldtype_tTable.SetInteger("FIELD_INT32", 0x5);
    fieldtype_tTable.SetInteger("FIELD_BOOLEAN", 0x6);
    fieldtype_tTable.SetInteger("FIELD_INT16", 0x7);
    fieldtype_tTable.SetInteger("FIELD_CHARACTER", 0x8);
    fieldtype_tTable.SetInteger("FIELD_COLOR32", 0x9);
    fieldtype_tTable.SetInteger("FIELD_EMBEDDED", 0xa);
    fieldtype_tTable.SetInteger("FIELD_CUSTOM", 0xb);
    fieldtype_tTable.SetInteger("FIELD_CLASSPTR", 0xc);
    fieldtype_tTable.SetInteger("FIELD_EHANDLE", 0xd);
    fieldtype_tTable.SetInteger("FIELD_POSITION_VECTOR", 0xe);
    fieldtype_tTable.SetInteger("FIELD_TIME", 0xf);
    fieldtype_tTable.SetInteger("FIELD_TICK", 0x10);
    fieldtype_tTable.SetInteger("FIELD_SOUNDNAME", 0x11);
    fieldtype_tTable.SetInteger("FIELD_INPUT", 0x12);
    fieldtype_tTable.SetInteger("FIELD_FUNCTION", 0x13);
    fieldtype_tTable.SetInteger("FIELD_VMATRIX", 0x14);
    fieldtype_tTable.SetInteger("FIELD_VMATRIX_WORLDSPACE", 0x15);
    fieldtype_tTable.SetInteger("FIELD_MATRIX3X4_WORLDSPACE", 0x16);
    fieldtype_tTable.SetInteger("FIELD_INTERVAL", 0x17);
    fieldtype_tTable.SetInteger("FIELD_UNUSED", 0x18);
    fieldtype_tTable.SetInteger("FIELD_VECTOR2D", 0x19);
    fieldtype_tTable.SetInteger("FIELD_INT64", 0x1a);
    fieldtype_tTable.SetInteger("FIELD_VECTOR4D", 0x1b);
    fieldtype_tTable.SetInteger("FIELD_RESOURCE", 0x1c);
    fieldtype_tTable.SetInteger("FIELD_TYPEUNKNOWN", 0x1d);
    fieldtype_tTable.SetInteger("FIELD_CSTRING", 0x1e);
    fieldtype_tTable.SetInteger("FIELD_HSCRIPT", 0x1f);
    fieldtype_tTable.SetInteger("FIELD_VARIANT", 0x20);
    fieldtype_tTable.SetInteger("FIELD_UINT64", 0x21);
    fieldtype_tTable.SetInteger("FIELD_FLOAT64", 0x22);
    fieldtype_tTable.SetInteger("FIELD_POSITIVEINTEGER_OR_NULL", 0x23);
    fieldtype_tTable.SetInteger("FIELD_HSCRIPT_NEW_INSTANCE", 0x24);
    fieldtype_tTable.SetInteger("FIELD_UINT32", 0x25);
    fieldtype_tTable.SetInteger("FIELD_UTLSTRINGTOKEN", 0x26);
    fieldtype_tTable.SetInteger("FIELD_QANGLE", 0x27);
    fieldtype_tTable.SetInteger("FIELD_NETWORK_ORIGIN_CELL_QUANTIZED_VECTOR", 0x28);
    fieldtype_tTable.SetInteger("FIELD_HMATERIAL", 0x29);
    fieldtype_tTable.SetInteger("FIELD_HMODEL", 0x2a);
    fieldtype_tTable.SetInteger("FIELD_NETWORK_QUANTIZED_VECTOR", 0x2b);
    fieldtype_tTable.SetInteger("FIELD_NETWORK_QUANTIZED_FLOAT", 0x2c);
    fieldtype_tTable.SetInteger("FIELD_DIRECTION_VECTOR_WORLDSPACE", 0x2d);
    fieldtype_tTable.SetInteger("FIELD_QANGLE_WORLDSPACE", 0x2e);
    fieldtype_tTable.SetInteger("FIELD_QUATERNION_WORLDSPACE", 0x2f);
    fieldtype_tTable.SetInteger("FIELD_HSCRIPT_LIGHTBINDING", 0x30);
    fieldtype_tTable.SetInteger("FIELD_V8_VALUE", 0x31);
    fieldtype_tTable.SetInteger("FIELD_V8_OBJECT", 0x32);
    fieldtype_tTable.SetInteger("FIELD_V8_ARRAY", 0x33);
    fieldtype_tTable.SetInteger("FIELD_V8_CALLBACK_INFO", 0x34);
    fieldtype_tTable.SetInteger("FIELD_UTLSTRING", 0x35);
    fieldtype_tTable.SetInteger("FIELD_NETWORK_ORIGIN_CELL_QUANTIZED_POSITION_VECTOR", 0x36);
    fieldtype_tTable.SetInteger("FIELD_HRENDERTEXTURE", 0x37);
    fieldtype_tTable.SetInteger("FIELD_HPARTICLESYSTEMDEFINITION", 0x38);
    fieldtype_tTable.SetInteger("FIELD_UINT8", 0x39);
    fieldtype_tTable.SetInteger("FIELD_UINT16", 0x3a);
    fieldtype_tTable.SetInteger("FIELD_CTRANSFORM", 0x3b);
    fieldtype_tTable.SetInteger("FIELD_CTRANSFORM_WORLDSPACE", 0x3c);
    fieldtype_tTable.SetInteger("FIELD_HPOSTPROCESSING", 0x3d);
    fieldtype_tTable.SetInteger("FIELD_MATRIX3X4", 0x3e);
    fieldtype_tTable.SetInteger("FIELD_SHIM", 0x3f);
    fieldtype_tTable.SetInteger("FIELD_CMOTIONTRANSFORM", 0x40);
    fieldtype_tTable.SetInteger("FIELD_CMOTIONTRANSFORM_WORLDSPACE", 0x41);
    fieldtype_tTable.SetInteger("FIELD_ATTACHMENT_HANDLE", 0x42);
    fieldtype_tTable.SetInteger("FIELD_AMMO_INDEX", 0x43);
    fieldtype_tTable.SetInteger("FIELD_CONDITION_ID", 0x44);
    fieldtype_tTable.SetInteger("FIELD_AI_SCHEDULE_BITS", 0x45);
    fieldtype_tTable.SetInteger("FIELD_MODIFIER_HANDLE", 0x46);
    fieldtype_tTable.SetInteger("FIELD_ROTATION_VECTOR", 0x47);
    fieldtype_tTable.SetInteger("FIELD_ROTATION_VECTOR_WORLDSPACE", 0x48);
    fieldtype_tTable.SetInteger("FIELD_HVDATA", 0x49);
    fieldtype_tTable.SetInteger("FIELD_SCALE32", 0x4a);
    fieldtype_tTable.SetInteger("FIELD_STRING_AND_TOKEN", 0x4b);
    fieldtype_tTable.SetInteger("FIELD_ENGINE_TIME", 0x4c);
    fieldtype_tTable.SetInteger("FIELD_ENGINE_TICK", 0x4d);
    fieldtype_tTable.SetInteger("FIELD_WORLD_GROUP_ID", 0x4e);
    fieldtype_tTable.SetInteger("FIELD_GLOBALSYMBOL", 0x4f);
    fieldtype_tTable.SetInteger("FIELD_TYPECOUNT", 0x50);


    auto IKTargetCoordinateSystemTable = state->CreateTable("IKTargetCoordinateSystem");
    IKTargetCoordinateSystemTable.SetInteger("IKTARGETCOORDINATESYSTEM_WorldSpace", 0x0);
    IKTargetCoordinateSystemTable.SetInteger("IKTARGETCOORDINATESYSTEM_ModelSpace", 0x1);
    IKTargetCoordinateSystemTable.SetInteger("IKTARGETCOORDINATESYSTEM_COUNT", 0x2);


    auto StandardLightingAttenuationStyle_tTable = state->CreateTable("StandardLightingAttenuationStyle_t");
    StandardLightingAttenuationStyle_tTable.SetInteger("LIGHT_STYLE_OLD", 0x0);
    StandardLightingAttenuationStyle_tTable.SetInteger("LIGHT_STYLE_NEW", 0x1);


    auto PoseType_tTable = state->CreateTable("PoseType_t");
    PoseType_tTable.SetInteger("POSETYPE_STATIC", 0x0);
    PoseType_tTable.SetInteger("POSETYPE_DYNAMIC", 0x1);
    PoseType_tTable.SetInteger("POSETYPE_INVALID", 0xff);


    auto FuseVariableType_tTable = state->CreateTable("FuseVariableType_t");
    FuseVariableType_tTable.SetInteger("INVALID", 0x0);
    FuseVariableType_tTable.SetInteger("BOOL", 0x1);
    FuseVariableType_tTable.SetInteger("INT8", 0x2);
    FuseVariableType_tTable.SetInteger("INT16", 0x3);
    FuseVariableType_tTable.SetInteger("INT32", 0x4);
    FuseVariableType_tTable.SetInteger("UINT8", 0x5);
    FuseVariableType_tTable.SetInteger("UINT16", 0x6);
    FuseVariableType_tTable.SetInteger("UINT32", 0x7);
    FuseVariableType_tTable.SetInteger("FLOAT32", 0x8);


    auto ParticleTraceSet_tTable = state->CreateTable("ParticleTraceSet_t");
    ParticleTraceSet_tTable.SetInteger("PARTICLE_TRACE_SET_ALL", 0x0);
    ParticleTraceSet_tTable.SetInteger("PARTICLE_TRACE_SET_STATIC", 0x1);
    ParticleTraceSet_tTable.SetInteger("PARTICLE_TRACE_SET_STATIC_AND_KEYFRAMED", 0x2);
    ParticleTraceSet_tTable.SetInteger("PARTICLE_TRACE_SET_DYNAMIC", 0x3);


    auto EntityIOTargetType_tTable = state->CreateTable("EntityIOTargetType_t");
    EntityIOTargetType_tTable.SetInteger("ENTITY_IO_TARGET_INVALID", 0xffffffffffffffff);
    EntityIOTargetType_tTable.SetInteger("ENTITY_IO_TARGET_ENTITYNAME", 0x2);
    EntityIOTargetType_tTable.SetInteger("ENTITY_IO_TARGET_EHANDLE", 0x6);
    EntityIOTargetType_tTable.SetInteger("ENTITY_IO_TARGET_ENTITYNAME_OR_CLASSNAME", 0x7);


    auto ModelSkeletonData_t__BoneFlags_tTable = state->CreateTable("ModelSkeletonData_t__BoneFlags_t");
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_NO_BONE_FLAGS", 0x0);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONEFLEXDRIVER", 0x4);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_CLOTH", 0x8);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_PHYSICS", 0x10);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_ATTACHMENT", 0x20);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_ANIMATION", 0x40);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_MESH", 0x80);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_HITBOX", 0x100);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD0", 0x400);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD1", 0x800);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD2", 0x1000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD3", 0x2000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD4", 0x4000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD5", 0x8000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD6", 0x10000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_USED_BY_VERTEX_LOD7", 0x20000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_MERGE_READ", 0x40000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_BONE_MERGE_WRITE", 0x80000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_ALL_BONE_FLAGS", 0xfffff);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("BLEND_PREALIGNED", 0x100000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_RIGIDLENGTH", 0x200000);
    ModelSkeletonData_t__BoneFlags_tTable.SetInteger("FLAG_PROCEDURAL", 0x400000);


    auto ParticleLightBehaviorChoiceList_tTable = state->CreateTable("ParticleLightBehaviorChoiceList_t");
    ParticleLightBehaviorChoiceList_tTable.SetInteger("PARTICLE_LIGHT_BEHAVIOR_FOLLOW_DIRECTION", 0x0);
    ParticleLightBehaviorChoiceList_tTable.SetInteger("PARTICLE_LIGHT_BEHAVIOR_ROPE", 0x1);
    ParticleLightBehaviorChoiceList_tTable.SetInteger("PARTICLE_LIGHT_BEHAVIOR_TRAILS", 0x2);


    auto CompositeMaterialInputContainerSourceType_tTable = state->CreateTable("CompositeMaterialInputContainerSourceType_t");
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_TARGET_MATERIAL", 0x0);
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_MATERIAL_FROM_TARGET_ATTR", 0x1);
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_SPECIFIC_MATERIAL", 0x2);
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_LOOSE_VARIABLES", 0x3);
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_VARIABLE_FROM_TARGET_ATTR", 0x4);
    CompositeMaterialInputContainerSourceType_tTable.SetInteger("CONTAINER_SOURCE_TYPE_TARGET_INSTANCE_MATERIAL", 0x5);


    auto ParticleSortingChoiceList_tTable = state->CreateTable("ParticleSortingChoiceList_t");
    ParticleSortingChoiceList_tTable.SetInteger("PARTICLE_SORTING_NEAREST", 0x0);
    ParticleSortingChoiceList_tTable.SetInteger("PARTICLE_SORTING_CREATION_TIME", 0x1);


    auto SosActionSortType_tTable = state->CreateTable("SosActionSortType_t");
    SosActionSortType_tTable.SetInteger("SOS_SORTTYPE_HIGHEST", 0x0);
    SosActionSortType_tTable.SetInteger("SOS_SORTTYPE_LOWEST", 0x1);


    auto ParticleFalloffFunction_tTable = state->CreateTable("ParticleFalloffFunction_t");
    ParticleFalloffFunction_tTable.SetInteger("PARTICLE_FALLOFF_CONSTANT", 0x0);
    ParticleFalloffFunction_tTable.SetInteger("PARTICLE_FALLOFF_LINEAR", 0x1);
    ParticleFalloffFunction_tTable.SetInteger("PARTICLE_FALLOFF_EXPONENTIAL", 0x2);


    auto JumpCorrectionMethodTable = state->CreateTable("JumpCorrectionMethod");
    JumpCorrectionMethodTable.SetInteger("ScaleMotion", 0x0);
    JumpCorrectionMethodTable.SetInteger("AddCorrectionDelta", 0x1);


    auto PetGroundType_tTable = state->CreateTable("PetGroundType_t");
    PetGroundType_tTable.SetInteger("PET_GROUND_NONE", 0x0);
    PetGroundType_tTable.SetInteger("PET_GROUND_GRID", 0x1);
    PetGroundType_tTable.SetInteger("PET_GROUND_PLANE", 0x2);


    auto VMixChannelOperation_tTable = state->CreateTable("VMixChannelOperation_t");
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_STEREO", 0x0);
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_LEFT", 0x1);
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_RIGHT", 0x2);
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_SWAP", 0x3);
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_MONO", 0x4);
    VMixChannelOperation_tTable.SetInteger("VMIX_CHAN_MID_SIDE", 0x5);


    auto MatterialAttributeTagType_tTable = state->CreateTable("MatterialAttributeTagType_t");
    MatterialAttributeTagType_tTable.SetInteger("MATERIAL_ATTRIBUTE_TAG_VALUE", 0x0);
    MatterialAttributeTagType_tTable.SetInteger("MATERIAL_ATTRIBUTE_TAG_COLOR", 0x1);


    auto ParticleDirectionNoiseType_tTable = state->CreateTable("ParticleDirectionNoiseType_t");
    ParticleDirectionNoiseType_tTable.SetInteger("PARTICLE_DIR_NOISE_PERLIN", 0x0);
    ParticleDirectionNoiseType_tTable.SetInteger("PARTICLE_DIR_NOISE_CURL", 0x1);
    ParticleDirectionNoiseType_tTable.SetInteger("PARTICLE_DIR_NOISE_WORLEY_BASIC", 0x2);


    auto InputLayoutVariation_tTable = state->CreateTable("InputLayoutVariation_t");
    InputLayoutVariation_tTable.SetInteger("INPUT_LAYOUT_VARIATION_DEFAULT", 0x0);
    InputLayoutVariation_tTable.SetInteger("INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID", 0x1);
    InputLayoutVariation_tTable.SetInteger("INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID_MORPH_VERT_ID", 0x2);
    InputLayoutVariation_tTable.SetInteger("INPUT_LAYOUT_VARIATION_MAX", 0x3);


    auto CAnimationGraphVisualizerPrimitiveTypeTable = state->CreateTable("CAnimationGraphVisualizerPrimitiveType");
    CAnimationGraphVisualizerPrimitiveTypeTable.SetInteger("ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Text", 0x0);
    CAnimationGraphVisualizerPrimitiveTypeTable.SetInteger("ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Sphere", 0x1);
    CAnimationGraphVisualizerPrimitiveTypeTable.SetInteger("ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Line", 0x2);
    CAnimationGraphVisualizerPrimitiveTypeTable.SetInteger("ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Pie", 0x3);
    CAnimationGraphVisualizerPrimitiveTypeTable.SetInteger("ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Axis", 0x4);


    auto BlendKeyTypeTable = state->CreateTable("BlendKeyType");
    BlendKeyTypeTable.SetInteger("BlendKey_UserValue", 0x0);
    BlendKeyTypeTable.SetInteger("BlendKey_Velocity", 0x1);
    BlendKeyTypeTable.SetInteger("BlendKey_Distance", 0x2);
    BlendKeyTypeTable.SetInteger("BlendKey_RemainingDistance", 0x3);


    auto ParticlePinDistance_tTable = state->CreateTable("ParticlePinDistance_t");
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_NONE", 0xffffffffffffffff);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_NEIGHBOR", 0x0);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_FARTHEST", 0x1);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_FIRST", 0x2);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_LAST", 0x3);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_CENTER", 0x5);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_CP", 0x6);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_CP_PAIR_EITHER", 0x7);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_DISTANCE_CP_PAIR_BOTH", 0x8);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_SPEED", 0x9);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_COLLECTION_AGE", 0xa);
    ParticlePinDistance_tTable.SetInteger("PARTICLE_PIN_FLOAT_VALUE", 0xb);


    auto SpriteCardTextureChannel_tTable = state->CreateTable("SpriteCardTextureChannel_t");
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGB", 0x0);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA", 0x1);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_A", 0x2);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A", 0x3);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_ALPHAMASK", 0x4);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_RGBMASK", 0x5);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA_RGBALPHA", 0x6);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_A_RGBALPHA", 0x7);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A_RGBALPHA", 0x8);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_R", 0x9);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_G", 0xa);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_B", 0xb);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_RALPHA", 0xc);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_GALPHA", 0xd);
    SpriteCardTextureChannel_tTable.SetInteger("SPRITECARD_TEXTURE_CHANNEL_MIX_BALPHA", 0xe);


    auto VertJustification_eTable = state->CreateTable("VertJustification_e");
    VertJustification_eTable.SetInteger("VERT_JUSTIFICATION_TOP", 0x0);
    VertJustification_eTable.SetInteger("VERT_JUSTIFICATION_CENTER", 0x1);
    VertJustification_eTable.SetInteger("VERT_JUSTIFICATION_BOTTOM", 0x2);
    VertJustification_eTable.SetInteger("VERT_JUSTIFICATION_NONE", 0x3);


    auto HorizJustification_eTable = state->CreateTable("HorizJustification_e");
    HorizJustification_eTable.SetInteger("HORIZ_JUSTIFICATION_LEFT", 0x0);
    HorizJustification_eTable.SetInteger("HORIZ_JUSTIFICATION_CENTER", 0x1);
    HorizJustification_eTable.SetInteger("HORIZ_JUSTIFICATION_RIGHT", 0x2);
    HorizJustification_eTable.SetInteger("HORIZ_JUSTIFICATION_NONE", 0x3);


    auto EDemoBoneSelectionModeTable = state->CreateTable("EDemoBoneSelectionMode");
    EDemoBoneSelectionModeTable.SetInteger("CaptureAllBones", 0x0);
    EDemoBoneSelectionModeTable.SetInteger("CaptureSelectedBones", 0x1);


    auto SeqPoseSetting_tTable = state->CreateTable("SeqPoseSetting_t");
    SeqPoseSetting_tTable.SetInteger("SEQ_POSE_SETTING_CONSTANT", 0x0);
    SeqPoseSetting_tTable.SetInteger("SEQ_POSE_SETTING_ROTATION", 0x1);
    SeqPoseSetting_tTable.SetInteger("SEQ_POSE_SETTING_POSITION", 0x2);
    SeqPoseSetting_tTable.SetInteger("SEQ_POSE_SETTING_VELOCITY", 0x3);


    auto MorphFlexControllerRemapType_tTable = state->CreateTable("MorphFlexControllerRemapType_t");
    MorphFlexControllerRemapType_tTable.SetInteger("MORPH_FLEXCONTROLLER_REMAP_PASSTHRU", 0x0);
    MorphFlexControllerRemapType_tTable.SetInteger("MORPH_FLEXCONTROLLER_REMAP_2WAY", 0x1);
    MorphFlexControllerRemapType_tTable.SetInteger("MORPH_FLEXCONTROLLER_REMAP_NWAY", 0x2);
    MorphFlexControllerRemapType_tTable.SetInteger("MORPH_FLEXCONTROLLER_REMAP_EYELID", 0x3);


    auto SpawnDebugOverrideState_tTable = state->CreateTable("SpawnDebugOverrideState_t");
    SpawnDebugOverrideState_tTable.SetInteger("SPAWN_DEBUG_OVERRIDE_NONE", 0x0);
    SpawnDebugOverrideState_tTable.SetInteger("SPAWN_DEBUG_OVERRIDE_FORCE_ENABLED", 0x1);
    SpawnDebugOverrideState_tTable.SetInteger("SPAWN_DEBUG_OVERRIDE_FORCE_DISABLED", 0x2);


    auto ParticleLightnintBranchBehavior_tTable = state->CreateTable("ParticleLightnintBranchBehavior_t");
    ParticleLightnintBranchBehavior_tTable.SetInteger("PARTICLE_LIGHTNING_BRANCH_CURRENT_DIR", 0x0);
    ParticleLightnintBranchBehavior_tTable.SetInteger("PARTICLE_LIGHTNING_BRANCH_ENDPOINT_DIR", 0x1);


    auto MorphBundleType_tTable = state->CreateTable("MorphBundleType_t");
    MorphBundleType_tTable.SetInteger("MORPH_BUNDLE_TYPE_NONE", 0x0);
    MorphBundleType_tTable.SetInteger("MORPH_BUNDLE_TYPE_POSITION_SPEED", 0x1);
    MorphBundleType_tTable.SetInteger("MORPH_BUNDLE_TYPE_NORMAL_WRINKLE", 0x2);
    MorphBundleType_tTable.SetInteger("MORPH_BUNDLE_TYPE_COUNT", 0x3);


    auto ParticleLightFogLightingMode_tTable = state->CreateTable("ParticleLightFogLightingMode_t");
    ParticleLightFogLightingMode_tTable.SetInteger("PARTICLE_LIGHT_FOG_LIGHTING_MODE_NONE", 0x0);
    ParticleLightFogLightingMode_tTable.SetInteger("PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC", 0x2);
    ParticleLightFogLightingMode_tTable.SetInteger("PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC_NOSHADOWS", 0x4);


    auto RenderBufferFlags_tTable = state->CreateTable("RenderBufferFlags_t");
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_USAGE_VERTEX_BUFFER", 0x1);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_USAGE_INDEX_BUFFER", 0x2);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_USAGE_SHADER_RESOURCE", 0x4);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_USAGE_UNORDERED_ACCESS", 0x8);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_BYTEADDRESS_BUFFER", 0x10);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_STRUCTURED_BUFFER", 0x20);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_APPEND_CONSUME_BUFFER", 0x40);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_UAV_COUNTER", 0x80);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_UAV_DRAW_INDIRECT_ARGS", 0x100);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_ACCELERATION_STRUCTURE", 0x200);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_SHADER_BINDING_TABLE", 0x400);
    RenderBufferFlags_tTable.SetInteger("RENDER_BUFFER_PER_FRAME_WRITE_ONCE", 0x800);


    auto ParticleDetailLevel_tTable = state->CreateTable("ParticleDetailLevel_t");
    ParticleDetailLevel_tTable.SetInteger("PARTICLEDETAIL_LOW", 0x0);
    ParticleDetailLevel_tTable.SetInteger("PARTICLEDETAIL_MEDIUM", 0x1);
    ParticleDetailLevel_tTable.SetInteger("PARTICLEDETAIL_HIGH", 0x2);
    ParticleDetailLevel_tTable.SetInteger("PARTICLEDETAIL_ULTRA", 0x3);


    auto FootstepLandedFootSoundType_tTable = state->CreateTable("FootstepLandedFootSoundType_t");
    FootstepLandedFootSoundType_tTable.SetInteger("FOOTSOUND_Left", 0x0);
    FootstepLandedFootSoundType_tTable.SetInteger("FOOTSOUND_Right", 0x1);
    FootstepLandedFootSoundType_tTable.SetInteger("FOOTSOUND_UseOverrideSound", 0x2);


    auto SosEditItemType_tTable = state->CreateTable("SosEditItemType_t");
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_SOUNDEVENTS", 0x0);
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_SOUNDEVENT", 0x1);
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_LIBRARYSTACKS", 0x2);
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_STACK", 0x3);
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_OPERATOR", 0x4);
    SosEditItemType_tTable.SetInteger("SOS_EDIT_ITEM_TYPE_FIELD", 0x5);


    auto SosActionStopType_tTable = state->CreateTable("SosActionStopType_t");
    SosActionStopType_tTable.SetInteger("SOS_STOPTYPE_NONE", 0x0);
    SosActionStopType_tTable.SetInteger("SOS_STOPTYPE_TIME", 0x1);
    SosActionStopType_tTable.SetInteger("SOS_STOPTYPE_OPVAR", 0x2);


    auto ModelBoneFlexComponent_tTable = state->CreateTable("ModelBoneFlexComponent_t");
    ModelBoneFlexComponent_tTable.SetInteger("MODEL_BONE_FLEX_INVALID", 0xffffffffffffffff);
    ModelBoneFlexComponent_tTable.SetInteger("MODEL_BONE_FLEX_TX", 0x0);
    ModelBoneFlexComponent_tTable.SetInteger("MODEL_BONE_FLEX_TY", 0x1);
    ModelBoneFlexComponent_tTable.SetInteger("MODEL_BONE_FLEX_TZ", 0x2);


    auto ParticleAttachment_tTable = state->CreateTable("ParticleAttachment_t");
    ParticleAttachment_tTable.SetInteger("PATTACH_INVALID", 0xffffffffffffffff);
    ParticleAttachment_tTable.SetInteger("PATTACH_ABSORIGIN", 0x0);
    ParticleAttachment_tTable.SetInteger("PATTACH_ABSORIGIN_FOLLOW", 0x1);
    ParticleAttachment_tTable.SetInteger("PATTACH_CUSTOMORIGIN", 0x2);
    ParticleAttachment_tTable.SetInteger("PATTACH_CUSTOMORIGIN_FOLLOW", 0x3);
    ParticleAttachment_tTable.SetInteger("PATTACH_POINT", 0x4);
    ParticleAttachment_tTable.SetInteger("PATTACH_POINT_FOLLOW", 0x5);
    ParticleAttachment_tTable.SetInteger("PATTACH_EYES_FOLLOW", 0x6);
    ParticleAttachment_tTable.SetInteger("PATTACH_OVERHEAD_FOLLOW", 0x7);
    ParticleAttachment_tTable.SetInteger("PATTACH_WORLDORIGIN", 0x8);
    ParticleAttachment_tTable.SetInteger("PATTACH_ROOTBONE_FOLLOW", 0x9);
    ParticleAttachment_tTable.SetInteger("PATTACH_RENDERORIGIN_FOLLOW", 0xa);
    ParticleAttachment_tTable.SetInteger("PATTACH_MAIN_VIEW", 0xb);
    ParticleAttachment_tTable.SetInteger("PATTACH_WATERWAKE", 0xc);
    ParticleAttachment_tTable.SetInteger("PATTACH_CENTER_FOLLOW", 0xd);
    ParticleAttachment_tTable.SetInteger("PATTACH_CUSTOM_GAME_STATE_1", 0xe);
    ParticleAttachment_tTable.SetInteger("PATTACH_HEALTHBAR", 0xf);
    ParticleAttachment_tTable.SetInteger("MAX_PATTACH_TYPES", 0x10);


    auto CompMatPropertyMutatorType_tTable = state->CreateTable("CompMatPropertyMutatorType_t");
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_INIT", 0x0);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_COPY_MATCHING_KEYS", 0x1);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_COPY_KEYS_WITH_SUFFIX", 0x2);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_COPY_PROPERTY", 0x3);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_SET_VALUE", 0x4);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_GENERATE_TEXTURE", 0x5);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_CONDITIONAL_MUTATORS", 0x6);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_POP_INPUT_QUEUE", 0x7);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_DRAW_TEXT", 0x8);
    CompMatPropertyMutatorType_tTable.SetInteger("COMP_MAT_PROPERTY_MUTATOR_RANDOM_ROLL_INPUT_VARIABLES", 0x9);


    auto ParticleOrientationChoiceList_tTable = state->CreateTable("ParticleOrientationChoiceList_t");
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_SCREEN_ALIGNED", 0x0);
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_SCREEN_Z_ALIGNED", 0x1);
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_WORLD_Z_ALIGNED", 0x2);
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_ALIGN_TO_PARTICLE_NORMAL", 0x3);
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_SCREENALIGN_TO_PARTICLE_NORMAL", 0x4);
    ParticleOrientationChoiceList_tTable.SetInteger("PARTICLE_ORIENTATION_FULL_3AXIS_ROTATION", 0x5);


    auto NmFrameSnapEventMode_tTable = state->CreateTable("NmFrameSnapEventMode_t");
    NmFrameSnapEventMode_tTable.SetInteger("Floor", 0x0);
    NmFrameSnapEventMode_tTable.SetInteger("Round", 0x1);


    auto JiggleBoneSimSpaceTable = state->CreateTable("JiggleBoneSimSpace");
    JiggleBoneSimSpaceTable.SetInteger("SimSpace_Local", 0x0);
    JiggleBoneSimSpaceTable.SetInteger("SimSpace_Model", 0x1);
    JiggleBoneSimSpaceTable.SetInteger("SimSpace_World", 0x2);


    auto ParticleTopology_tTable = state->CreateTable("ParticleTopology_t");
    ParticleTopology_tTable.SetInteger("PARTICLE_TOPOLOGY_POINTS", 0x0);
    ParticleTopology_tTable.SetInteger("PARTICLE_TOPOLOGY_LINES", 0x1);
    ParticleTopology_tTable.SetInteger("PARTICLE_TOPOLOGY_TRIS", 0x2);
    ParticleTopology_tTable.SetInteger("PARTICLE_TOPOLOGY_QUADS", 0x3);
    ParticleTopology_tTable.SetInteger("PARTICLE_TOPOLOGY_CUBES", 0x4);


    auto DampingSpeedFunctionTable = state->CreateTable("DampingSpeedFunction");
    DampingSpeedFunctionTable.SetInteger("NoDamping", 0x0);
    DampingSpeedFunctionTable.SetInteger("Constant", 0x1);
    DampingSpeedFunctionTable.SetInteger("Spring", 0x2);


    auto ParticleColorBlendType_tTable = state->CreateTable("ParticleColorBlendType_t");
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_MULTIPLY", 0x0);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_MULTIPLY2X", 0x1);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_DIVIDE", 0x2);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_ADD", 0x3);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_SUBTRACT", 0x4);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_MOD2X", 0x5);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_SCREEN", 0x6);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_MAX", 0x7);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_MIN", 0x8);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_REPLACE", 0x9);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_AVERAGE", 0xa);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_NEGATE", 0xb);
    ParticleColorBlendType_tTable.SetInteger("PARTICLE_COLOR_BLEND_LUMINANCE", 0xc);


    auto VMixSubgraphSwitchInterpolationType_tTable = state->CreateTable("VMixSubgraphSwitchInterpolationType_t");
    VMixSubgraphSwitchInterpolationType_tTable.SetInteger("SUBGRAPH_INTERPOLATION_TEMPORAL_CROSSFADE", 0x0);
    VMixSubgraphSwitchInterpolationType_tTable.SetInteger("SUBGRAPH_INTERPOLATION_TEMPORAL_FADE_OUT", 0x1);
    VMixSubgraphSwitchInterpolationType_tTable.SetInteger("SUBGRAPH_INTERPOLATION_KEEP_LAST_SUBGRAPH_RUNNING", 0x2);


    auto soundlevel_tTable = state->CreateTable("soundlevel_t");
    soundlevel_tTable.SetInteger("SNDLVL_NONE", 0x0);
    soundlevel_tTable.SetInteger("SNDLVL_20dB", 0x14);
    soundlevel_tTable.SetInteger("SNDLVL_25dB", 0x19);
    soundlevel_tTable.SetInteger("SNDLVL_30dB", 0x1e);
    soundlevel_tTable.SetInteger("SNDLVL_35dB", 0x23);
    soundlevel_tTable.SetInteger("SNDLVL_40dB", 0x28);
    soundlevel_tTable.SetInteger("SNDLVL_45dB", 0x2d);
    soundlevel_tTable.SetInteger("SNDLVL_50dB", 0x32);
    soundlevel_tTable.SetInteger("SNDLVL_55dB", 0x37);
    soundlevel_tTable.SetInteger("SNDLVL_IDLE", 0x3c);
    soundlevel_tTable.SetInteger("SNDLVL_60dB", 0x3c);
    soundlevel_tTable.SetInteger("SNDLVL_65dB", 0x41);
    soundlevel_tTable.SetInteger("SNDLVL_STATIC", 0x42);
    soundlevel_tTable.SetInteger("SNDLVL_70dB", 0x46);
    soundlevel_tTable.SetInteger("SNDLVL_NORM", 0x4b);
    soundlevel_tTable.SetInteger("SNDLVL_75dB", 0x4b);
    soundlevel_tTable.SetInteger("SNDLVL_80dB", 0x50);
    soundlevel_tTable.SetInteger("SNDLVL_TALKING", 0x50);
    soundlevel_tTable.SetInteger("SNDLVL_85dB", 0x55);
    soundlevel_tTable.SetInteger("SNDLVL_90dB", 0x5a);
    soundlevel_tTable.SetInteger("SNDLVL_95dB", 0x5f);
    soundlevel_tTable.SetInteger("SNDLVL_100dB", 0x64);
    soundlevel_tTable.SetInteger("SNDLVL_105dB", 0x69);
    soundlevel_tTable.SetInteger("SNDLVL_110dB", 0x6e);
    soundlevel_tTable.SetInteger("SNDLVL_120dB", 0x78);
    soundlevel_tTable.SetInteger("SNDLVL_130dB", 0x82);
    soundlevel_tTable.SetInteger("SNDLVL_GUNFIRE", 0x8c);
    soundlevel_tTable.SetInteger("SNDLVL_140dB", 0x8c);
    soundlevel_tTable.SetInteger("SNDLVL_150dB", 0x96);
    soundlevel_tTable.SetInteger("SNDLVL_180dB", 0xb4);


    auto AnimationSnapshotType_tTable = state->CreateTable("AnimationSnapshotType_t");
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_SERVER_SIMULATION", 0x0);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_CLIENT_SIMULATION", 0x1);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_CLIENT_PREDICTION", 0x2);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_CLIENT_INTERPOLATION", 0x3);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_CLIENT_RENDER", 0x4);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_FINAL_COMPOSITE", 0x5);
    AnimationSnapshotType_tTable.SetInteger("ANIMATION_SNAPSHOT_MAX", 0x6);


    auto SpriteCardPerParticleScale_tTable = state->CreateTable("SpriteCardPerParticleScale_t");
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_NONE", 0x0);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_AGE", 0x1);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_ANIMATION_FRAME", 0x2);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA1", 0x3);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA2", 0x4);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_ALPHA", 0x5);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_SHADER_RADIUS", 0x6);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_ROLL", 0x7);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_YAW", 0x8);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_PITCH", 0x9);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_RANDOM", 0xa);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM", 0xb);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_RANDOM_TIME", 0xc);
    SpriteCardPerParticleScale_tTable.SetInteger("SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM_TIME", 0xd);


    auto SpriteCardShaderType_tTable = state->CreateTable("SpriteCardShaderType_t");
    SpriteCardShaderType_tTable.SetInteger("SPRITECARD_SHADER_BASE", 0x0);
    SpriteCardShaderType_tTable.SetInteger("SPRITECARD_SHADER_CUSTOM", 0x1);


    auto BBoxVolumeType_tTable = state->CreateTable("BBoxVolumeType_t");
    BBoxVolumeType_tTable.SetInteger("BBOX_VOLUME", 0x0);
    BBoxVolumeType_tTable.SetInteger("BBOX_DIMENSIONS", 0x1);
    BBoxVolumeType_tTable.SetInteger("BBOX_MINS_MAXS", 0x2);


    auto PulseTestEnumColor_tTable = state->CreateTable("PulseTestEnumColor_t");
    PulseTestEnumColor_tTable.SetInteger("BLACK", 0x0);
    PulseTestEnumColor_tTable.SetInteger("WHITE", 0x1);
    PulseTestEnumColor_tTable.SetInteger("RED", 0x2);
    PulseTestEnumColor_tTable.SetInteger("GREEN", 0x3);
    PulseTestEnumColor_tTable.SetInteger("BLUE", 0x4);


    auto ParticleCollisionMode_tTable = state->CreateTable("ParticleCollisionMode_t");
    ParticleCollisionMode_tTable.SetInteger("COLLISION_MODE_PER_PARTICLE_TRACE", 0x3);
    ParticleCollisionMode_tTable.SetInteger("COLLISION_MODE_USE_NEAREST_TRACE", 0x2);
    ParticleCollisionMode_tTable.SetInteger("COLLISION_MODE_PER_FRAME_PLANESET", 0x1);
    ParticleCollisionMode_tTable.SetInteger("COLLISION_MODE_INITIAL_TRACE_DOWN", 0x0);
    ParticleCollisionMode_tTable.SetInteger("COLLISION_MODE_DISABLED", 0xffffffffffffffff);


    auto PermModelInfo_t__FlagEnumTable = state->CreateTable("PermModelInfo_t__FlagEnum");
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_TRANSLUCENT", 0x1);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_TRANSLUCENT_TWO_PASS", 0x2);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_MODEL_IS_RUNTIME_COMBINED", 0x4);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_SOURCE1_IMPORT", 0x8);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_MODEL_PART_CHILD", 0x10);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_NAV_GEN_NONE", 0x20);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_NAV_GEN_HULL", 0x40);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_NO_FORCED_FADE", 0x800);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_HAS_SKINNED_MESHES", 0x400);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_DO_NOT_CAST_SHADOWS", 0x20000);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_FORCE_PHONEME_CROSSFADE", 0x1000);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_NO_ANIM_EVENTS", 0x100000);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_ANIMATION_DRIVEN_FLEXES", 0x200000);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_IMPLICIT_BIND_POSE_SEQUENCE", 0x400000);
    PermModelInfo_t__FlagEnumTable.SetInteger("FLAG_MODEL_DOC", 0x800000);


    auto ParticleControlPointAxis_tTable = state->CreateTable("ParticleControlPointAxis_t");
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_X", 0x0);
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_Y", 0x1);
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_Z", 0x2);
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_NEGATIVE_X", 0x3);
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_NEGATIVE_Y", 0x4);
    ParticleControlPointAxis_tTable.SetInteger("PARTICLE_CP_AXIS_NEGATIVE_Z", 0x5);


    auto ELayoutNodeTypeTable = state->CreateTable("ELayoutNodeType");
    ELayoutNodeTypeTable.SetInteger("ROOT", 0x0);
    ELayoutNodeTypeTable.SetInteger("STYLES", 0x1);
    ELayoutNodeTypeTable.SetInteger("SCRIPT_BODY", 0x2);
    ELayoutNodeTypeTable.SetInteger("SCRIPTS", 0x3);
    ELayoutNodeTypeTable.SetInteger("SNIPPETS", 0x4);
    ELayoutNodeTypeTable.SetInteger("INCLUDE", 0x5);
    ELayoutNodeTypeTable.SetInteger("SNIPPET", 0x6);
    ELayoutNodeTypeTable.SetInteger("PANEL", 0x7);
    ELayoutNodeTypeTable.SetInteger("PANEL_ATTRIBUTE", 0x8);
    ELayoutNodeTypeTable.SetInteger("PANEL_ATTRIBUTE_VALUE", 0x9);
    ELayoutNodeTypeTable.SetInteger("REFERENCE_CONTENT", 0xa);
    ELayoutNodeTypeTable.SetInteger("REFERENCE_COMPILED", 0xb);
    ELayoutNodeTypeTable.SetInteger("REFERENCE_PASSTHROUGH", 0xc);


    auto IKChannelModeTable = state->CreateTable("IKChannelMode");
    IKChannelModeTable.SetInteger("TwoBone", 0x0);
    IKChannelModeTable.SetInteger("TwoBone_Translate", 0x1);
    IKChannelModeTable.SetInteger("OneBone", 0x2);
    IKChannelModeTable.SetInteger("OneBone_Translate", 0x3);


    auto PulseTestEnumShape_tTable = state->CreateTable("PulseTestEnumShape_t");
    PulseTestEnumShape_tTable.SetInteger("CIRCLE", 0x64);
    PulseTestEnumShape_tTable.SetInteger("SQUARE", 0xc8);
    PulseTestEnumShape_tTable.SetInteger("TRIANGLE", 0x12c);


    auto ParticleColorBlendMode_tTable = state->CreateTable("ParticleColorBlendMode_t");
    ParticleColorBlendMode_tTable.SetInteger("PARTICLEBLEND_DEFAULT", 0x0);
    ParticleColorBlendMode_tTable.SetInteger("PARTICLEBLEND_OVERLAY", 0x1);
    ParticleColorBlendMode_tTable.SetInteger("PARTICLEBLEND_DARKEN", 0x2);
    ParticleColorBlendMode_tTable.SetInteger("PARTICLEBLEND_LIGHTEN", 0x3);
    ParticleColorBlendMode_tTable.SetInteger("PARTICLEBLEND_MULTIPLY", 0x4);


    auto AnimParamType_tTable = state->CreateTable("AnimParamType_t");
    AnimParamType_tTable.SetInteger("ANIMPARAM_UNKNOWN", 0x0);
    AnimParamType_tTable.SetInteger("ANIMPARAM_BOOL", 0x1);
    AnimParamType_tTable.SetInteger("ANIMPARAM_ENUM", 0x2);
    AnimParamType_tTable.SetInteger("ANIMPARAM_INT", 0x3);
    AnimParamType_tTable.SetInteger("ANIMPARAM_FLOAT", 0x4);
    AnimParamType_tTable.SetInteger("ANIMPARAM_VECTOR", 0x5);
    AnimParamType_tTable.SetInteger("ANIMPARAM_QUATERNION", 0x6);
    AnimParamType_tTable.SetInteger("ANIMPARAM_GLOBALSYMBOL", 0x7);
    AnimParamType_tTable.SetInteger("ANIMPARAM_COUNT", 0x8);


    auto ParticleLightUnitChoiceList_tTable = state->CreateTable("ParticleLightUnitChoiceList_t");
    ParticleLightUnitChoiceList_tTable.SetInteger("PARTICLE_LIGHT_UNIT_CANDELAS", 0x0);
    ParticleLightUnitChoiceList_tTable.SetInteger("PARTICLE_LIGHT_UNIT_LUMENS", 0x1);


    auto VMixLFOShape_tTable = state->CreateTable("VMixLFOShape_t");
    VMixLFOShape_tTable.SetInteger("LFO_SHAPE_SINE", 0x0);
    VMixLFOShape_tTable.SetInteger("LFO_SHAPE_SQUARE", 0x1);
    VMixLFOShape_tTable.SetInteger("LFO_SHAPE_TRI", 0x2);
    VMixLFOShape_tTable.SetInteger("LFO_SHAPE_SAW", 0x3);
    VMixLFOShape_tTable.SetInteger("LFO_SHAPE_NOISE", 0x4);


    auto IkEndEffectorTypeTable = state->CreateTable("IkEndEffectorType");
    IkEndEffectorTypeTable.SetInteger("IkEndEffector_Attachment", 0x0);
    IkEndEffectorTypeTable.SetInteger("IkEndEffector_Bone", 0x1);


    auto EStyleNodeTypeTable = state->CreateTable("EStyleNodeType");
    EStyleNodeTypeTable.SetInteger("ROOT", 0x0);
    EStyleNodeTypeTable.SetInteger("EXPRESSION", 0x1);
    EStyleNodeTypeTable.SetInteger("PROPERTY", 0x2);
    EStyleNodeTypeTable.SetInteger("DEFINE", 0x3);
    EStyleNodeTypeTable.SetInteger("IMPORT", 0x4);
    EStyleNodeTypeTable.SetInteger("KEYFRAMES", 0x5);
    EStyleNodeTypeTable.SetInteger("KEYFRAME_SELECTOR", 0x6);
    EStyleNodeTypeTable.SetInteger("STYLE_SELECTOR", 0x7);
    EStyleNodeTypeTable.SetInteger("WHITESPACE", 0x8);
    EStyleNodeTypeTable.SetInteger("EXPRESSION_TEXT", 0x9);
    EStyleNodeTypeTable.SetInteger("EXPRESSION_URL", 0xa);
    EStyleNodeTypeTable.SetInteger("EXPRESSION_CONCAT", 0xb);
    EStyleNodeTypeTable.SetInteger("REFERENCE_CONTENT", 0xc);
    EStyleNodeTypeTable.SetInteger("REFERENCE_COMPILED", 0xd);
    EStyleNodeTypeTable.SetInteger("REFERENCE_PASSTHROUGH", 0xe);


    auto FieldNetworkOptionTable = state->CreateTable("FieldNetworkOption");
    FieldNetworkOptionTable.SetInteger("Auto", 0x0);
    FieldNetworkOptionTable.SetInteger("ForceEnable", 0x1);
    FieldNetworkOptionTable.SetInteger("ForceDisable", 0x2);


    auto VelocityMetricModeTable = state->CreateTable("VelocityMetricMode");
    VelocityMetricModeTable.SetInteger("DirectionOnly", 0x0);
    VelocityMetricModeTable.SetInteger("MagnitudeOnly", 0x1);
    VelocityMetricModeTable.SetInteger("DirectionAndMagnitude", 0x2);


    auto IkTargetTypeTable = state->CreateTable("IkTargetType");
    IkTargetTypeTable.SetInteger("IkTarget_Attachment", 0x0);
    IkTargetTypeTable.SetInteger("IkTarget_Bone", 0x1);
    IkTargetTypeTable.SetInteger("IkTarget_Parameter_ModelSpace", 0x2);
    IkTargetTypeTable.SetInteger("IkTarget_Parameter_WorldSpace", 0x3);


    auto FootPinningTimingSourceTable = state->CreateTable("FootPinningTimingSource");
    FootPinningTimingSourceTable.SetInteger("FootMotion", 0x0);
    FootPinningTimingSourceTable.SetInteger("Tag", 0x1);
    FootPinningTimingSourceTable.SetInteger("Parameter", 0x2);


    auto PFNoiseType_tTable = state->CreateTable("PFNoiseType_t");
    PFNoiseType_tTable.SetInteger("PF_NOISE_TYPE_PERLIN", 0x0);
    PFNoiseType_tTable.SetInteger("PF_NOISE_TYPE_SIMPLEX", 0x1);
    PFNoiseType_tTable.SetInteger("PF_NOISE_TYPE_WORLEY", 0x2);
    PFNoiseType_tTable.SetInteger("PF_NOISE_TYPE_CURL", 0x3);


    auto ParticleFloatBiasType_tTable = state->CreateTable("ParticleFloatBiasType_t");
    ParticleFloatBiasType_tTable.SetInteger("PF_BIAS_TYPE_INVALID", 0xffffffffffffffff);
    ParticleFloatBiasType_tTable.SetInteger("PF_BIAS_TYPE_STANDARD", 0x0);
    ParticleFloatBiasType_tTable.SetInteger("PF_BIAS_TYPE_GAIN", 0x1);
    ParticleFloatBiasType_tTable.SetInteger("PF_BIAS_TYPE_EXPONENTIAL", 0x2);
    ParticleFloatBiasType_tTable.SetInteger("PF_BIAS_TYPE_COUNT", 0x3);


    auto ParticleDepthFeatheringMode_tTable = state->CreateTable("ParticleDepthFeatheringMode_t");
    ParticleDepthFeatheringMode_tTable.SetInteger("PARTICLE_DEPTH_FEATHERING_OFF", 0x0);
    ParticleDepthFeatheringMode_tTable.SetInteger("PARTICLE_DEPTH_FEATHERING_ON_OPTIONAL", 0x1);
    ParticleDepthFeatheringMode_tTable.SetInteger("PARTICLE_DEPTH_FEATHERING_ON_REQUIRED", 0x2);


    auto ParticleSequenceCropOverride_tTable = state->CreateTable("ParticleSequenceCropOverride_t");
    ParticleSequenceCropOverride_tTable.SetInteger("PARTICLE_SEQUENCE_CROP_OVERRIDE_DEFAULT", 0xffffffffffffffff);
    ParticleSequenceCropOverride_tTable.SetInteger("PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_OFF", 0x0);
    ParticleSequenceCropOverride_tTable.SetInteger("PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_ON", 0x1);


    auto RenderSlotType_tTable = state->CreateTable("RenderSlotType_t");
    RenderSlotType_tTable.SetInteger("RENDER_SLOT_INVALID", 0xffffffffffffffff);
    RenderSlotType_tTable.SetInteger("RENDER_SLOT_PER_VERTEX", 0x0);
    RenderSlotType_tTable.SetInteger("RENDER_SLOT_PER_INSTANCE", 0x1);


    auto VPhysXConstraintParams_t__EnumFlags0_tTable = state->CreateTable("VPhysXConstraintParams_t__EnumFlags0_t");
    VPhysXConstraintParams_t__EnumFlags0_tTable.SetInteger("FLAG0_SHIFT_INTERPENETRATE", 0x0);
    VPhysXConstraintParams_t__EnumFlags0_tTable.SetInteger("FLAG0_SHIFT_CONSTRAIN", 0x1);
    VPhysXConstraintParams_t__EnumFlags0_tTable.SetInteger("FLAG0_SHIFT_BREAKABLE_FORCE", 0x2);
    VPhysXConstraintParams_t__EnumFlags0_tTable.SetInteger("FLAG0_SHIFT_BREAKABLE_TORQUE", 0x3);


    auto AnimValueSourceTable = state->CreateTable("AnimValueSource");
    AnimValueSourceTable.SetInteger("MoveHeading", 0x0);
    AnimValueSourceTable.SetInteger("MoveSpeed", 0x1);
    AnimValueSourceTable.SetInteger("ForwardSpeed", 0x2);
    AnimValueSourceTable.SetInteger("StrafeSpeed", 0x3);
    AnimValueSourceTable.SetInteger("FacingHeading", 0x4);
    AnimValueSourceTable.SetInteger("ManualFacingHeading", 0x5);
    AnimValueSourceTable.SetInteger("LookHeading", 0x6);
    AnimValueSourceTable.SetInteger("LookPitch", 0x7);
    AnimValueSourceTable.SetInteger("LookDistance", 0x8);
    AnimValueSourceTable.SetInteger("Parameter", 0x9);
    AnimValueSourceTable.SetInteger("WayPointHeading", 0xa);
    AnimValueSourceTable.SetInteger("WayPointDistance", 0xb);
    AnimValueSourceTable.SetInteger("BoundaryRadius", 0xc);
    AnimValueSourceTable.SetInteger("TargetMoveHeading", 0xd);
    AnimValueSourceTable.SetInteger("TargetMoveSpeed", 0xe);
    AnimValueSourceTable.SetInteger("AccelerationHeading", 0xf);
    AnimValueSourceTable.SetInteger("AccelerationSpeed", 0x10);
    AnimValueSourceTable.SetInteger("SlopeHeading", 0x11);
    AnimValueSourceTable.SetInteger("SlopeAngle", 0x12);
    AnimValueSourceTable.SetInteger("SlopePitch", 0x13);
    AnimValueSourceTable.SetInteger("SlopeYaw", 0x14);
    AnimValueSourceTable.SetInteger("GoalDistance", 0x15);
    AnimValueSourceTable.SetInteger("AccelerationLeftRight", 0x16);
    AnimValueSourceTable.SetInteger("AccelerationFrontBack", 0x17);
    AnimValueSourceTable.SetInteger("RootMotionSpeed", 0x18);
    AnimValueSourceTable.SetInteger("RootMotionTurnSpeed", 0x19);
    AnimValueSourceTable.SetInteger("MoveHeadingRelativeToLookHeading", 0x1a);
    AnimValueSourceTable.SetInteger("MaxMoveSpeed", 0x1b);
    AnimValueSourceTable.SetInteger("FingerCurl_Thumb", 0x1c);
    AnimValueSourceTable.SetInteger("FingerCurl_Index", 0x1d);
    AnimValueSourceTable.SetInteger("FingerCurl_Middle", 0x1e);
    AnimValueSourceTable.SetInteger("FingerCurl_Ring", 0x1f);
    AnimValueSourceTable.SetInteger("FingerCurl_Pinky", 0x20);
    AnimValueSourceTable.SetInteger("FingerSplay_Thumb_Index", 0x21);
    AnimValueSourceTable.SetInteger("FingerSplay_Index_Middle", 0x22);
    AnimValueSourceTable.SetInteger("FingerSplay_Middle_Ring", 0x23);
    AnimValueSourceTable.SetInteger("FingerSplay_Ring_Pinky", 0x24);


    auto HitboxLerpType_tTable = state->CreateTable("HitboxLerpType_t");
    HitboxLerpType_tTable.SetInteger("HITBOX_LERP_LIFETIME", 0x0);
    HitboxLerpType_tTable.SetInteger("HITBOX_LERP_CONSTANT", 0x1);


    auto BoneTransformSpace_tTable = state->CreateTable("BoneTransformSpace_t");
    BoneTransformSpace_tTable.SetInteger("BoneTransformSpace_Invalid", 0xffffffffffffffff);
    BoneTransformSpace_tTable.SetInteger("BoneTransformSpace_Parent", 0x0);
    BoneTransformSpace_tTable.SetInteger("BoneTransformSpace_Model", 0x1);
    BoneTransformSpace_tTable.SetInteger("BoneTransformSpace_World", 0x2);


    auto VPhysXBodyPart_t__VPhysXFlagEnum_tTable = state->CreateTable("VPhysXBodyPart_t__VPhysXFlagEnum_t");
    VPhysXBodyPart_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_STATIC", 0x1);
    VPhysXBodyPart_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_KINEMATIC", 0x2);
    VPhysXBodyPart_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_JOINT", 0x4);
    VPhysXBodyPart_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_MASS", 0x8);
    VPhysXBodyPart_t__VPhysXFlagEnum_tTable.SetInteger("FLAG_ALWAYS_DYNAMIC_ON_CLIENT", 0x10);


    auto EntityDormancyType_tTable = state->CreateTable("EntityDormancyType_t");
    EntityDormancyType_tTable.SetInteger("ENTITY_NOT_DORMANT", 0x0);
    EntityDormancyType_tTable.SetInteger("ENTITY_DORMANT", 0x1);
    EntityDormancyType_tTable.SetInteger("ENTITY_SUSPENDED", 0x2);


    auto ParticleTraceMissBehavior_tTable = state->CreateTable("ParticleTraceMissBehavior_t");
    ParticleTraceMissBehavior_tTable.SetInteger("PARTICLE_TRACE_MISS_BEHAVIOR_NONE", 0x0);
    ParticleTraceMissBehavior_tTable.SetInteger("PARTICLE_TRACE_MISS_BEHAVIOR_KILL", 0x1);
    ParticleTraceMissBehavior_tTable.SetInteger("PARTICLE_TRACE_MISS_BEHAVIOR_TRACE_END", 0x2);


    auto NmFootPhase_tTable = state->CreateTable("NmFootPhase_t");
    NmFootPhase_tTable.SetInteger("LeftFootDown", 0x0);
    NmFootPhase_tTable.SetInteger("RightFootPassing", 0x1);
    NmFootPhase_tTable.SetInteger("RightFootDown", 0x2);
    NmFootPhase_tTable.SetInteger("LeftFootPassing", 0x3);


    auto ParticleOmni2LightTypeChoiceList_tTable = state->CreateTable("ParticleOmni2LightTypeChoiceList_t");
    ParticleOmni2LightTypeChoiceList_tTable.SetInteger("PARTICLE_OMNI2_LIGHT_TYPE_POINT", 0x0);
    ParticleOmni2LightTypeChoiceList_tTable.SetInteger("PARTICLE_OMNI2_LIGHT_TYPE_SPHERE", 0x1);


    auto BinaryNodeTimingTable = state->CreateTable("BinaryNodeTiming");
    BinaryNodeTimingTable.SetInteger("UseChild1", 0x0);
    BinaryNodeTimingTable.SetInteger("UseChild2", 0x1);
    BinaryNodeTimingTable.SetInteger("SyncChildren", 0x2);


    auto StepPhaseTable = state->CreateTable("StepPhase");
    StepPhaseTable.SetInteger("StepPhase_OnGround", 0x0);
    StepPhaseTable.SetInteger("StepPhase_InAir", 0x1);


    auto ScalarExpressionType_tTable = state->CreateTable("ScalarExpressionType_t");
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_UNINITIALIZED", 0xffffffffffffffff);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_ADD", 0x0);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_SUBTRACT", 0x1);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_MUL", 0x2);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_DIVIDE", 0x3);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_INPUT_1", 0x4);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_MIN", 0x5);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_MAX", 0x6);
    ScalarExpressionType_tTable.SetInteger("SCALAR_EXPRESSION_MOD", 0x7);


    auto ResetCycleOptionTable = state->CreateTable("ResetCycleOption");
    ResetCycleOptionTable.SetInteger("Beginning", 0x0);
    ResetCycleOptionTable.SetInteger("SameCycleAsSource", 0x1);
    ResetCycleOptionTable.SetInteger("InverseSourceCycle", 0x2);
    ResetCycleOptionTable.SetInteger("FixedValue", 0x3);
    ResetCycleOptionTable.SetInteger("SameTimeAsSource", 0x4);


    auto ModelConfigAttachmentType_tTable = state->CreateTable("ModelConfigAttachmentType_t");
    ModelConfigAttachmentType_tTable.SetInteger("MODEL_CONFIG_ATTACHMENT_INVALID", 0xffffffffffffffff);
    ModelConfigAttachmentType_tTable.SetInteger("MODEL_CONFIG_ATTACHMENT_BONE_OR_ATTACHMENT", 0x0);
    ModelConfigAttachmentType_tTable.SetInteger("MODEL_CONFIG_ATTACHMENT_ROOT_RELATIVE", 0x1);
    ModelConfigAttachmentType_tTable.SetInteger("MODEL_CONFIG_ATTACHMENT_BONEMERGE", 0x2);
    ModelConfigAttachmentType_tTable.SetInteger("MODEL_CONFIG_ATTACHMENT_COUNT", 0x3);


    auto ActionType_tTable = state->CreateTable("ActionType_t");
    ActionType_tTable.SetInteger("SOS_ACTION_NONE", 0x0);
    ActionType_tTable.SetInteger("SOS_ACTION_LIMITER", 0x1);
    ActionType_tTable.SetInteger("SOS_ACTION_TIME_LIMIT", 0x2);
    ActionType_tTable.SetInteger("SOS_ACTION_TIME_BLOCK_LIMITER", 0x3);
    ActionType_tTable.SetInteger("SOS_ACTION_SET_SOUNDEVENT_PARAM", 0x4);
    ActionType_tTable.SetInteger("SOS_ACTION_SOUNDEVENT_CLUSTER", 0x5);


    auto MoodType_tTable = state->CreateTable("MoodType_t");
    MoodType_tTable.SetInteger("eMoodType_Head", 0x0);
    MoodType_tTable.SetInteger("eMoodType_Body", 0x1);


    auto ParticleEndcapMode_tTable = state->CreateTable("ParticleEndcapMode_t");
    ParticleEndcapMode_tTable.SetInteger("PARTICLE_ENDCAP_ALWAYS_ON", 0xffffffffffffffff);
    ParticleEndcapMode_tTable.SetInteger("PARTICLE_ENDCAP_ENDCAP_OFF", 0x0);
    ParticleEndcapMode_tTable.SetInteger("PARTICLE_ENDCAP_ENDCAP_ON", 0x1);


    auto FootFallTagFoot_tTable = state->CreateTable("FootFallTagFoot_t");
    FootFallTagFoot_tTable.SetInteger("FOOT1", 0x0);
    FootFallTagFoot_tTable.SetInteger("FOOT2", 0x1);
    FootFallTagFoot_tTable.SetInteger("FOOT3", 0x2);
    FootFallTagFoot_tTable.SetInteger("FOOT4", 0x3);
    FootFallTagFoot_tTable.SetInteger("FOOT5", 0x4);
    FootFallTagFoot_tTable.SetInteger("FOOT6", 0x5);
    FootFallTagFoot_tTable.SetInteger("FOOT7", 0x6);
    FootFallTagFoot_tTable.SetInteger("FOOT8", 0x7);


    auto IKTargetSourceTable = state->CreateTable("IKTargetSource");
    IKTargetSourceTable.SetInteger("IKTARGETSOURCE_Bone", 0x0);
    IKTargetSourceTable.SetInteger("IKTARGETSOURCE_AnimgraphParameter", 0x1);
    IKTargetSourceTable.SetInteger("IKTARGETSOURCE_COUNT", 0x2);


    auto ClosestPointTestType_tTable = state->CreateTable("ClosestPointTestType_t");
    ClosestPointTestType_tTable.SetInteger("PARTICLE_CLOSEST_TYPE_BOX", 0x0);
    ClosestPointTestType_tTable.SetInteger("PARTICLE_CLOSEST_TYPE_CAPSULE", 0x1);
    ClosestPointTestType_tTable.SetInteger("PARTICLE_CLOSEST_TYPE_HYBRID", 0x2);


}