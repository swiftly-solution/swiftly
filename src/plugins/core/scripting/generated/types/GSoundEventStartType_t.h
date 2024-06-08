#ifndef _gsoundeventstarttype_t_h
#define _gsoundeventstarttype_t_h

enum class SoundEventStartType_t : uint64_t
{
    SOUNDEVENT_START_PLAYER = 0x0,
    SOUNDEVENT_START_WORLD = 0x1,
    SOUNDEVENT_START_ENTITY = 0x2,
};

#endif