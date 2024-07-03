#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCChoiceUpdateNode::GCChoiceUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCChoiceUpdateNode::GCChoiceUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimUpdateNodeRef> GCChoiceUpdateNode::GetChildren() const {
    CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CChoiceUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCChoiceUpdateNode::SetChildren(std::vector<GCAnimUpdateNodeRef> value) {
    SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CChoiceUpdateNode", "m_children", false, value);
}
std::vector<float32> GCChoiceUpdateNode::GetWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CChoiceUpdateNode", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCChoiceUpdateNode::SetWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CChoiceUpdateNode", "m_weights", false, value);
}
std::vector<float32> GCChoiceUpdateNode::GetBlendTimes() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CChoiceUpdateNode", "m_blendTimes"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCChoiceUpdateNode::SetBlendTimes(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CChoiceUpdateNode", "m_blendTimes", false, value);
}
uint64_t GCChoiceUpdateNode::GetChoiceMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CChoiceUpdateNode", "m_choiceMethod");
}
void GCChoiceUpdateNode::SetChoiceMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_choiceMethod", false, value);
}
uint64_t GCChoiceUpdateNode::GetChoiceChangeMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CChoiceUpdateNode", "m_choiceChangeMethod");
}
void GCChoiceUpdateNode::SetChoiceChangeMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_choiceChangeMethod", false, value);
}
uint64_t GCChoiceUpdateNode::GetBlendMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CChoiceUpdateNode", "m_blendMethod");
}
void GCChoiceUpdateNode::SetBlendMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_blendMethod", false, value);
}
float GCChoiceUpdateNode::GetBlendTime() const {
    return GetSchemaValue<float>(m_ptr, "CChoiceUpdateNode", "m_blendTime");
}
void GCChoiceUpdateNode::SetBlendTime(float value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_blendTime", false, value);
}
bool GCChoiceUpdateNode::GetCrossFade() const {
    return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bCrossFade");
}
void GCChoiceUpdateNode::SetCrossFade(bool value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bCrossFade", false, value);
}
bool GCChoiceUpdateNode::GetResetChosen() const {
    return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bResetChosen");
}
void GCChoiceUpdateNode::SetResetChosen(bool value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bResetChosen", false, value);
}
bool GCChoiceUpdateNode::GetDontResetSameSelection() const {
    return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bDontResetSameSelection");
}
void GCChoiceUpdateNode::SetDontResetSameSelection(bool value) {
    SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bDontResetSameSelection", false, value);
}
std::string GCChoiceUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCChoiceUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCChoiceUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCChoiceUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCChoiceUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChoiceUpdateNode>("CChoiceUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Children", &GCChoiceUpdateNode::GetChildren, &GCChoiceUpdateNode::SetChildren)
        .addProperty("Weights", &GCChoiceUpdateNode::GetWeights, &GCChoiceUpdateNode::SetWeights)
        .addProperty("BlendTimes", &GCChoiceUpdateNode::GetBlendTimes, &GCChoiceUpdateNode::SetBlendTimes)
        .addProperty("ChoiceMethod", &GCChoiceUpdateNode::GetChoiceMethod, &GCChoiceUpdateNode::SetChoiceMethod)
        .addProperty("ChoiceChangeMethod", &GCChoiceUpdateNode::GetChoiceChangeMethod, &GCChoiceUpdateNode::SetChoiceChangeMethod)
        .addProperty("BlendMethod", &GCChoiceUpdateNode::GetBlendMethod, &GCChoiceUpdateNode::SetBlendMethod)
        .addProperty("BlendTime", &GCChoiceUpdateNode::GetBlendTime, &GCChoiceUpdateNode::SetBlendTime)
        .addProperty("CrossFade", &GCChoiceUpdateNode::GetCrossFade, &GCChoiceUpdateNode::SetCrossFade)
        .addProperty("ResetChosen", &GCChoiceUpdateNode::GetResetChosen, &GCChoiceUpdateNode::SetResetChosen)
        .addProperty("DontResetSameSelection", &GCChoiceUpdateNode::GetDontResetSameSelection, &GCChoiceUpdateNode::SetDontResetSameSelection)
        .addProperty("Parent", &GCChoiceUpdateNode::GetParent, &GCChoiceUpdateNode::SetParent)
        .addFunction("ToPtr", &GCChoiceUpdateNode::ToPtr)
        .addFunction("IsValid", &GCChoiceUpdateNode::IsValid)
        .endClass();
}