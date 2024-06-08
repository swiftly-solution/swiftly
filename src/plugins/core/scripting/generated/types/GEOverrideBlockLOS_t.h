#ifndef _geoverrideblocklos_t_h
#define _geoverrideblocklos_t_h

enum class EOverrideBlockLOS_t : uint64_t
{
    BLOCK_LOS_DEFAULT = 0x0,
    BLOCK_LOS_FORCE_FALSE = 0x1,
    BLOCK_LOS_FORCE_TRUE = 0x2,
};

#endif