#ifndef _gpreviewcharactermode_h
#define _gpreviewcharactermode_h

enum class PreviewCharacterMode : uint64_t
{
    DIORAMA = 0x0,
    MAIN_MENU = 0x1,
    BUY_MENU = 0x2,
    TEAM_SELECT = 0x3,
    END_OF_MATCH = 0x4,
    INVENTORY_INSPECT = 0x5,
    WALKING = 0x6,
    TEAM_INTRO = 0x7,
    WINGMAN_INTRO = 0x8,
};

#endif