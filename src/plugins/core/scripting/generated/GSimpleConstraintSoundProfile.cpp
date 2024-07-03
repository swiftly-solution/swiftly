#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSimpleConstraintSoundProfile::GSimpleConstraintSoundProfile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSimpleConstraintSoundProfile::GSimpleConstraintSoundProfile(void *ptr) {
    m_ptr = ptr;
}
GSimpleConstraintSoundProfile GSimpleConstraintSoundProfile::GetKeypoints() const {
    GSimpleConstraintSoundProfile value(GetSchemaPtr(m_ptr, "SimpleConstraintSoundProfile", "eKeypoints"));
    return value;
}
void GSimpleConstraintSoundProfile::SetKeypoints(GSimpleConstraintSoundProfile value) {
    SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "eKeypoints", false, value);
}
std::vector<float> GSimpleConstraintSoundProfile::GetKeyPoints() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GSimpleConstraintSoundProfile::SetKeyPoints(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints", false, outValue);
}
std::vector<float> GSimpleConstraintSoundProfile::GetReversalSoundThresholds() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GSimpleConstraintSoundProfile::SetReversalSoundThresholds(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds", false, outValue);
}
std::string GSimpleConstraintSoundProfile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSimpleConstraintSoundProfile::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSimpleConstraintSoundProfile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSimpleConstraintSoundProfile>("SimpleConstraintSoundProfile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Keypoints", &GSimpleConstraintSoundProfile::GetKeypoints, &GSimpleConstraintSoundProfile::SetKeypoints)
        .addProperty("KeyPoints", &GSimpleConstraintSoundProfile::GetKeyPoints, &GSimpleConstraintSoundProfile::SetKeyPoints)
        .addProperty("ReversalSoundThresholds", &GSimpleConstraintSoundProfile::GetReversalSoundThresholds, &GSimpleConstraintSoundProfile::SetReversalSoundThresholds)
        .addFunction("ToPtr", &GSimpleConstraintSoundProfile::ToPtr)
        .addFunction("IsValid", &GSimpleConstraintSoundProfile::IsValid)
        .endClass();
}