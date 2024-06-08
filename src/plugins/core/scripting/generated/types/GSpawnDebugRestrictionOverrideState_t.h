#ifndef _gspawndebugrestrictionoverridestate_t_h
#define _gspawndebugrestrictionoverridestate_t_h

enum class SpawnDebugRestrictionOverrideState_t : uint64_t
{
    SPAWN_DEBUG_RESTRICT_NONE = 0x0,
    SPAWN_DEBUG_RESTRICT_IGNORE_MANAGER_DISTANCE_REQS = 0x1,
    SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_DISTANCE_LOS_REQS = 0x2,
    SPAWN_DEBUG_RESTRICT_IGNORE_TEMPLATE_COOLDOWN_LIMITS = 0x4,
    SPAWN_DEBUG_RESTRICT_IGNORE_TARGET_COOLDOWN_LIMITS = 0x8,
};

#endif