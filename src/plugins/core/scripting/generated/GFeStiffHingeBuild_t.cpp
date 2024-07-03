#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeStiffHingeBuild_t::GFeStiffHingeBuild_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeStiffHingeBuild_t::GFeStiffHingeBuild_t(void *ptr) {
    m_ptr = ptr;
}
float GFeStiffHingeBuild_t::GetMaxAngle() const {
    return GetSchemaValue<float>(m_ptr, "FeStiffHingeBuild_t", "flMaxAngle");
}
void GFeStiffHingeBuild_t::SetMaxAngle(float value) {
    SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flMaxAngle", true, value);
}
float GFeStiffHingeBuild_t::GetStrength() const {
    return GetSchemaValue<float>(m_ptr, "FeStiffHingeBuild_t", "flStrength");
}
void GFeStiffHingeBuild_t::SetStrength(float value) {
    SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flStrength", true, value);
}
std::vector<float> GFeStiffHingeBuild_t::GetMotionBias() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeStiffHingeBuild_t", "flMotionBias"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeStiffHingeBuild_t::SetMotionBias(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeStiffHingeBuild_t", "flMotionBias"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flMotionBias", true, outValue);
}
std::vector<uint16_t> GFeStiffHingeBuild_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeStiffHingeBuild_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeStiffHingeBuild_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeStiffHingeBuild_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "nNode", true, outValue);
}
std::string GFeStiffHingeBuild_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeStiffHingeBuild_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeStiffHingeBuild_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeStiffHingeBuild_t>("FeStiffHingeBuild_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxAngle", &GFeStiffHingeBuild_t::GetMaxAngle, &GFeStiffHingeBuild_t::SetMaxAngle)
        .addProperty("Strength", &GFeStiffHingeBuild_t::GetStrength, &GFeStiffHingeBuild_t::SetStrength)
        .addProperty("MotionBias", &GFeStiffHingeBuild_t::GetMotionBias, &GFeStiffHingeBuild_t::SetMotionBias)
        .addProperty("Node", &GFeStiffHingeBuild_t::GetNode, &GFeStiffHingeBuild_t::SetNode)
        .addFunction("ToPtr", &GFeStiffHingeBuild_t::ToPtr)
        .addFunction("IsValid", &GFeStiffHingeBuild_t::IsValid)
        .endClass();
}