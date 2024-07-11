#ifndef _g_enums_h
#define _g_enums_h

enum class CLogicBranchList__LogicBranchListenerLastState_t : uint64_t
{
    LOGIC_BRANCH_LISTENER_NOT_INIT = 0x0,
    LOGIC_BRANCH_LISTENER_ALL_TRUE = 0x1,
    LOGIC_BRANCH_LISTENER_ALL_FALSE = 0x2,
    LOGIC_BRANCH_LISTENER_MIXED = 0x3,
};

enum class CFuncMover__Move_t : uint64_t
{
    MOVE_LOOP = 0x0,
    MOVE_OSCILLATE = 0x1,
    MOVE_STOP_AT_END = 0x2,
};

enum class PropDoorRotatingOpenDirection_e : uint64_t
{
    DOOR_ROTATING_OPEN_BOTH_WAYS = 0x0,
    DOOR_ROTATING_OPEN_FORWARD = 0x1,
    DOOR_ROTATING_OPEN_BACKWARD = 0x2,
};

enum class SceneOnPlayerDeath_t : uint64_t
{
    SCENE_ONPLAYERDEATH_DO_NOTHING = 0x0,
    SCENE_ONPLAYERDEATH_CANCEL = 0x1,
};

enum class LessonPanelLayoutFileTypes_t : uint64_t
{
    LAYOUT_HAND_DEFAULT = 0x0,
    LAYOUT_WORLD_DEFAULT = 0x1,
    LAYOUT_CUSTOM = 0x2,
};

enum class TimelineCompression_t : uint64_t
{
    TIMELINE_COMPRESSION_SUM = 0x0,
    TIMELINE_COMPRESSION_COUNT_PER_INTERVAL = 0x1,
    TIMELINE_COMPRESSION_AVERAGE = 0x2,
    TIMELINE_COMPRESSION_AVERAGE_BLEND = 0x3,
    TIMELINE_COMPRESSION_TOTAL = 0x4,
};

enum class SubclassVDataChangeType_t : uint64_t
{
    SUBCLASS_VDATA_CREATED = 0x0,
    SUBCLASS_VDATA_SUBCLASS_CHANGED = 0x1,
    SUBCLASS_VDATA_RELOADED = 0x2,
};

enum class C4LightEffect_t : uint64_t
{
    eLightEffectNone = 0x0,
    eLightEffectDropped = 0x1,
    eLightEffectThirdPersonHeld = 0x2,
};

enum class StanceType_t : uint64_t
{
    STANCE_CURRENT = 0xffffffffffffffff,
    STANCE_DEFAULT = 0x0,
    STANCE_CROUCHING = 0x1,
    STANCE_PRONE = 0x2,
    NUM_STANCES = 0x3,
};

enum class Explosions : uint64_t
{
    expRandom = 0x0,
    expDirected = 0x1,
    expUsePrecise = 0x2,
};

enum class PreviewCharacterMode : uint64_t
{
    DIORAMA = 0x0,
    MAIN_MENU = 0x1,
    BUY_MENU = 0x2,
    TEAM_SELECT = 0x3,
    END_OF_MATCH = 0x4,
    INVENTORY_INSPECT = 0x5,
    WALKING = 0x6,
    TEAM_INTRO = 0x7,
    WINGMAN_INTRO = 0x8,
};

enum class ObserverInterpState_t : uint64_t
{
    OBSERVER_INTERP_NONE = 0x0,
    OBSERVER_INTERP_TRAVELING = 0x1,
    OBSERVER_INTERP_SETTLING = 0x2,
};

enum class WorldTextPanelOrientation_t : uint64_t
{
    WORLDTEXT_ORIENTATION_DEFAULT = 0x0,
    WORLDTEXT_ORIENTATION_FACEUSER = 0x1,
    WORLDTEXT_ORIENTATION_FACEUSER_UPRIGHT = 0x2,
};

enum class WorldTextPanelHorizontalAlign_t : uint64_t
{
    WORLDTEXT_HORIZONTAL_ALIGN_LEFT = 0x0,
    WORLDTEXT_HORIZONTAL_ALIGN_CENTER = 0x1,
    WORLDTEXT_HORIZONTAL_ALIGN_RIGHT = 0x2,
};

enum class SequenceFinishNotifyState_t : uint64_t
{
    eDoNotNotify = 0x0,
    eNotifyWhenFinished = 0x1,
    eNotifyTriggered = 0x2,
};

enum class SoundEventStartType_t : uint64_t
{
    SOUNDEVENT_START_PLAYER = 0x0,
    SOUNDEVENT_START_WORLD = 0x1,
    SOUNDEVENT_START_ENTITY = 0x2,
};

enum class TrainOrientationType_t : uint64_t
{
    TrainOrientation_Fixed = 0x0,
    TrainOrientation_AtPathTracks = 0x1,
    TrainOrientation_LinearBlend = 0x2,
    TrainOrientation_EaseInEaseOut = 0x3,
};

enum class CSWeaponCategory : uint64_t
{
    WEAPONCATEGORY_OTHER = 0x0,
    WEAPONCATEGORY_MELEE = 0x1,
    WEAPONCATEGORY_SECONDARY = 0x2,
    WEAPONCATEGORY_SMG = 0x3,
    WEAPONCATEGORY_RIFLE = 0x4,
    WEAPONCATEGORY_HEAVY = 0x5,
    WEAPONCATEGORY_COUNT = 0x6,
};

enum class BeginDeathLifeStateTransition_t : uint64_t
{
    NO_CHANGE_IN_LIFESTATE = 0x0,
    TRANSITION_TO_LIFESTATE_DYING = 0x1,
    TRANSITION_TO_LIFESTATE_DEAD = 0x2,
};

enum class SoundTypes_t : uint64_t
{
    SOUND_NONE = 0x0,
    SOUND_COMBAT = 0x1,
    SOUND_PLAYER = 0x2,
    SOUND_DANGER = 0x3,
    SOUND_BULLET_IMPACT = 0x4,
    SOUND_THUMPER = 0x5,
    SOUND_PHYSICS_DANGER = 0x6,
    SOUND_MOVE_AWAY = 0x7,
    SOUND_PLAYER_VEHICLE = 0x8,
    SOUND_GLASS_BREAK = 0x9,
    SOUND_PHYSICS_OBJECT = 0xa,
    NUM_AI_SOUND_TYPES = 0xb,
};

enum class PlayerAnimEvent_t : uint64_t
{
    PLAYERANIMEVENT_FIRE_GUN_PRIMARY = 0x0,
    PLAYERANIMEVENT_FIRE_GUN_SECONDARY = 0x1,
    PLAYERANIMEVENT_GRENADE_PULL_PIN = 0x2,
    PLAYERANIMEVENT_THROW_GRENADE = 0x3,
    PLAYERANIMEVENT_JUMP = 0x4,
    PLAYERANIMEVENT_RELOAD = 0x5,
    PLAYERANIMEVENT_CLEAR_FIRING = 0x6,
    PLAYERANIMEVENT_DEPLOY = 0x7,
    PLAYERANIMEVENT_SILENCER_STATE = 0x8,
    PLAYERANIMEVENT_SILENCER_TOGGLE = 0x9,
    PLAYERANIMEVENT_THROW_GRENADE_UNDERHAND = 0xa,
    PLAYERANIMEVENT_CATCH_WEAPON = 0xb,
    PLAYERANIMEVENT_LOOKATWEAPON_REQUEST = 0xc,
    PLAYERANIMEVENT_RELOAD_CANCEL_LOOKATWEAPON = 0xd,
    PLAYERANIMEVENT_HAULBACK = 0xe,
    PLAYERANIMEVENT_IDLE = 0xf,
    PLAYERANIMEVENT_STRIKE_HIT = 0x10,
    PLAYERANIMEVENT_STRIKE_MISS = 0x11,
    PLAYERANIMEVENT_BACKSTAB = 0x12,
    PLAYERANIMEVENT_DRYFIRE = 0x13,
    PLAYERANIMEVENT_FIDGET = 0x14,
    PLAYERANIMEVENT_RELEASE = 0x15,
    PLAYERANIMEVENT_TAUNT = 0x16,
    PLAYERANIMEVENT_COUNT = 0x17,
};

enum class ItemFlagTypes_t : uint64_t
{
    ITEM_FLAG_NONE = 0x0,
    ITEM_FLAG_CAN_SELECT_WITHOUT_AMMO = 0x1,
    ITEM_FLAG_NOAUTORELOAD = 0x2,
    ITEM_FLAG_NOAUTOSWITCHEMPTY = 0x4,
    ITEM_FLAG_LIMITINWORLD = 0x8,
    ITEM_FLAG_EXHAUSTIBLE = 0x10,
    ITEM_FLAG_DOHITLOCATIONDMG = 0x20,
    ITEM_FLAG_NOAMMOPICKUPS = 0x40,
    ITEM_FLAG_NOITEMPICKUP = 0x80,
};

enum class ShatterPanelMode : uint64_t
{
    SHATTER_GLASS = 0x0,
    SHATTER_DRYWALL = 0x1,
};

enum class SurroundingBoundsType_t : uint64_t
{
    USE_OBB_COLLISION_BOUNDS = 0x0,
    USE_BEST_COLLISION_BOUNDS = 0x1,
    USE_HITBOXES = 0x2,
    USE_SPECIFIED_BOUNDS = 0x3,
    USE_GAME_CODE = 0x4,
    USE_ROTATION_EXPANDED_BOUNDS = 0x5,
    USE_ROTATION_EXPANDED_ORIENTED_BOUNDS = 0x6,
    USE_COLLISION_BOUNDS_NEVER_VPHYSICS = 0x7,
    USE_ROTATION_EXPANDED_SEQUENCE_BOUNDS = 0x8,
    SURROUNDING_TYPE_BIT_COUNT = 0x3,
};

enum class NPCFollowFormation_t : uint64_t
{
    Default = 0xffffffffffffffff,
    CloseCircle = 0x0,
    WideCircle = 0x1,
    MediumCircle = 0x5,
    Sidekick = 0x6,
};

enum class CSWeaponMode : uint64_t
{
    Primary_Mode = 0x0,
    Secondary_Mode = 0x1,
    WeaponMode_MAX = 0x2,
};

enum class OnFrame : uint64_t
{
    ONFRAME_UNKNOWN = 0x0,
    ONFRAME_TRUE = 0x1,
    ONFRAME_FALSE = 0x2,
};

enum class Materials : uint64_t
{
    matGlass = 0x0,
    matWood = 0x1,
    matMetal = 0x2,
    matFlesh = 0x3,
    matCinderBlock = 0x4,
    matCeilingTile = 0x5,
    matComputer = 0x6,
    matUnbreakableGlass = 0x7,
    matRocks = 0x8,
    matWeb = 0x9,
    matNone = 0xa,
    matLastMaterial = 0xb,
};

enum class BloodType : uint64_t
{
    None = 0xffffffffffffffff,
    ColorRed = 0x0,
    ColorYellow = 0x1,
    ColorGreen = 0x2,
    ColorRedLVL2 = 0x3,
    ColorRedLVL3 = 0x4,
    ColorRedLVL4 = 0x5,
    ColorRedLVL5 = 0x6,
    ColorRedLVL6 = 0x7,
};

enum class ScriptedMoveTo_t : uint64_t
{
    eWait = 0x0,
    eMoveWithGait = 0x3,
    eTeleport = 0x4,
    eWaitFacing = 0x5,
    eObsoleteBackCompat1 = 0x1,
    eObsoleteBackCompat2 = 0x2,
};

enum class AnimLoopMode_t : uint64_t
{
    ANIM_LOOP_MODE_INVALID = 0xffffffffffffffff,
    ANIM_LOOP_MODE_NOT_LOOPING = 0x0,
    ANIM_LOOP_MODE_LOOPING = 0x1,
    ANIM_LOOP_MODE_USE_SEQUENCE_SETTINGS = 0x2,
    ANIM_LOOP_MODE_COUNT = 0x3,
};

enum class Class_T : uint64_t
{
    CLASS_NONE = 0x0,
    CLASS_PLAYER = 0x1,
    CLASS_PLAYER_ALLY = 0x2,
    CLASS_BOMB = 0x3,
    CLASS_FOOT_CONTACT_SHADOW = 0x4,
    CLASS_WEAPON = 0x5,
    CLASS_WATER_SPLASHER = 0x6,
    CLASS_WEAPON_VIEWMODEL = 0x7,
    CLASS_DOOR = 0x8,
    NUM_CLASSIFY_CLASSES = 0x9,
};

enum class filter_t : uint64_t
{
    FILTER_AND = 0x0,
    FILTER_OR = 0x1,
};

enum class CSWeaponSilencerType : uint64_t
{
    WEAPONSILENCER_NONE = 0x0,
    WEAPONSILENCER_DETACHABLE = 0x1,
    WEAPONSILENCER_INTEGRATED = 0x2,
};

enum class BaseExplosionTypes_t : uint64_t
{
    EXPLOSION_TYPE_DEFAULT = 0x0,
    EXPLOSION_TYPE_GRENADE = 0x1,
    EXPLOSION_TYPE_MOLOTOV = 0x2,
    EXPLOSION_TYPE_FIREWORKS = 0x3,
    EXPLOSION_TYPE_GASCAN = 0x4,
    EXPLOSION_TYPE_GASCYLINDER = 0x5,
    EXPLOSION_TYPE_EXPLOSIVEBARREL = 0x6,
    EXPLOSION_TYPE_ELECTRICAL = 0x7,
    EXPLOSION_TYPE_EMP = 0x8,
    EXPLOSION_TYPE_SHRAPNEL = 0x9,
    EXPLOSION_TYPE_SMOKEGRENADE = 0xa,
    EXPLOSION_TYPE_FLASHBANG = 0xb,
    EXPLOSION_TYPE_TRIPMINE = 0xc,
    EXPLOSION_TYPE_ICE = 0xd,
    EXPLOSION_TYPE_NONE = 0xe,
    EXPLOSION_TYPE_CUSTOM = 0xf,
    EXPLOSION_TYPE_COUNT = 0x10,
};

enum class GameAnimEventIndex_t : uint64_t
{
    AE_EMPTY = 0x0,
    AE_CL_PLAYSOUND = 0x1,
    AE_CL_PLAYSOUND_ATTACHMENT = 0x2,
    AE_CL_PLAYSOUND_POSITION = 0x3,
    AE_SV_PLAYSOUND = 0x4,
    AE_CL_STOPSOUND = 0x5,
    AE_CL_PLAYSOUND_LOOPING = 0x6,
    AE_CL_CREATE_PARTICLE_EFFECT = 0x7,
    AE_CL_STOP_PARTICLE_EFFECT = 0x8,
    AE_CL_CREATE_PARTICLE_EFFECT_CFG = 0x9,
    AE_SV_CREATE_PARTICLE_EFFECT_CFG = 0xa,
    AE_SV_STOP_PARTICLE_EFFECT = 0xb,
    AE_FOOTSTEP = 0xc,
    AE_RAGDOLL = 0xd,
    AE_CL_STOP_RAGDOLL_CONTROL = 0xe,
    AE_CL_ENABLE_BODYGROUP = 0xf,
    AE_CL_DISABLE_BODYGROUP = 0x10,
    AE_BODYGROUP_SET_VALUE = 0x11,
    AE_CL_BODYGROUP_SET_VALUE_CMODEL_WPN = 0x12,
    AE_WEAPON_PERFORM_ATTACK = 0x13,
    AE_FIRE_INPUT = 0x14,
    AE_CL_CLOTH_ATTR = 0x15,
    AE_CL_CLOTH_GROUND_OFFSET = 0x16,
    AE_CL_CLOTH_STIFFEN = 0x17,
    AE_CL_CLOTH_EFFECT = 0x18,
    AE_CL_CREATE_ANIM_SCOPE_PROP = 0x19,
    AE_SV_IKLOCK = 0x1a,
    AE_PULSE_GRAPH = 0x1b,
    AE_PULSE_GRAPH_LOOKAT = 0x1c,
    AE_PULSE_GRAPH_AIMAT = 0x1d,
    AE_PULSE_GRAPH_IKLOCKLEFTARM = 0x1e,
    AE_PULSE_GRAPH_IKLOCKRIGHTARM = 0x1f,
    AE_CL_WEAPON_TRANSITION_INTO_HAND = 0x20,
    AE_CL_BODYGROUP_SET_TO_CLIP = 0x21,
    AE_CL_BODYGROUP_SET_TO_NEXTCLIP = 0x22,
    AE_SV_SHOW_SILENCER = 0x23,
    AE_SV_ATTACH_SILENCER_COMPLETE = 0x24,
    AE_SV_HIDE_SILENCER = 0x25,
    AE_SV_DETACH_SILENCER_COMPLETE = 0x26,
    AE_CL_EJECT_MAG = 0x27,
    AE_WPN_COMPLETE_RELOAD = 0x28,
    AE_WPN_HEALTHSHOT_INJECT = 0x29,
    AE_CL_C4_SCREEN_TEXT = 0x2a,
    AE_GRENADE_THROW_COMPLETE = 0x2b,
};

enum class FixAngleSet_t : uint64_t
{
    None = 0x0,
    Absolute = 0x1,
    Relative = 0x2,
};

enum class IChoreoServices__ScriptState_t : uint64_t
{
    SCRIPT_PLAYING = 0x0,
    SCRIPT_WAIT = 0x1,
    SCRIPT_POST_IDLE = 0x2,
    SCRIPT_CLEANUP = 0x3,
    SCRIPT_MOVE_TO_MARK = 0x4,
};

enum class CommandEntitySpecType_t : uint64_t
{
    SPEC_SEARCH = 0x0,
    SPEC_TYPES_COUNT = 0x1,
};

enum class Touch_t : uint64_t
{
    touch_none = 0x0,
    touch_player_only = 0x1,
    touch_npc_only = 0x2,
    touch_player_or_npc = 0x3,
    touch_player_or_npc_or_physicsprop = 0x4,
};

enum class TrainVelocityType_t : uint64_t
{
    TrainVelocity_Instantaneous = 0x0,
    TrainVelocity_LinearBlend = 0x1,
    TrainVelocity_EaseInEaseOut = 0x2,
};

