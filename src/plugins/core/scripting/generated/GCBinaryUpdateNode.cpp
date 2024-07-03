#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBinaryUpdateNode::GCBinaryUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBinaryUpdateNode::GCBinaryUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimUpdateNodeRef GCBinaryUpdateNode::GetChild1() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "CBinaryUpdateNode", "m_pChild1"));
    return value;
}
void GCBinaryUpdateNode::SetChild1(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_pChild1", false, value);
}
GCAnimUpdateNodeRef GCBinaryUpdateNode::GetChild2() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "CBinaryUpdateNode", "m_pChild2"));
    return value;
}
void GCBinaryUpdateNode::SetChild2(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_pChild2", false, value);
}
uint64_t GCBinaryUpdateNode::GetTimingBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBinaryUpdateNode", "m_timingBehavior");
}
void GCBinaryUpdateNode::SetTimingBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_timingBehavior", false, value);
}
float GCBinaryUpdateNode::GetTimingBlend() const {
    return GetSchemaValue<float>(m_ptr, "CBinaryUpdateNode", "m_flTimingBlend");
}
void GCBinaryUpdateNode::SetTimingBlend(float value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_flTimingBlend", false, value);
}
bool GCBinaryUpdateNode::GetResetChild1() const {
    return GetSchemaValue<bool>(m_ptr, "CBinaryUpdateNode", "m_bResetChild1");
}
void GCBinaryUpdateNode::SetResetChild1(bool value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_bResetChild1", false, value);
}
bool GCBinaryUpdateNode::GetResetChild2() const {
    return GetSchemaValue<bool>(m_ptr, "CBinaryUpdateNode", "m_bResetChild2");
}
void GCBinaryUpdateNode::SetResetChild2(bool value) {
    SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_bResetChild2", false, value);
}
std::string GCBinaryUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBinaryUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCBinaryUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCBinaryUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBinaryUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBinaryUpdateNode>("CBinaryUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Child1", &GCBinaryUpdateNode::GetChild1, &GCBinaryUpdateNode::SetChild1)
        .addProperty("Child2", &GCBinaryUpdateNode::GetChild2, &GCBinaryUpdateNode::SetChild2)
        .addProperty("TimingBehavior", &GCBinaryUpdateNode::GetTimingBehavior, &GCBinaryUpdateNode::SetTimingBehavior)
        .addProperty("TimingBlend", &GCBinaryUpdateNode::GetTimingBlend, &GCBinaryUpdateNode::SetTimingBlend)
        .addProperty("ResetChild1", &GCBinaryUpdateNode::GetResetChild1, &GCBinaryUpdateNode::SetResetChild1)
        .addProperty("ResetChild2", &GCBinaryUpdateNode::GetResetChild2, &GCBinaryUpdateNode::SetResetChild2)
        .addProperty("Parent", &GCBinaryUpdateNode::GetParent, &GCBinaryUpdateNode::SetParent)
        .addFunction("ToPtr", &GCBinaryUpdateNode::ToPtr)
        .addFunction("IsValid", &GCBinaryUpdateNode::IsValid)
        .endClass();
}