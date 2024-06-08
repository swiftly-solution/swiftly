#ifndef _gclogicbranchlist__logicbranchlistenerlaststate_t_h
#define _gclogicbranchlist__logicbranchlistenerlaststate_t_h

enum class CLogicBranchList__LogicBranchListenerLastState_t : uint64_t
{
    LOGIC_BRANCH_LISTENER_NOT_INIT = 0x0,
    LOGIC_BRANCH_LISTENER_ALL_TRUE = 0x1,
    LOGIC_BRANCH_LISTENER_ALL_FALSE = 0x2,
    LOGIC_BRANCH_LISTENER_MIXED = 0x3,
};

#endif