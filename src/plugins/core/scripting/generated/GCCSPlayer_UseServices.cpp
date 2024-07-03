#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_UseServices::GCCSPlayer_UseServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_UseServices::GCCSPlayer_UseServices(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCCSPlayer_UseServices::GetLastKnownUseEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_UseServices", "m_hLastKnownUseEntity"));
    return value;
}
void GCCSPlayer_UseServices::SetLastKnownUseEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastKnownUseEntity' is not possible.\n");
}
float GCCSPlayer_UseServices::GetLastUseTimeStamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_UseServices", "m_flLastUseTimeStamp");
}
void GCCSPlayer_UseServices::SetLastUseTimeStamp(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_UseServices", "m_flLastUseTimeStamp", false, value);
}
float GCCSPlayer_UseServices::GetTimeLastUsedWindow() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_UseServices", "m_flTimeLastUsedWindow");
}
void GCCSPlayer_UseServices::SetTimeLastUsedWindow(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_UseServices", "m_flTimeLastUsedWindow", false, value);
}
std::string GCCSPlayer_UseServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_UseServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_UseServices GCCSPlayer_UseServices::GetParent() const {
    GCPlayer_UseServices value(m_ptr);
    return value;
}
void GCCSPlayer_UseServices::SetParent(GCPlayer_UseServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_UseServices>("CCSPlayer_UseServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LastKnownUseEntity", &GCCSPlayer_UseServices::GetLastKnownUseEntity, &GCCSPlayer_UseServices::SetLastKnownUseEntity)
        .addProperty("LastUseTimeStamp", &GCCSPlayer_UseServices::GetLastUseTimeStamp, &GCCSPlayer_UseServices::SetLastUseTimeStamp)
        .addProperty("TimeLastUsedWindow", &GCCSPlayer_UseServices::GetTimeLastUsedWindow, &GCCSPlayer_UseServices::SetTimeLastUsedWindow)
        .addProperty("Parent", &GCCSPlayer_UseServices::GetParent, &GCCSPlayer_UseServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_UseServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_UseServices::IsValid)
        .endClass();
}