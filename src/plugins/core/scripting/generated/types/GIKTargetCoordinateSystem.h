#ifndef _giktargetcoordinatesystem_h
#define _giktargetcoordinatesystem_h

enum class IKTargetCoordinateSystem : uint64_t
{
    IKTARGETCOORDINATESYSTEM_WorldSpace = 0x0,
    IKTARGETCOORDINATESYSTEM_ModelSpace = 0x1,
    IKTARGETCOORDINATESYSTEM_COUNT = 0x2,
};

#endif