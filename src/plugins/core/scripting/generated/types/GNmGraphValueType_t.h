#ifndef _gnmgraphvaluetype_t_h
#define _gnmgraphvaluetype_t_h

enum class NmGraphValueType_t : uint64_t
{
    Unknown = 0x0,
    Bool = 0x1,
    ID = 0x2,
    Float = 0x3,
    Vector = 0x4,
    Target = 0x5,
    BoneMask = 0x6,
    Pose = 0x7,
    Special = 0x8,
};

#endif