#ifndef _gvelocitymetricmode_h
#define _gvelocitymetricmode_h

enum class VelocityMetricMode : uint64_t
{
    DirectionOnly = 0x0,
    MagnitudeOnly = 0x1,
    DirectionAndMagnitude = 0x2,
};

#endif