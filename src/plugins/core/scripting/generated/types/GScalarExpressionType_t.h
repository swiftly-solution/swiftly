#ifndef _gscalarexpressiontype_t_h
#define _gscalarexpressiontype_t_h

enum class ScalarExpressionType_t : uint64_t
{
    SCALAR_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    SCALAR_EXPRESSION_ADD = 0x0,
    SCALAR_EXPRESSION_SUBTRACT = 0x1,
    SCALAR_EXPRESSION_MUL = 0x2,
    SCALAR_EXPRESSION_DIVIDE = 0x3,
    SCALAR_EXPRESSION_INPUT_1 = 0x4,
    SCALAR_EXPRESSION_MIN = 0x5,
    SCALAR_EXPRESSION_MAX = 0x6,
    SCALAR_EXPRESSION_MOD = 0x7,
};

#endif