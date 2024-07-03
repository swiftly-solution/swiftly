#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvViewPunch::GCEnvViewPunch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvViewPunch::GCEnvViewPunch(void *ptr) {
    m_ptr = ptr;
}
float GCEnvViewPunch::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvViewPunch", "m_flRadius");
}
void GCEnvViewPunch::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvViewPunch", "m_flRadius", false, value);
}
QAngle GCEnvViewPunch::GetViewPunch() const {
    return GetSchemaValue<QAngle>(m_ptr, "CEnvViewPunch", "m_angViewPunch");
}
void GCEnvViewPunch::SetViewPunch(QAngle value) {
    SetSchemaValue(m_ptr, "CEnvViewPunch", "m_angViewPunch", false, value);
}
std::string GCEnvViewPunch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvViewPunch::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvViewPunch::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvViewPunch::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvViewPunch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvViewPunch>("CEnvViewPunch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCEnvViewPunch::GetRadius, &GCEnvViewPunch::SetRadius)
        .addProperty("ViewPunch", &GCEnvViewPunch::GetViewPunch, &GCEnvViewPunch::SetViewPunch)
        .addProperty("Parent", &GCEnvViewPunch::GetParent, &GCEnvViewPunch::SetParent)
        .addFunction("ToPtr", &GCEnvViewPunch::ToPtr)
        .addFunction("IsValid", &GCEnvViewPunch::IsValid)
        .endClass();
}