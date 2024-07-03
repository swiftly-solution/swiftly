#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWayPointHelperUpdateNode::GCWayPointHelperUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWayPointHelperUpdateNode::GCWayPointHelperUpdateNode(void *ptr) {
    m_ptr = ptr;
}
float GCWayPointHelperUpdateNode::GetStartCycle() const {
    return GetSchemaValue<float>(m_ptr, "CWayPointHelperUpdateNode", "m_flStartCycle");
}
void GCWayPointHelperUpdateNode::SetStartCycle(float value) {
    SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_flStartCycle", false, value);
}
float GCWayPointHelperUpdateNode::GetEndCycle() const {
    return GetSchemaValue<float>(m_ptr, "CWayPointHelperUpdateNode", "m_flEndCycle");
}
void GCWayPointHelperUpdateNode::SetEndCycle(float value) {
    SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_flEndCycle", false, value);
}
bool GCWayPointHelperUpdateNode::GetOnlyGoals() const {
    return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bOnlyGoals");
}
void GCWayPointHelperUpdateNode::SetOnlyGoals(bool value) {
    SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bOnlyGoals", false, value);
}
bool GCWayPointHelperUpdateNode::GetPreventOvershoot() const {
    return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventOvershoot");
}
void GCWayPointHelperUpdateNode::SetPreventOvershoot(bool value) {
    SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventOvershoot", false, value);
}
bool GCWayPointHelperUpdateNode::GetPreventUndershoot() const {
    return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventUndershoot");
}
void GCWayPointHelperUpdateNode::SetPreventUndershoot(bool value) {
    SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventUndershoot", false, value);
}
std::string GCWayPointHelperUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWayPointHelperUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCWayPointHelperUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCWayPointHelperUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWayPointHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWayPointHelperUpdateNode>("CWayPointHelperUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartCycle", &GCWayPointHelperUpdateNode::GetStartCycle, &GCWayPointHelperUpdateNode::SetStartCycle)
        .addProperty("EndCycle", &GCWayPointHelperUpdateNode::GetEndCycle, &GCWayPointHelperUpdateNode::SetEndCycle)
        .addProperty("OnlyGoals", &GCWayPointHelperUpdateNode::GetOnlyGoals, &GCWayPointHelperUpdateNode::SetOnlyGoals)
        .addProperty("PreventOvershoot", &GCWayPointHelperUpdateNode::GetPreventOvershoot, &GCWayPointHelperUpdateNode::SetPreventOvershoot)
        .addProperty("PreventUndershoot", &GCWayPointHelperUpdateNode::GetPreventUndershoot, &GCWayPointHelperUpdateNode::SetPreventUndershoot)
        .addProperty("Parent", &GCWayPointHelperUpdateNode::GetParent, &GCWayPointHelperUpdateNode::SetParent)
        .addFunction("ToPtr", &GCWayPointHelperUpdateNode::ToPtr)
        .addFunction("IsValid", &GCWayPointHelperUpdateNode::IsValid)
        .endClass();
}