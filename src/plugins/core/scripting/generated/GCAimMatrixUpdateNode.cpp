#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAimMatrixUpdateNode::GCAimMatrixUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAimMatrixUpdateNode::GCAimMatrixUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GAimMatrixOpFixedSettings_t GCAimMatrixUpdateNode::GetOpFixedSettings() const {
    GAimMatrixOpFixedSettings_t value(GetSchemaPtr(m_ptr, "CAimMatrixUpdateNode", "m_opFixedSettings"));
    return value;
}
void GCAimMatrixUpdateNode::SetOpFixedSettings(GAimMatrixOpFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_opFixedSettings", false, value);
}
uint64_t GCAimMatrixUpdateNode::GetTarget() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAimMatrixUpdateNode", "m_target");
}
void GCAimMatrixUpdateNode::SetTarget(uint64_t value) {
    SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_target", false, value);
}
GCAnimParamHandle GCAimMatrixUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimMatrixUpdateNode", "m_paramIndex"));
    return value;
}
void GCAimMatrixUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_paramIndex", false, value);
}
bool GCAimMatrixUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CAimMatrixUpdateNode", "m_bResetChild");
}
void GCAimMatrixUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_bResetChild", false, value);
}
bool GCAimMatrixUpdateNode::GetLockWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CAimMatrixUpdateNode", "m_bLockWhenWaning");
}
void GCAimMatrixUpdateNode::SetLockWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_bLockWhenWaning", false, value);
}
std::string GCAimMatrixUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAimMatrixUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCAimMatrixUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCAimMatrixUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAimMatrixUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimMatrixUpdateNode>("CAimMatrixUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedSettings", &GCAimMatrixUpdateNode::GetOpFixedSettings, &GCAimMatrixUpdateNode::SetOpFixedSettings)
        .addProperty("Target", &GCAimMatrixUpdateNode::GetTarget, &GCAimMatrixUpdateNode::SetTarget)
        .addProperty("ParamIndex", &GCAimMatrixUpdateNode::GetParamIndex, &GCAimMatrixUpdateNode::SetParamIndex)
        .addProperty("ResetChild", &GCAimMatrixUpdateNode::GetResetChild, &GCAimMatrixUpdateNode::SetResetChild)
        .addProperty("LockWhenWaning", &GCAimMatrixUpdateNode::GetLockWhenWaning, &GCAimMatrixUpdateNode::SetLockWhenWaning)
        .addProperty("Parent", &GCAimMatrixUpdateNode::GetParent, &GCAimMatrixUpdateNode::SetParent)
        .addFunction("ToPtr", &GCAimMatrixUpdateNode::ToPtr)
        .addFunction("IsValid", &GCAimMatrixUpdateNode::IsValid)
        .endClass();
}