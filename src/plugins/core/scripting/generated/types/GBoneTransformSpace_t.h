#ifndef _gbonetransformspace_t_h
#define _gbonetransformspace_t_h

enum class BoneTransformSpace_t : uint64_t
{
    BoneTransformSpace_Invalid = 0xffffffffffffffff,
    BoneTransformSpace_Parent = 0x0,
    BoneTransformSpace_Model = 0x1,
    BoneTransformSpace_World = 0x2,
};

#endif