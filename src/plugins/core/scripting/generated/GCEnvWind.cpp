#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvWind::GCEnvWind(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvWind::GCEnvWind(void *ptr) {
    m_ptr = ptr;
}
GCEnvWindShared GCEnvWind::GetEnvWindShared() const {
    GCEnvWindShared value(GetSchemaPtr(m_ptr, "CEnvWind", "m_EnvWindShared"));
    return value;
}
void GCEnvWind::SetEnvWindShared(GCEnvWindShared value) {
    SetSchemaValue(m_ptr, "CEnvWind", "m_EnvWindShared", false, value);
}
std::string GCEnvWind::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvWind::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvWind::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvWind::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvWind(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWind>("CEnvWind")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EnvWindShared", &GCEnvWind::GetEnvWindShared, &GCEnvWind::SetEnvWindShared)
        .addProperty("Parent", &GCEnvWind::GetParent, &GCEnvWind::SetParent)
        .addFunction("ToPtr", &GCEnvWind::ToPtr)
        .addFunction("IsValid", &GCEnvWind::IsValid)
        .endClass();
}