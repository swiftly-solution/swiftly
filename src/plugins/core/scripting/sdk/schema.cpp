#include "../../scripting.h"

void WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, bool isStruct, byte* value, int size)
{
    const auto m_key = sch::GetOffset(className, fieldName);

    void* fieldPtr = reinterpret_cast<std::add_pointer_t<void>>((uintptr_t)(ptr)+m_key);

    Plat_WriteMemory(fieldPtr, value, size);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);
}

void* GetSchemaPtr(void* ptr, const char* className, const char* fieldName)
{
    auto m_key = sch::GetOffset(className, fieldName);

    return reinterpret_cast<void*>((uintptr_t)(ptr)+m_key);
}

void scripting_StateUpdate(std::string ptr, std::string classname, std::string field, bool isStruct)
{

    if (!starts_with(ptr, "0x")) return;
    void* vPtr = (void*)(strtol(ptr.c_str(), nullptr, 16));

    SetStateChanged((uintptr_t)vPtr, classname, field, 0, isStruct);
}