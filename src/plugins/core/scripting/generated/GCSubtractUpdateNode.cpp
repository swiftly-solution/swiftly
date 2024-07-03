#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSubtractUpdateNode::GCSubtractUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSubtractUpdateNode::GCSubtractUpdateNode(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCSubtractUpdateNode::GetFootMotionTiming() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSubtractUpdateNode", "m_footMotionTiming");
}
void GCSubtractUpdateNode::SetFootMotionTiming(uint64_t value) {
    SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_footMotionTiming", false, value);
}
bool GCSubtractUpdateNode::GetApplyToFootMotion() const {
    return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bApplyToFootMotion");
}
void GCSubtractUpdateNode::SetApplyToFootMotion(bool value) {
    SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bApplyToFootMotion", false, value);
}
bool GCSubtractUpdateNode::GetApplyChannelsSeparately() const {
    return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bApplyChannelsSeparately");
}
void GCSubtractUpdateNode::SetApplyChannelsSeparately(bool value) {
    SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bApplyChannelsSeparately", false, value);
}
bool GCSubtractUpdateNode::GetUseModelSpace() const {
    return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bUseModelSpace");
}
void GCSubtractUpdateNode::SetUseModelSpace(bool value) {
    SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bUseModelSpace", false, value);
}
std::string GCSubtractUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSubtractUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCBinaryUpdateNode GCSubtractUpdateNode::GetParent() const {
    GCBinaryUpdateNode value(m_ptr);
    return value;
}
void GCSubtractUpdateNode::SetParent(GCBinaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSubtractUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSubtractUpdateNode>("CSubtractUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootMotionTiming", &GCSubtractUpdateNode::GetFootMotionTiming, &GCSubtractUpdateNode::SetFootMotionTiming)
        .addProperty("ApplyToFootMotion", &GCSubtractUpdateNode::GetApplyToFootMotion, &GCSubtractUpdateNode::SetApplyToFootMotion)
        .addProperty("ApplyChannelsSeparately", &GCSubtractUpdateNode::GetApplyChannelsSeparately, &GCSubtractUpdateNode::SetApplyChannelsSeparately)
        .addProperty("UseModelSpace", &GCSubtractUpdateNode::GetUseModelSpace, &GCSubtractUpdateNode::SetUseModelSpace)
        .addProperty("Parent", &GCSubtractUpdateNode::GetParent, &GCSubtractUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSubtractUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSubtractUpdateNode::IsValid)
        .endClass();
}