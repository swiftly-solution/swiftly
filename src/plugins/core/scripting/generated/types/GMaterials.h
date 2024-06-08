#ifndef _gmaterials_h
#define _gmaterials_h

enum class Materials : uint64_t
{
    matGlass = 0x0,
    matWood = 0x1,
    matMetal = 0x2,
    matFlesh = 0x3,
    matCinderBlock = 0x4,
    matCeilingTile = 0x5,
    matComputer = 0x6,
    matUnbreakableGlass = 0x7,
    matRocks = 0x8,
    matWeb = 0x9,
    matNone = 0xa,
    matLastMaterial = 0xb,
};

#endif