enum class CSWeaponType : uint64_t
{
    WEAPONTYPE_KNIFE = 0x0,
    WEAPONTYPE_PISTOL = 0x1,
    WEAPONTYPE_SUBMACHINEGUN = 0x2,
    WEAPONTYPE_RIFLE = 0x3,
    WEAPONTYPE_SHOTGUN = 0x4,
    WEAPONTYPE_SNIPER_RIFLE = 0x5,
    WEAPONTYPE_MACHINEGUN = 0x6,
    WEAPONTYPE_C4 = 0x7,
    WEAPONTYPE_TASER = 0x8,
    WEAPONTYPE_GRENADE = 0x9,
    WEAPONTYPE_EQUIPMENT = 0xa,
    WEAPONTYPE_STACKABLEITEM = 0xb,
    WEAPONTYPE_FISTS = 0xc,
    WEAPONTYPE_BREACHCHARGE = 0xd,
    WEAPONTYPE_BUMPMINE = 0xe,
    WEAPONTYPE_TABLET = 0xf,
    WEAPONTYPE_MELEE = 0x10,
    WEAPONTYPE_SHIELD = 0x11,
    WEAPONTYPE_ZONE_REPULSOR = 0x12,
    WEAPONTYPE_UNKNOWN = 0x13,
};

enum class EntFinderMethod_t : uint64_t
{
    ENT_FIND_METHOD_NEAREST = 0x0,
    ENT_FIND_METHOD_FARTHEST = 0x1,
    ENT_FIND_METHOD_RANDOM = 0x2,
};

enum class PropDoorRotatingSpawnPos_t : uint64_t
{
    DOOR_SPAWN_CLOSED = 0x0,
    DOOR_SPAWN_OPEN_FORWARD = 0x1,
    DOOR_SPAWN_OPEN_BACK = 0x2,
    DOOR_SPAWN_AJAR = 0x3,
};

enum class ShardSolid_t : uint64_t
{
    SHARD_SOLID = 0x0,
    SHARD_DEBRIS = 0x1,
};

enum class PulseNPCCondition_t : uint64_t
{
    COND_SEE_PLAYER = 0x1,
    COND_LOST_PLAYER = 0x2,
    COND_HEAR_PLAYER = 0x3,
    COND_PLAYER_PUSHING = 0x4,
    COND_NO_PRIMARY_AMMO = 0x5,
};

enum class ForcedCrouchState_t : uint64_t
{
    FORCEDCROUCH_NONE = 0x0,
    FORCEDCROUCH_CROUCHED = 0x1,
    FORCEDCROUCH_UNCROUCHED = 0x2,
};

enum class PerformanceMode_t : uint64_t
{
    PM_NORMAL = 0x0,
    PM_NO_GIBS = 0x1,
    PM_FULL_GIBS = 0x2,
    PM_REDUCED_GIBS = 0x3,
};

enum class TOGGLE_STATE : uint64_t
{
    TS_AT_TOP = 0x0,
    TS_AT_BOTTOM = 0x1,
    TS_GOING_UP = 0x2,
    TS_GOING_DOWN = 0x3,
    DOOR_OPEN = 0x0,
    DOOR_CLOSED = 0x1,
    DOOR_OPENING = 0x2,
    DOOR_CLOSING = 0x3,
};

enum class loadout_slot_t : uint64_t
{
    LOADOUT_SLOT_PROMOTED = 0xfffffffffffffffe,
    LOADOUT_SLOT_INVALID = 0xffffffffffffffff,
    LOADOUT_SLOT_MELEE = 0x0,
    LOADOUT_SLOT_C4 = 0x1,
    LOADOUT_SLOT_FIRST_AUTO_BUY_WEAPON = 0x0,
    LOADOUT_SLOT_LAST_AUTO_BUY_WEAPON = 0x1,
    LOADOUT_SLOT_SECONDARY0 = 0x2,
    LOADOUT_SLOT_SECONDARY1 = 0x3,
    LOADOUT_SLOT_SECONDARY2 = 0x4,
    LOADOUT_SLOT_SECONDARY3 = 0x5,
    LOADOUT_SLOT_SECONDARY4 = 0x6,
    LOADOUT_SLOT_SECONDARY5 = 0x7,
    LOADOUT_SLOT_SMG0 = 0x8,
    LOADOUT_SLOT_SMG1 = 0x9,
    LOADOUT_SLOT_SMG2 = 0xa,
    LOADOUT_SLOT_SMG3 = 0xb,
    LOADOUT_SLOT_SMG4 = 0xc,
    LOADOUT_SLOT_SMG5 = 0xd,
    LOADOUT_SLOT_RIFLE0 = 0xe,
    LOADOUT_SLOT_RIFLE1 = 0xf,
    LOADOUT_SLOT_RIFLE2 = 0x10,
    LOADOUT_SLOT_RIFLE3 = 0x11,
    LOADOUT_SLOT_RIFLE4 = 0x12,
    LOADOUT_SLOT_RIFLE5 = 0x13,
    LOADOUT_SLOT_HEAVY0 = 0x14,
    LOADOUT_SLOT_HEAVY1 = 0x15,
    LOADOUT_SLOT_HEAVY2 = 0x16,
    LOADOUT_SLOT_HEAVY3 = 0x17,
    LOADOUT_SLOT_HEAVY4 = 0x18,
    LOADOUT_SLOT_HEAVY5 = 0x19,
    LOADOUT_SLOT_FIRST_WHEEL_WEAPON = 0x2,
    LOADOUT_SLOT_LAST_WHEEL_WEAPON = 0x19,
    LOADOUT_SLOT_FIRST_PRIMARY_WEAPON = 0x8,
    LOADOUT_SLOT_LAST_PRIMARY_WEAPON = 0x19,
    LOADOUT_SLOT_FIRST_WHEEL_GRENADE = 0x1a,
    LOADOUT_SLOT_GRENADE0 = 0x1a,
    LOADOUT_SLOT_GRENADE1 = 0x1b,
    LOADOUT_SLOT_GRENADE2 = 0x1c,
    LOADOUT_SLOT_GRENADE3 = 0x1d,
    LOADOUT_SLOT_GRENADE4 = 0x1e,
    LOADOUT_SLOT_GRENADE5 = 0x1f,
    LOADOUT_SLOT_LAST_WHEEL_GRENADE = 0x1f,
    LOADOUT_SLOT_EQUIPMENT0 = 0x20,
    LOADOUT_SLOT_EQUIPMENT1 = 0x21,
    LOADOUT_SLOT_EQUIPMENT2 = 0x22,
    LOADOUT_SLOT_EQUIPMENT3 = 0x23,
    LOADOUT_SLOT_EQUIPMENT4 = 0x24,
    LOADOUT_SLOT_EQUIPMENT5 = 0x25,
    LOADOUT_SLOT_FIRST_WHEEL_EQUIPMENT = 0x20,
    LOADOUT_SLOT_LAST_WHEEL_EQUIPMENT = 0x25,
    LOADOUT_SLOT_CLOTHING_CUSTOMPLAYER = 0x26,
    LOADOUT_SLOT_CLOTHING_CUSTOMHEAD = 0x27,
    LOADOUT_SLOT_CLOTHING_FACEMASK = 0x28,
    LOADOUT_SLOT_CLOTHING_HANDS = 0x29,
    LOADOUT_SLOT_FIRST_COSMETIC = 0x29,
    LOADOUT_SLOT_LAST_COSMETIC = 0x29,
    LOADOUT_SLOT_CLOTHING_EYEWEAR = 0x2a,
    LOADOUT_SLOT_CLOTHING_HAT = 0x2b,
    LOADOUT_SLOT_CLOTHING_LOWERBODY = 0x2c,
    LOADOUT_SLOT_CLOTHING_TORSO = 0x2d,
    LOADOUT_SLOT_CLOTHING_APPEARANCE = 0x2e,
    LOADOUT_SLOT_MISC0 = 0x2f,
    LOADOUT_SLOT_MISC1 = 0x30,
    LOADOUT_SLOT_MISC2 = 0x31,
    LOADOUT_SLOT_MISC3 = 0x32,
    LOADOUT_SLOT_MISC4 = 0x33,
    LOADOUT_SLOT_MISC5 = 0x34,
    LOADOUT_SLOT_MISC6 = 0x35,
    LOADOUT_SLOT_MUSICKIT = 0x36,
    LOADOUT_SLOT_FLAIR0 = 0x37,
    LOADOUT_SLOT_SPRAY0 = 0x38,
    LOADOUT_SLOT_FIRST_ALL_CHARACTER = 0x36,
    LOADOUT_SLOT_LAST_ALL_CHARACTER = 0x38,
    LOADOUT_SLOT_COUNT = 0x39,
};

enum class NavAttributeEnum : uint64_t
{
    NAV_MESH_AVOID = 0x80,
    NAV_MESH_STAIRS = 0x1000,
    NAV_MESH_NON_ZUP = 0x8000,
    NAV_MESH_SHORT_HEIGHT = 0x10000,
    NAV_MESH_NON_ZUP_TRANSITION = 0x20000,
    NAV_MESH_CROUCH = 0x10000,
    NAV_MESH_JUMP = 0x2,
    NAV_MESH_PRECISE = 0x4,
    NAV_MESH_NO_JUMP = 0x8,
    NAV_MESH_STOP = 0x10,
    NAV_MESH_RUN = 0x20,
    NAV_MESH_WALK = 0x40,
    NAV_MESH_TRANSIENT = 0x100,
    NAV_MESH_DONT_HIDE = 0x200,
    NAV_MESH_STAND = 0x400,
    NAV_MESH_NO_HOSTAGES = 0x800,
    NAV_MESH_NO_MERGE = 0x2000,
    NAV_MESH_OBSTACLE_TOP = 0x4000,
    NAV_ATTR_FIRST_GAME_INDEX = 0x13,
    NAV_ATTR_LAST_INDEX = 0x1f,
};

enum class MoveLinearAuthoredPos_t : uint64_t
{
    MOVELINEAR_AUTHORED_AT_START_POSITION = 0x0,
    MOVELINEAR_AUTHORED_AT_OPEN_POSITION = 0x1,
    MOVELINEAR_AUTHORED_AT_CLOSED_POSITION = 0x2,
};

enum class ValueRemapperMomentumType_t : uint64_t
{
    MomentumType_None = 0x0,
    MomentumType_Friction = 0x1,
    MomentumType_SpringTowardSnapValue = 0x2,
    MomentumType_SpringAwayFromSnapValue = 0x3,
};

enum class Hull_t : uint64_t
{
    HULL_HUMAN = 0x0,
    HULL_SMALL_CENTERED = 0x1,
    HULL_WIDE_HUMAN = 0x2,
    HULL_TINY = 0x3,
    HULL_MEDIUM = 0x4,
    HULL_TINY_CENTERED = 0x5,
    HULL_LARGE = 0x6,
    HULL_LARGE_CENTERED = 0x7,
    HULL_MEDIUM_TALL = 0x8,
    HULL_SMALL = 0x9,
    NUM_HULLS = 0xa,
    HULL_NONE = 0xb,
};

enum class PreviewWeaponState : uint64_t
{
    DROPPED = 0x0,
    HOLSTERED = 0x1,
    DEPLOYED = 0x2,
    PLANTED = 0x3,
    INSPECT = 0x4,
    ICON = 0x5,
};

enum class EInButtonState : uint64_t
{
    IN_BUTTON_UP = 0x0,
    IN_BUTTON_DOWN = 0x1,
    IN_BUTTON_DOWN_UP = 0x2,
    IN_BUTTON_UP_DOWN = 0x3,
    IN_BUTTON_UP_DOWN_UP = 0x4,
    IN_BUTTON_DOWN_UP_DOWN = 0x5,
    IN_BUTTON_DOWN_UP_DOWN_UP = 0x6,
    IN_BUTTON_UP_DOWN_UP_DOWN = 0x7,
    IN_BUTTON_STATE_COUNT = 0x8,
};

enum class BeamClipStyle_t : uint64_t
{
    kNOCLIP = 0x0,
    kGEOCLIP = 0x1,
    kMODELCLIP = 0x2,
    kBEAMCLIPSTYLE_NUMBITS = 0x2,
};

enum class WeaponAttackType_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    ePrimary = 0x0,
    eSecondary = 0x1,
    eCount = 0x2,
};

enum class CSPlayerBlockingUseAction_t : uint64_t
{
    k_CSPlayerBlockingUseAction_None = 0x0,
    k_CSPlayerBlockingUseAction_DefusingDefault = 0x1,
    k_CSPlayerBlockingUseAction_DefusingWithKit = 0x2,
    k_CSPlayerBlockingUseAction_HostageGrabbing = 0x3,
    k_CSPlayerBlockingUseAction_HostageDropping = 0x4,
    k_CSPlayerBlockingUseAction_OpeningSafe = 0x5,
    k_CSPlayerBlockingUseAction_EquippingParachute = 0x6,
    k_CSPlayerBlockingUseAction_EquippingHeavyArmor = 0x7,
    k_CSPlayerBlockingUseAction_EquippingContract = 0x8,
    k_CSPlayerBlockingUseAction_EquippingTabletUpgrade = 0x9,
    k_CSPlayerBlockingUseAction_TakingOffHeavyArmor = 0xa,
    k_CSPlayerBlockingUseAction_PayingToOpenDoor = 0xb,
    k_CSPlayerBlockingUseAction_CancelingSpawnRappelling = 0xc,
    k_CSPlayerBlockingUseAction_EquippingExoJump = 0xd,
    k_CSPlayerBlockingUseAction_PickingUpBumpMine = 0xe,
    k_CSPlayerBlockingUseAction_MapLongUseEntity_Pickup = 0xf,
    k_CSPlayerBlockingUseAction_MapLongUseEntity_Place = 0x10,
    k_CSPlayerBlockingUseAction_MaxCount = 0x11,
};

enum class CSWeaponState_t : uint64_t
{
    WEAPON_NOT_CARRIED = 0x0,
    WEAPON_IS_CARRIED_BY_PLAYER = 0x1,
    WEAPON_IS_ACTIVE = 0x2,
};

enum class CommandExecMode_t : uint64_t
{
    EXEC_MANUAL = 0x0,
    EXEC_LEVELSTART = 0x1,
    EXEC_PERIODIC = 0x2,
    EXEC_MODES_COUNT = 0x3,
};

enum class ShatterDamageCause : uint64_t
{
    SHATTERDAMAGE_BULLET = 0x0,
    SHATTERDAMAGE_MELEE = 0x1,
    SHATTERDAMAGE_THROWN = 0x2,
    SHATTERDAMAGE_SCRIPT = 0x3,
    SHATTERDAMAGE_EXPLOSIVE = 0x4,
};

enum class ScriptedOnDeath_t : uint64_t
{
    SS_ONDEATH_NOT_APPLICABLE = 0xffffffffffffffff,
    SS_ONDEATH_UNDEFINED = 0x0,
    SS_ONDEATH_RAGDOLL = 0x1,
    SS_ONDEATH_ANIMATED_DEATH = 0x2,
};

enum class ChoreoLookAtSpeed_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eSlow = 0x0,
    eMedium = 0x1,
    eFast = 0x2,
};

enum class ScriptedMoveType_t : uint64_t
{
    SCRIPTED_MOVETYPE_NONE = 0x0,
    SCRIPTED_MOVETYPE_TO_WITH_DURATION = 0x1,
    SCRIPTED_MOVETYPE_TO_WITH_MOVESPEED = 0x2,
    SCRIPTED_MOVETYPE_SWEEP_TO_AT_MOVEMENT_SPEED = 0x3,
};

enum class gear_slot_t : uint64_t
{
    GEAR_SLOT_INVALID = 0xffffffffffffffff,
    GEAR_SLOT_RIFLE = 0x0,
    GEAR_SLOT_PISTOL = 0x1,
    GEAR_SLOT_KNIFE = 0x2,
    GEAR_SLOT_GRENADES = 0x3,
    GEAR_SLOT_C4 = 0x4,
    GEAR_SLOT_RESERVED_SLOT6 = 0x5,
    GEAR_SLOT_RESERVED_SLOT7 = 0x6,
    GEAR_SLOT_RESERVED_SLOT8 = 0x7,
    GEAR_SLOT_RESERVED_SLOT9 = 0x8,
    GEAR_SLOT_RESERVED_SLOT10 = 0x9,
    GEAR_SLOT_RESERVED_SLOT11 = 0xa,
    GEAR_SLOT_BOOSTS = 0xb,
    GEAR_SLOT_UTILITY = 0xc,
    GEAR_SLOT_COUNT = 0xd,
    GEAR_SLOT_FIRST = 0x0,
    GEAR_SLOT_LAST = 0xc,
};

enum class CSPlayerState : uint64_t
{
    STATE_ACTIVE = 0x0,
    STATE_WELCOME = 0x1,
    STATE_PICKINGTEAM = 0x2,
    STATE_PICKINGCLASS = 0x3,
    STATE_DEATH_ANIM = 0x4,
    STATE_DEATH_WAIT_FOR_KEY = 0x5,
    STATE_OBSERVER_MODE = 0x6,
    STATE_GUNGAME_RESPAWN = 0x7,
    STATE_DORMANT = 0x8,
    NUM_PLAYER_STATES = 0x9,
};

enum class ScriptedConflictResponse_t : uint64_t
{
    SS_CONFLICT_ENQUEUE = 0x0,
    SS_CONFLICT_INTERRUPT = 0x1,
};

enum class WaterLevel_t : uint64_t
{
    WL_NotInWater = 0x0,
    WL_Feet = 0x1,
    WL_Knees = 0x2,
    WL_Waist = 0x3,
    WL_Chest = 0x4,
    WL_FullyUnderwater = 0x5,
    WL_Count = 0x6,
};

enum class WorldTextPanelVerticalAlign_t : uint64_t
{
    WORLDTEXT_VERTICAL_ALIGN_TOP = 0x0,
    WORLDTEXT_VERTICAL_ALIGN_CENTER = 0x1,
    WORLDTEXT_VERTICAL_ALIGN_BOTTOM = 0x2,
};

enum class AmmoPosition_t : uint64_t
{
    AMMO_POSITION_INVALID = 0xffffffffffffffff,
    AMMO_POSITION_PRIMARY = 0x0,
    AMMO_POSITION_SECONDARY = 0x1,
    AMMO_POSITION_COUNT = 0x2,
};

enum class PreviewEOMCelebration : uint64_t
{
    WALKUP = 0x0,
    PUNCHING = 0x1,
    SWAGGER = 0x2,
    DROPDOWN = 0x3,
    STRETCH = 0x4,
    SWAT_FEMALE = 0x5,
    MASK_F = 0x6,
    GUERILLA = 0x7,
    GUERILLA02 = 0x8,
    GENDARMERIE = 0x9,
    SCUBA_FEMALE = 0xa,
    SCUBA_MALE = 0xb,
    AVA_DEFEAT = 0xc,
    GENDARMERIE_DEFEAT = 0xd,
    MAE_DEFEAT = 0xe,
    RICKSAW_DEFEAT = 0xf,
    SCUBA_FEMALE_DEFEAT = 0x10,
    SCUBA_MALE_DEFEAT = 0x11,
    CRASSWATER_DEFEAT = 0x12,
    DARRYL_DEFEAT = 0x13,
    DOCTOR_DEFEAT = 0x14,
    MUHLIK_DEFEAT = 0x15,
    VYPA_DEFEAT = 0x16,
};

