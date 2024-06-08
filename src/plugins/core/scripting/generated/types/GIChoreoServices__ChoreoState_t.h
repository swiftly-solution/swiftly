#ifndef _gichoreoservices__choreostate_t_h
#define _gichoreoservices__choreostate_t_h

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

#endif