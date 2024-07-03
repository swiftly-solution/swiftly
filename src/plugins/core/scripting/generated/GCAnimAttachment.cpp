#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimAttachment::GCAnimAttachment(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimAttachment::GCAnimAttachment(void *ptr) {
    m_ptr = ptr;
}
std::vector<Quaternion> GCAnimAttachment::GetInfluenceRotations() const {
    Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAnimAttachment", "m_influenceRotations"); std::vector<Quaternion> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimAttachment::SetInfluenceRotations(std::vector<Quaternion> value) {
    Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAnimAttachment", "m_influenceRotations"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceRotations", false, outValue);
}
std::vector<Vector> GCAnimAttachment::GetInfluenceOffsets() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAnimAttachment", "m_influenceOffsets"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimAttachment::SetInfluenceOffsets(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAnimAttachment", "m_influenceOffsets"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceOffsets", false, outValue);
}
std::vector<int32_t> GCAnimAttachment::GetInfluenceIndices() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CAnimAttachment", "m_influenceIndices"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimAttachment::SetInfluenceIndices(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CAnimAttachment", "m_influenceIndices"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceIndices", false, outValue);
}
std::vector<float> GCAnimAttachment::GetInfluenceWeights() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CAnimAttachment", "m_influenceWeights"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimAttachment::SetInfluenceWeights(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CAnimAttachment", "m_influenceWeights"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceWeights", false, outValue);
}
uint8_t GCAnimAttachment::GetNumInfluences() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CAnimAttachment", "m_numInfluences");
}
void GCAnimAttachment::SetNumInfluences(uint8_t value) {
    SetSchemaValue(m_ptr, "CAnimAttachment", "m_numInfluences", false, value);
}
std::string GCAnimAttachment::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimAttachment::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimAttachment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimAttachment>("CAnimAttachment")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InfluenceRotations", &GCAnimAttachment::GetInfluenceRotations, &GCAnimAttachment::SetInfluenceRotations)
        .addProperty("InfluenceOffsets", &GCAnimAttachment::GetInfluenceOffsets, &GCAnimAttachment::SetInfluenceOffsets)
        .addProperty("InfluenceIndices", &GCAnimAttachment::GetInfluenceIndices, &GCAnimAttachment::SetInfluenceIndices)
        .addProperty("InfluenceWeights", &GCAnimAttachment::GetInfluenceWeights, &GCAnimAttachment::SetInfluenceWeights)
        .addProperty("NumInfluences", &GCAnimAttachment::GetNumInfluences, &GCAnimAttachment::SetNumInfluences)
        .addFunction("ToPtr", &GCAnimAttachment::ToPtr)
        .addFunction("IsValid", &GCAnimAttachment::IsValid)
        .endClass();
}