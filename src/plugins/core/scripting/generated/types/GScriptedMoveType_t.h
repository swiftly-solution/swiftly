#ifndef _gscriptedmovetype_t_h
#define _gscriptedmovetype_t_h

enum class ScriptedMoveType_t : uint64_t
{
    SCRIPTED_MOVETYPE_NONE = 0x0,
    SCRIPTED_MOVETYPE_TO_WITH_DURATION = 0x1,
    SCRIPTED_MOVETYPE_TO_WITH_MOVESPEED = 0x2,
    SCRIPTED_MOVETYPE_SWEEP_TO_AT_MOVEMENT_SPEED = 0x3,
};

#endif