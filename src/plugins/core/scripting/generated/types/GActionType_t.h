#ifndef _gactiontype_t_h
#define _gactiontype_t_h

enum class ActionType_t : uint64_t
{
    SOS_ACTION_NONE = 0x0,
    SOS_ACTION_LIMITER = 0x1,
    SOS_ACTION_TIME_LIMIT = 0x2,
    SOS_ACTION_TIME_BLOCK_LIMITER = 0x3,
    SOS_ACTION_SET_SOUNDEVENT_PARAM = 0x4,
    SOS_ACTION_SOUNDEVENT_CLUSTER = 0x5,
    SOS_ACTION_SOUNDEVENT_PRIORITY = 0x6,
    SOS_ACTION_COUNT_ENVELOPE = 0x7,
};

#endif