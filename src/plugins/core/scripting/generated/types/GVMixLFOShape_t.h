#ifndef _gvmixlfoshape_t_h
#define _gvmixlfoshape_t_h

enum class VMixLFOShape_t : uint64_t
{
    LFO_SHAPE_SINE = 0x0,
    LFO_SHAPE_SQUARE = 0x1,
    LFO_SHAPE_TRI = 0x2,
    LFO_SHAPE_SAW = 0x3,
    LFO_SHAPE_NOISE = 0x4,
};

#endif