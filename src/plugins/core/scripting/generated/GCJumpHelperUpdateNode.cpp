#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCJumpHelperUpdateNode::GCJumpHelperUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCJumpHelperUpdateNode::GCJumpHelperUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCJumpHelperUpdateNode::GetTargetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CJumpHelperUpdateNode", "m_hTargetParam"));
    return value;
}
void GCJumpHelperUpdateNode::SetTargetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_hTargetParam", false, value);
}
Vector GCJumpHelperUpdateNode::GetOriginalJumpMovement() const {
    return GetSchemaValue<Vector>(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpMovement");
}
void GCJumpHelperUpdateNode::SetOriginalJumpMovement(Vector value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpMovement", false, value);
}
float GCJumpHelperUpdateNode::GetOriginalJumpDuration() const {
    return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpDuration");
}
void GCJumpHelperUpdateNode::SetOriginalJumpDuration(float value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpDuration", false, value);
}
float GCJumpHelperUpdateNode::GetJumpStartCycle() const {
    return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flJumpStartCycle");
}
void GCJumpHelperUpdateNode::SetJumpStartCycle(float value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flJumpStartCycle", false, value);
}
float GCJumpHelperUpdateNode::GetJumpEndCycle() const {
    return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flJumpEndCycle");
}
void GCJumpHelperUpdateNode::SetJumpEndCycle(float value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flJumpEndCycle", false, value);
}
uint64_t GCJumpHelperUpdateNode::GetCorrectionMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CJumpHelperUpdateNode", "m_eCorrectionMethod");
}
void GCJumpHelperUpdateNode::SetCorrectionMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_eCorrectionMethod", false, value);
}
std::vector<bool> GCJumpHelperUpdateNode::GetTranslationAxis() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis"); std::vector<bool> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCJumpHelperUpdateNode::SetTranslationAxis(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis", false, outValue);
}
bool GCJumpHelperUpdateNode::GetScaleSpeed() const {
    return GetSchemaValue<bool>(m_ptr, "CJumpHelperUpdateNode", "m_bScaleSpeed");
}
void GCJumpHelperUpdateNode::SetScaleSpeed(bool value) {
    SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_bScaleSpeed", false, value);
}
std::string GCJumpHelperUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCJumpHelperUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCSequenceUpdateNode GCJumpHelperUpdateNode::GetParent() const {
    GCSequenceUpdateNode value(m_ptr);
    return value;
}
void GCJumpHelperUpdateNode::SetParent(GCSequenceUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCJumpHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCJumpHelperUpdateNode>("CJumpHelperUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetParam", &GCJumpHelperUpdateNode::GetTargetParam, &GCJumpHelperUpdateNode::SetTargetParam)
        .addProperty("OriginalJumpMovement", &GCJumpHelperUpdateNode::GetOriginalJumpMovement, &GCJumpHelperUpdateNode::SetOriginalJumpMovement)
        .addProperty("OriginalJumpDuration", &GCJumpHelperUpdateNode::GetOriginalJumpDuration, &GCJumpHelperUpdateNode::SetOriginalJumpDuration)
        .addProperty("JumpStartCycle", &GCJumpHelperUpdateNode::GetJumpStartCycle, &GCJumpHelperUpdateNode::SetJumpStartCycle)
        .addProperty("JumpEndCycle", &GCJumpHelperUpdateNode::GetJumpEndCycle, &GCJumpHelperUpdateNode::SetJumpEndCycle)
        .addProperty("CorrectionMethod", &GCJumpHelperUpdateNode::GetCorrectionMethod, &GCJumpHelperUpdateNode::SetCorrectionMethod)
        .addProperty("TranslationAxis", &GCJumpHelperUpdateNode::GetTranslationAxis, &GCJumpHelperUpdateNode::SetTranslationAxis)
        .addProperty("ScaleSpeed", &GCJumpHelperUpdateNode::GetScaleSpeed, &GCJumpHelperUpdateNode::SetScaleSpeed)
        .addProperty("Parent", &GCJumpHelperUpdateNode::GetParent, &GCJumpHelperUpdateNode::SetParent)
        .addFunction("ToPtr", &GCJumpHelperUpdateNode::ToPtr)
        .addFunction("IsValid", &GCJumpHelperUpdateNode::IsValid)
        .endClass();
}