#include "../scripting.h"

void WriteSchemaPtrValue(void *ptr, const char *className, const char *fieldName, bool isStruct, byte *value, int size)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    const auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    void *fieldPtr = reinterpret_cast<std::add_pointer_t<void>>((uintptr_t)(ptr) + m_key.offset);

    Plat_WriteMemory(fieldPtr, value, size);
}

void *GetSchemaPtr(void *ptr, const char *className, const char *fieldName)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    return reinterpret_cast<void *>((uintptr_t)(ptr) + m_key.offset);
}