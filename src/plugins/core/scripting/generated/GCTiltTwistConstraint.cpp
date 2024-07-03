#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTiltTwistConstraint::GCTiltTwistConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTiltTwistConstraint::GCTiltTwistConstraint(void *ptr) {
    m_ptr = ptr;
}
int32_t GCTiltTwistConstraint::GetTargetAxis() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTiltTwistConstraint", "m_nTargetAxis");
}
void GCTiltTwistConstraint::SetTargetAxis(int32_t value) {
    SetSchemaValue(m_ptr, "CTiltTwistConstraint", "m_nTargetAxis", false, value);
}
int32_t GCTiltTwistConstraint::GetSlaveAxis() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTiltTwistConstraint", "m_nSlaveAxis");
}
void GCTiltTwistConstraint::SetSlaveAxis(int32_t value) {
    SetSchemaValue(m_ptr, "CTiltTwistConstraint", "m_nSlaveAxis", false, value);
}
std::string GCTiltTwistConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTiltTwistConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCTiltTwistConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCTiltTwistConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTiltTwistConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTiltTwistConstraint>("CTiltTwistConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetAxis", &GCTiltTwistConstraint::GetTargetAxis, &GCTiltTwistConstraint::SetTargetAxis)
        .addProperty("SlaveAxis", &GCTiltTwistConstraint::GetSlaveAxis, &GCTiltTwistConstraint::SetSlaveAxis)
        .addProperty("Parent", &GCTiltTwistConstraint::GetParent, &GCTiltTwistConstraint::SetParent)
        .addFunction("ToPtr", &GCTiltTwistConstraint::ToPtr)
        .addFunction("IsValid", &GCTiltTwistConstraint::IsValid)
        .endClass();
}