#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeAxialEdgeBend_t::GFeAxialEdgeBend_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeAxialEdgeBend_t::GFeAxialEdgeBend_t(void *ptr) {
    m_ptr = ptr;
}
float GFeAxialEdgeBend_t::GetTe() const {
    return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "te");
}
void GFeAxialEdgeBend_t::SetTe(float value) {
    SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "te", true, value);
}
float GFeAxialEdgeBend_t::GetTv() const {
    return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "tv");
}
void GFeAxialEdgeBend_t::SetTv(float value) {
    SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "tv", true, value);
}
float GFeAxialEdgeBend_t::GetDist() const {
    return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "flDist");
}
void GFeAxialEdgeBend_t::SetDist(float value) {
    SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "flDist", true, value);
}
std::vector<float> GFeAxialEdgeBend_t::GetWeight() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeAxialEdgeBend_t", "flWeight"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeAxialEdgeBend_t::SetWeight(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeAxialEdgeBend_t", "flWeight"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "flWeight", true, outValue);
}
std::vector<uint16_t> GFeAxialEdgeBend_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAxialEdgeBend_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeAxialEdgeBend_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAxialEdgeBend_t", "nNode"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "nNode", true, outValue);
}
std::string GFeAxialEdgeBend_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeAxialEdgeBend_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeAxialEdgeBend_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeAxialEdgeBend_t>("FeAxialEdgeBend_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Te", &GFeAxialEdgeBend_t::GetTe, &GFeAxialEdgeBend_t::SetTe)
        .addProperty("Tv", &GFeAxialEdgeBend_t::GetTv, &GFeAxialEdgeBend_t::SetTv)
        .addProperty("Dist", &GFeAxialEdgeBend_t::GetDist, &GFeAxialEdgeBend_t::SetDist)
        .addProperty("Weight", &GFeAxialEdgeBend_t::GetWeight, &GFeAxialEdgeBend_t::SetWeight)
        .addProperty("Node", &GFeAxialEdgeBend_t::GetNode, &GFeAxialEdgeBend_t::SetNode)
        .addFunction("ToPtr", &GFeAxialEdgeBend_t::ToPtr)
        .addFunction("IsValid", &GFeAxialEdgeBend_t::IsValid)
        .endClass();
}