#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRevertSaved::GCRevertSaved(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRevertSaved::GCRevertSaved(void *ptr) {
    m_ptr = ptr;
}
float GCRevertSaved::GetLoadTime() const {
    return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_loadTime");
}
void GCRevertSaved::SetLoadTime(float value) {
    SetSchemaValue(m_ptr, "CRevertSaved", "m_loadTime", false, value);
}
float GCRevertSaved::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_Duration");
}
void GCRevertSaved::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CRevertSaved", "m_Duration", false, value);
}
float GCRevertSaved::GetHoldTime() const {
    return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_HoldTime");
}
void GCRevertSaved::SetHoldTime(float value) {
    SetSchemaValue(m_ptr, "CRevertSaved", "m_HoldTime", false, value);
}
std::string GCRevertSaved::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRevertSaved::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCRevertSaved::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCRevertSaved::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRevertSaved(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRevertSaved>("CRevertSaved")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoadTime", &GCRevertSaved::GetLoadTime, &GCRevertSaved::SetLoadTime)
        .addProperty("Duration", &GCRevertSaved::GetDuration, &GCRevertSaved::SetDuration)
        .addProperty("HoldTime", &GCRevertSaved::GetHoldTime, &GCRevertSaved::SetHoldTime)
        .addProperty("Parent", &GCRevertSaved::GetParent, &GCRevertSaved::SetParent)
        .addFunction("ToPtr", &GCRevertSaved::ToPtr)
        .addFunction("IsValid", &GCRevertSaved::IsValid)
        .endClass();
}