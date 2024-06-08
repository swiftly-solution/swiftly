#ifndef _gselectortagbehavior_t_h
#define _gselectortagbehavior_t_h

enum class SelectorTagBehavior_t : uint64_t
{
    SelectorTagBehavior_OnWhileCurrent = 0x0,
    SelectorTagBehavior_OffWhenFinished = 0x1,
    SelectorTagBehavior_OffBeforeFinished = 0x2,
};

#endif