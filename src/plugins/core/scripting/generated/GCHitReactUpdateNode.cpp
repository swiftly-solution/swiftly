#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHitReactUpdateNode::GCHitReactUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHitReactUpdateNode::GCHitReactUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GHitReactFixedSettings_t GCHitReactUpdateNode::GetOpFixedSettings() const {
    GHitReactFixedSettings_t value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_opFixedSettings"));
    return value;
}
void GCHitReactUpdateNode::SetOpFixedSettings(GHitReactFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_opFixedSettings", false, value);
}
GCAnimParamHandle GCHitReactUpdateNode::GetTriggerParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_triggerParam"));
    return value;
}
void GCHitReactUpdateNode::SetTriggerParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_triggerParam", false, value);
}
GCAnimParamHandle GCHitReactUpdateNode::GetHitBoneParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_hitBoneParam"));
    return value;
}
void GCHitReactUpdateNode::SetHitBoneParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitBoneParam", false, value);
}
GCAnimParamHandle GCHitReactUpdateNode::GetHitOffsetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_hitOffsetParam"));
    return value;
}
void GCHitReactUpdateNode::SetHitOffsetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitOffsetParam", false, value);
}
GCAnimParamHandle GCHitReactUpdateNode::GetHitDirectionParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_hitDirectionParam"));
    return value;
}
void GCHitReactUpdateNode::SetHitDirectionParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitDirectionParam", false, value);
}
GCAnimParamHandle GCHitReactUpdateNode::GetHitStrengthParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CHitReactUpdateNode", "m_hitStrengthParam"));
    return value;
}
void GCHitReactUpdateNode::SetHitStrengthParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitStrengthParam", false, value);
}
float GCHitReactUpdateNode::GetMinDelayBetweenHits() const {
    return GetSchemaValue<float>(m_ptr, "CHitReactUpdateNode", "m_flMinDelayBetweenHits");
}
void GCHitReactUpdateNode::SetMinDelayBetweenHits(float value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_flMinDelayBetweenHits", false, value);
}
bool GCHitReactUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CHitReactUpdateNode", "m_bResetChild");
}
void GCHitReactUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_bResetChild", false, value);
}
std::string GCHitReactUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHitReactUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCHitReactUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCHitReactUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHitReactUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitReactUpdateNode>("CHitReactUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedSettings", &GCHitReactUpdateNode::GetOpFixedSettings, &GCHitReactUpdateNode::SetOpFixedSettings)
        .addProperty("TriggerParam", &GCHitReactUpdateNode::GetTriggerParam, &GCHitReactUpdateNode::SetTriggerParam)
        .addProperty("HitBoneParam", &GCHitReactUpdateNode::GetHitBoneParam, &GCHitReactUpdateNode::SetHitBoneParam)
        .addProperty("HitOffsetParam", &GCHitReactUpdateNode::GetHitOffsetParam, &GCHitReactUpdateNode::SetHitOffsetParam)
        .addProperty("HitDirectionParam", &GCHitReactUpdateNode::GetHitDirectionParam, &GCHitReactUpdateNode::SetHitDirectionParam)
        .addProperty("HitStrengthParam", &GCHitReactUpdateNode::GetHitStrengthParam, &GCHitReactUpdateNode::SetHitStrengthParam)
        .addProperty("MinDelayBetweenHits", &GCHitReactUpdateNode::GetMinDelayBetweenHits, &GCHitReactUpdateNode::SetMinDelayBetweenHits)
        .addProperty("ResetChild", &GCHitReactUpdateNode::GetResetChild, &GCHitReactUpdateNode::SetResetChild)
        .addProperty("Parent", &GCHitReactUpdateNode::GetParent, &GCHitReactUpdateNode::SetParent)
        .addFunction("ToPtr", &GCHitReactUpdateNode::ToPtr)
        .addFunction("IsValid", &GCHitReactUpdateNode::IsValid)
        .endClass();
}