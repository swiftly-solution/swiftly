#ifndef _gvphysxbodypart_t__vphysxflagenum_t_h
#define _gvphysxbodypart_t__vphysxflagenum_t_h

enum class VPhysXBodyPart_t__VPhysXFlagEnum_t : uint64_t
{
    FLAG_STATIC = 0x1,
    FLAG_KINEMATIC = 0x2,
    FLAG_JOINT = 0x4,
    FLAG_MASS = 0x8,
    FLAG_ALWAYS_DYNAMIC_ON_CLIENT = 0x10,
};

#endif