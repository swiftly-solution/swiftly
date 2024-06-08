#ifndef _gcnmtransitionnode__transitionoptions_t_h
#define _gcnmtransitionnode__transitionoptions_t_h

enum class CNmTransitionNode__TransitionOptions_t : uint64_t
{
    None = 0x0,
    ClampDuration = 0x1,
    Synchronized = 0x2,
    MatchSourceTime = 0x4,
    MatchSyncEventIndex = 0x8,
    MatchSyncEventID = 0x10,
    MatchSyncEventPercentage = 0x20,
    PreferClosestSyncEventID = 0x40,
};

#endif