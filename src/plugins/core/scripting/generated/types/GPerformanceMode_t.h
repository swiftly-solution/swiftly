#ifndef _gperformancemode_t_h
#define _gperformancemode_t_h

enum class PerformanceMode_t : uint64_t
{
    PM_NORMAL = 0x0,
    PM_NO_GIBS = 0x1,
    PM_FULL_GIBS = 0x2,
    PM_REDUCED_GIBS = 0x3,
};

#endif