enum class EntityDisolveType_t : uint64_t
{
    ENTITY_DISSOLVE_INVALID = 0xffffffffffffffff,
    ENTITY_DISSOLVE_NORMAL = 0x0,
    ENTITY_DISSOLVE_ELECTRICAL = 0x1,
    ENTITY_DISSOLVE_ELECTRICAL_LIGHT = 0x2,
    ENTITY_DISSOLVE_CORE = 0x3,
};

enum class InputBitMask_t : uint64_t
{
    IN_NONE = 0x0,
    IN_ALL = 0xffffffffffffffff,
    IN_ATTACK = 0x1,
    IN_JUMP = 0x2,
    IN_DUCK = 0x4,
    IN_FORWARD = 0x8,
    IN_BACK = 0x10,
    IN_USE = 0x20,
    IN_TURNLEFT = 0x80,
    IN_TURNRIGHT = 0x100,
    IN_MOVELEFT = 0x200,
    IN_MOVERIGHT = 0x400,
    IN_ATTACK2 = 0x800,
    IN_RELOAD = 0x2000,
    IN_SPEED = 0x10000,
    IN_JOYAUTOSPRINT = 0x20000,
    IN_FIRST_MOD_SPECIFIC_BIT = 0x100000000,
    IN_USEORRELOAD = 0x100000000,
    IN_SCORE = 0x200000000,
    IN_ZOOM = 0x400000000,
    IN_LOOK_AT_WEAPON = 0x800000000,
};

enum class ChickenActivity : uint64_t
{
    IDLE = 0x0,
    SQUAT = 0x1,
    WALK = 0x2,
    RUN = 0x3,
    GLIDE = 0x4,
    LAND = 0x5,
    PANIC = 0x6,
};

enum class PointWorldTextReorientMode_t : uint64_t
{
    POINT_WORLD_TEXT_REORIENT_NONE = 0x0,
    POINT_WORLD_TEXT_REORIENT_AROUND_UP = 0x1,
};

enum class DebugOverlayBits_t : uint64_t
{
    OVERLAY_TEXT_BIT = 0x1,
    OVERLAY_NAME_BIT = 0x2,
    OVERLAY_BBOX_BIT = 0x4,
    OVERLAY_PIVOT_BIT = 0x8,
    OVERLAY_MESSAGE_BIT = 0x10,
    OVERLAY_ABSBOX_BIT = 0x20,
    OVERLAY_RBOX_BIT = 0x40,
    OVERLAY_SHOW_BLOCKSLOS = 0x80,
    OVERLAY_ATTACHMENTS_BIT = 0x100,
    OVERLAY_INTERPOLATED_ATTACHMENTS_BIT = 0x200,
    OVERLAY_INTERPOLATED_PIVOT_BIT = 0x400,
    OVERLAY_SKELETON_BIT = 0x800,
    OVERLAY_INTERPOLATED_SKELETON_BIT = 0x1000,
    OVERLAY_TRIGGER_BOUNDS_BIT = 0x2000,
    OVERLAY_HITBOX_BIT = 0x4000,
    OVERLAY_INTERPOLATED_HITBOX_BIT = 0x8000,
    OVERLAY_AUTOAIM_BIT = 0x10000,
    OVERLAY_NPC_SELECTED_BIT = 0x20000,
    OVERLAY_JOINT_INFO_BIT = 0x40000,
    OVERLAY_NPC_ROUTE_BIT = 0x80000,
    OVERLAY_VISIBILITY_TRACES_BIT = 0x100000,
    OVERLAY_NPC_ENEMIES_BIT = 0x400000,
    OVERLAY_NPC_CONDITIONS_BIT = 0x800000,
    OVERLAY_NPC_COMBAT_BIT = 0x1000000,
    OVERLAY_NPC_TASK_BIT = 0x2000000,
    OVERLAY_NPC_BODYLOCATIONS = 0x4000000,
    OVERLAY_NPC_VIEWCONE_BIT = 0x8000000,
    OVERLAY_NPC_KILL_BIT = 0x10000000,
    OVERLAY_WC_CHANGE_ENTITY = 0x20000000,
    OVERLAY_BUDDHA_MODE = 0x40000000,
    OVERLAY_NPC_STEERING_REGULATIONS = 0x80000000,
    OVERLAY_NPC_TASK_TEXT_BIT = 0x100000000,
    OVERLAY_PROP_DEBUG = 0x200000000,
    OVERLAY_NPC_RELATION_BIT = 0x400000000,
    OVERLAY_VIEWOFFSET = 0x800000000,
    OVERLAY_VCOLLIDE_WIREFRAME_BIT = 0x1000000000,
    OVERLAY_NPC_SCRIPTED_COMMANDS_BIT = 0x2000000000,
    OVERLAY_ACTORNAME_BIT = 0x4000000000,
    OVERLAY_NPC_CONDITIONS_TEXT_BIT = 0x8000000000,
    OVERLAY_NPC_ABILITY_RANGE_DEBUG_BIT = 0x10000000000,
};

enum class AmmoFlags_t : uint64_t
{
    AMMO_FORCE_DROP_IF_CARRIED = 0x1,
    AMMO_RESERVE_STAYS_WITH_WEAPON = 0x2,
    AMMO_FLAG_MAX = 0x2,
};

enum class HierarchyType_t : uint64_t
{
    HIERARCHY_NONE = 0x0,
    HIERARCHY_BONE_MERGE = 0x1,
    HIERARCHY_ATTACHMENT = 0x2,
    HIERARCHY_ABSORIGIN = 0x3,
    HIERARCHY_BONE = 0x4,
    HIERARCHY_TYPE_COUNT = 0x5,
};

enum class doorCheck_e : uint64_t
{
    DOOR_CHECK_FORWARD = 0x0,
    DOOR_CHECK_BACKWARD = 0x1,
    DOOR_CHECK_FULL = 0x2,
};

enum class BeamType_t : uint64_t
{
    BEAM_INVALID = 0x0,
    BEAM_POINTS = 0x1,
    BEAM_ENTPOINT = 0x2,
    BEAM_ENTS = 0x3,
    BEAM_HOSE = 0x4,
    BEAM_SPLINE = 0x5,
    BEAM_LASER = 0x6,
};

enum class EntitySubclassScope_t : uint64_t
{
    SUBCLASS_SCOPE_NONE = 0xffffffffffffffff,
    SUBCLASS_SCOPE_PRECIPITATION = 0x0,
    SUBCLASS_SCOPE_PLAYER_WEAPONS = 0x1,
    SUBCLASS_SCOPE_COUNT = 0x2,
};

enum class PointTemplateClientOnlyEntityBehavior_t : uint64_t
{
    CREATE_FOR_CURRENTLY_CONNECTED_CLIENTS_ONLY = 0x0,
    CREATE_FOR_CLIENTS_WHO_CONNECT_LATER = 0x1,
};

enum class ShatterGlassStressType : uint64_t
{
    SHATTERGLASS_BLUNT = 0x0,
    SHATTERGLASS_BALLISTIC = 0x1,
    SHATTERGLASS_PULSE = 0x2,
    SHATTERDRYWALL_CHUNKS = 0x3,
    SHATTERGLASS_EXPLOSIVE = 0x4,
};

enum class TrackOrientationType_t : uint64_t
{
    TrackOrientation_Fixed = 0x0,
    TrackOrientation_FacePath = 0x1,
    TrackOrientation_FacePathAngles = 0x2,
};

enum class WeaponSwitchReason_t : uint64_t
{
    eDrawn = 0x0,
    eEquipped = 0x1,
    eUserInitiatedSwitchToLast = 0x2,
    eUserInitiatedSwitchHands = 0x3,
};

enum class ValueRemapperRatchetType_t : uint64_t
{
    RatchetType_Absolute = 0x0,
    RatchetType_EachEngage = 0x1,
};

enum class NavDirType : uint64_t
{
    NORTH = 0x0,
    EAST = 0x1,
    SOUTH = 0x2,
    WEST = 0x3,
    NUM_NAV_DIR_TYPE_DIRECTIONS = 0x4,
};

enum class CRR_Response__ResponseEnum_t : uint64_t
{
    MAX_RESPONSE_NAME = 0xc0,
    MAX_RULE_NAME = 0x80,
};

enum class MoveMountingAmount_t : uint64_t
{
    MOVE_MOUNT_NONE = 0x0,
    MOVE_MOUNT_LOW = 0x1,
    MOVE_MOUNT_HIGH = 0x2,
    MOVE_MOUNT_MAXCOUNT = 0x3,
};

enum class vote_create_failed_t : uint64_t
{
    VOTE_FAILED_GENERIC = 0x0,
    VOTE_FAILED_TRANSITIONING_PLAYERS = 0x1,
    VOTE_FAILED_RATE_EXCEEDED = 0x2,
    VOTE_FAILED_YES_MUST_EXCEED_NO = 0x3,
    VOTE_FAILED_QUORUM_FAILURE = 0x4,
    VOTE_FAILED_ISSUE_DISABLED = 0x5,
    VOTE_FAILED_MAP_NOT_FOUND = 0x6,
    VOTE_FAILED_MAP_NAME_REQUIRED = 0x7,
    VOTE_FAILED_FAILED_RECENTLY = 0x8,
    VOTE_FAILED_TEAM_CANT_CALL = 0x9,
    VOTE_FAILED_WAITINGFORPLAYERS = 0xa,
    VOTE_FAILED_PLAYERNOTFOUND = 0xb,
    VOTE_FAILED_CANNOT_KICK_ADMIN = 0xc,
    VOTE_FAILED_SCRAMBLE_IN_PROGRESS = 0xd,
    VOTE_FAILED_SPECTATOR = 0xe,
    VOTE_FAILED_FAILED_RECENT_KICK = 0xf,
    VOTE_FAILED_FAILED_RECENT_CHANGEMAP = 0x10,
    VOTE_FAILED_FAILED_RECENT_SWAPTEAMS = 0x11,
    VOTE_FAILED_FAILED_RECENT_SCRAMBLETEAMS = 0x12,
    VOTE_FAILED_FAILED_RECENT_RESTART = 0x13,
    VOTE_FAILED_SWAP_IN_PROGRESS = 0x14,
    VOTE_FAILED_DISABLED = 0x15,
    VOTE_FAILED_NEXTLEVEL_SET = 0x16,
    VOTE_FAILED_TOO_EARLY_SURRENDER = 0x17,
    VOTE_FAILED_MATCH_PAUSED = 0x18,
    VOTE_FAILED_MATCH_NOT_PAUSED = 0x19,
    VOTE_FAILED_NOT_IN_WARMUP = 0x1a,
    VOTE_FAILED_NOT_10_PLAYERS = 0x1b,
    VOTE_FAILED_TIMEOUT_ACTIVE = 0x1c,
    VOTE_FAILED_TIMEOUT_INACTIVE = 0x1d,
    VOTE_FAILED_TIMEOUT_EXHAUSTED = 0x1e,
    VOTE_FAILED_CANT_ROUND_END = 0x1f,
    VOTE_FAILED_REMATCH = 0x20,
    VOTE_FAILED_CONTINUE = 0x21,
    VOTE_FAILED_MAX = 0x22,
};

enum class RumbleEffect_t : uint64_t
{
    RUMBLE_INVALID = 0xffffffffffffffff,
    RUMBLE_STOP_ALL = 0x0,
    RUMBLE_PISTOL = 0x1,
    RUMBLE_357 = 0x2,
    RUMBLE_SMG1 = 0x3,
    RUMBLE_AR2 = 0x4,
    RUMBLE_SHOTGUN_SINGLE = 0x5,
    RUMBLE_SHOTGUN_DOUBLE = 0x6,
    RUMBLE_AR2_ALT_FIRE = 0x7,
    RUMBLE_RPG_MISSILE = 0x8,
    RUMBLE_CROWBAR_SWING = 0x9,
    RUMBLE_AIRBOAT_GUN = 0xa,
    RUMBLE_JEEP_ENGINE_LOOP = 0xb,
    RUMBLE_FLAT_LEFT = 0xc,
    RUMBLE_FLAT_RIGHT = 0xd,
    RUMBLE_FLAT_BOTH = 0xe,
    RUMBLE_DMG_LOW = 0xf,
    RUMBLE_DMG_MED = 0x10,
    RUMBLE_DMG_HIGH = 0x11,
    RUMBLE_FALL_LONG = 0x12,
    RUMBLE_FALL_SHORT = 0x13,
    RUMBLE_PHYSCANNON_OPEN = 0x14,
    RUMBLE_PHYSCANNON_PUNT = 0x15,
    RUMBLE_PHYSCANNON_LOW = 0x16,
    RUMBLE_PHYSCANNON_MEDIUM = 0x17,
    RUMBLE_PHYSCANNON_HIGH = 0x18,
    NUM_RUMBLE_EFFECTS = 0x19,
};

enum class LatchDirtyPermission_t : uint64_t
{
    LATCH_DIRTY_DISALLOW = 0x0,
    LATCH_DIRTY_SERVER_CONTROLLED = 0x1,
    LATCH_DIRTY_CLIENT_SIMULATED = 0x2,
    LATCH_DIRTY_PREDICTION = 0x3,
    LATCH_DIRTY_FRAMESIMULATE = 0x4,
    LATCH_DIRTY_PARTICLE_SIMULATE = 0x5,
};

enum class DoorState_t : uint64_t
{
    DOOR_STATE_CLOSED = 0x0,
    DOOR_STATE_OPENING = 0x1,
    DOOR_STATE_OPEN = 0x2,
    DOOR_STATE_CLOSING = 0x3,
    DOOR_STATE_AJAR = 0x4,
};

enum class ChoreoLookAtMode_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eChest = 0x0,
    eHead = 0x1,
    eEyesOnly = 0x2,
};

enum class ChatIgnoreType_t : uint64_t
{
    CHAT_IGNORE_NONE = 0x0,
    CHAT_IGNORE_ALL = 0x1,
    CHAT_IGNORE_TEAM = 0x2,
};

enum class PlayerConnectedState : uint64_t
{
    PlayerNeverConnected = 0xffffffffffffffff,
    PlayerConnected = 0x0,
    PlayerConnecting = 0x1,
    PlayerReconnecting = 0x2,
    PlayerDisconnecting = 0x3,
    PlayerDisconnected = 0x4,
    PlayerReserved = 0x5,
};

enum class SimpleConstraintSoundProfile__SimpleConstraintsSoundProfileKeypoints_t : uint64_t
{
    kMIN_THRESHOLD = 0x0,
    kMIN_FULL = 0x1,
    kHIGHWATER = 0x2,
};

enum class navproperties_t : uint64_t
{
    NAV_IGNORE = 0x1,
};

enum class DamageTypes_t : uint64_t
{
    DMG_GENERIC = 0x0,
    DMG_CRUSH = 0x1,
    DMG_BULLET = 0x2,
    DMG_SLASH = 0x4,
    DMG_BURN = 0x8,
    DMG_VEHICLE = 0x10,
    DMG_FALL = 0x20,
    DMG_BLAST = 0x40,
    DMG_CLUB = 0x80,
    DMG_SHOCK = 0x100,
    DMG_SONIC = 0x200,
    DMG_ENERGYBEAM = 0x400,
    DMG_DROWN = 0x4000,
    DMG_POISON = 0x8000,
    DMG_RADIATION = 0x10000,
    DMG_DROWNRECOVER = 0x20000,
    DMG_ACID = 0x40000,
    DMG_PHYSGUN = 0x100000,
    DMG_DISSOLVE = 0x200000,
    DMG_BLAST_SURFACE = 0x400000,
    DMG_BUCKSHOT = 0x1000000,
    DMG_LASTGENERICFLAG = 0x1000000,
    DMG_HEADSHOT = 0x2000000,
    DMG_DANGERZONE = 0x4000000,
};

enum class PointWorldTextJustifyVertical_t : uint64_t
{
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_BOTTOM = 0x0,
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_CENTER = 0x1,
    POINT_WORLD_TEXT_JUSTIFY_VERTICAL_TOP = 0x2,
};

enum class attributeprovidertypes_t : uint64_t
{
    PROVIDER_GENERIC = 0x0,
    PROVIDER_WEAPON = 0x1,
};

enum class IChoreoServices__ChoreoState_t : uint64_t
{
    STATE_PRE_SCRIPT = 0x0,
    STATE_WAIT_FOR_SCRIPT = 0x1,
    STATE_WALK_TO_MARK = 0x2,
    STATE_SYNCHRONIZE_SCRIPT = 0x3,
    STATE_PLAY_SCRIPT = 0x4,
    STATE_PLAY_SCRIPT_POST_IDLE = 0x5,
    STATE_PLAY_SCRIPT_POST_IDLE_DONE = 0x6,
};

enum class ValueRemapperOutputType_t : uint64_t
{
    OutputType_AnimationCycle = 0x0,
    OutputType_RotationX = 0x1,
    OutputType_RotationY = 0x2,
    OutputType_RotationZ = 0x3,
};

enum class PointTemplateOwnerSpawnGroupType_t : uint64_t
{
    INSERT_INTO_POINT_TEMPLATE_SPAWN_GROUP = 0x0,
    INSERT_INTO_CURRENTLY_ACTIVE_SPAWN_GROUP = 0x1,
    INSERT_INTO_NEWLY_CREATED_SPAWN_GROUP = 0x2,
};

enum class eSplinePushType : uint64_t
{
    k_eSplinePushAlong = 0x0,
    k_eSplinePushAway = 0x1,
    k_eSplinePushTowards = 0x2,
};

enum class PointWorldTextJustifyHorizontal_t : uint64_t
{
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_LEFT = 0x0,
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_CENTER = 0x1,
    POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_RIGHT = 0x2,
};

enum class ShakeCommand_t : uint64_t
{
    SHAKE_START = 0x0,
    SHAKE_STOP = 0x1,
    SHAKE_AMPLITUDE = 0x2,
    SHAKE_FREQUENCY = 0x3,
    SHAKE_START_RUMBLEONLY = 0x4,
    SHAKE_START_NORUMBLE = 0x5,
};

enum class TRAIN_CODE : uint64_t
{
    TRAIN_SAFE = 0x0,
    TRAIN_BLOCKING = 0x1,
    TRAIN_FOLLOWING = 0x2,
};

enum class BrushSolidities_e : uint64_t
{
    BRUSHSOLID_TOGGLE = 0x0,
    BRUSHSOLID_NEVER = 0x1,
    BRUSHSOLID_ALWAYS = 0x2,
};

