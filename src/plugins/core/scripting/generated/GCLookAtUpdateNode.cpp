#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLookAtUpdateNode::GCLookAtUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLookAtUpdateNode::GCLookAtUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GLookAtOpFixedSettings_t GCLookAtUpdateNode::GetOpFixedSettings() const {
    GLookAtOpFixedSettings_t value(GetSchemaPtr(m_ptr, "CLookAtUpdateNode", "m_opFixedSettings"));
    return value;
}
void GCLookAtUpdateNode::SetOpFixedSettings(GLookAtOpFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_opFixedSettings", false, value);
}
uint64_t GCLookAtUpdateNode::GetTarget() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CLookAtUpdateNode", "m_target");
}
void GCLookAtUpdateNode::SetTarget(uint64_t value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_target", false, value);
}
GCAnimParamHandle GCLookAtUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookAtUpdateNode", "m_paramIndex"));
    return value;
}
void GCLookAtUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_paramIndex", false, value);
}
GCAnimParamHandle GCLookAtUpdateNode::GetWeightParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLookAtUpdateNode", "m_weightParamIndex"));
    return value;
}
void GCLookAtUpdateNode::SetWeightParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_weightParamIndex", false, value);
}
bool GCLookAtUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CLookAtUpdateNode", "m_bResetChild");
}
void GCLookAtUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_bResetChild", false, value);
}
bool GCLookAtUpdateNode::GetLockWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CLookAtUpdateNode", "m_bLockWhenWaning");
}
void GCLookAtUpdateNode::SetLockWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_bLockWhenWaning", false, value);
}
std::string GCLookAtUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLookAtUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCLookAtUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCLookAtUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLookAtUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLookAtUpdateNode>("CLookAtUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedSettings", &GCLookAtUpdateNode::GetOpFixedSettings, &GCLookAtUpdateNode::SetOpFixedSettings)
        .addProperty("Target", &GCLookAtUpdateNode::GetTarget, &GCLookAtUpdateNode::SetTarget)
        .addProperty("ParamIndex", &GCLookAtUpdateNode::GetParamIndex, &GCLookAtUpdateNode::SetParamIndex)
        .addProperty("WeightParamIndex", &GCLookAtUpdateNode::GetWeightParamIndex, &GCLookAtUpdateNode::SetWeightParamIndex)
        .addProperty("ResetChild", &GCLookAtUpdateNode::GetResetChild, &GCLookAtUpdateNode::SetResetChild)
        .addProperty("LockWhenWaning", &GCLookAtUpdateNode::GetLockWhenWaning, &GCLookAtUpdateNode::SetLockWhenWaning)
        .addProperty("Parent", &GCLookAtUpdateNode::GetParent, &GCLookAtUpdateNode::SetParent)
        .addFunction("ToPtr", &GCLookAtUpdateNode::ToPtr)
        .addFunction("IsValid", &GCLookAtUpdateNode::IsValid)
        .endClass();
}