#ifndef _ginputbitmask_t_h
#define _ginputbitmask_t_h

enum class InputBitMask_t : uint64_t
{
    IN_NONE = 0x0,
    IN_ALL = 0xffffffffffffffff,
    IN_ATTACK = 0x1,
    IN_JUMP = 0x2,
    IN_DUCK = 0x4,
    IN_FORWARD = 0x8,
    IN_BACK = 0x10,
    IN_USE = 0x20,
    IN_TURNLEFT = 0x80,
    IN_TURNRIGHT = 0x100,
    IN_MOVELEFT = 0x200,
    IN_MOVERIGHT = 0x400,
    IN_ATTACK2 = 0x800,
    IN_RELOAD = 0x2000,
    IN_SPEED = 0x10000,
    IN_JOYAUTOSPRINT = 0x20000,
    IN_FIRST_MOD_SPECIFIC_BIT = 0x100000000,
    IN_USEORRELOAD = 0x100000000,
    IN_SCORE = 0x200000000,
    IN_ZOOM = 0x400000000,
    IN_LOOK_AT_WEAPON = 0x800000000,
};

#endif