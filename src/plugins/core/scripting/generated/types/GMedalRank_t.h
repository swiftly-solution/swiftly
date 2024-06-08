#ifndef _gmedalrank_t_h
#define _gmedalrank_t_h

enum class MedalRank_t : uint64_t
{
    MEDAL_RANK_NONE = 0x0,
    MEDAL_RANK_BRONZE = 0x1,
    MEDAL_RANK_SILVER = 0x2,
    MEDAL_RANK_GOLD = 0x3,
    MEDAL_RANK_COUNT = 0x4,
};

#endif