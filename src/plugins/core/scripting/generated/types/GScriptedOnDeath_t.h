#ifndef _gscriptedondeath_t_h
#define _gscriptedondeath_t_h

enum class ScriptedOnDeath_t : uint64_t
{
    SS_ONDEATH_NOT_APPLICABLE = 0xffffffffffffffff,
    SS_ONDEATH_UNDEFINED = 0x0,
    SS_ONDEATH_RAGDOLL = 0x1,
    SS_ONDEATH_ANIMATED_DEATH = 0x2,
};

#endif