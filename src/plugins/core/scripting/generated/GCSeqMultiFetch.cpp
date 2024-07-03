#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqMultiFetch::GCSeqMultiFetch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqMultiFetch::GCSeqMultiFetch(void *ptr) {
    m_ptr = ptr;
}
GCSeqMultiFetchFlag GCSeqMultiFetch::GetFlags() const {
    GCSeqMultiFetchFlag value(GetSchemaPtr(m_ptr, "CSeqMultiFetch", "m_flags"));
    return value;
}
void GCSeqMultiFetch::SetFlags(GCSeqMultiFetchFlag value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_flags", false, value);
}
std::vector<int16> GCSeqMultiFetch::GetLocalReferenceArray() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqMultiFetch", "m_localReferenceArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqMultiFetch::SetLocalReferenceArray(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqMultiFetch", "m_localReferenceArray", false, value);
}
std::vector<int32_t> GCSeqMultiFetch::GetGroupSize() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nGroupSize"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSeqMultiFetch::SetGroupSize(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nGroupSize"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nGroupSize", false, outValue);
}
std::vector<int32_t> GCSeqMultiFetch::GetLocalPose() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nLocalPose"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSeqMultiFetch::SetLocalPose(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSeqMultiFetch", "m_nLocalPose"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nLocalPose", false, outValue);
}
std::vector<float32> GCSeqMultiFetch::GetPoseKeyArray0() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray0"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqMultiFetch::SetPoseKeyArray0(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray0", false, value);
}
std::vector<float32> GCSeqMultiFetch::GetPoseKeyArray1() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray1"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqMultiFetch::SetPoseKeyArray1(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqMultiFetch", "m_poseKeyArray1", false, value);
}
int32_t GCSeqMultiFetch::GetLocalCyclePoseParameter() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSeqMultiFetch", "m_nLocalCyclePoseParameter");
}
void GCSeqMultiFetch::SetLocalCyclePoseParameter(int32_t value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_nLocalCyclePoseParameter", false, value);
}
bool GCSeqMultiFetch::GetCalculatePoseParameters() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetch", "m_bCalculatePoseParameters");
}
void GCSeqMultiFetch::SetCalculatePoseParameters(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_bCalculatePoseParameters", false, value);
}
bool GCSeqMultiFetch::GetFixedBlendWeight() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetch", "m_bFixedBlendWeight");
}
void GCSeqMultiFetch::SetFixedBlendWeight(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_bFixedBlendWeight", false, value);
}
std::vector<float> GCSeqMultiFetch::GetFixedBlendWeightVals() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSeqMultiFetch::SetFixedBlendWeightVals(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSeqMultiFetch", "m_flFixedBlendWeightVals", false, outValue);
}
std::string GCSeqMultiFetch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqMultiFetch::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqMultiFetch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqMultiFetch>("CSeqMultiFetch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GCSeqMultiFetch::GetFlags, &GCSeqMultiFetch::SetFlags)
        .addProperty("LocalReferenceArray", &GCSeqMultiFetch::GetLocalReferenceArray, &GCSeqMultiFetch::SetLocalReferenceArray)
        .addProperty("GroupSize", &GCSeqMultiFetch::GetGroupSize, &GCSeqMultiFetch::SetGroupSize)
        .addProperty("LocalPose", &GCSeqMultiFetch::GetLocalPose, &GCSeqMultiFetch::SetLocalPose)
        .addProperty("PoseKeyArray0", &GCSeqMultiFetch::GetPoseKeyArray0, &GCSeqMultiFetch::SetPoseKeyArray0)
        .addProperty("PoseKeyArray1", &GCSeqMultiFetch::GetPoseKeyArray1, &GCSeqMultiFetch::SetPoseKeyArray1)
        .addProperty("LocalCyclePoseParameter", &GCSeqMultiFetch::GetLocalCyclePoseParameter, &GCSeqMultiFetch::SetLocalCyclePoseParameter)
        .addProperty("CalculatePoseParameters", &GCSeqMultiFetch::GetCalculatePoseParameters, &GCSeqMultiFetch::SetCalculatePoseParameters)
        .addProperty("FixedBlendWeight", &GCSeqMultiFetch::GetFixedBlendWeight, &GCSeqMultiFetch::SetFixedBlendWeight)
        .addProperty("FixedBlendWeightVals", &GCSeqMultiFetch::GetFixedBlendWeightVals, &GCSeqMultiFetch::SetFixedBlendWeightVals)
        .addFunction("ToPtr", &GCSeqMultiFetch::ToPtr)
        .addFunction("IsValid", &GCSeqMultiFetch::IsValid)
        .endClass();
}