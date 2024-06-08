#ifndef _gnavdirtype_h
#define _gnavdirtype_h

enum class NavDirType : uint64_t
{
    NORTH = 0x0,
    EAST = 0x1,
    SOUTH = 0x2,
    WEST = 0x3,
    NUM_NAV_DIR_TYPE_DIRECTIONS = 0x4,
};

#endif