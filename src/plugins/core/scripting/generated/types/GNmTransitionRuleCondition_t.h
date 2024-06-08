#ifndef _gnmtransitionrulecondition_t_h
#define _gnmtransitionrulecondition_t_h

enum class NmTransitionRuleCondition_t : uint64_t
{
    AnyAllowed = 0x0,
    FullyAllowed = 0x1,
    ConditionallyAllowed = 0x2,
    Blocked = 0x3,
};

#endif