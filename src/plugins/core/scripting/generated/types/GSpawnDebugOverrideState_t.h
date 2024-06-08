#ifndef _gspawndebugoverridestate_t_h
#define _gspawndebugoverridestate_t_h

enum class SpawnDebugOverrideState_t : uint64_t
{
    SPAWN_DEBUG_OVERRIDE_NONE = 0x0,
    SPAWN_DEBUG_OVERRIDE_FORCE_ENABLED = 0x1,
    SPAWN_DEBUG_OVERRIDE_FORCE_DISABLED = 0x2,
};

#endif