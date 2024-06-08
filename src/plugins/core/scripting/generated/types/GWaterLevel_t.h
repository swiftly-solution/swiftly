#ifndef _gwaterlevel_t_h
#define _gwaterlevel_t_h

enum class WaterLevel_t : uint64_t
{
    WL_NotInWater = 0x0,
    WL_Feet = 0x1,
    WL_Knees = 0x2,
    WL_Waist = 0x3,
    WL_Chest = 0x4,
    WL_FullyUnderwater = 0x5,
    WL_Count = 0x6,
};

#endif