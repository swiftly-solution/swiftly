#ifndef _gdampingspeedfunction_h
#define _gdampingspeedfunction_h

enum class DampingSpeedFunction : uint64_t
{
    NoDamping = 0x0,
    Constant = 0x1,
    Spring = 0x2,
};

#endif