enum class QuestProgress__Reason : uint64_t
{
    QUEST_NONINITIALIZED = 0x0,
    QUEST_OK = 0x1,
    QUEST_NOT_ENOUGH_PLAYERS = 0x2,
    QUEST_WARMUP = 0x3,
    QUEST_NOT_CONNECTED_TO_STEAM = 0x4,
    QUEST_NONOFFICIAL_SERVER = 0x5,
    QUEST_NO_ENTITLEMENT = 0x6,
    QUEST_NO_QUEST = 0x7,
    QUEST_PLAYER_IS_BOT = 0x8,
    QUEST_WRONG_MAP = 0x9,
    QUEST_WRONG_MODE = 0xa,
    QUEST_NOT_SYNCED_WITH_SERVER = 0xb,
    QUEST_REASON_MAX = 0xc,
};

enum class ModifyDamageReturn_t : uint64_t
{
    CONTINUE_TO_APPLY_DAMAGE = 0x0,
    ABORT_DO_NOT_APPLY_DAMAGE = 0x1,
};

enum class ShadowType_t : uint64_t
{
    SHADOWS_NONE = 0x0,
    SHADOWS_SIMPLE = 0x1,
};

enum class GrenadeType_t : uint64_t
{
    GRENADE_TYPE_EXPLOSIVE = 0x0,
    GRENADE_TYPE_FLASH = 0x1,
    GRENADE_TYPE_FIRE = 0x2,
    GRENADE_TYPE_DECOY = 0x3,
    GRENADE_TYPE_SMOKE = 0x4,
    GRENADE_TYPE_SENSOR = 0x5,
    GRENADE_TYPE_SNOWBALL = 0x6,
    GRENADE_TYPE_TOTAL = 0x7,
};

enum class ValueRemapperInputType_t : uint64_t
{
    InputType_PlayerShootPosition = 0x0,
    InputType_PlayerShootPositionAroundAxis = 0x1,
};

enum class EKillTypes_t : uint64_t
{
    KILL_NONE = 0x0,
    KILL_DEFAULT = 0x1,
    KILL_HEADSHOT = 0x2,
    KILL_BLAST = 0x3,
    KILL_BURN = 0x4,
    KILL_SLASH = 0x5,
    KILL_SHOCK = 0x6,
    KILLTYPE_COUNT = 0x7,
};

enum class WeaponSound_t : uint64_t
{
    WEAPON_SOUND_EMPTY = 0x0,
    WEAPON_SOUND_SECONDARY_EMPTY = 0x1,
    WEAPON_SOUND_SINGLE = 0x2,
    WEAPON_SOUND_SECONDARY_ATTACK = 0x3,
    WEAPON_SOUND_MELEE_MISS = 0x4,
    WEAPON_SOUND_MELEE_HIT = 0x5,
    WEAPON_SOUND_MELEE_HIT_WORLD = 0x6,
    WEAPON_SOUND_MELEE_HIT_PLAYER = 0x7,
    WEAPON_SOUND_MELEE_HIT_NPC = 0x8,
    WEAPON_SOUND_SPECIAL1 = 0x9,
    WEAPON_SOUND_SPECIAL2 = 0xa,
    WEAPON_SOUND_SPECIAL3 = 0xb,
    WEAPON_SOUND_NEARLYEMPTY = 0xc,
    WEAPON_SOUND_IMPACT = 0xd,
    WEAPON_SOUND_REFLECT = 0xe,
    WEAPON_SOUND_SECONDARY_IMPACT = 0xf,
    WEAPON_SOUND_SECONDARY_REFLECT = 0x10,
    WEAPON_SOUND_RELOAD = 0x11,
    WEAPON_SOUND_SINGLE_ACCURATE = 0x12,
    WEAPON_SOUND_ZOOM_IN = 0x13,
    WEAPON_SOUND_ZOOM_OUT = 0x14,
    WEAPON_SOUND_MOUSE_PRESSED = 0x15,
    WEAPON_SOUND_DROP = 0x16,
    WEAPON_SOUND_RADIO_USE = 0x17,
    WEAPON_SOUND_NUM_TYPES = 0x18,
};

enum class TakeDamageFlags_t : uint64_t
{
    DFLAG_NONE = 0x0,
    DFLAG_SUPPRESS_HEALTH_CHANGES = 0x1,
    DFLAG_SUPPRESS_PHYSICS_FORCE = 0x2,
    DFLAG_SUPPRESS_EFFECTS = 0x4,
    DFLAG_PREVENT_DEATH = 0x8,
    DFLAG_FORCE_DEATH = 0x10,
    DFLAG_ALWAYS_GIB = 0x20,
    DFLAG_NEVER_GIB = 0x40,
    DFLAG_REMOVE_NO_RAGDOLL = 0x80,
    DFLAG_SUPPRESS_DAMAGE_MODIFICATION = 0x100,
    DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
    DFLAG_RADIUS_DMG = 0x400,
    DFLAG_FORCEREDUCEARMOR_DMG = 0x800,
    DMG_LASTDFLAG = 0x800,
    DFLAG_IGNORE_ARMOR = 0x1000,
    DFLAG_SUPPRESS_UTILREMOVE = 0x2000,
};

enum class ValueRemapperHapticsType_t : uint64_t
{
    HaticsType_Default = 0x0,
    HaticsType_None = 0x1,
};

enum class Disposition_t : uint64_t
{
    D_ER = 0x0,
    D_HT = 0x1,
    D_FR = 0x2,
    D_LI = 0x3,
    D_NU = 0x4,
    D_ERROR = 0x0,
    D_HATE = 0x1,
    D_FEAR = 0x2,
    D_LIKE = 0x3,
    D_NEUTRAL = 0x4,
};

enum class CanPlaySequence_t : uint64_t
{
    CANNOT_PLAY = 0x0,
    CAN_PLAY_NOW = 0x1,
    CAN_PLAY_ENQUEUED = 0x2,
};

enum class MedalRank_t : uint64_t
{
    MEDAL_RANK_NONE = 0x0,
    MEDAL_RANK_BRONZE = 0x1,
    MEDAL_RANK_SILVER = 0x2,
    MEDAL_RANK_GOLD = 0x3,
    MEDAL_RANK_COUNT = 0x4,
};

enum class ObserverMode_t : uint64_t
{
    OBS_MODE_NONE = 0x0,
    OBS_MODE_FIXED = 0x1,
    OBS_MODE_IN_EYE = 0x2,
    OBS_MODE_CHASE = 0x3,
    OBS_MODE_ROAMING = 0x4,
    OBS_MODE_DIRECTED = 0x5,
    NUM_OBSERVER_MODES = 0x6,
};

enum class FuncDoorSpawnPos_t : uint64_t
{
    FUNC_DOOR_SPAWN_CLOSED = 0x0,
    FUNC_DOOR_SPAWN_OPEN = 0x1,
};

enum class EOverrideBlockLOS_t : uint64_t
{
    BLOCK_LOS_DEFAULT = 0x0,
    BLOCK_LOS_FORCE_FALSE = 0x1,
    BLOCK_LOS_FORCE_TRUE = 0x2,
};

enum class ParticleTextureLayerBlendType_t : uint64_t
{
    SPRITECARD_TEXTURE_BLEND_MULTIPLY = 0x0,
    SPRITECARD_TEXTURE_BLEND_MOD2X = 0x1,
    SPRITECARD_TEXTURE_BLEND_REPLACE = 0x2,
    SPRITECARD_TEXTURE_BLEND_ADD = 0x3,
    SPRITECARD_TEXTURE_BLEND_SUBTRACT = 0x4,
    SPRITECARD_TEXTURE_BLEND_AVERAGE = 0x5,
    SPRITECARD_TEXTURE_BLEND_LUMINANCE = 0x6,
};

enum class AnimationProcessingType_t : uint64_t
{
    ANIMATION_PROCESSING_SERVER_SIMULATION = 0x0,
    ANIMATION_PROCESSING_CLIENT_SIMULATION = 0x1,
    ANIMATION_PROCESSING_CLIENT_PREDICTION = 0x2,
    ANIMATION_PROCESSING_CLIENT_INTERPOLATION = 0x3,
    ANIMATION_PROCESSING_CLIENT_RENDER = 0x4,
    ANIMATION_PROCESSING_MAX = 0x5,
};

enum class RenderPrimitiveType_t : uint64_t
{
    RENDER_PRIM_POINTS = 0x0,
    RENDER_PRIM_LINES = 0x1,
    RENDER_PRIM_LINES_WITH_ADJACENCY = 0x2,
    RENDER_PRIM_LINE_STRIP = 0x3,
    RENDER_PRIM_LINE_STRIP_WITH_ADJACENCY = 0x4,
    RENDER_PRIM_TRIANGLES = 0x5,
    RENDER_PRIM_TRIANGLES_WITH_ADJACENCY = 0x6,
    RENDER_PRIM_TRIANGLE_STRIP = 0x7,
    RENDER_PRIM_TRIANGLE_STRIP_WITH_ADJACENCY = 0x8,
    RENDER_PRIM_INSTANCED_QUADS = 0x9,
    RENDER_PRIM_HETEROGENOUS = 0xa,
    RENDER_PRIM_COMPUTE_SHADER = 0xb,
    RENDER_PRIM_TYPE_COUNT = 0xc,
};

enum class ObjectTypeFlags_t : uint64_t
{
    OBJECT_TYPE_NONE = 0x0,
    OBJECT_TYPE_MODEL = 0x8,
    OBJECT_TYPE_BLOCK_LIGHT = 0x10,
    OBJECT_TYPE_NO_SHADOWS = 0x20,
    OBJECT_TYPE_WORLDSPACE_TEXURE_BLEND = 0x40,
    OBJECT_TYPE_DISABLED_IN_LOW_QUALITY = 0x80,
    OBJECT_TYPE_NO_SUN_SHADOWS = 0x100,
    OBJECT_TYPE_RENDER_WITH_DYNAMIC = 0x200,
    OBJECT_TYPE_RENDER_TO_CUBEMAPS = 0x400,
    OBJECT_TYPE_MODEL_HAS_LODS = 0x800,
    OBJECT_TYPE_OVERLAY = 0x2000,
    OBJECT_TYPE_PRECOMPUTED_VISMEMBERS = 0x4000,
    OBJECT_TYPE_STATIC_CUBE_MAP = 0x8000,
};

enum class ParticleModelType_t : uint64_t
{
    PM_TYPE_INVALID = 0x0,
    PM_TYPE_NAMED_VALUE_MODEL = 0x1,
    PM_TYPE_NAMED_VALUE_EHANDLE = 0x2,
    PM_TYPE_CONTROL_POINT = 0x3,
    PM_TYPE_COUNT = 0x4,
};

enum class PulseInstructionCode_t : uint64_t
{
    INVALID = 0x0,
    IMMEDIATE_HALT = 0x1,
    RETURN_VOID = 0x2,
    RETURN_VALUE = 0x3,
    NOP = 0x4,
    JUMP = 0x5,
    JUMP_COND = 0x6,
    CHUNK_LEAP = 0x7,
    CHUNK_LEAP_COND = 0x8,
    PULSE_CALL_SYNC = 0x9,
    PULSE_CALL_ASYNC_FIRE = 0xa,
    CELL_INVOKE = 0xb,
    LIBRARY_INVOKE = 0xc,
    SET_VAR = 0xd,
    GET_VAR = 0xe,
    GET_CONST = 0xf,
    GET_DOMAIN_VALUE = 0x10,
    COPY = 0x11,
    NOT = 0x12,
    NEGATE = 0x13,
    ADD = 0x14,
    SUB = 0x15,
    MUL = 0x16,
    DIV = 0x17,
    MOD = 0x18,
    LT = 0x19,
    LTE = 0x1a,
    EQ = 0x1b,
    NE = 0x1c,
    AND = 0x1d,
    OR = 0x1e,
    CONVERT_VALUE = 0x1f,
    REINTERPRET_INSTANCE = 0x20,
    GET_BLACKBOARD_REFERENCE = 0x21,
    SET_BLACKBOARD_REFERENCE = 0x22,
    REQUIREMENT_RESULT = 0x23,
    LAST_SERIALIZED_CODE = 0x24,
    NEGATE_INT = 0x25,
    NEGATE_FLOAT = 0x26,
    ADD_INT = 0x27,
    ADD_FLOAT = 0x28,
    ADD_STRING = 0x29,
    SUB_INT = 0x2a,
    SUB_FLOAT = 0x2b,
    MUL_INT = 0x2c,
    MUL_FLOAT = 0x2d,
    DIV_INT = 0x2e,
    DIV_FLOAT = 0x2f,
    MOD_INT = 0x30,
    MOD_FLOAT = 0x31,
    LT_INT = 0x32,
    LT_FLOAT = 0x33,
    LTE_INT = 0x34,
    LTE_FLOAT = 0x35,
    EQ_BOOL = 0x36,
    EQ_INT = 0x37,
    EQ_FLOAT = 0x38,
    EQ_STRING = 0x39,
    EQ_ENTITY_NAME = 0x3a,
    EQ_EHANDLE = 0x3b,
    EQ_PANEL_HANDLE = 0x3c,
    EQ_OPAQUE_HANDLE = 0x3d,
    EQ_TEST_HANDLE = 0x3e,
    NE_BOOL = 0x3f,
    NE_INT = 0x40,
    NE_FLOAT = 0x41,
    NE_STRING = 0x42,
    NE_ENTITY_NAME = 0x43,
    NE_EHANDLE = 0x44,
    NE_PANEL_HANDLE = 0x45,
    NE_OPAQUE_HANDLE = 0x46,
    NE_TEST_HANDLE = 0x47,
    GET_CONST_INLINE_STORAGE = 0x48,
};

enum class StateActionBehavior : uint64_t
{
    STATETAGBEHAVIOR_ACTIVE_WHILE_CURRENT = 0x0,
    STATETAGBEHAVIOR_FIRE_ON_ENTER = 0x1,
    STATETAGBEHAVIOR_FIRE_ON_EXIT = 0x2,
    STATETAGBEHAVIOR_FIRE_ON_ENTER_AND_EXIT = 0x3,
};

enum class Blend2DMode : uint64_t
{
    Blend2DMode_General = 0x0,
    Blend2DMode_Directional = 0x1,
};

enum class ParticleOrientationSetMode_t : uint64_t
{
    PARTICLE_ORIENTATION_SET_FROM_VELOCITY = 0x0,
    PARTICLE_ORIENTATION_SET_FROM_ROTATIONS = 0x1,
};

enum class ParticleVRHandChoiceList_t : uint64_t
{
    PARTICLE_VRHAND_LEFT = 0x0,
    PARTICLE_VRHAND_RIGHT = 0x1,
    PARTICLE_VRHAND_CP = 0x2,
    PARTICLE_VRHAND_CP_OBJECT = 0x3,
};

enum class SpawnDebugRestrictionOverrideState_t : uint64_t
{
    SPAWN_DEBUG_RESTRICT_NONE = 0x0,
    SPAWN_DEBUG_RESTRICT_IGNORE_MANAGER_DISTANCE_REQS = 0x1,
    SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_DISTANCE_LOS_REQS = 0x2,
    SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_COOLDOWN_LIMITS = 0x4,
    SPAWN_DEBUG_RESTRICT_IGNORE_TARGET_COOLDOWN_LIMITS = 0x8,
};

enum class JointMotion_t : uint64_t
{
    JOINT_MOTION_FREE = 0x0,
    JOINT_MOTION_LOCKED = 0x1,
    JOINT_MOTION_COUNT = 0x2,
};

enum class ParticleLightingQuality_t : uint64_t
{
    PARTICLE_LIGHTING_PER_PARTICLE = 0x0,
    PARTICLE_LIGHTING_PER_VERTEX = 0x1,
    PARTICLE_LIGHTING_PER_PIXEL = 0xffffffffffffffff,
};

enum class NmRootMotionBlendMode_t : uint64_t
{
    Blend = 0x0,
    Additive = 0x1,
    IgnoreSource = 0x2,
    IgnoreTarget = 0x3,
};

enum class SnapshotIndexType_t : uint64_t
{
    SNAPSHOT_INDEX_INCREMENT = 0x0,
    SNAPSHOT_INDEX_DIRECT = 0x1,
};

enum class RagdollPoseControl : uint64_t
{
    Absolute = 0x0,
    Relative = 0x1,
};

enum class ParticleReplicationMode_t : uint64_t
{
    PARTICLE_REPLICATIONMODE_NONE = 0x0,
    PARTICLE_REPLICATIONMODE_REPLICATE_FOR_EACH_PARENT_PARTICLE = 0x1,
};

enum class ParticleOutputBlendMode_t : uint64_t
{
    PARTICLE_OUTPUT_BLEND_MODE_ALPHA = 0x0,
    PARTICLE_OUTPUT_BLEND_MODE_ADD = 0x1,
    PARTICLE_OUTPUT_BLEND_MODE_BLEND_ADD = 0x2,
    PARTICLE_OUTPUT_BLEND_MODE_HALF_BLEND_ADD = 0x3,
    PARTICLE_OUTPUT_BLEND_MODE_NEG_HALF_BLEND_ADD = 0x4,
    PARTICLE_OUTPUT_BLEND_MODE_MOD2X = 0x5,
    PARTICLE_OUTPUT_BLEND_MODE_LIGHTEN = 0x6,
};

enum class PulseMethodCallMode_t : uint64_t
{
    SYNC_WAIT_FOR_COMPLETION = 0x0,
    ASYNC_FIRE_AND_FORGET = 0x1,
};

enum class VMixFilterSlope_t : uint64_t
{
    FILTER_SLOPE_1POLE_6dB = 0x0,
    FILTER_SLOPE_1POLE_12dB = 0x1,
    FILTER_SLOPE_1POLE_18dB = 0x2,
    FILTER_SLOPE_1POLE_24dB = 0x3,
    FILTER_SLOPE_12dB = 0x4,
    FILTER_SLOPE_24dB = 0x5,
    FILTER_SLOPE_36dB = 0x6,
    FILTER_SLOPE_48dB = 0x7,
    FILTER_SLOPE_MAX = 0x7,
};

enum class NmPoseBlendMode_t : uint64_t
{
    Overlay = 0x0,
    Additive = 0x1,
    GlobalSpace = 0x2,
};

enum class ViewFadeMode_t : uint64_t
{
    VIEW_FADE_CONSTANT_COLOR = 0x0,
    VIEW_FADE_MODULATE = 0x1,
    VIEW_FADE_MOD2X = 0x2,
};

