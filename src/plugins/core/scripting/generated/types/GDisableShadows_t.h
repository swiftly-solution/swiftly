#ifndef _gdisableshadows_t_h
#define _gdisableshadows_t_h

enum class DisableShadows_t : uint64_t
{
    kDisableShadows_None = 0x0,
    kDisableShadows_All = 0x1,
    kDisableShadows_Baked = 0x2,
    kDisableShadows_Realtime = 0x3,
};

#endif