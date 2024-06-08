#ifndef _gpulsemethodcallmode_t_h
#define _gpulsemethodcallmode_t_h

enum class PulseMethodCallMode_t : uint64_t
{
    SYNC_WAIT_FOR_COMPLETION = 0x0,
    ASYNC_FIRE_AND_FORGET = 0x1,
};

#endif