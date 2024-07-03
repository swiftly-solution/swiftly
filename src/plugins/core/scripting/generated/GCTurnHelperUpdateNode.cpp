#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTurnHelperUpdateNode::GCTurnHelperUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTurnHelperUpdateNode::GCTurnHelperUpdateNode(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCTurnHelperUpdateNode::GetFacingTarget() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CTurnHelperUpdateNode", "m_facingTarget");
}
void GCTurnHelperUpdateNode::SetFacingTarget(uint64_t value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_facingTarget", false, value);
}
float GCTurnHelperUpdateNode::GetTurnStartTimeOffset() const {
    return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_turnStartTimeOffset");
}
void GCTurnHelperUpdateNode::SetTurnStartTimeOffset(float value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_turnStartTimeOffset", false, value);
}
float GCTurnHelperUpdateNode::GetTurnDuration() const {
    return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_turnDuration");
}
void GCTurnHelperUpdateNode::SetTurnDuration(float value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_turnDuration", false, value);
}
bool GCTurnHelperUpdateNode::GetMatchChildDuration() const {
    return GetSchemaValue<bool>(m_ptr, "CTurnHelperUpdateNode", "m_bMatchChildDuration");
}
void GCTurnHelperUpdateNode::SetMatchChildDuration(bool value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_bMatchChildDuration", false, value);
}
float GCTurnHelperUpdateNode::GetManualTurnOffset() const {
    return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_manualTurnOffset");
}
void GCTurnHelperUpdateNode::SetManualTurnOffset(float value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_manualTurnOffset", false, value);
}
bool GCTurnHelperUpdateNode::GetUseManualTurnOffset() const {
    return GetSchemaValue<bool>(m_ptr, "CTurnHelperUpdateNode", "m_bUseManualTurnOffset");
}
void GCTurnHelperUpdateNode::SetUseManualTurnOffset(bool value) {
    SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_bUseManualTurnOffset", false, value);
}
std::string GCTurnHelperUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTurnHelperUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCTurnHelperUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCTurnHelperUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTurnHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTurnHelperUpdateNode>("CTurnHelperUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FacingTarget", &GCTurnHelperUpdateNode::GetFacingTarget, &GCTurnHelperUpdateNode::SetFacingTarget)
        .addProperty("TurnStartTimeOffset", &GCTurnHelperUpdateNode::GetTurnStartTimeOffset, &GCTurnHelperUpdateNode::SetTurnStartTimeOffset)
        .addProperty("TurnDuration", &GCTurnHelperUpdateNode::GetTurnDuration, &GCTurnHelperUpdateNode::SetTurnDuration)
        .addProperty("MatchChildDuration", &GCTurnHelperUpdateNode::GetMatchChildDuration, &GCTurnHelperUpdateNode::SetMatchChildDuration)
        .addProperty("ManualTurnOffset", &GCTurnHelperUpdateNode::GetManualTurnOffset, &GCTurnHelperUpdateNode::SetManualTurnOffset)
        .addProperty("UseManualTurnOffset", &GCTurnHelperUpdateNode::GetUseManualTurnOffset, &GCTurnHelperUpdateNode::SetUseManualTurnOffset)
        .addProperty("Parent", &GCTurnHelperUpdateNode::GetParent, &GCTurnHelperUpdateNode::SetParent)
        .addFunction("ToPtr", &GCTurnHelperUpdateNode::ToPtr)
        .addFunction("IsValid", &GCTurnHelperUpdateNode::IsValid)
        .endClass();
}