#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCConstraintAnchor::GCConstraintAnchor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCConstraintAnchor::GCConstraintAnchor(void *ptr) {
    m_ptr = ptr;
}
float GCConstraintAnchor::GetMassScale() const {
    return GetSchemaValue<float>(m_ptr, "CConstraintAnchor", "m_massScale");
}
void GCConstraintAnchor::SetMassScale(float value) {
    SetSchemaValue(m_ptr, "CConstraintAnchor", "m_massScale", false, value);
}
std::string GCConstraintAnchor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCConstraintAnchor::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCConstraintAnchor::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCConstraintAnchor::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCConstraintAnchor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintAnchor>("CConstraintAnchor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MassScale", &GCConstraintAnchor::GetMassScale, &GCConstraintAnchor::SetMassScale)
        .addProperty("Parent", &GCConstraintAnchor::GetParent, &GCConstraintAnchor::SetParent)
        .addFunction("ToPtr", &GCConstraintAnchor::ToPtr)
        .addFunction("IsValid", &GCConstraintAnchor::IsValid)
        .endClass();
}