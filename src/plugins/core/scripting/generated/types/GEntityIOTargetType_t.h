#ifndef _gentityiotargettype_t_h
#define _gentityiotargettype_t_h

enum class EntityIOTargetType_t : uint64_t
{
    ENTITY_IO_TARGET_INVALID = 0xffffffffffffffff,
    ENTITY_IO_TARGET_ENTITYNAME = 0x2,
    ENTITY_IO_TARGET_EHANDLE = 0x6,
    ENTITY_IO_TARGET_ENTITYNAME_OR_CLASSNAME = 0x7,
};

#endif