#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStopAtGoalUpdateNode::GCStopAtGoalUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStopAtGoalUpdateNode::GCStopAtGoalUpdateNode(void *ptr) {
    m_ptr = ptr;
}
float GCStopAtGoalUpdateNode::GetOuterRadius() const {
    return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flOuterRadius");
}
void GCStopAtGoalUpdateNode::SetOuterRadius(float value) {
    SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flOuterRadius", false, value);
}
float GCStopAtGoalUpdateNode::GetInnerRadius() const {
    return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flInnerRadius");
}
void GCStopAtGoalUpdateNode::SetInnerRadius(float value) {
    SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flInnerRadius", false, value);
}
float GCStopAtGoalUpdateNode::GetMaxScale() const {
    return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flMaxScale");
}
void GCStopAtGoalUpdateNode::SetMaxScale(float value) {
    SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flMaxScale", false, value);
}
float GCStopAtGoalUpdateNode::GetMinScale() const {
    return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flMinScale");
}
void GCStopAtGoalUpdateNode::SetMinScale(float value) {
    SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flMinScale", false, value);
}
GCAnimInputDamping GCStopAtGoalUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CStopAtGoalUpdateNode", "m_damping"));
    return value;
}
void GCStopAtGoalUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_damping", false, value);
}
std::string GCStopAtGoalUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStopAtGoalUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCStopAtGoalUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCStopAtGoalUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStopAtGoalUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopAtGoalUpdateNode>("CStopAtGoalUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OuterRadius", &GCStopAtGoalUpdateNode::GetOuterRadius, &GCStopAtGoalUpdateNode::SetOuterRadius)
        .addProperty("InnerRadius", &GCStopAtGoalUpdateNode::GetInnerRadius, &GCStopAtGoalUpdateNode::SetInnerRadius)
        .addProperty("MaxScale", &GCStopAtGoalUpdateNode::GetMaxScale, &GCStopAtGoalUpdateNode::SetMaxScale)
        .addProperty("MinScale", &GCStopAtGoalUpdateNode::GetMinScale, &GCStopAtGoalUpdateNode::SetMinScale)
        .addProperty("Damping", &GCStopAtGoalUpdateNode::GetDamping, &GCStopAtGoalUpdateNode::SetDamping)
        .addProperty("Parent", &GCStopAtGoalUpdateNode::GetParent, &GCStopAtGoalUpdateNode::SetParent)
        .addFunction("ToPtr", &GCStopAtGoalUpdateNode::ToPtr)
        .addFunction("IsValid", &GCStopAtGoalUpdateNode::IsValid)
        .endClass();
}