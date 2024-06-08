#ifndef _gfusevariabletype_t_h
#define _gfusevariabletype_t_h

enum class FuseVariableType_t : uint64_t
{
    INVALID = 0x0,
    BOOL = 0x1,
    INT8 = 0x2,
    INT16 = 0x3,
    INT32 = 0x4,
    UINT8 = 0x5,
    UINT16 = 0x6,
    UINT32 = 0x7,
    FLOAT32 = 0x8,
};

#endif