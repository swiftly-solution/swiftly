#ifndef _gpulsecursorexecresult_t_h
#define _gpulsecursorexecresult_t_h

enum class PulseCursorExecResult_t : uint64_t
{
    Succeeded = 0x0,
    Canceled = 0x1,
    Failed = 0x2,
    OngoingNotify = 0x3,
};

#endif