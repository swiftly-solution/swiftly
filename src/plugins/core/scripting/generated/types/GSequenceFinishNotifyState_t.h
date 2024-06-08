#ifndef _gsequencefinishnotifystate_t_h
#define _gsequencefinishnotifystate_t_h

enum class SequenceFinishNotifyState_t : uint64_t
{
    eDoNotNotify = 0x0,
    eNotifyWhenFinished = 0x1,
    eNotifyTriggered = 0x2,
};

#endif