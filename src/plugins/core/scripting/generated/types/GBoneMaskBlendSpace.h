#ifndef _gbonemaskblendspace_h
#define _gbonemaskblendspace_h

enum class BoneMaskBlendSpace : uint64_t
{
    BlendSpace_Parent = 0x0,
    BlendSpace_Model = 0x1,
    BlendSpace_Model_RotationOnly = 0x2,
    BlendSpace_Model_TranslationOnly = 0x3,
};

#endif