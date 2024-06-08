#ifndef _gvectorfloatexpressiontype_t_h
#define _gvectorfloatexpressiontype_t_h

enum class VectorFloatExpressionType_t : uint64_t
{
    VECTOR_FLOAT_EXPRESSION_UNINITIALIZED = 0xffffffffffffffff,
    VECTOR_FLOAT_EXPRESSION_DOTPRODUCT = 0x0,
    VECTOR_FLOAT_EXPRESSION_DISTANCE = 0x1,
    VECTOR_FLOAT_EXPRESSION_DISTANCESQR = 0x2,
    VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTH = 0x3,
    VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTHSQR = 0x4,
    VECTOR_FLOAT_EXPRESSION_INPUT1_NOISE = 0x5,
};

#endif