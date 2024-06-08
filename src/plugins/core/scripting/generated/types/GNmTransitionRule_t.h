#ifndef _gnmtransitionrule_t_h
#define _gnmtransitionrule_t_h

enum class NmTransitionRule_t : uint64_t
{
    AllowTransition = 0x0,
    ConditionallyAllowTransition = 0x1,
    BlockTransition = 0x2,
};

#endif