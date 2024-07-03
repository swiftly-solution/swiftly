#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimDemoCaptureSettings::GCAnimDemoCaptureSettings(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimDemoCaptureSettings::GCAnimDemoCaptureSettings(void *ptr) {
    m_ptr = ptr;
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeSplineRotation() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineRotation");
}
void GCAnimDemoCaptureSettings::SetErrorRangeSplineRotation(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineRotation", false, value);
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeSplineTranslation() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineTranslation");
}
void GCAnimDemoCaptureSettings::SetErrorRangeSplineTranslation(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineTranslation", false, value);
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeSplineScale() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineScale");
}
void GCAnimDemoCaptureSettings::SetErrorRangeSplineScale(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineScale", false, value);
}
float GCAnimDemoCaptureSettings::GetIkRotation_MaxSplineError() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxSplineError");
}
void GCAnimDemoCaptureSettings::SetIkRotation_MaxSplineError(float value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxSplineError", false, value);
}
float GCAnimDemoCaptureSettings::GetIkTranslation_MaxSplineError() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxSplineError");
}
void GCAnimDemoCaptureSettings::SetIkTranslation_MaxSplineError(float value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxSplineError", false, value);
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeQuantizationRotation() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationRotation");
}
void GCAnimDemoCaptureSettings::SetErrorRangeQuantizationRotation(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationRotation", false, value);
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeQuantizationTranslation() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationTranslation");
}
void GCAnimDemoCaptureSettings::SetErrorRangeQuantizationTranslation(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationTranslation", false, value);
}
Vector2D GCAnimDemoCaptureSettings::GetErrorRangeQuantizationScale() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationScale");
}
void GCAnimDemoCaptureSettings::SetErrorRangeQuantizationScale(Vector2D value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationScale", false, value);
}
float GCAnimDemoCaptureSettings::GetIkRotation_MaxQuantizationError() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxQuantizationError");
}
void GCAnimDemoCaptureSettings::SetIkRotation_MaxQuantizationError(float value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxQuantizationError", false, value);
}
float GCAnimDemoCaptureSettings::GetIkTranslation_MaxQuantizationError() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxQuantizationError");
}
void GCAnimDemoCaptureSettings::SetIkTranslation_MaxQuantizationError(float value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxQuantizationError", false, value);
}
std::string GCAnimDemoCaptureSettings::GetBaseSequence() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimDemoCaptureSettings", "m_baseSequence").Get();
}
void GCAnimDemoCaptureSettings::SetBaseSequence(std::string value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_baseSequence", false, CUtlString(value.c_str()));
}
int32_t GCAnimDemoCaptureSettings::GetBaseSequenceFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimDemoCaptureSettings", "m_nBaseSequenceFrame");
}
void GCAnimDemoCaptureSettings::SetBaseSequenceFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_nBaseSequenceFrame", false, value);
}
uint64_t GCAnimDemoCaptureSettings::GetBoneSelectionMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimDemoCaptureSettings", "m_boneSelectionMode");
}
void GCAnimDemoCaptureSettings::SetBoneSelectionMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_boneSelectionMode", false, value);
}
std::vector<GBoneDemoCaptureSettings_t> GCAnimDemoCaptureSettings::GetBones() const {
    CUtlVector<GBoneDemoCaptureSettings_t>* vec = GetSchemaValue<CUtlVector<GBoneDemoCaptureSettings_t>*>(m_ptr, "CAnimDemoCaptureSettings", "m_bones"); std::vector<GBoneDemoCaptureSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDemoCaptureSettings::SetBones(std::vector<GBoneDemoCaptureSettings_t> value) {
    SetSchemaValueCUtlVector<GBoneDemoCaptureSettings_t>(m_ptr, "CAnimDemoCaptureSettings", "m_bones", false, value);
}
std::vector<GIKDemoCaptureSettings_t> GCAnimDemoCaptureSettings::GetIkChains() const {
    CUtlVector<GIKDemoCaptureSettings_t>* vec = GetSchemaValue<CUtlVector<GIKDemoCaptureSettings_t>*>(m_ptr, "CAnimDemoCaptureSettings", "m_ikChains"); std::vector<GIKDemoCaptureSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDemoCaptureSettings::SetIkChains(std::vector<GIKDemoCaptureSettings_t> value) {
    SetSchemaValueCUtlVector<GIKDemoCaptureSettings_t>(m_ptr, "CAnimDemoCaptureSettings", "m_ikChains", false, value);
}
std::string GCAnimDemoCaptureSettings::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimDemoCaptureSettings::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimDemoCaptureSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDemoCaptureSettings>("CAnimDemoCaptureSettings")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ErrorRangeSplineRotation", &GCAnimDemoCaptureSettings::GetErrorRangeSplineRotation, &GCAnimDemoCaptureSettings::SetErrorRangeSplineRotation)
        .addProperty("ErrorRangeSplineTranslation", &GCAnimDemoCaptureSettings::GetErrorRangeSplineTranslation, &GCAnimDemoCaptureSettings::SetErrorRangeSplineTranslation)
        .addProperty("ErrorRangeSplineScale", &GCAnimDemoCaptureSettings::GetErrorRangeSplineScale, &GCAnimDemoCaptureSettings::SetErrorRangeSplineScale)
        .addProperty("IkRotation_MaxSplineError", &GCAnimDemoCaptureSettings::GetIkRotation_MaxSplineError, &GCAnimDemoCaptureSettings::SetIkRotation_MaxSplineError)
        .addProperty("IkTranslation_MaxSplineError", &GCAnimDemoCaptureSettings::GetIkTranslation_MaxSplineError, &GCAnimDemoCaptureSettings::SetIkTranslation_MaxSplineError)
        .addProperty("ErrorRangeQuantizationRotation", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationRotation, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationRotation)
        .addProperty("ErrorRangeQuantizationTranslation", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationTranslation, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationTranslation)
        .addProperty("ErrorRangeQuantizationScale", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationScale, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationScale)
        .addProperty("IkRotation_MaxQuantizationError", &GCAnimDemoCaptureSettings::GetIkRotation_MaxQuantizationError, &GCAnimDemoCaptureSettings::SetIkRotation_MaxQuantizationError)
        .addProperty("IkTranslation_MaxQuantizationError", &GCAnimDemoCaptureSettings::GetIkTranslation_MaxQuantizationError, &GCAnimDemoCaptureSettings::SetIkTranslation_MaxQuantizationError)
        .addProperty("BaseSequence", &GCAnimDemoCaptureSettings::GetBaseSequence, &GCAnimDemoCaptureSettings::SetBaseSequence)
        .addProperty("BaseSequenceFrame", &GCAnimDemoCaptureSettings::GetBaseSequenceFrame, &GCAnimDemoCaptureSettings::SetBaseSequenceFrame)
        .addProperty("BoneSelectionMode", &GCAnimDemoCaptureSettings::GetBoneSelectionMode, &GCAnimDemoCaptureSettings::SetBoneSelectionMode)
        .addProperty("Bones", &GCAnimDemoCaptureSettings::GetBones, &GCAnimDemoCaptureSettings::SetBones)
        .addProperty("IkChains", &GCAnimDemoCaptureSettings::GetIkChains, &GCAnimDemoCaptureSettings::SetIkChains)
        .addFunction("ToPtr", &GCAnimDemoCaptureSettings::ToPtr)
        .addFunction("IsValid", &GCAnimDemoCaptureSettings::IsValid)
        .endClass();
}