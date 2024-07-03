#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityComponentHelper::GCEntityComponentHelper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityComponentHelper::GCEntityComponentHelper(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCEntityComponentHelper::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEntityComponentHelper", "m_flags");
}
void GCEntityComponentHelper::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CEntityComponentHelper", "m_flags", false, value);
}
GEntComponentInfo_t GCEntityComponentHelper::GetInfo() const {
    GEntComponentInfo_t value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityComponentHelper", "m_pInfo"));
    return value;
}
void GCEntityComponentHelper::SetInfo(GEntComponentInfo_t* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Info' is not possible.\n");
}
int32_t GCEntityComponentHelper::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEntityComponentHelper", "m_nPriority");
}
void GCEntityComponentHelper::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CEntityComponentHelper", "m_nPriority", false, value);
}
GCEntityComponentHelper GCEntityComponentHelper::GetNext() const {
    GCEntityComponentHelper value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityComponentHelper", "m_pNext"));
    return value;
}
void GCEntityComponentHelper::SetNext(GCEntityComponentHelper* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
std::string GCEntityComponentHelper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityComponentHelper::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntityComponentHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityComponentHelper>("CEntityComponentHelper")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GCEntityComponentHelper::GetFlags, &GCEntityComponentHelper::SetFlags)
        .addProperty("Info", &GCEntityComponentHelper::GetInfo, &GCEntityComponentHelper::SetInfo)
        .addProperty("Priority", &GCEntityComponentHelper::GetPriority, &GCEntityComponentHelper::SetPriority)
        .addProperty("Next", &GCEntityComponentHelper::GetNext, &GCEntityComponentHelper::SetNext)
        .addFunction("ToPtr", &GCEntityComponentHelper::ToPtr)
        .addFunction("IsValid", &GCEntityComponentHelper::IsValid)
        .endClass();
}