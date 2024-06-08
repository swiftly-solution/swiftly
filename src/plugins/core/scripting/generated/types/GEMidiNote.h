#ifndef _gemidinote_h
#define _gemidinote_h

enum class EMidiNote : uint64_t
{
    C = 0x0,
    C_Sharp = 0x1,
    D = 0x2,
    D_Sharp = 0x3,
    E = 0x4,
    F = 0x5,
    F_Sharp = 0x6,
    G = 0x7,
    G_Sharp = 0x8,
    A = 0x9,
    A_Sharp = 0xa,
    B = 0xb,
    Count = 0xc,
};

#endif