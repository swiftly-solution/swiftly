#ifndef _gflexopcode_t_h
#define _gflexopcode_t_h

enum class FlexOpCode_t : uint64_t
{
    FLEX_OP_CONST = 0x1,
    FLEX_OP_FETCH1 = 0x2,
    FLEX_OP_FETCH2 = 0x3,
    FLEX_OP_ADD = 0x4,
    FLEX_OP_SUB = 0x5,
    FLEX_OP_MUL = 0x6,
    FLEX_OP_DIV = 0x7,
    FLEX_OP_NEG = 0x8,
    FLEX_OP_EXP = 0x9,
    FLEX_OP_OPEN = 0xa,
    FLEX_OP_CLOSE = 0xb,
    FLEX_OP_COMMA = 0xc,
    FLEX_OP_MAX = 0xd,
    FLEX_OP_MIN = 0xe,
    FLEX_OP_2WAY_0 = 0xf,
    FLEX_OP_2WAY_1 = 0x10,
    FLEX_OP_NWAY = 0x11,
    FLEX_OP_COMBO = 0x12,
    FLEX_OP_DOMINATE = 0x13,
    FLEX_OP_DME_LOWER_EYELID = 0x14,
    FLEX_OP_DME_UPPER_EYELID = 0x15,
    FLEX_OP_SQRT = 0x16,
    FLEX_OP_REMAPVALCLAMPED = 0x17,
    FLEX_OP_SIN = 0x18,
    FLEX_OP_COS = 0x19,
    FLEX_OP_ABS = 0x1a,
};

#endif