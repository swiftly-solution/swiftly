#ifndef _gbeamtype_t_h
#define _gbeamtype_t_h

enum class BeamType_t : uint64_t
{
    BEAM_INVALID = 0x0,
    BEAM_POINTS = 0x1,
    BEAM_ENTPOINT = 0x2,
    BEAM_ENTS = 0x3,
    BEAM_HOSE = 0x4,
    BEAM_SPLINE = 0x5,
    BEAM_LASER = 0x6,
};

#endif