enum class PulseCursorExecResult_t : uint64_t
{
    Succeeded = 0x0,
    Canceled = 0x1,
    Failed = 0x2,
    OngoingNotify = 0x3,
};

enum class CNmBoneMask__WeightInfo_t : uint64_t
{
    Zero = 0x0,
    Mixed = 0x1,
    One = 0x2,
};

enum class NmTransitionRuleCondition_t : uint64_t
{
    AnyAllowed = 0x0,
    FullyAllowed = 0x1,
    ConditionallyAllowed = 0x2,
    Blocked = 0x3,
};

enum class FlexOpCode_t : uint64_t
{
    FLEX_OP_CONST = 0x1,
    FLEX_OP_FETCH1 = 0x2,
    FLEX_OP_FETCH2 = 0x3,
    FLEX_OP_ADD = 0x4,
    FLEX_OP_SUB = 0x5,
    FLEX_OP_MUL = 0x6,
    FLEX_OP_DIV = 0x7,
    FLEX_OP_NEG = 0x8,
    FLEX_OP_EXP = 0x9,
    FLEX_OP_OPEN = 0xa,
    FLEX_OP_CLOSE = 0xb,
    FLEX_OP_COMMA = 0xc,
    FLEX_OP_MAX = 0xd,
    FLEX_OP_MIN = 0xe,
    FLEX_OP_2WAY_0 = 0xf,
    FLEX_OP_2WAY_1 = 0x10,
    FLEX_OP_NWAY = 0x11,
    FLEX_OP_COMBO = 0x12,
    FLEX_OP_DOMINATE = 0x13,
    FLEX_OP_DME_LOWER_EYELID = 0x14,
    FLEX_OP_DME_UPPER_EYELID = 0x15,
    FLEX_OP_SQRT = 0x16,
    FLEX_OP_REMAPVALCLAMPED = 0x17,
    FLEX_OP_SIN = 0x18,
    FLEX_OP_COS = 0x19,
    FLEX_OP_ABS = 0x1a,
};

enum class ParticleLightTypeChoiceList_t : uint64_t
{
    PARTICLE_LIGHT_TYPE_POINT = 0x0,
    PARTICLE_LIGHT_TYPE_SPOT = 0x1,
    PARTICLE_LIGHT_TYPE_FX = 0x2,
    PARTICLE_LIGHT_TYPE_CAPSULE = 0x3,
};

enum class IKSolverType : uint64_t
{
    IKSOLVER_Perlin = 0x0,
    IKSOLVER_TwoBone = 0x1,
    IKSOLVER_Fabrik = 0x2,
    IKSOLVER_DogLeg3Bone = 0x3,
    IKSOLVER_CCD = 0x4,
    IKSOLVER_COUNT = 0x5,
};

enum class SolveIKChainAnimNodeDebugSetting : uint64_t
{
    SOLVEIKCHAINANIMNODEDEBUGSETTING_None = 0x0,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_X_Axis_Circle = 0x1,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Y_Axis_Circle = 0x2,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Z_Axis_Circle = 0x3,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Forward = 0x4,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Up = 0x5,
    SOLVEIKCHAINANIMNODEDEBUGSETTING_Left = 0x6,
};

enum class PulseCursorCancelPriority_t : uint64_t
{
    None = 0x0,
    CancelOnSucceeded = 0x1,
    SoftCancel = 0x2,
    HardCancel = 0x3,
};

enum class CVSoundFormat_t : uint64_t
{
    PCM16 = 0x0,
    PCM8 = 0x1,
    MP3 = 0x2,
    ADPCM = 0x3,
};

enum class MaterialProxyType_t : uint64_t
{
    MATERIAL_PROXY_STATUS_EFFECT = 0x0,
    MATERIAL_PROXY_TINT = 0x1,
};

enum class PFuncVisualizationType_t : uint64_t
{
    PFUNC_VISUALIZATION_SPHERE_WIREFRAME = 0x0,
    PFUNC_VISUALIZATION_SPHERE_SOLID = 0x1,
    PFUNC_VISUALIZATION_BOX = 0x2,
    PFUNC_VISUALIZATION_RING = 0x3,
    PFUNC_VISUALIZATION_PLANE = 0x4,
    PFUNC_VISUALIZATION_LINE = 0x5,
    PFUNC_VISUALIZATION_CYLINDER = 0x6,
};

enum class VPhysXJoint_t__Flags_t : uint64_t
{
    JOINT_FLAGS_NONE = 0x0,
    JOINT_FLAGS_BODY1_FIXED = 0x1,
    JOINT_FLAGS_USE_BLOCK_SOLVER = 0x2,
};

enum class ParticlePostProcessPriorityGroup_t : uint64_t
{
    PARTICLE_POST_PROCESS_PRIORITY_LEVEL_VOLUME = 0x0,
    PARTICLE_POST_PROCESS_PRIORITY_LEVEL_OVERRIDE = 0x1,
    PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_EFFECT = 0x2,
    PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_LOW = 0x3,
    PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_HIGH = 0x4,
    PARTICLE_POST_PROCESS_PRIORITY_GLOBAL_UI = 0x5,
};

enum class VMixPannerType_t : uint64_t
{
    PANNER_TYPE_LINEAR = 0x0,
    PANNER_TYPE_EQUAL_POWER = 0x1,
};

enum class LayoutPositionType_e : uint64_t
{
    LAYOUTPOSITIONTYPE_VIEWPORT_RELATIVE = 0x0,
    LAYOUTPOSITIONTYPE_FRACTIONAL = 0x1,
    LAYOUTPOSITIONTYPE_NONE = 0x2,
};

enum class AnimParamNetworkSetting : uint64_t
{
    Auto = 0x0,
    AlwaysNetwork = 0x1,
    NeverNetwork = 0x2,
};

enum class JointAxis_t : uint64_t
{
    JOINT_AXIS_X = 0x0,
    JOINT_AXIS_Y = 0x1,
    JOINT_AXIS_Z = 0x2,
    JOINT_AXIS_COUNT = 0x3,
};

enum class MovementGait_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eSlow = 0x0,
    eMedium = 0x1,
    eFast = 0x2,
    eVeryFast = 0x3,
    eCount = 0x4,
};

enum class ParticleRotationLockType_t : uint64_t
{
    PARTICLE_ROTATION_LOCK_NONE = 0x0,
    PARTICLE_ROTATION_LOCK_ROTATIONS = 0x1,
    PARTICLE_ROTATION_LOCK_NORMAL = 0x2,
};

enum class ParticleFloatInputMode_t : uint64_t
{
    PF_INPUT_MODE_INVALID = 0xffffffffffffffff,
    PF_INPUT_MODE_CLAMPED = 0x0,
    PF_INPUT_MODE_LOOPED = 0x1,
    PF_INPUT_MODE_COUNT = 0x2,
};

enum class AimMatrixBlendMode : uint64_t
{
    AimMatrixBlendMode_None = 0x0,
    AimMatrixBlendMode_Additive = 0x1,
    AimMatrixBlendMode_ModelSpaceAdditive = 0x2,
    AimMatrixBlendMode_BoneMask = 0x3,
};

enum class ParticleHitboxBiasType_t : uint64_t
{
    PARTICLE_HITBOX_BIAS_ENTITY = 0x0,
    PARTICLE_HITBOX_BIAS_HITBOX = 0x1,
};

enum class CompositeMaterialInputLooseVariableType_t : uint64_t
{
    LOOSE_VARIABLE_TYPE_BOOLEAN = 0x0,
    LOOSE_VARIABLE_TYPE_INTEGER1 = 0x1,
    LOOSE_VARIABLE_TYPE_INTEGER2 = 0x2,
    LOOSE_VARIABLE_TYPE_INTEGER3 = 0x3,
    LOOSE_VARIABLE_TYPE_INTEGER4 = 0x4,
    LOOSE_VARIABLE_TYPE_FLOAT1 = 0x5,
    LOOSE_VARIABLE_TYPE_FLOAT2 = 0x6,
    LOOSE_VARIABLE_TYPE_FLOAT3 = 0x7,
    LOOSE_VARIABLE_TYPE_FLOAT4 = 0x8,
    LOOSE_VARIABLE_TYPE_COLOR4 = 0x9,
    LOOSE_VARIABLE_TYPE_STRING = 0xa,
    LOOSE_VARIABLE_TYPE_SYSTEMVAR = 0xb,
    LOOSE_VARIABLE_TYPE_RESOURCE_MATERIAL = 0xc,
    LOOSE_VARIABLE_TYPE_RESOURCE_TEXTURE = 0xd,
    LOOSE_VARIABLE_TYPE_PANORAMA_RENDER = 0xe,
};

enum class BlurFilterType_t : uint64_t
{
    BLURFILTER_GAUSSIAN = 0x0,
    BLURFILTER_BOX = 0x1,
};

enum class StanceOverrideMode : uint64_t
{
    Sequence = 0x0,
    Node = 0x1,
};

enum class MeshDrawPrimitiveFlags_t : uint64_t
{
    MESH_DRAW_FLAGS_NONE = 0x0,
    MESH_DRAW_FLAGS_USE_SHADOW_FAST_PATH = 0x1,
    MESH_DRAW_FLAGS_USE_COMPRESSED_NORMAL_TANGENT = 0x2,
    MESH_DRAW_INPUT_LAYOUT_IS_NOT_MATCHED_TO_MATERIAL = 0x8,
    MESH_DRAW_FLAGS_USE_COMPRESSED_PER_VERTEX_LIGHTING = 0x10,
    MESH_DRAW_FLAGS_USE_UNCOMPRESSED_PER_VERTEX_LIGHTING = 0x20,
    MESH_DRAW_FLAGS_CAN_BATCH_WITH_DYNAMIC_SHADER_CONSTANTS = 0x40,
    MESH_DRAW_FLAGS_DRAW_LAST = 0x80,
};

enum class ParticleFloatType_t : uint64_t
{
    PF_TYPE_INVALID = 0xffffffffffffffff,
    PF_TYPE_LITERAL = 0x0,
    PF_TYPE_NAMED_VALUE = 0x1,
    PF_TYPE_RANDOM_UNIFORM = 0x2,
    PF_TYPE_RANDOM_BIASED = 0x3,
    PF_TYPE_COLLECTION_AGE = 0x4,
    PF_TYPE_ENDCAP_AGE = 0x5,
    PF_TYPE_CONTROL_POINT_COMPONENT = 0x6,
    PF_TYPE_CONTROL_POINT_CHANGE_AGE = 0x7,
    PF_TYPE_CONTROL_POINT_SPEED = 0x8,
    PF_TYPE_PARTICLE_DETAIL_LEVEL = 0x9,
    PF_TYPE_CONCURRENT_DEF_COUNT = 0xa,
    PF_TYPE_CLOSEST_CAMERA_DISTANCE = 0xb,
    PF_TYPE_RENDERER_CAMERA_DISTANCE = 0xc,
    PF_TYPE_RENDERER_CAMERA_DOT_PRODUCT = 0xd,
    PF_TYPE_PARTICLE_NOISE = 0xe,
    PF_TYPE_PARTICLE_AGE = 0xf,
    PF_TYPE_PARTICLE_AGE_NORMALIZED = 0x10,
    PF_TYPE_PARTICLE_FLOAT = 0x11,
    PF_TYPE_PARTICLE_VECTOR_COMPONENT = 0x12,
    PF_TYPE_PARTICLE_SPEED = 0x13,
    PF_TYPE_PARTICLE_NUMBER = 0x14,
    PF_TYPE_PARTICLE_NUMBER_NORMALIZED = 0x15,
    PF_TYPE_COUNT = 0x16,
};

enum class EMode_t : uint64_t
{
    Peak = 0x0,
    RMS = 0x1,
};

enum class NmTransitionRule_t : uint64_t
{
    AllowTransition = 0x0,
    ConditionallyAllowTransition = 0x1,
    BlockTransition = 0x2,
};

enum class SpriteCardTextureType_t : uint64_t
{
    SPRITECARD_TEXTURE_DIFFUSE = 0x0,
    SPRITECARD_TEXTURE_ZOOM = 0x1,
    SPRITECARD_TEXTURE_1D_COLOR_LOOKUP = 0x2,
    SPRITECARD_TEXTURE_UVDISTORTION = 0x3,
    SPRITECARD_TEXTURE_UVDISTORTION_ZOOM = 0x4,
    SPRITECARD_TEXTURE_NORMALMAP = 0x5,
    SPRITECARD_TEXTURE_ANIMMOTIONVEC = 0x6,
    SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_A = 0x7,
    SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_B = 0x8,
    SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_C = 0x9,
};

enum class SelectorTagBehavior_t : uint64_t
{
    SelectorTagBehavior_OnWhileCurrent = 0x0,
    SelectorTagBehavior_OffWhenFinished = 0x1,
    SelectorTagBehavior_OffBeforeFinished = 0x2,
};

enum class ParticleFloatMapType_t : uint64_t
{
    PF_MAP_TYPE_INVALID = 0xffffffffffffffff,
    PF_MAP_TYPE_DIRECT = 0x0,
    PF_MAP_TYPE_MULT = 0x1,
    PF_MAP_TYPE_REMAP = 0x2,
    PF_MAP_TYPE_REMAP_BIASED = 0x3,
    PF_MAP_TYPE_CURVE = 0x4,
    PF_MAP_TYPE_NOTCHED = 0x5,
    PF_MAP_TYPE_COUNT = 0x6,
};

enum class VMixFilterType_t : uint64_t
{
    FILTER_UNKNOWN = 0xffffffffffffffff,
    FILTER_LOWPASS = 0x0,
    FILTER_HIGHPASS = 0x1,
    FILTER_BANDPASS = 0x2,
    FILTER_NOTCH = 0x3,
    FILTER_PEAKING_EQ = 0x4,
    FILTER_LOW_SHELF = 0x5,
    FILTER_HIGH_SHELF = 0x6,
    FILTER_ALLPASS = 0x7,
    FILTER_PASSTHROUGH = 0x8,
};

enum class ParticleAttrBoxFlags_t : uint64_t
{
    PARTICLE_ATTR_BOX_FLAGS_NONE = 0x0,
    PARTICLE_ATTR_BOX_FLAGS_WATER = 0x1,
};

enum class SosGroupType_t : uint64_t
{
    SOS_GROUPTYPE_DYNAMIC = 0x0,
    SOS_GROUPTYPE_STATIC = 0x1,
};

enum class PFNoiseTurbulence_t : uint64_t
{
    PF_NOISE_TURB_NONE = 0x0,
    PF_NOISE_TURB_HIGHLIGHT = 0x1,
    PF_NOISE_TURB_FEEDBACK = 0x2,
    PF_NOISE_TURB_LOOPY = 0x3,
    PF_NOISE_TURB_CONTRAST = 0x4,
    PF_NOISE_TURB_ALTERNATE = 0x5,
};

enum class MissingParentInheritBehavior_t : uint64_t
{
    MISSING_PARENT_DO_NOTHING = 0xffffffffffffffff,
    MISSING_PARENT_KILL = 0x0,
    MISSING_PARENT_FIND_NEW = 0x1,
    MISSING_PARENT_SAME_INDEX = 0x2,
};

enum class EventTypeSelection_t : uint64_t
{
    PARTICLE_EVENT_TYPE_MASK_NONE = 0x0,
    PARTICLE_EVENT_TYPE_MASK_SPAWNED = 0x1,
    PARTICLE_EVENT_TYPE_MASK_KILLED = 0x2,
    PARTICLE_EVENT_TYPE_MASK_COLLISION = 0x4,
    PARTICLE_EVENT_TYPE_MASK_FIRST_COLLISION = 0x8,
    PARTICLE_EVENT_TYPE_MASK_COLLISION_STOPPED = 0x10,
    PARTICLE_EVENT_TYPE_MASK_KILLED_ON_COLLISION = 0x20,
    PARTICLE_EVENT_TYPE_MASK_USER_1 = 0x40,
    PARTICLE_EVENT_TYPE_MASK_USER_2 = 0x80,
    PARTICLE_EVENT_TYPE_MASK_USER_3 = 0x100,
    PARTICLE_EVENT_TYPE_MASK_USER_4 = 0x200,
};

enum class AnimationType_t : uint64_t
{
    ANIMATION_TYPE_FIXED_RATE = 0x0,
    ANIMATION_TYPE_FIT_LIFETIME = 0x1,
    ANIMATION_TYPE_MANUAL_FRAMES = 0x2,
};

enum class AnimParamButton_t : uint64_t
{
    ANIMPARAM_BUTTON_NONE = 0x0,
    ANIMPARAM_BUTTON_DPAD_UP = 0x1,
    ANIMPARAM_BUTTON_DPAD_RIGHT = 0x2,
    ANIMPARAM_BUTTON_DPAD_DOWN = 0x3,
    ANIMPARAM_BUTTON_DPAD_LEFT = 0x4,
    ANIMPARAM_BUTTON_A = 0x5,
    ANIMPARAM_BUTTON_B = 0x6,
    ANIMPARAM_BUTTON_X = 0x7,
    ANIMPARAM_BUTTON_Y = 0x8,
    ANIMPARAM_BUTTON_LEFT_SHOULDER = 0x9,
    ANIMPARAM_BUTTON_RIGHT_SHOULDER = 0xa,
    ANIMPARAM_BUTTON_LTRIGGER = 0xb,
    ANIMPARAM_BUTTON_RTRIGGER = 0xc,
};

enum class BloomBlendMode_t : uint64_t
{
    BLOOM_BLEND_ADD = 0x0,
    BLOOM_BLEND_SCREEN = 0x1,
    BLOOM_BLEND_BLUR = 0x2,
};

enum class CompMatPropertyMutatorConditionType_t : uint64_t
{
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_EXISTS = 0x0,
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EXISTS = 0x1,
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EQUALS = 0x2,
};

enum class ParticleSetMethod_t : uint64_t
{
    PARTICLE_SET_REPLACE_VALUE = 0x0,
    PARTICLE_SET_SCALE_INITIAL_VALUE = 0x1,
    PARTICLE_SET_ADD_TO_INITIAL_VALUE = 0x2,
    PARTICLE_SET_RAMP_CURRENT_VALUE = 0x3,
    PARTICLE_SET_SCALE_CURRENT_VALUE = 0x4,
    PARTICLE_SET_ADD_TO_CURRENT_VALUE = 0x5,
};

enum class VectorFloatExpressionType_t : uint64_t
{
    VECTOR_FLOAT_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    VECTOR_FLOAT_EXPRESSION_DOTPRODUCT = 0x0,
    VECTOR_FLOAT_EXPRESSION_DISTANCE = 0x1,
    VECTOR_FLOAT_EXPRESSION_DISTANCESQR = 0x2,
    VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTH = 0x3,
    VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTHSQR = 0x4,
    VECTOR_FLOAT_EXPRESSION_INPUT1_NOISE = 0x5,
};

