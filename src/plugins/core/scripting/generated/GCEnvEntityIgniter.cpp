#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvEntityIgniter::GCEnvEntityIgniter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvEntityIgniter::GCEnvEntityIgniter(void *ptr) {
    m_ptr = ptr;
}
float GCEnvEntityIgniter::GetLifetime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvEntityIgniter", "m_flLifetime");
}
void GCEnvEntityIgniter::SetLifetime(float value) {
    SetSchemaValue(m_ptr, "CEnvEntityIgniter", "m_flLifetime", false, value);
}
std::string GCEnvEntityIgniter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvEntityIgniter::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvEntityIgniter::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvEntityIgniter::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvEntityIgniter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvEntityIgniter>("CEnvEntityIgniter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Lifetime", &GCEnvEntityIgniter::GetLifetime, &GCEnvEntityIgniter::SetLifetime)
        .addProperty("Parent", &GCEnvEntityIgniter::GetParent, &GCEnvEntityIgniter::SetParent)
        .addFunction("ToPtr", &GCEnvEntityIgniter::ToPtr)
        .addFunction("IsValid", &GCEnvEntityIgniter::IsValid)
        .endClass();
}