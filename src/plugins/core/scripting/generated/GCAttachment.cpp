#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAttachment::GCAttachment(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAttachment::GCAttachment(void *ptr) {
    m_ptr = ptr;
}
std::string GCAttachment::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAttachment", "m_name").Get();
}
void GCAttachment::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CAttachment", "m_name", false, CUtlString(value.c_str()));
}
std::vector<CUtlString> GCAttachment::GetInfluenceNames() const {
    CUtlString* outValue = GetSchemaValue<CUtlString*>(m_ptr, "CAttachment", "m_influenceNames"); std::vector<CUtlString> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAttachment::SetInfluenceNames(std::vector<CUtlString> value) {
    CUtlString* outValue = GetSchemaValue<CUtlString*>(m_ptr, "CAttachment", "m_influenceNames"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_influenceNames", false, outValue);
}
std::vector<Quaternion> GCAttachment::GetInfluenceRotations() const {
    Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAttachment", "m_vInfluenceRotations"); std::vector<Quaternion> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAttachment::SetInfluenceRotations(std::vector<Quaternion> value) {
    Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAttachment", "m_vInfluenceRotations"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_vInfluenceRotations", false, outValue);
}
std::vector<Vector> GCAttachment::GetInfluenceOffsets() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAttachment", "m_vInfluenceOffsets"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAttachment::SetInfluenceOffsets(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAttachment", "m_vInfluenceOffsets"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_vInfluenceOffsets", false, outValue);
}
std::vector<float> GCAttachment::GetInfluenceWeights() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CAttachment", "m_influenceWeights"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAttachment::SetInfluenceWeights(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CAttachment", "m_influenceWeights"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_influenceWeights", false, outValue);
}
std::vector<bool> GCAttachment::GetInfluenceRootTransform() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CAttachment", "m_bInfluenceRootTransform"); std::vector<bool> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAttachment::SetInfluenceRootTransform(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CAttachment", "m_bInfluenceRootTransform"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_bInfluenceRootTransform", false, outValue);
}
uint8_t GCAttachment::GetInfluences() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CAttachment", "m_nInfluences");
}
void GCAttachment::SetInfluences(uint8_t value) {
    SetSchemaValue(m_ptr, "CAttachment", "m_nInfluences", false, value);
}
bool GCAttachment::GetIgnoreRotation() const {
    return GetSchemaValue<bool>(m_ptr, "CAttachment", "m_bIgnoreRotation");
}
void GCAttachment::SetIgnoreRotation(bool value) {
    SetSchemaValue(m_ptr, "CAttachment", "m_bIgnoreRotation", false, value);
}
std::string GCAttachment::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAttachment::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAttachment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttachment>("CAttachment")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAttachment::GetName, &GCAttachment::SetName)
        .addProperty("InfluenceNames", &GCAttachment::GetInfluenceNames, &GCAttachment::SetInfluenceNames)
        .addProperty("InfluenceRotations", &GCAttachment::GetInfluenceRotations, &GCAttachment::SetInfluenceRotations)
        .addProperty("InfluenceOffsets", &GCAttachment::GetInfluenceOffsets, &GCAttachment::SetInfluenceOffsets)
        .addProperty("InfluenceWeights", &GCAttachment::GetInfluenceWeights, &GCAttachment::SetInfluenceWeights)
        .addProperty("InfluenceRootTransform", &GCAttachment::GetInfluenceRootTransform, &GCAttachment::SetInfluenceRootTransform)
        .addProperty("Influences", &GCAttachment::GetInfluences, &GCAttachment::SetInfluences)
        .addProperty("IgnoreRotation", &GCAttachment::GetIgnoreRotation, &GCAttachment::SetIgnoreRotation)
        .addFunction("ToPtr", &GCAttachment::ToPtr)
        .addFunction("IsValid", &GCAttachment::IsValid)
        .endClass();
}