#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAddUpdateNode::GCAddUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAddUpdateNode::GCAddUpdateNode(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCAddUpdateNode::GetFootMotionTiming() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAddUpdateNode", "m_footMotionTiming");
}
void GCAddUpdateNode::SetFootMotionTiming(uint64_t value) {
    SetSchemaValue(m_ptr, "CAddUpdateNode", "m_footMotionTiming", false, value);
}
bool GCAddUpdateNode::GetApplyToFootMotion() const {
    return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyToFootMotion");
}
void GCAddUpdateNode::SetApplyToFootMotion(bool value) {
    SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyToFootMotion", false, value);
}
bool GCAddUpdateNode::GetApplyChannelsSeparately() const {
    return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyChannelsSeparately");
}
void GCAddUpdateNode::SetApplyChannelsSeparately(bool value) {
    SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyChannelsSeparately", false, value);
}
bool GCAddUpdateNode::GetUseModelSpace() const {
    return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bUseModelSpace");
}
void GCAddUpdateNode::SetUseModelSpace(bool value) {
    SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bUseModelSpace", false, value);
}
bool GCAddUpdateNode::GetApplyScale() const {
    return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyScale");
}
void GCAddUpdateNode::SetApplyScale(bool value) {
    SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyScale", false, value);
}
std::string GCAddUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAddUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCBinaryUpdateNode GCAddUpdateNode::GetParent() const {
    GCBinaryUpdateNode value(m_ptr);
    return value;
}
void GCAddUpdateNode::SetParent(GCBinaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAddUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAddUpdateNode>("CAddUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootMotionTiming", &GCAddUpdateNode::GetFootMotionTiming, &GCAddUpdateNode::SetFootMotionTiming)
        .addProperty("ApplyToFootMotion", &GCAddUpdateNode::GetApplyToFootMotion, &GCAddUpdateNode::SetApplyToFootMotion)
        .addProperty("ApplyChannelsSeparately", &GCAddUpdateNode::GetApplyChannelsSeparately, &GCAddUpdateNode::SetApplyChannelsSeparately)
        .addProperty("UseModelSpace", &GCAddUpdateNode::GetUseModelSpace, &GCAddUpdateNode::SetUseModelSpace)
        .addProperty("ApplyScale", &GCAddUpdateNode::GetApplyScale, &GCAddUpdateNode::SetApplyScale)
        .addProperty("Parent", &GCAddUpdateNode::GetParent, &GCAddUpdateNode::SetParent)
        .addFunction("ToPtr", &GCAddUpdateNode::ToPtr)
        .addFunction("IsValid", &GCAddUpdateNode::IsValid)
        .endClass();
}