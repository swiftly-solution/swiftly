#ifndef _gvectorexpressiontype_t_h
#define _gvectorexpressiontype_t_h

enum class VectorExpressionType_t : uint64_t
{
    VECTOR_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    VECTOR_EXPRESSION_ADD = 0x0,
    VECTOR_EXPRESSION_SUBTRACT = 0x1,
    VECTOR_EXPRESSION_MUL = 0x2,
    VECTOR_EXPRESSION_DIVIDE = 0x3,
    VECTOR_EXPRESSION_INPUT_1 = 0x4,
    VECTOR_EXPRESSION_MIN = 0x5,
    VECTOR_EXPRESSION_MAX = 0x6,
    VECTOR_EXPRESSION_CROSSPRODUCT = 0x7,
};

#endif