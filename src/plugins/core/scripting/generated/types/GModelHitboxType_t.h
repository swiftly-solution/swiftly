#ifndef _gmodelhitboxtype_t_h
#define _gmodelhitboxtype_t_h

enum class ModelHitboxType_t : uint64_t
{
    MODEL_HITBOX_TYPE_STANDARD = 0x0,
    MODEL_HITBOX_TYPE_RAW_BONES = 0x1,
    MODEL_HITBOX_TYPE_RENDERBOUNDS = 0x2,
    MODEL_HITBOX_TYPE_SNAPSHOT = 0x3,
};

#endif