enum class ChoiceMethod : uint64_t
{
    WeightedRandom = 0x0,
    WeightedRandomNoRepeat = 0x1,
    Iterate = 0x2,
    IterateRandom = 0x3,
};

enum class NmFootPhaseCondition_t : uint64_t
{
    LeftFootDown = 0x0,
    LeftFootPassing = 0x1,
    LeftPhase = 0x4,
    RightFootDown = 0x2,
    RightFootPassing = 0x3,
    RightPhase = 0x5,
};

enum class CompositeMaterialVarSystemVar_t : uint64_t
{
    COMPMATSYSVAR_COMPOSITETIME = 0x0,
    COMPMATSYSVAR_EMPTY_RESOURCE_SPACER = 0x1,
};

enum class VectorExpressionType_t : uint64_t
{
    VECTOR_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    VECTOR_EXPRESSION_ADD = 0x0,
    VECTOR_EXPRESSION_SUBTRACT = 0x1,
    VECTOR_EXPRESSION_MUL = 0x2,
    VECTOR_EXPRESSION_DIVIDE = 0x3,
    VECTOR_EXPRESSION_INPUT_1 = 0x4,
    VECTOR_EXPRESSION_MIN = 0x5,
    VECTOR_EXPRESSION_MAX = 0x6,
    VECTOR_EXPRESSION_CROSSPRODUCT = 0x7,
};

enum class ParticleSelection_t : uint64_t
{
    PARTICLE_SELECTION_FIRST = 0x0,
    PARTICLE_SELECTION_LAST = 0x1,
    PARTICLE_SELECTION_NUMBER = 0x2,
};

enum class DisableShadows_t : uint64_t
{
    kDisableShadows_None = 0x0,
    kDisableShadows_All = 0x1,
    kDisableShadows_Baked = 0x2,
    kDisableShadows_Realtime = 0x3,
};

enum class ParticleFogType_t : uint64_t
{
    PARTICLE_FOG_GAME_DEFAULT = 0x0,
    PARTICLE_FOG_ENABLED = 0x1,
    PARTICLE_FOG_DISABLED = 0x2,
};

enum class Detail2Combo_t : uint64_t
{
    DETAIL_2_COMBO_UNINITIALIZED = 0xffffffffffffffff,
    DETAIL_2_COMBO_OFF = 0x0,
    DETAIL_2_COMBO_ADD = 0x1,
    DETAIL_2_COMBO_ADD_SELF_ILLUM = 0x2,
    DETAIL_2_COMBO_MOD2X = 0x3,
    DETAIL_2_COMBO_MUL = 0x4,
    DETAIL_2_COMBO_CROSSFADE = 0x5,
};

enum class ParticleAlphaReferenceType_t : uint64_t
{
    PARTICLE_ALPHA_REFERENCE_ALPHA_ALPHA = 0x0,
    PARTICLE_ALPHA_REFERENCE_OPAQUE_ALPHA = 0x1,
    PARTICLE_ALPHA_REFERENCE_ALPHA_OPAQUE = 0x2,
    PARTICLE_ALPHA_REFERENCE_OPAQUE_OPAQUE = 0x3,
};

enum class ParticleVecType_t : uint64_t
{
    PVEC_TYPE_INVALID = 0xffffffffffffffff,
    PVEC_TYPE_LITERAL = 0x0,
    PVEC_TYPE_LITERAL_COLOR = 0x1,
    PVEC_TYPE_NAMED_VALUE = 0x2,
    PVEC_TYPE_PARTICLE_VECTOR = 0x3,
    PVEC_TYPE_PARTICLE_VELOCITY = 0x4,
    PVEC_TYPE_CP_VALUE = 0x5,
    PVEC_TYPE_CP_RELATIVE_POSITION = 0x6,
    PVEC_TYPE_CP_RELATIVE_DIR = 0x7,
    PVEC_TYPE_CP_RELATIVE_RANDOM_DIR = 0x8,
    PVEC_TYPE_FLOAT_COMPONENTS = 0x9,
    PVEC_TYPE_FLOAT_INTERP_CLAMPED = 0xa,
    PVEC_TYPE_FLOAT_INTERP_OPEN = 0xb,
    PVEC_TYPE_FLOAT_INTERP_GRADIENT = 0xc,
    PVEC_TYPE_RANDOM_UNIFORM = 0xd,
    PVEC_TYPE_RANDOM_UNIFORM_OFFSET = 0xe,
    PVEC_TYPE_CP_DELTA = 0xf,
    PVEC_TYPE_CLOSEST_CAMERA_POSITION = 0x10,
    PVEC_TYPE_COUNT = 0x11,
};

enum class PFNoiseModifier_t : uint64_t
{
    PF_NOISE_MODIFIER_NONE = 0x0,
    PF_NOISE_MODIFIER_LINES = 0x1,
    PF_NOISE_MODIFIER_CLUMPS = 0x2,
    PF_NOISE_MODIFIER_RINGS = 0x3,
};

enum class ParticleImpulseType_t : uint64_t
{
    IMPULSE_TYPE_NONE = 0x0,
    IMPULSE_TYPE_GENERIC = 0x1,
    IMPULSE_TYPE_ROPE = 0x2,
    IMPULSE_TYPE_EXPLOSION = 0x4,
    IMPULSE_TYPE_EXPLOSION_UNDERWATER = 0x8,
    IMPULSE_TYPE_PARTICLE_SYSTEM = 0x10,
};

enum class VPhysXAggregateData_t__VPhysXFlagEnum_t : uint64_t
{
    FLAG_IS_POLYSOUP_GEOMETRY = 0x1,
    FLAG_LEVEL_COLLISION = 0x10,
    FLAG_IGNORE_SCALE_OBSOLETE_DO_NOT_USE = 0x20,
};

enum class ParticleFloatRandomMode_t : uint64_t
{
    PF_RANDOM_MODE_INVALID = 0xffffffffffffffff,
    PF_RANDOM_MODE_CONSTANT = 0x0,
    PF_RANDOM_MODE_VARYING = 0x1,
    PF_RANDOM_MODE_COUNT = 0x2,
};

enum class AnimNodeNetworkMode : uint64_t
{
    ServerAuthoritative = 0x0,
    ClientSimulate = 0x1,
};

enum class CompositeMaterialMatchFilterType_t : uint64_t
{
    MATCH_FILTER_MATERIAL_ATTRIBUTE_EXISTS = 0x0,
    MATCH_FILTER_MATERIAL_SHADER = 0x1,
    MATCH_FILTER_MATERIAL_NAME_SUBSTR = 0x2,
    MATCH_FILTER_MATERIAL_ATTRIBUTE_EQUALS = 0x3,
    MATCH_FILTER_MATERIAL_PROPERTY_EXISTS = 0x4,
    MATCH_FILTER_MATERIAL_PROPERTY_EQUALS = 0x5,
};

enum class AnimPoseControl : uint64_t
{
    NoPoseControl = 0x0,
    AbsolutePoseControl = 0x1,
    RelativePoseControl = 0x2,
};

enum class EMidiNote : uint64_t
{
    C = 0x0,
    C_Sharp = 0x1,
    D = 0x2,
    D_Sharp = 0x3,
    E = 0x4,
    F = 0x5,
    F_Sharp = 0x6,
    G = 0x7,
    G_Sharp = 0x8,
    A = 0x9,
    A_Sharp = 0xa,
    B = 0xb,
    Count = 0xc,
};

enum class FootLockSubVisualization : uint64_t
{
    FOOTLOCKSUBVISUALIZATION_ReachabilityAnalysis = 0x0,
    FOOTLOCKSUBVISUALIZATION_IKSolve = 0x1,
};

enum class PulseValueType_t : uint64_t
{
    PVAL_INVALID = 0xffffffffffffffff,
    PVAL_BOOL = 0x0,
    PVAL_INT = 0x1,
    PVAL_FLOAT = 0x2,
    PVAL_STRING = 0x3,
    PVAL_VEC3 = 0x4,
    PVAL_TRANSFORM = 0x5,
    PVAL_COLOR_RGB = 0x6,
    PVAL_EHANDLE = 0x7,
    PVAL_RESOURCE = 0x8,
    PVAL_SNDEVT_GUID = 0x9,
    PVAL_ENTITY_NAME = 0xa,
    PVAL_OPAQUE_HANDLE = 0xb,
    PVAL_TYPESAFE_INT = 0xc,
    PVAL_CURSOR_FLOW = 0xd,
    PVAL_ANY = 0xe,
    PVAL_SCHEMA_ENUM = 0xf,
    PVAL_PANORAMA_PANEL_HANDLE = 0x10,
    PVAL_TEST_HANDLE = 0x11,
    PVAL_COUNT = 0x12,
};

enum class FacingMode : uint64_t
{
    FacingMode_Invalid = 0x0,
    FacingMode_Manual = 0x1,
    FacingMode_Path = 0x2,
    FacingMode_LookTarget = 0x3,
    FacingMode_ManualPosition = 0x4,
};

enum class SeqCmd_t : uint64_t
{
    SeqCmd_Nop = 0x0,
    SeqCmd_LinearDelta = 0x1,
    SeqCmd_FetchFrameRange = 0x2,
    SeqCmd_Slerp = 0x3,
    SeqCmd_Add = 0x4,
    SeqCmd_Subtract = 0x5,
    SeqCmd_Scale = 0x6,
    SeqCmd_Copy = 0x7,
    SeqCmd_Blend = 0x8,
    SeqCmd_Worldspace = 0x9,
    SeqCmd_Sequence = 0xa,
    SeqCmd_FetchCycle = 0xb,
    SeqCmd_FetchFrame = 0xc,
    SeqCmd_IKLockInPlace = 0xd,
    SeqCmd_IKRestoreAll = 0xe,
    SeqCmd_ReverseSequence = 0xf,
    SeqCmd_Transform = 0x10,
};

enum class ChoiceBlendMethod : uint64_t
{
    SingleBlendTime = 0x0,
    PerChoiceBlendTimes = 0x1,
};

enum class ParticleParentSetMode_t : uint64_t
{
    PARTICLE_SET_PARENT_NO = 0x0,
    PARTICLE_SET_PARENT_IMMEDIATE = 0x1,
    PARTICLE_SET_PARENT_ROOT = 0x1,
};

enum class EPulseGraphExecutionHistoryFlag : uint64_t
{
    NO_FLAGS = 0x0,
    CURSOR_ADD_TAG = 0x1,
    CURSOR_REMOVE_TAG = 0x2,
    CURSOR_RETIRED = 0x4,
    REQUIREMENT_PASS = 0x8,
    REQUIREMENT_FAIL = 0x10,
};

enum class VMixProcessorType_t : uint64_t
{
    VPROCESSOR_UNKNOWN = 0x0,
    VPROCESSOR_RT_PITCH = 0x1,
    VPROCESSOR_STEAMAUDIO_HRTF = 0x2,
    VPROCESSOR_DYNAMICS = 0x3,
    VPROCESSOR_PRESETDSP = 0x4,
    VPROCESSOR_DELAY = 0x5,
    VPROCESSOR_MOD_DELAY = 0x6,
    VPROCESSOR_DIFFUSOR = 0x7,
    VPROCESSOR_BOXVERB = 0x8,
    VPROCESSOR_FREEVERB = 0x9,
    VPROCESSOR_PLATEVERB = 0xa,
    VPROCESSOR_FULLWAVE_INTEGRATOR = 0xb,
    VPROCESSOR_FILTER = 0xc,
    VPROCESSOR_STEAMAUDIO_PATHING = 0xd,
    VPROCESSOR_EQ8 = 0xe,
    VPROCESSOR_ENVELOPE = 0xf,
    VPROCESSOR_VOCODER = 0x10,
    VPROCESSOR_CONVOLUTION = 0x11,
    VPROCESSOR_DYNAMICS_3BAND = 0x12,
    VPROCESSOR_DYNAMICS_COMPRESSOR = 0x13,
    VPROCESSOR_SHAPER = 0x14,
    VPROCESSOR_PANNER = 0x15,
    VPROCESSOR_UTILITY = 0x16,
    VPROCESSOR_AUTOFILTER = 0x17,
    VPROCESSOR_OSC = 0x18,
    VPROCESSOR_STEREODELAY = 0x19,
    VPROCESSOR_EFFECT_CHAIN = 0x1a,
    VPROCESSOR_SUBGRAPH_SWITCH = 0x1b,
    VPROCESSOR_STEAMAUDIO_DIRECT = 0x1c,
    VPROCESSOR_STEAMAUDIO_HYBRIDREVERB = 0x1d,
};

enum class PlayBackMode_t : uint64_t
{
    Random = 0x0,
    RandomNoRepeats = 0x1,
    RandomAvoidLast = 0x2,
    Sequential = 0x3,
};

enum class ChoiceChangeMethod : uint64_t
{
    OnReset = 0x0,
    OnCycleEnd = 0x1,
    OnResetOrCycleEnd = 0x2,
};

enum class CNmTransitionNode__TransitionOptions_t : uint64_t
{
    None = 0x0,
    ClampDuration = 0x1,
    Synchronized = 0x2,
    MatchSourceTime = 0x4,
    MatchSyncEventIndex = 0x8,
    MatchSyncEventID = 0x10,
    MatchSyncEventPercentage = 0x20,
    PreferClosestSyncEventID = 0x40,
};

enum class BinaryNodeChildOption : uint64_t
{
    Child1 = 0x0,
    Child2 = 0x1,
};

enum class CompositeMaterialInputTextureType_t : uint64_t
{
    INPUT_TEXTURE_TYPE_DEFAULT = 0x0,
    INPUT_TEXTURE_TYPE_NORMALMAP = 0x1,
    INPUT_TEXTURE_TYPE_COLOR = 0x2,
    INPUT_TEXTURE_TYPE_MASKS = 0x3,
    INPUT_TEXTURE_TYPE_ROUGHNESS = 0x4,
    INPUT_TEXTURE_TYPE_PEARLESCENCE_MASK = 0x5,
    INPUT_TEXTURE_TYPE_AO = 0x6,
};

enum class BoneMaskBlendSpace : uint64_t
{
    BlendSpace_Parent = 0x0,
    BlendSpace_Model = 0x1,
    BlendSpace_Model_RotationOnly = 0x2,
    BlendSpace_Model_TranslationOnly = 0x3,
};

enum class AnimScriptType : uint64_t
{
    ANIMSCRIPT_TYPE_INVALID = 0xffffffffffffffff,
    ANIMSCRIPT_FUSE_GENERAL = 0x0,
    ANIMSCRIPT_FUSE_STATEMACHINE = 0x1,
};

enum class FuseVariableAccess_t : uint64_t
{
    WRITABLE = 0x0,
    READ_ONLY = 0x1,
};

enum class DetailCombo_t : uint64_t
{
    DETAIL_COMBO_OFF = 0x0,
    DETAIL_COMBO_ADD = 0x1,
    DETAIL_COMBO_ADD_SELF_ILLUM = 0x2,
    DETAIL_COMBO_MOD2X = 0x3,
};

enum class HandshakeTagType_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eTask = 0x0,
    eMovement = 0x1,
    eCount = 0x2,
};

enum class InheritableBoolType_t : uint64_t
{
    INHERITABLE_BOOL_INHERIT = 0x0,
    INHERITABLE_BOOL_FALSE = 0x1,
    INHERITABLE_BOOL_TRUE = 0x2,
};

enum class ParticleTransformType_t : uint64_t
{
    PT_TYPE_INVALID = 0x0,
    PT_TYPE_NAMED_VALUE = 0x1,
    PT_TYPE_CONTROL_POINT = 0x2,
    PT_TYPE_CONTROL_POINT_RANGE = 0x3,
    PT_TYPE_COUNT = 0x4,
};

enum class ParticleHitboxDataSelection_t : uint64_t
{
    PARTICLE_HITBOX_AVERAGE_SPEED = 0x0,
    PARTICLE_HITBOX_COUNT = 0x1,
};

enum class AnimVectorSource : uint64_t
{
    MoveDirection = 0x0,
    FacingDirection = 0x1,
    LookDirection = 0x2,
    VectorParameter = 0x3,
    WayPointDirection = 0x4,
    Acceleration = 0x5,
    SlopeNormal = 0x6,
    SlopeNormal_WorldSpace = 0x7,
    LookTarget = 0x8,
    LookTarget_WorldSpace = 0x9,
    WayPointPosition = 0xa,
    GoalPosition = 0xb,
    RootMotionVelocity = 0xc,
    ManualTarget_WorldSpace = 0xd,
};

enum class TextureRepetitionMode_t : uint64_t
{
    TEXTURE_REPETITION_PARTICLE = 0x0,
    TEXTURE_REPETITION_PATH = 0x1,
};

enum class IKTargetCoordinateSystem : uint64_t
{
    IKTARGETCOORDINATESYSTEM_WorldSpace = 0x0,
    IKTARGETCOORDINATESYSTEM_ModelSpace = 0x1,
    IKTARGETCOORDINATESYSTEM_COUNT = 0x2,
};

enum class StandardLightingAttenuationStyle_t : uint64_t
{
    LIGHT_STYLE_OLD = 0x0,
    LIGHT_STYLE_NEW = 0x1,
};

enum class PoseType_t : uint64_t
{
    POSETYPE_STATIC = 0x0,
    POSETYPE_DYNAMIC = 0x1,
    POSETYPE_INVALID = 0xff,
};

enum class FuseVariableType_t : uint64_t
{
    INVALID = 0x0,
    BOOL = 0x1,
    INT8 = 0x2,
    INT16 = 0x3,
    INT32 = 0x4,
    UINT8 = 0x5,
    UINT16 = 0x6,
    UINT32 = 0x7,
    FLOAT32 = 0x8,
};

enum class ParticleTraceSet_t : uint64_t
{
    PARTICLE_TRACE_SET_ALL = 0x0,
    PARTICLE_TRACE_SET_STATIC = 0x1,
    PARTICLE_TRACE_SET_STATIC_AND_KEYFRAMED = 0x2,
    PARTICLE_TRACE_SET_DYNAMIC = 0x3,
};

