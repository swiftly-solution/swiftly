#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSpark::GCEnvSpark(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSpark::GCEnvSpark(void *ptr) {
    m_ptr = ptr;
}
float GCEnvSpark::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSpark", "m_flDelay");
}
void GCEnvSpark::SetDelay(float value) {
    SetSchemaValue(m_ptr, "CEnvSpark", "m_flDelay", false, value);
}
int32_t GCEnvSpark::GetMagnitude() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nMagnitude");
}
void GCEnvSpark::SetMagnitude(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSpark", "m_nMagnitude", false, value);
}
int32_t GCEnvSpark::GetTrailLength() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nTrailLength");
}
void GCEnvSpark::SetTrailLength(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSpark", "m_nTrailLength", false, value);
}
int32_t GCEnvSpark::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nType");
}
void GCEnvSpark::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSpark", "m_nType", false, value);
}
GCEntityIOOutput GCEnvSpark::GetOnSpark() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvSpark", "m_OnSpark"));
    return value;
}
void GCEnvSpark::SetOnSpark(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvSpark", "m_OnSpark", false, value);
}
std::string GCEnvSpark::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSpark::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvSpark::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvSpark::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSpark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSpark>("CEnvSpark")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Delay", &GCEnvSpark::GetDelay, &GCEnvSpark::SetDelay)
        .addProperty("Magnitude", &GCEnvSpark::GetMagnitude, &GCEnvSpark::SetMagnitude)
        .addProperty("TrailLength", &GCEnvSpark::GetTrailLength, &GCEnvSpark::SetTrailLength)
        .addProperty("Type", &GCEnvSpark::GetType, &GCEnvSpark::SetType)
        .addProperty("OnSpark", &GCEnvSpark::GetOnSpark, &GCEnvSpark::SetOnSpark)
        .addProperty("Parent", &GCEnvSpark::GetParent, &GCEnvSpark::SetParent)
        .addFunction("ToPtr", &GCEnvSpark::ToPtr)
        .addFunction("IsValid", &GCEnvSpark::IsValid)
        .endClass();
}