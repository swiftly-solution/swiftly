#ifndef _gnpcfollowformation_t_h
#define _gnpcfollowformation_t_h

enum class NPCFollowFormation_t : uint64_t
{
    Default = 0xffffffffffffffff,
    CloseCircle = 0x0,
    WideCircle = 0x1,
    MediumCircle = 0x5,
    Sidekick = 0x6,
};

#endif