enum class ModelSkeletonData_t__BoneFlags_t : uint64_t
{
    FLAG_NO_BONE_FLAGS = 0x0,
    FLAG_BONEFLEXDRIVER = 0x4,
    FLAG_CLOTH = 0x8,
    FLAG_PHYSICS = 0x10,
    FLAG_ATTACHMENT = 0x20,
    FLAG_ANIMATION = 0x40,
    FLAG_MESH = 0x80,
    FLAG_HITBOX = 0x100,
    FLAG_BONE_USED_BY_VERTEX_LOD0 = 0x400,
    FLAG_BONE_USED_BY_VERTEX_LOD1 = 0x800,
    FLAG_BONE_USED_BY_VERTEX_LOD2 = 0x1000,
    FLAG_BONE_USED_BY_VERTEX_LOD3 = 0x2000,
    FLAG_BONE_USED_BY_VERTEX_LOD4 = 0x4000,
    FLAG_BONE_USED_BY_VERTEX_LOD5 = 0x8000,
    FLAG_BONE_USED_BY_VERTEX_LOD6 = 0x10000,
    FLAG_BONE_USED_BY_VERTEX_LOD7 = 0x20000,
    FLAG_BONE_MERGE_READ = 0x40000,
    FLAG_BONE_MERGE_WRITE = 0x80000,
    FLAG_ALL_BONE_FLAGS = 0xfffff,
    BLEND_PREALIGNED = 0x100000,
    FLAG_RIGIDLENGTH = 0x200000,
    FLAG_PROCEDURAL = 0x400000,
};

enum class ParticleLightBehaviorChoiceList_t : uint64_t
{
    PARTICLE_LIGHT_BEHAVIOR_FOLLOW_DIRECTION = 0x0,
    PARTICLE_LIGHT_BEHAVIOR_ROPE = 0x1,
    PARTICLE_LIGHT_BEHAVIOR_TRAILS = 0x2,
};

enum class CompositeMaterialInputContainerSourceType_t : uint64_t
{
    CONTAINER_SOURCE_TYPE_TARGET_MATERIAL = 0x0,
    CONTAINER_SOURCE_TYPE_MATERIAL_FROM_TARGET_ATTR = 0x1,
    CONTAINER_SOURCE_TYPE_SPECIFIC_MATERIAL = 0x2,
    CONTAINER_SOURCE_TYPE_LOOSE_VARIABLES = 0x3,
    CONTAINER_SOURCE_TYPE_VARIABLE_FROM_TARGET_ATTR = 0x4,
    CONTAINER_SOURCE_TYPE_TARGET_INSTANCE_MATERIAL = 0x5,
};

enum class ParticleSortingChoiceList_t : uint64_t
{
    PARTICLE_SORTING_NEAREST = 0x0,
    PARTICLE_SORTING_CREATION_TIME = 0x1,
};

enum class SosActionSortType_t : uint64_t
{
    SOS_SORTTYPE_HIGHEST = 0x0,
    SOS_SORTTYPE_LOWEST = 0x1,
};

enum class ParticleFalloffFunction_t : uint64_t
{
    PARTICLE_FALLOFF_CONSTANT = 0x0,
    PARTICLE_FALLOFF_LINEAR = 0x1,
    PARTICLE_FALLOFF_EXPONENTIAL = 0x2,
};

enum class JumpCorrectionMethod : uint64_t
{
    ScaleMotion = 0x0,
    AddCorrectionDelta = 0x1,
};

enum class PetGroundType_t : uint64_t
{
    PET_GROUND_NONE = 0x0,
    PET_GROUND_GRID = 0x1,
    PET_GROUND_PLANE = 0x2,
};

enum class VMixChannelOperation_t : uint64_t
{
    VMIX_CHAN_STEREO = 0x0,
    VMIX_CHAN_LEFT = 0x1,
    VMIX_CHAN_RIGHT = 0x2,
    VMIX_CHAN_SWAP = 0x3,
    VMIX_CHAN_MONO = 0x4,
    VMIX_CHAN_MID_SIDE = 0x5,
};

enum class MatterialAttributeTagType_t : uint64_t
{
    MATERIAL_ATTRIBUTE_TAG_VALUE = 0x0,
    MATERIAL_ATTRIBUTE_TAG_COLOR = 0x1,
};

enum class ParticleDirectionNoiseType_t : uint64_t
{
    PARTICLE_DIR_NOISE_PERLIN = 0x0,
    PARTICLE_DIR_NOISE_CURL = 0x1,
    PARTICLE_DIR_NOISE_WORLEY_BASIC = 0x2,
};

enum class InputLayoutVariation_t : uint64_t
{
    INPUT_LAYOUT_VARIATION_DEFAULT = 0x0,
    INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID = 0x1,
    INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID_MORPH_VERT_ID = 0x2,
    INPUT_LAYOUT_VARIATION_MAX = 0x3,
};

enum class CAnimationGraphVisualizerPrimitiveType : uint64_t
{
    ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Text = 0x0,
    ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Sphere = 0x1,
    ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Line = 0x2,
    ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Pie = 0x3,
    ANIMATIONGRAPHVISUALIZERPRIMITIVETYPE_Axis = 0x4,
};

enum class BlendKeyType : uint64_t
{
    BlendKey_UserValue = 0x0,
    BlendKey_Velocity = 0x1,
    BlendKey_Distance = 0x2,
    BlendKey_RemainingDistance = 0x3,
};

enum class ParticlePinDistance_t : uint64_t
{
    PARTICLE_PIN_DISTANCE_NONE = 0xffffffffffffffff,
    PARTICLE_PIN_DISTANCE_NEIGHBOR = 0x0,
    PARTICLE_PIN_DISTANCE_FARTHEST = 0x1,
    PARTICLE_PIN_DISTANCE_FIRST = 0x2,
    PARTICLE_PIN_DISTANCE_LAST = 0x3,
    PARTICLE_PIN_DISTANCE_CENTER = 0x5,
    PARTICLE_PIN_DISTANCE_CP = 0x6,
    PARTICLE_PIN_DISTANCE_CP_PAIR_EITHER = 0x7,
    PARTICLE_PIN_DISTANCE_CP_PAIR_BOTH = 0x8,
    PARTICLE_PIN_SPEED = 0x9,
    PARTICLE_PIN_COLLECTION_AGE = 0xa,
    PARTICLE_PIN_FLOAT_VALUE = 0xb,
};

enum class SpriteCardTextureChannel_t : uint64_t
{
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGB = 0x0,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA = 0x1,
    SPRITECARD_TEXTURE_CHANNEL_MIX_A = 0x2,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A = 0x3,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_ALPHAMASK = 0x4,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_RGBMASK = 0x5,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA_RGBALPHA = 0x6,
    SPRITECARD_TEXTURE_CHANNEL_MIX_A_RGBALPHA = 0x7,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A_RGBALPHA = 0x8,
    SPRITECARD_TEXTURE_CHANNEL_MIX_R = 0x9,
    SPRITECARD_TEXTURE_CHANNEL_MIX_G = 0xa,
    SPRITECARD_TEXTURE_CHANNEL_MIX_B = 0xb,
    SPRITECARD_TEXTURE_CHANNEL_MIX_RALPHA = 0xc,
    SPRITECARD_TEXTURE_CHANNEL_MIX_GALPHA = 0xd,
    SPRITECARD_TEXTURE_CHANNEL_MIX_BALPHA = 0xe,
};

enum class VertJustification_e : uint64_t
{
    VERT_JUSTIFICATION_TOP = 0x0,
    VERT_JUSTIFICATION_CENTER = 0x1,
    VERT_JUSTIFICATION_BOTTOM = 0x2,
    VERT_JUSTIFICATION_NONE = 0x3,
};

enum class HorizJustification_e : uint64_t
{
    HORIZ_JUSTIFICATION_LEFT = 0x0,
    HORIZ_JUSTIFICATION_CENTER = 0x1,
    HORIZ_JUSTIFICATION_RIGHT = 0x2,
    HORIZ_JUSTIFICATION_NONE = 0x3,
};

enum class EDemoBoneSelectionMode : uint64_t
{
    CaptureAllBones = 0x0,
    CaptureSelectedBones = 0x1,
};

enum class SeqPoseSetting_t : uint64_t
{
    SEQ_POSE_SETTING_CONSTANT = 0x0,
    SEQ_POSE_SETTING_ROTATION = 0x1,
    SEQ_POSE_SETTING_POSITION = 0x2,
    SEQ_POSE_SETTING_VELOCITY = 0x3,
};

enum class MorphFlexControllerRemapType_t : uint64_t
{
    MORPH_FLEXCONTROLLER_REMAP_PASSTHRU = 0x0,
    MORPH_FLEXCONTROLLER_REMAP_2WAY = 0x1,
    MORPH_FLEXCONTROLLER_REMAP_NWAY = 0x2,
    MORPH_FLEXCONTROLLER_REMAP_EYELID = 0x3,
};

enum class NmGraphValueType_t : uint64_t
{
    Unknown = 0x0,
    Bool = 0x1,
    ID = 0x2,
    Float = 0x3,
    Vector = 0x4,
    Target = 0x5,
    BoneMask = 0x6,
    Pose = 0x7,
    Special = 0x8,
};

enum class SpawnDebugOverrideState_t : uint64_t
{
    SPAWN_DEBUG_OVERRIDE_NONE = 0x0,
    SPAWN_DEBUG_OVERRIDE_FORCE_ENABLED = 0x1,
    SPAWN_DEBUG_OVERRIDE_FORCE_DISABLED = 0x2,
};

enum class ParticleLightnintBranchBehavior_t : uint64_t
{
    PARTICLE_LIGHTNING_BRANCH_CURRENT_DIR = 0x0,
    PARTICLE_LIGHTNING_BRANCH_ENDPOINT_DIR = 0x1,
};

enum class MorphBundleType_t : uint64_t
{
    MORPH_BUNDLE_TYPE_NONE = 0x0,
    MORPH_BUNDLE_TYPE_POSITION_SPEED = 0x1,
    MORPH_BUNDLE_TYPE_NORMAL_WRINKLE = 0x2,
    MORPH_BUNDLE_TYPE_COUNT = 0x3,
};

enum class ParticleLightFogLightingMode_t : uint64_t
{
    PARTICLE_LIGHT_FOG_LIGHTING_MODE_NONE = 0x0,
    PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC = 0x2,
    PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC_NOSHADOWS = 0x4,
};

enum class RenderBufferFlags_t : uint64_t
{
    RENDER_BUFFER_USAGE_VERTEX_BUFFER = 0x1,
    RENDER_BUFFER_USAGE_INDEX_BUFFER = 0x2,
    RENDER_BUFFER_USAGE_SHADER_RESOURCE = 0x4,
    RENDER_BUFFER_USAGE_UNORDERED_ACCESS = 0x8,
    RENDER_BUFFER_BYTEADDRESS_BUFFER = 0x10,
    RENDER_BUFFER_STRUCTURED_BUFFER = 0x20,
    RENDER_BUFFER_APPEND_CONSUME_BUFFER = 0x40,
    RENDER_BUFFER_UAV_COUNTER = 0x80,
    RENDER_BUFFER_UAV_DRAW_INDIRECT_ARGS = 0x100,
    RENDER_BUFFER_ACCELERATION_STRUCTURE = 0x200,
    RENDER_BUFFER_SHADER_BINDING_TABLE = 0x400,
    RENDER_BUFFER_PER_FRAME_WRITE_ONCE = 0x800,
    RENDER_BUFFER_POOL_ALLOCATED = 0x1000,
};

enum class ParticleDetailLevel_t : uint64_t
{
    PARTICLEDETAIL_LOW = 0x0,
    PARTICLEDETAIL_MEDIUM = 0x1,
    PARTICLEDETAIL_HIGH = 0x2,
    PARTICLEDETAIL_ULTRA = 0x3,
};

enum class ModelHitboxType_t : uint64_t
{
    MODEL_HITBOX_TYPE_STANDARD = 0x0,
    MODEL_HITBOX_TYPE_RAW_BONES = 0x1,
    MODEL_HITBOX_TYPE_RENDERBOUNDS = 0x2,
    MODEL_HITBOX_TYPE_SNAPSHOT = 0x3,
};

enum class FootstepLandedFootSoundType_t : uint64_t
{
    FOOTSOUND_Left = 0x0,
    FOOTSOUND_Right = 0x1,
    FOOTSOUND_UseOverrideSound = 0x2,
};

enum class SosEditItemType_t : uint64_t
{
    SOS_EDIT_ITEM_TYPE_SOUNDEVENTS = 0x0,
    SOS_EDIT_ITEM_TYPE_SOUNDEVENT = 0x1,
    SOS_EDIT_ITEM_TYPE_LIBRARYSTACKS = 0x2,
    SOS_EDIT_ITEM_TYPE_STACK = 0x3,
    SOS_EDIT_ITEM_TYPE_OPERATOR = 0x4,
    SOS_EDIT_ITEM_TYPE_FIELD = 0x5,
};

enum class PulseDomainValueType_t : uint64_t
{
    INVALID = 0xffffffffffffffff,
    ENTITY_NAME = 0x0,
    PANEL_ID = 0x1,
    COUNT = 0x2,
};

enum class SosActionStopType_t : uint64_t
{
    SOS_STOPTYPE_NONE = 0x0,
    SOS_STOPTYPE_TIME = 0x1,
    SOS_STOPTYPE_OPVAR = 0x2,
};

enum class ModelBoneFlexComponent_t : uint64_t
{
    MODEL_BONE_FLEX_INVALID = 0xffffffffffffffff,
    MODEL_BONE_FLEX_TX = 0x0,
    MODEL_BONE_FLEX_TY = 0x1,
    MODEL_BONE_FLEX_TZ = 0x2,
};

enum class ParticleAttachment_t : uint64_t
{
    PATTACH_INVALID = 0xffffffffffffffff,
    PATTACH_ABSORIGIN = 0x0,
    PATTACH_ABSORIGIN_FOLLOW = 0x1,
    PATTACH_CUSTOMORIGIN = 0x2,
    PATTACH_CUSTOMORIGIN_FOLLOW = 0x3,
    PATTACH_POINT = 0x4,
    PATTACH_POINT_FOLLOW = 0x5,
    PATTACH_EYES_FOLLOW = 0x6,
    PATTACH_OVERHEAD_FOLLOW = 0x7,
    PATTACH_WORLDORIGIN = 0x8,
    PATTACH_ROOTBONE_FOLLOW = 0x9,
    PATTACH_RENDERORIGIN_FOLLOW = 0xa,
    PATTACH_MAIN_VIEW = 0xb,
    PATTACH_WATERWAKE = 0xc,
    PATTACH_CENTER_FOLLOW = 0xd,
    PATTACH_CUSTOM_GAME_STATE_1 = 0xe,
    PATTACH_HEALTHBAR = 0xf,
    MAX_PATTACH_TYPES = 0x10,
};

enum class CompMatPropertyMutatorType_t : uint64_t
{
    COMP_MAT_PROPERTY_MUTATOR_INIT = 0x0,
    COMP_MAT_PROPERTY_MUTATOR_COPY_MATCHING_KEYS = 0x1,
    COMP_MAT_PROPERTY_MUTATOR_COPY_KEYS_WITH_SUFFIX = 0x2,
    COMP_MAT_PROPERTY_MUTATOR_COPY_PROPERTY = 0x3,
    COMP_MAT_PROPERTY_MUTATOR_SET_VALUE = 0x4,
    COMP_MAT_PROPERTY_MUTATOR_GENERATE_TEXTURE = 0x5,
    COMP_MAT_PROPERTY_MUTATOR_CONDITIONAL_MUTATORS = 0x6,
    COMP_MAT_PROPERTY_MUTATOR_POP_INPUT_QUEUE = 0x7,
    COMP_MAT_PROPERTY_MUTATOR_DRAW_TEXT = 0x8,
    COMP_MAT_PROPERTY_MUTATOR_RANDOM_ROLL_INPUT_VARIABLES = 0x9,
};

enum class ParticleMassMode_t : uint64_t
{
    PARTICLE_MASSMODE_RADIUS_CUBED = 0x0,
    PARTICLE_MASSMODE_RADIUS_SQUARED = 0x2,
};

enum class ParticleOrientationChoiceList_t : uint64_t
{
    PARTICLE_ORIENTATION_SCREEN_ALIGNED = 0x0,
    PARTICLE_ORIENTATION_SCREEN_Z_ALIGNED = 0x1,
    PARTICLE_ORIENTATION_WORLD_Z_ALIGNED = 0x2,
    PARTICLE_ORIENTATION_ALIGN_TO_PARTICLE_NORMAL = 0x3,
    PARTICLE_ORIENTATION_SCREENALIGN_TO_PARTICLE_NORMAL = 0x4,
    PARTICLE_ORIENTATION_FULL_3AXIS_ROTATION = 0x5,
};

enum class NmEasingFunction_t : uint64_t
{
    Linear = 0x0,
    Quad = 0x1,
    Cubic = 0x2,
    Quart = 0x3,
    Quint = 0x4,
    Sine = 0x5,
    Expo = 0x6,
    Circ = 0x7,
    Back = 0x8,
};

enum class NmFrameSnapEventMode_t : uint64_t
{
    Floor = 0x0,
    Round = 0x1,
};

enum class JiggleBoneSimSpace : uint64_t
{
    SimSpace_Local = 0x0,
    SimSpace_Model = 0x1,
    SimSpace_World = 0x2,
};

enum class ParticleTopology_t : uint64_t
{
    PARTICLE_TOPOLOGY_POINTS = 0x0,
    PARTICLE_TOPOLOGY_LINES = 0x1,
    PARTICLE_TOPOLOGY_TRIS = 0x2,
    PARTICLE_TOPOLOGY_QUADS = 0x3,
    PARTICLE_TOPOLOGY_CUBES = 0x4,
};

enum class DampingSpeedFunction : uint64_t
{
    NoDamping = 0x0,
    Constant = 0x1,
    Spring = 0x2,
};

enum class ParticleColorBlendType_t : uint64_t
{
    PARTICLE_COLOR_BLEND_MULTIPLY = 0x0,
    PARTICLE_COLOR_BLEND_MULTIPLY2X = 0x1,
    PARTICLE_COLOR_BLEND_DIVIDE = 0x2,
    PARTICLE_COLOR_BLEND_ADD = 0x3,
    PARTICLE_COLOR_BLEND_SUBTRACT = 0x4,
    PARTICLE_COLOR_BLEND_MOD2X = 0x5,
    PARTICLE_COLOR_BLEND_SCREEN = 0x6,
    PARTICLE_COLOR_BLEND_MAX = 0x7,
    PARTICLE_COLOR_BLEND_MIN = 0x8,
    PARTICLE_COLOR_BLEND_REPLACE = 0x9,
    PARTICLE_COLOR_BLEND_AVERAGE = 0xa,
    PARTICLE_COLOR_BLEND_NEGATE = 0xb,
    PARTICLE_COLOR_BLEND_LUMINANCE = 0xc,
};

