#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompMatPropertyMutator_t::GCompMatPropertyMutator_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompMatPropertyMutator_t::GCompMatPropertyMutator_t(void *ptr) {
    m_ptr = ptr;
}
bool GCompMatPropertyMutator_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bEnabled");
}
void GCompMatPropertyMutator_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bEnabled", true, value);
}
uint64_t GCompMatPropertyMutator_t::GetMutatorCommandType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompMatPropertyMutator_t", "m_nMutatorCommandType");
}
void GCompMatPropertyMutator_t::SetMutatorCommandType(uint64_t value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nMutatorCommandType", true, value);
}
std::string GCompMatPropertyMutator_t::GetStrInitWith_Container() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strInitWith_Container").Get();
}
void GCompMatPropertyMutator_t::SetStrInitWith_Container(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strInitWith_Container", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyProperty_InputContainerSrc() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerSrc").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyProperty_InputContainerSrc(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerSrc", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyProperty_InputContainerProperty() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerProperty").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyProperty_InputContainerProperty(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerProperty", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyProperty_TargetProperty() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_TargetProperty").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyProperty_TargetProperty(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_TargetProperty", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrRandomRollInputVars_SeedInputVar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strRandomRollInputVars_SeedInputVar").Get();
}
void GCompMatPropertyMutator_t::SetStrRandomRollInputVars_SeedInputVar(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strRandomRollInputVars_SeedInputVar", true, CUtlString(value.c_str()));
}
std::vector<CUtlString> GCompMatPropertyMutator_t::GetRandomRollInputVars_InputVarsToRoll() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecRandomRollInputVars_InputVarsToRoll"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompMatPropertyMutator_t::SetRandomRollInputVars_InputVarsToRoll(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_vecRandomRollInputVars_InputVarsToRoll", true, value);
}
std::string GCompMatPropertyMutator_t::GetStrCopyMatchingKeys_InputContainerSrc() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyMatchingKeys_InputContainerSrc").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyMatchingKeys_InputContainerSrc(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyMatchingKeys_InputContainerSrc", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_InputContainerSrc() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_InputContainerSrc").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_InputContainerSrc(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_InputContainerSrc", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_FindSuffix() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_FindSuffix").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_FindSuffix(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_FindSuffix", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_ReplaceSuffix() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_ReplaceSuffix").Get();
}
void GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_ReplaceSuffix(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_ReplaceSuffix", true, CUtlString(value.c_str()));
}
GCompositeMaterialInputLooseVariable_t GCompMatPropertyMutator_t::GetSetValue_Value() const {
    GCompositeMaterialInputLooseVariable_t value(GetSchemaPtr(m_ptr, "CompMatPropertyMutator_t", "m_nSetValue_Value"));
    return value;
}
void GCompMatPropertyMutator_t::SetSetValue_Value(GCompositeMaterialInputLooseVariable_t value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nSetValue_Value", true, value);
}
std::string GCompMatPropertyMutator_t::GetStrGenerateTexture_TargetParam() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_TargetParam").Get();
}
void GCompMatPropertyMutator_t::SetStrGenerateTexture_TargetParam(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_TargetParam", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrGenerateTexture_InitialContainer() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_InitialContainer").Get();
}
void GCompMatPropertyMutator_t::SetStrGenerateTexture_InitialContainer(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_InitialContainer", true, CUtlString(value.c_str()));
}
int32_t GCompMatPropertyMutator_t::GetResolution() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompMatPropertyMutator_t", "m_nResolution");
}
void GCompMatPropertyMutator_t::SetResolution(int32_t value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nResolution", true, value);
}
bool GCompMatPropertyMutator_t::GetIsScratchTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bIsScratchTarget");
}
void GCompMatPropertyMutator_t::SetIsScratchTarget(bool value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bIsScratchTarget", true, value);
}
bool GCompMatPropertyMutator_t::GetSplatDebugInfo() const {
    return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bSplatDebugInfo");
}
void GCompMatPropertyMutator_t::SetSplatDebugInfo(bool value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bSplatDebugInfo", true, value);
}
bool GCompMatPropertyMutator_t::GetCaptureInRenderDoc() const {
    return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bCaptureInRenderDoc");
}
void GCompMatPropertyMutator_t::SetCaptureInRenderDoc(bool value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bCaptureInRenderDoc", true, value);
}
std::vector<GCompMatPropertyMutator_t> GCompMatPropertyMutator_t::GetTexGenInstructions() const {
    CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecTexGenInstructions"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompMatPropertyMutator_t::SetTexGenInstructions(std::vector<GCompMatPropertyMutator_t> value) {
    SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecTexGenInstructions", true, value);
}
std::vector<GCompMatPropertyMutator_t> GCompMatPropertyMutator_t::GetConditionalMutators() const {
    CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditionalMutators"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompMatPropertyMutator_t::SetConditionalMutators(std::vector<GCompMatPropertyMutator_t> value) {
    SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditionalMutators", true, value);
}
std::string GCompMatPropertyMutator_t::GetStrPopInputQueue_Container() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strPopInputQueue_Container").Get();
}
void GCompMatPropertyMutator_t::SetStrPopInputQueue_Container(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strPopInputQueue_Container", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrDrawText_InputContainerSrc() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerSrc").Get();
}
void GCompMatPropertyMutator_t::SetStrDrawText_InputContainerSrc(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerSrc", true, CUtlString(value.c_str()));
}
std::string GCompMatPropertyMutator_t::GetStrDrawText_InputContainerProperty() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerProperty").Get();
}
void GCompMatPropertyMutator_t::SetStrDrawText_InputContainerProperty(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerProperty", true, CUtlString(value.c_str()));
}
Vector2D GCompMatPropertyMutator_t::GetDrawText_Position() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CompMatPropertyMutator_t", "m_vecDrawText_Position");
}
void GCompMatPropertyMutator_t::SetDrawText_Position(Vector2D value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_vecDrawText_Position", true, value);
}
Color GCompMatPropertyMutator_t::GetColDrawText_Color() const {
    return GetSchemaValue<Color>(m_ptr, "CompMatPropertyMutator_t", "m_colDrawText_Color");
}
void GCompMatPropertyMutator_t::SetColDrawText_Color(Color value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_colDrawText_Color", true, value);
}
std::string GCompMatPropertyMutator_t::GetStrDrawText_Font() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_Font").Get();
}
void GCompMatPropertyMutator_t::SetStrDrawText_Font(std::string value) {
    SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_Font", true, CUtlString(value.c_str()));
}
std::vector<GCompMatMutatorCondition_t> GCompMatPropertyMutator_t::GetConditions() const {
    CUtlVector<GCompMatMutatorCondition_t>* vec = GetSchemaValue<CUtlVector<GCompMatMutatorCondition_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditions"); std::vector<GCompMatMutatorCondition_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompMatPropertyMutator_t::SetConditions(std::vector<GCompMatMutatorCondition_t> value) {
    SetSchemaValueCUtlVector<GCompMatMutatorCondition_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditions", true, value);
}
std::string GCompMatPropertyMutator_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompMatPropertyMutator_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompMatPropertyMutator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompMatPropertyMutator_t>("CompMatPropertyMutator_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCompMatPropertyMutator_t::GetEnabled, &GCompMatPropertyMutator_t::SetEnabled)
        .addProperty("MutatorCommandType", &GCompMatPropertyMutator_t::GetMutatorCommandType, &GCompMatPropertyMutator_t::SetMutatorCommandType)
        .addProperty("StrInitWith_Container", &GCompMatPropertyMutator_t::GetStrInitWith_Container, &GCompMatPropertyMutator_t::SetStrInitWith_Container)
        .addProperty("StrCopyProperty_InputContainerSrc", &GCompMatPropertyMutator_t::GetStrCopyProperty_InputContainerSrc, &GCompMatPropertyMutator_t::SetStrCopyProperty_InputContainerSrc)
        .addProperty("StrCopyProperty_InputContainerProperty", &GCompMatPropertyMutator_t::GetStrCopyProperty_InputContainerProperty, &GCompMatPropertyMutator_t::SetStrCopyProperty_InputContainerProperty)
        .addProperty("StrCopyProperty_TargetProperty", &GCompMatPropertyMutator_t::GetStrCopyProperty_TargetProperty, &GCompMatPropertyMutator_t::SetStrCopyProperty_TargetProperty)
        .addProperty("StrRandomRollInputVars_SeedInputVar", &GCompMatPropertyMutator_t::GetStrRandomRollInputVars_SeedInputVar, &GCompMatPropertyMutator_t::SetStrRandomRollInputVars_SeedInputVar)
        .addProperty("RandomRollInputVars_InputVarsToRoll", &GCompMatPropertyMutator_t::GetRandomRollInputVars_InputVarsToRoll, &GCompMatPropertyMutator_t::SetRandomRollInputVars_InputVarsToRoll)
        .addProperty("StrCopyMatchingKeys_InputContainerSrc", &GCompMatPropertyMutator_t::GetStrCopyMatchingKeys_InputContainerSrc, &GCompMatPropertyMutator_t::SetStrCopyMatchingKeys_InputContainerSrc)
        .addProperty("StrCopyKeysWithSuffix_InputContainerSrc", &GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_InputContainerSrc, &GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_InputContainerSrc)
        .addProperty("StrCopyKeysWithSuffix_FindSuffix", &GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_FindSuffix, &GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_FindSuffix)
        .addProperty("StrCopyKeysWithSuffix_ReplaceSuffix", &GCompMatPropertyMutator_t::GetStrCopyKeysWithSuffix_ReplaceSuffix, &GCompMatPropertyMutator_t::SetStrCopyKeysWithSuffix_ReplaceSuffix)
        .addProperty("SetValue_Value", &GCompMatPropertyMutator_t::GetSetValue_Value, &GCompMatPropertyMutator_t::SetSetValue_Value)
        .addProperty("StrGenerateTexture_TargetParam", &GCompMatPropertyMutator_t::GetStrGenerateTexture_TargetParam, &GCompMatPropertyMutator_t::SetStrGenerateTexture_TargetParam)
        .addProperty("StrGenerateTexture_InitialContainer", &GCompMatPropertyMutator_t::GetStrGenerateTexture_InitialContainer, &GCompMatPropertyMutator_t::SetStrGenerateTexture_InitialContainer)
        .addProperty("Resolution", &GCompMatPropertyMutator_t::GetResolution, &GCompMatPropertyMutator_t::SetResolution)
        .addProperty("IsScratchTarget", &GCompMatPropertyMutator_t::GetIsScratchTarget, &GCompMatPropertyMutator_t::SetIsScratchTarget)
        .addProperty("SplatDebugInfo", &GCompMatPropertyMutator_t::GetSplatDebugInfo, &GCompMatPropertyMutator_t::SetSplatDebugInfo)
        .addProperty("CaptureInRenderDoc", &GCompMatPropertyMutator_t::GetCaptureInRenderDoc, &GCompMatPropertyMutator_t::SetCaptureInRenderDoc)
        .addProperty("TexGenInstructions", &GCompMatPropertyMutator_t::GetTexGenInstructions, &GCompMatPropertyMutator_t::SetTexGenInstructions)
        .addProperty("ConditionalMutators", &GCompMatPropertyMutator_t::GetConditionalMutators, &GCompMatPropertyMutator_t::SetConditionalMutators)
        .addProperty("StrPopInputQueue_Container", &GCompMatPropertyMutator_t::GetStrPopInputQueue_Container, &GCompMatPropertyMutator_t::SetStrPopInputQueue_Container)
        .addProperty("StrDrawText_InputContainerSrc", &GCompMatPropertyMutator_t::GetStrDrawText_InputContainerSrc, &GCompMatPropertyMutator_t::SetStrDrawText_InputContainerSrc)
        .addProperty("StrDrawText_InputContainerProperty", &GCompMatPropertyMutator_t::GetStrDrawText_InputContainerProperty, &GCompMatPropertyMutator_t::SetStrDrawText_InputContainerProperty)
        .addProperty("DrawText_Position", &GCompMatPropertyMutator_t::GetDrawText_Position, &GCompMatPropertyMutator_t::SetDrawText_Position)
        .addProperty("ColDrawText_Color", &GCompMatPropertyMutator_t::GetColDrawText_Color, &GCompMatPropertyMutator_t::SetColDrawText_Color)
        .addProperty("StrDrawText_Font", &GCompMatPropertyMutator_t::GetStrDrawText_Font, &GCompMatPropertyMutator_t::SetStrDrawText_Font)
        .addProperty("Conditions", &GCompMatPropertyMutator_t::GetConditions, &GCompMatPropertyMutator_t::SetConditions)
        .addFunction("ToPtr", &GCompMatPropertyMutator_t::ToPtr)
        .addFunction("IsValid", &GCompMatPropertyMutator_t::IsValid)
        .endClass();
}