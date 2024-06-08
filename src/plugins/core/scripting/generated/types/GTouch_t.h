#ifndef _gtouch_t_h
#define _gtouch_t_h

enum class Touch_t : uint64_t
{
    touch_none = 0x0,
    touch_player_only = 0x1,
    touch_npc_only = 0x2,
    touch_player_or_npc = 0x3,
    touch_player_or_npc_or_physicsprop = 0x4,
};

#endif