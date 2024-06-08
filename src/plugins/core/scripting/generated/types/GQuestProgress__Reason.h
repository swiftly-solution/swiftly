#ifndef _gquestprogress__reason_h
#define _gquestprogress__reason_h

enum class QuestProgress__Reason : uint64_t
{
    QUEST_NONINITIALIZED = 0x0,
    QUEST_OK = 0x1,
    QUEST_NOT_ENOUGH_PLAYERS = 0x2,
    QUEST_WARMUP = 0x3,
    QUEST_NOT_CONNECTED_TO_STEAM = 0x4,
    QUEST_NONOFFICIAL_SERVER = 0x5,
    QUEST_NO_ENTITLEMENT = 0x6,
    QUEST_NO_QUEST = 0x7,
    QUEST_PLAYER_IS_BOT = 0x8,
    QUEST_WRONG_MAP = 0x9,
    QUEST_WRONG_MODE = 0xa,
    QUEST_NOT_SYNCED_WITH_SERVER = 0xb,
    QUEST_REASON_MAX = 0xc,
};

#endif