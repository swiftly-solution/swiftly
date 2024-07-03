#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTwistConstraint::GCTwistConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTwistConstraint::GCTwistConstraint(void *ptr) {
    m_ptr = ptr;
}
bool GCTwistConstraint::GetInverse() const {
    return GetSchemaValue<bool>(m_ptr, "CTwistConstraint", "m_bInverse");
}
void GCTwistConstraint::SetInverse(bool value) {
    SetSchemaValue(m_ptr, "CTwistConstraint", "m_bInverse", false, value);
}
Quaternion GCTwistConstraint::GetParentBindRotation() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CTwistConstraint", "m_qParentBindRotation");
}
void GCTwistConstraint::SetParentBindRotation(Quaternion value) {
    SetSchemaValue(m_ptr, "CTwistConstraint", "m_qParentBindRotation", false, value);
}
Quaternion GCTwistConstraint::GetChildBindRotation() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CTwistConstraint", "m_qChildBindRotation");
}
void GCTwistConstraint::SetChildBindRotation(Quaternion value) {
    SetSchemaValue(m_ptr, "CTwistConstraint", "m_qChildBindRotation", false, value);
}
std::string GCTwistConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTwistConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCTwistConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCTwistConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTwistConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTwistConstraint>("CTwistConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Inverse", &GCTwistConstraint::GetInverse, &GCTwistConstraint::SetInverse)
        .addProperty("ParentBindRotation", &GCTwistConstraint::GetParentBindRotation, &GCTwistConstraint::SetParentBindRotation)
        .addProperty("ChildBindRotation", &GCTwistConstraint::GetChildBindRotation, &GCTwistConstraint::SetChildBindRotation)
        .addProperty("Parent", &GCTwistConstraint::GetParent, &GCTwistConstraint::SetParent)
        .addFunction("ToPtr", &GCTwistConstraint::ToPtr)
        .addFunction("IsValid", &GCTwistConstraint::IsValid)
        .endClass();
}