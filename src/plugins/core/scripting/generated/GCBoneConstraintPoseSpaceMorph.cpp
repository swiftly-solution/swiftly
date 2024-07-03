#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintPoseSpaceMorph::GCBoneConstraintPoseSpaceMorph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintPoseSpaceMorph::GCBoneConstraintPoseSpaceMorph(void *ptr) {
    m_ptr = ptr;
}
std::string GCBoneConstraintPoseSpaceMorph::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sBoneName").Get();
}
void GCBoneConstraintPoseSpaceMorph::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sBoneName", false, CUtlString(value.c_str()));
}
std::string GCBoneConstraintPoseSpaceMorph::GetAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sAttachmentName").Get();
}
void GCBoneConstraintPoseSpaceMorph::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sAttachmentName", false, CUtlString(value.c_str()));
}
std::vector<CUtlString> GCBoneConstraintPoseSpaceMorph::GetOutputMorph() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_outputMorph"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBoneConstraintPoseSpaceMorph::SetOutputMorph(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_outputMorph", false, value);
}
std::vector<GCBoneConstraintPoseSpaceMorph> GCBoneConstraintPoseSpaceMorph::GetInputList() const {
    CUtlVector<GCBoneConstraintPoseSpaceMorph>* vec = GetSchemaValue<CUtlVector<GCBoneConstraintPoseSpaceMorph>*>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_inputList"); std::vector<GCBoneConstraintPoseSpaceMorph> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBoneConstraintPoseSpaceMorph::SetInputList(std::vector<GCBoneConstraintPoseSpaceMorph> value) {
    SetSchemaValueCUtlVector<GCBoneConstraintPoseSpaceMorph>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_inputList", false, value);
}
bool GCBoneConstraintPoseSpaceMorph::GetClamp() const {
    return GetSchemaValue<bool>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_bClamp");
}
void GCBoneConstraintPoseSpaceMorph::SetClamp(bool value) {
    SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_bClamp", false, value);
}
std::string GCBoneConstraintPoseSpaceMorph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintPoseSpaceMorph::IsValid() {
    return (m_ptr != nullptr);
}
GCBoneConstraintBase GCBoneConstraintPoseSpaceMorph::GetParent() const {
    GCBoneConstraintBase value(m_ptr);
    return value;
}
void GCBoneConstraintPoseSpaceMorph::SetParent(GCBoneConstraintBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoneConstraintPoseSpaceMorph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceMorph>("CBoneConstraintPoseSpaceMorph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GCBoneConstraintPoseSpaceMorph::GetBoneName, &GCBoneConstraintPoseSpaceMorph::SetBoneName)
        .addProperty("AttachmentName", &GCBoneConstraintPoseSpaceMorph::GetAttachmentName, &GCBoneConstraintPoseSpaceMorph::SetAttachmentName)
        .addProperty("OutputMorph", &GCBoneConstraintPoseSpaceMorph::GetOutputMorph, &GCBoneConstraintPoseSpaceMorph::SetOutputMorph)
        .addProperty("InputList", &GCBoneConstraintPoseSpaceMorph::GetInputList, &GCBoneConstraintPoseSpaceMorph::SetInputList)
        .addProperty("Clamp", &GCBoneConstraintPoseSpaceMorph::GetClamp, &GCBoneConstraintPoseSpaceMorph::SetClamp)
        .addProperty("Parent", &GCBoneConstraintPoseSpaceMorph::GetParent, &GCBoneConstraintPoseSpaceMorph::SetParent)
        .addFunction("ToPtr", &GCBoneConstraintPoseSpaceMorph::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintPoseSpaceMorph::IsValid)
        .endClass();
}