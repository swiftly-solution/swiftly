#ifndef _gdisposition_t_h
#define _gdisposition_t_h

enum class Disposition_t : uint64_t
{
    D_ER = 0x0,
    D_HT = 0x1,
    D_FR = 0x2,
    D_LI = 0x3,
    D_NU = 0x4,
    D_ERROR = 0x0,
    D_HATE = 0x1,
    D_FEAR = 0x2,
    D_LIKE = 0x3,
    D_NEUTRAL = 0x4,
};

#endif