enum class VMixSubgraphSwitchInterpolationType_t : uint64_t
{
    SUBGRAPH_INTERPOLATION_TEMPORAL_CROSSFADE = 0x0,
    SUBGRAPH_INTERPOLATION_TEMPORAL_FADE_OUT = 0x1,
    SUBGRAPH_INTERPOLATION_KEEP_LAST_SUBGRAPH_RUNNING = 0x2,
};

enum class AnimationSnapshotType_t : uint64_t
{
    ANIMATION_SNAPSHOT_SERVER_SIMULATION = 0x0,
    ANIMATION_SNAPSHOT_CLIENT_SIMULATION = 0x1,
    ANIMATION_SNAPSHOT_CLIENT_PREDICTION = 0x2,
    ANIMATION_SNAPSHOT_CLIENT_INTERPOLATION = 0x3,
    ANIMATION_SNAPSHOT_CLIENT_RENDER = 0x4,
    ANIMATION_SNAPSHOT_FINAL_COMPOSITE = 0x5,
    ANIMATION_SNAPSHOT_MAX = 0x6,
};

enum class SpriteCardPerParticleScale_t : uint64_t
{
    SPRITECARD_TEXTURE_PP_SCALE_NONE = 0x0,
    SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_AGE = 0x1,
    SPRITECARD_TEXTURE_PP_SCALE_ANIMATION_FRAME = 0x2,
    SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA1 = 0x3,
    SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA2 = 0x4,
    SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_ALPHA = 0x5,
    SPRITECARD_TEXTURE_PP_SCALE_SHADER_RADIUS = 0x6,
    SPRITECARD_TEXTURE_PP_SCALE_ROLL = 0x7,
    SPRITECARD_TEXTURE_PP_SCALE_YAW = 0x8,
    SPRITECARD_TEXTURE_PP_SCALE_PITCH = 0x9,
    SPRITECARD_TEXTURE_PP_SCALE_RANDOM = 0xa,
    SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM = 0xb,
    SPRITECARD_TEXTURE_PP_SCALE_RANDOM_TIME = 0xc,
    SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM_TIME = 0xd,
};

enum class EWaveform : uint64_t
{
    Sine = 0x0,
    Square = 0x1,
    Saw = 0x2,
    Triangle = 0x3,
    Noise = 0x4,
};

enum class SpriteCardShaderType_t : uint64_t
{
    SPRITECARD_SHADER_BASE = 0x0,
    SPRITECARD_SHADER_CUSTOM = 0x1,
};

enum class BBoxVolumeType_t : uint64_t
{
    BBOX_VOLUME = 0x0,
    BBOX_DIMENSIONS = 0x1,
    BBOX_MINS_MAXS = 0x2,
};

enum class PulseTestEnumColor_t : uint64_t
{
    BLACK = 0x0,
    WHITE = 0x1,
    RED = 0x2,
    GREEN = 0x3,
    BLUE = 0x4,
};

enum class ParticleCollisionMode_t : uint64_t
{
    COLLISION_MODE_PER_PARTICLE_TRACE = 0x3,
    COLLISION_MODE_USE_NEAREST_TRACE = 0x2,
    COLLISION_MODE_PER_FRAME_PLANESET = 0x1,
    COLLISION_MODE_INITIAL_TRACE_DOWN = 0x0,
    COLLISION_MODE_DISABLED = 0xffffffffffffffff,
};

enum class PermModelInfo_t__FlagEnum : uint64_t
{
    FLAG_TRANSLUCENT = 0x1,
    FLAG_TRANSLUCENT_TWO_PASS = 0x2,
    FLAG_MODEL_IS_RUNTIME_COMBINED = 0x4,
    FLAG_SOURCE1_IMPORT = 0x8,
    FLAG_MODEL_PART_CHILD = 0x10,
    FLAG_NAV_GEN_NONE = 0x20,
    FLAG_NAV_GEN_HULL = 0x40,
    FLAG_NO_FORCED_FADE = 0x800,
    FLAG_HAS_SKINNED_MESHES = 0x400,
    FLAG_DO_NOT_CAST_SHADOWS = 0x20000,
    FLAG_FORCE_PHONEME_CROSSFADE = 0x1000,
    FLAG_NO_ANIM_EVENTS = 0x100000,
    FLAG_ANIMATION_DRIVEN_FLEXES = 0x200000,
    FLAG_IMPLICIT_BIND_POSE_SEQUENCE = 0x400000,
    FLAG_MODEL_DOC = 0x800000,
};

enum class ParticleControlPointAxis_t : uint64_t
{
    PARTICLE_CP_AXIS_X = 0x0,
    PARTICLE_CP_AXIS_Y = 0x1,
    PARTICLE_CP_AXIS_Z = 0x2,
    PARTICLE_CP_AXIS_NEGATIVE_X = 0x3,
    PARTICLE_CP_AXIS_NEGATIVE_Y = 0x4,
    PARTICLE_CP_AXIS_NEGATIVE_Z = 0x5,
};

enum class ELayoutNodeType : uint64_t
{
    ROOT = 0x0,
    STYLES = 0x1,
    SCRIPT_BODY = 0x2,
    SCRIPTS = 0x3,
    SNIPPETS = 0x4,
    INCLUDE = 0x5,
    SNIPPET = 0x6,
    PANEL = 0x7,
    PANEL_ATTRIBUTE = 0x8,
    PANEL_ATTRIBUTE_VALUE = 0x9,
    REFERENCE_CONTENT = 0xa,
    REFERENCE_COMPILED = 0xb,
    REFERENCE_PASSTHROUGH = 0xc,
};

enum class IKChannelMode : uint64_t
{
    TwoBone = 0x0,
    TwoBone_Translate = 0x1,
    OneBone = 0x2,
    OneBone_Translate = 0x3,
};

enum class PulseTestEnumShape_t : uint64_t
{
    CIRCLE = 0x64,
    SQUARE = 0xc8,
    TRIANGLE = 0x12c,
};

enum class NmEasingOperation_t : uint64_t
{
    Linear = 0x0,
    InQuad = 0x1,
    OutQuad = 0x2,
    InOutQuad = 0x3,
    InCubic = 0x4,
    OutCubic = 0x5,
    InOutCubic = 0x6,
    InQuart = 0x7,
    OutQuart = 0x8,
    InOutQuart = 0x9,
    InQuint = 0xa,
    OutQuint = 0xb,
    InOutQuint = 0xc,
    InSine = 0xd,
    OutSine = 0xe,
    InOutSine = 0xf,
    InExpo = 0x10,
    OutExpo = 0x11,
    InOutExpo = 0x12,
    InCirc = 0x13,
    OutCirc = 0x14,
    InOutCirc = 0x15,
    None = 0x16,
};

enum class ParticleColorBlendMode_t : uint64_t
{
    PARTICLEBLEND_DEFAULT = 0x0,
    PARTICLEBLEND_OVERLAY = 0x1,
    PARTICLEBLEND_DARKEN = 0x2,
    PARTICLEBLEND_LIGHTEN = 0x3,
    PARTICLEBLEND_MULTIPLY = 0x4,
};

enum class AnimParamType_t : uint64_t
{
    ANIMPARAM_UNKNOWN = 0x0,
    ANIMPARAM_BOOL = 0x1,
    ANIMPARAM_ENUM = 0x2,
    ANIMPARAM_INT = 0x3,
    ANIMPARAM_FLOAT = 0x4,
    ANIMPARAM_VECTOR = 0x5,
    ANIMPARAM_QUATERNION = 0x6,
    ANIMPARAM_GLOBALSYMBOL = 0x7,
    ANIMPARAM_COUNT = 0x8,
};

enum class ParticleLightUnitChoiceList_t : uint64_t
{
    PARTICLE_LIGHT_UNIT_CANDELAS = 0x0,
    PARTICLE_LIGHT_UNIT_LUMENS = 0x1,
};

enum class VMixLFOShape_t : uint64_t
{
    LFO_SHAPE_SINE = 0x0,
    LFO_SHAPE_SQUARE = 0x1,
    LFO_SHAPE_TRI = 0x2,
    LFO_SHAPE_SAW = 0x3,
    LFO_SHAPE_NOISE = 0x4,
};

enum class IkEndEffectorType : uint64_t
{
    IkEndEffector_Attachment = 0x0,
    IkEndEffector_Bone = 0x1,
};

enum class EStyleNodeType : uint64_t
{
    ROOT = 0x0,
    EXPRESSION = 0x1,
    PROPERTY = 0x2,
    DEFINE = 0x3,
    IMPORT = 0x4,
    KEYFRAMES = 0x5,
    KEYFRAME_SELECTOR = 0x6,
    STYLE_SELECTOR = 0x7,
    WHITESPACE = 0x8,
    EXPRESSION_TEXT = 0x9,
    EXPRESSION_URL = 0xa,
    EXPRESSION_CONCAT = 0xb,
    REFERENCE_CONTENT = 0xc,
    REFERENCE_COMPILED = 0xd,
    REFERENCE_PASSTHROUGH = 0xe,
    COMPILER_CONDITIONAL = 0xf,
};

enum class FieldNetworkOption : uint64_t
{
    Auto = 0x0,
    ForceEnable = 0x1,
    ForceDisable = 0x2,
};

enum class VelocityMetricMode : uint64_t
{
    DirectionOnly = 0x0,
    MagnitudeOnly = 0x1,
    DirectionAndMagnitude = 0x2,
};

enum class IkTargetType : uint64_t
{
    IkTarget_Attachment = 0x0,
    IkTarget_Bone = 0x1,
    IkTarget_Parameter_ModelSpace = 0x2,
    IkTarget_Parameter_WorldSpace = 0x3,
};

enum class FootPinningTimingSource : uint64_t
{
    FootMotion = 0x0,
    Tag = 0x1,
    Parameter = 0x2,
};

enum class PFNoiseType_t : uint64_t
{
    PF_NOISE_TYPE_PERLIN = 0x0,
    PF_NOISE_TYPE_SIMPLEX = 0x1,
    PF_NOISE_TYPE_WORLEY = 0x2,
    PF_NOISE_TYPE_CURL = 0x3,
};

enum class ParticleFloatBiasType_t : uint64_t
{
    PF_BIAS_TYPE_INVALID = 0xffffffffffffffff,
    PF_BIAS_TYPE_STANDARD = 0x0,
    PF_BIAS_TYPE_GAIN = 0x1,
    PF_BIAS_TYPE_EXPONENTIAL = 0x2,
    PF_BIAS_TYPE_COUNT = 0x3,
};

enum class ParticleDepthFeatheringMode_t : uint64_t
{
    PARTICLE_DEPTH_FEATHERING_OFF = 0x0,
    PARTICLE_DEPTH_FEATHERING_ON_OPTIONAL = 0x1,
    PARTICLE_DEPTH_FEATHERING_ON_REQUIRED = 0x2,
};

enum class ParticleSequenceCropOverride_t : uint64_t
{
    PARTICLE_SEQUENCE_CROP_OVERRIDE_DEFAULT = 0xffffffffffffffff,
    PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_OFF = 0x0,
    PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_ON = 0x1,
};

enum class RenderSlotType_t : uint64_t
{
    RENDER_SLOT_INVALID = 0xffffffffffffffff,
    RENDER_SLOT_PER_VERTEX = 0x0,
    RENDER_SLOT_PER_INSTANCE = 0x1,
};

enum class VPhysXConstraintParams_t__EnumFlags0_t : uint64_t
{
    FLAG0_SHIFT_INTERPENETRATE = 0x0,
    FLAG0_SHIFT_CONSTRAIN = 0x1,
    FLAG0_SHIFT_BREAKABLE_FORCE = 0x2,
    FLAG0_SHIFT_BREAKABLE_TORQUE = 0x3,
};

enum class AnimValueSource : uint64_t
{
    MoveHeading = 0x0,
    MoveSpeed = 0x1,
    ForwardSpeed = 0x2,
    StrafeSpeed = 0x3,
    FacingHeading = 0x4,
    LookHeading = 0x5,
    LookPitch = 0x6,
    LookDistance = 0x7,
    Parameter = 0x8,
    WayPointHeading = 0x9,
    WayPointDistance = 0xa,
    BoundaryRadius = 0xb,
    TargetMoveHeading = 0xc,
    TargetMoveSpeed = 0xd,
    AccelerationHeading = 0xe,
    AccelerationSpeed = 0xf,
    SlopeHeading = 0x10,
    SlopeAngle = 0x11,
    SlopePitch = 0x12,
    SlopeYaw = 0x13,
    GoalDistance = 0x14,
    AccelerationLeftRight = 0x15,
    AccelerationFrontBack = 0x16,
    RootMotionSpeed = 0x17,
    RootMotionTurnSpeed = 0x18,
    MoveHeadingRelativeToLookHeading = 0x19,
    MaxMoveSpeed = 0x1a,
    FingerCurl_Thumb = 0x1b,
    FingerCurl_Index = 0x1c,
    FingerCurl_Middle = 0x1d,
    FingerCurl_Ring = 0x1e,
    FingerCurl_Pinky = 0x1f,
    FingerSplay_Thumb_Index = 0x20,
    FingerSplay_Index_Middle = 0x21,
    FingerSplay_Middle_Ring = 0x22,
    FingerSplay_Ring_Pinky = 0x23,
};

enum class HitboxLerpType_t : uint64_t
{
    HITBOX_LERP_LIFETIME = 0x0,
    HITBOX_LERP_CONSTANT = 0x1,
};

enum class RenderModelSubModelFieldType_t : uint64_t
{
    SUBMODEL_AS_BODYGROUP_SUBMODEL = 0x0,
    SUBMODEL_AS_MESHGROUP_INDEX = 0x1,
    SUBMODEL_AS_MESHGROUP_MASK = 0x2,
    SUBMODEL_IGNORED_USE_MODEL_DEFAULT_MESHGROUP_MASK = 0x3,
};

enum class BoneTransformSpace_t : uint64_t
{
    BoneTransformSpace_Invalid = 0xffffffffffffffff,
    BoneTransformSpace_Parent = 0x0,
    BoneTransformSpace_Model = 0x1,
    BoneTransformSpace_World = 0x2,
};

enum class VPhysXBodyPart_t__VPhysXFlagEnum_t : uint64_t
{
    FLAG_STATIC = 0x1,
    FLAG_KINEMATIC = 0x2,
    FLAG_JOINT = 0x4,
    FLAG_MASS = 0x8,
    FLAG_ALWAYS_DYNAMIC_ON_CLIENT = 0x10,
};

enum class ParticleTraceMissBehavior_t : uint64_t
{
    PARTICLE_TRACE_MISS_BEHAVIOR_NONE = 0x0,
    PARTICLE_TRACE_MISS_BEHAVIOR_KILL = 0x1,
    PARTICLE_TRACE_MISS_BEHAVIOR_TRACE_END = 0x2,
};

enum class NmFootPhase_t : uint64_t
{
    LeftFootDown = 0x0,
    RightFootPassing = 0x1,
    RightFootDown = 0x2,
    LeftFootPassing = 0x3,
};

enum class ParticleOmni2LightTypeChoiceList_t : uint64_t
{
    PARTICLE_OMNI2_LIGHT_TYPE_POINT = 0x0,
    PARTICLE_OMNI2_LIGHT_TYPE_SPHERE = 0x1,
};

enum class BinaryNodeTiming : uint64_t
{
    UseChild1 = 0x0,
    UseChild2 = 0x1,
    SyncChildren = 0x2,
};

enum class StepPhase : uint64_t
{
    StepPhase_OnGround = 0x0,
    StepPhase_InAir = 0x1,
};

enum class ScalarExpressionType_t : uint64_t
{
    SCALAR_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    SCALAR_EXPRESSION_ADD = 0x0,
    SCALAR_EXPRESSION_SUBTRACT = 0x1,
    SCALAR_EXPRESSION_MUL = 0x2,
    SCALAR_EXPRESSION_DIVIDE = 0x3,
    SCALAR_EXPRESSION_INPUT_1 = 0x4,
    SCALAR_EXPRESSION_MIN = 0x5,
    SCALAR_EXPRESSION_MAX = 0x6,
    SCALAR_EXPRESSION_MOD = 0x7,
};

enum class ResetCycleOption : uint64_t
{
    Beginning = 0x0,
    SameCycleAsSource = 0x1,
    InverseSourceCycle = 0x2,
    FixedValue = 0x3,
    SameTimeAsSource = 0x4,
};

enum class ModelConfigAttachmentType_t : uint64_t
{
    MODEL_CONFIG_ATTACHMENT_INVALID = 0xffffffffffffffff,
    MODEL_CONFIG_ATTACHMENT_BONE_OR_ATTACHMENT = 0x0,
    MODEL_CONFIG_ATTACHMENT_ROOT_RELATIVE = 0x1,
    MODEL_CONFIG_ATTACHMENT_BONEMERGE = 0x2,
    MODEL_CONFIG_ATTACHMENT_COUNT = 0x3,
};

enum class ActionType_t : uint64_t
{
    SOS_ACTION_NONE = 0x0,
    SOS_ACTION_LIMITER = 0x1,
    SOS_ACTION_TIME_LIMIT = 0x2,
    SOS_ACTION_TIME_BLOCK_LIMITER = 0x3,
    SOS_ACTION_SET_SOUNDEVENT_PARAM = 0x4,
    SOS_ACTION_SOUNDEVENT_CLUSTER = 0x5,
    SOS_ACTION_SOUNDEVENT_PRIORITY = 0x6,
    SOS_ACTION_COUNT_ENVELOPE = 0x7,
};

enum class MoodType_t : uint64_t
{
    eMoodType_Head = 0x0,
    eMoodType_Body = 0x1,
};

enum class ParticleEndcapMode_t : uint64_t
{
    PARTICLE_ENDCAP_ALWAYS_ON = 0xffffffffffffffff,
    PARTICLE_ENDCAP_ENDCAP_OFF = 0x0,
    PARTICLE_ENDCAP_ENDCAP_ON = 0x1,
};

enum class FootFallTagFoot_t : uint64_t
{
    FOOT1 = 0x0,
    FOOT2 = 0x1,
    FOOT3 = 0x2,
    FOOT4 = 0x3,
    FOOT5 = 0x4,
    FOOT6 = 0x5,
    FOOT7 = 0x6,
    FOOT8 = 0x7,
};

enum class IKTargetSource : uint64_t
{
    IKTARGETSOURCE_Bone = 0x0,
    IKTARGETSOURCE_AnimgraphParameter = 0x1,
    IKTARGETSOURCE_COUNT = 0x2,
};

enum class ClosestPointTestType_t : uint64_t
{
    PARTICLE_CLOSEST_TYPE_BOX = 0x0,
    PARTICLE_CLOSEST_TYPE_CAPSULE = 0x1,
    PARTICLE_CLOSEST_TYPE_HYBRID = 0x2,
};

#endif