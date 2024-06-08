#ifndef _gnmeasingfunction_t_h
#define _gnmeasingfunction_t_h

enum class NmEasingFunction_t : uint64_t
{
    Linear = 0x0,
    Quad = 0x1,
    Cubic = 0x2,
    Quart = 0x3,
    Quint = 0x4,
    Sine = 0x5,
    Expo = 0x6,
    Circ = 0x7,
    Back = 0x8,
};

#endif