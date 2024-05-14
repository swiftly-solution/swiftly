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
}