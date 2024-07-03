#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSplineConstraint::GCSplineConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSplineConstraint::GCSplineConstraint(void *ptr) {
    m_ptr = ptr;
}
Vector GCSplineConstraint::GetAnchorOffsetRestore() const {
    return GetSchemaValue<Vector>(m_ptr, "CSplineConstraint", "m_vAnchorOffsetRestore");
}
void GCSplineConstraint::SetAnchorOffsetRestore(Vector value) {
    SetSchemaValue(m_ptr, "CSplineConstraint", "m_vAnchorOffsetRestore", false, value);
}
std::string GCSplineConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSplineConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCSplineConstraint::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCSplineConstraint::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSplineConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSplineConstraint>("CSplineConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnchorOffsetRestore", &GCSplineConstraint::GetAnchorOffsetRestore, &GCSplineConstraint::SetAnchorOffsetRestore)
        .addProperty("Parent", &GCSplineConstraint::GetParent, &GCSplineConstraint::SetParent)
        .addFunction("ToPtr", &GCSplineConstraint::ToPtr)
        .addFunction("IsValid", &GCSplineConstraint::IsValid)
        .endClass();
}