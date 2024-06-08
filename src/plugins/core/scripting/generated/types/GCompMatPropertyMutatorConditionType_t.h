#ifndef _gcompmatpropertymutatorconditiontype_t_h
#define _gcompmatpropertymutatorconditiontype_t_h

enum class CompMatPropertyMutatorConditionType_t : uint64_t
{
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_EXISTS = 0x0,
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EXISTS = 0x1,
    COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EQUALS = 0x2,
};

#endif