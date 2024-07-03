#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSplash::GCEnvSplash(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSplash::GCEnvSplash(void *ptr) {
    m_ptr = ptr;
}
float GCEnvSplash::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSplash", "m_flScale");
}
void GCEnvSplash::SetScale(float value) {
    SetSchemaValue(m_ptr, "CEnvSplash", "m_flScale", false, value);
}
std::string GCEnvSplash::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSplash::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvSplash::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvSplash::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSplash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSplash>("CEnvSplash")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scale", &GCEnvSplash::GetScale, &GCEnvSplash::SetScale)
        .addProperty("Parent", &GCEnvSplash::GetParent, &GCEnvSplash::SetParent)
        .addFunction("ToPtr", &GCEnvSplash::ToPtr)
        .addFunction("IsValid", &GCEnvSplash::IsValid)
        .endClass();
}