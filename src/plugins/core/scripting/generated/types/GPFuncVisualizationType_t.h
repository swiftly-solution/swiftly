#ifndef _gpfuncvisualizationtype_t_h
#define _gpfuncvisualizationtype_t_h

enum class PFuncVisualizationType_t : uint64_t
{
    PFUNC_VISUALIZATION_SPHERE_WIREFRAME = 0x0,
    PFUNC_VISUALIZATION_SPHERE_SOLID = 0x1,
    PFUNC_VISUALIZATION_BOX = 0x2,
    PFUNC_VISUALIZATION_RING = 0x3,
    PFUNC_VISUALIZATION_PLANE = 0x4,
    PFUNC_VISUALIZATION_LINE = 0x5,
    PFUNC_VISUALIZATION_CYLINDER = 0x6,
};

#endif