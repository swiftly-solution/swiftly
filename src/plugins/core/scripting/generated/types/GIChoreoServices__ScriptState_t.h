#ifndef _gichoreoservices__scriptstate_t_h
#define _gichoreoservices__scriptstate_t_h

enum class IChoreoServices__ScriptState_t : uint64_t
{
    SCRIPT_PLAYING = 0x0,
    SCRIPT_WAIT = 0x1,
    SCRIPT_POST_IDLE = 0x2,
    SCRIPT_CLEANUP = 0x3,
    SCRIPT_MOVE_TO_MARK = 0x4,
};

#endif