#ifndef _gmodelconfigattachmenttype_t_h
#define _gmodelconfigattachmenttype_t_h

enum class ModelConfigAttachmentType_t : uint64_t
{
    MODEL_CONFIG_ATTACHMENT_INVALID = 0xffffffffffffffff,
    MODEL_CONFIG_ATTACHMENT_BONE_OR_ATTACHMENT = 0x0,
    MODEL_CONFIG_ATTACHMENT_ROOT_RELATIVE = 0x1,
    MODEL_CONFIG_ATTACHMENT_BONEMERGE = 0x2,
    MODEL_CONFIG_ATTACHMENT_COUNT = 0x3,
};

#endif