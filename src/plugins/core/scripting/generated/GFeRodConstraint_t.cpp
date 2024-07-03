#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeRodConstraint_t::GFeRodConstraint_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeRodConstraint_t::GFeRodConstraint_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeRodConstraint_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeRodConstraint_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeRodConstraint_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeRodConstraint_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeRodConstraint_t", "nNode", true, outValue);
}
float GFeRodConstraint_t::GetMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "FeRodConstraint_t", "flMaxDist");
}
void GFeRodConstraint_t::SetMaxDist(float value) {
    SetSchemaValue(m_ptr, "FeRodConstraint_t", "flMaxDist", true, value);
}
float GFeRodConstraint_t::GetMinDist() const {
    return GetSchemaValue<float>(m_ptr, "FeRodConstraint_t", "flMinDist");
}
void GFeRodConstraint_t::SetMinDist(float value) {
    SetSchemaValue(m_ptr, "FeRodConstraint_t", "flMinDist", true, value);
}
float GFeRodConstraint_t::GetWeight0() const {
    return GetSchemaValue<float>(m_ptr, "FeRodConstraint_t", "flWeight0");
}
void GFeRodConstraint_t::SetWeight0(float value) {
    SetSchemaValue(m_ptr, "FeRodConstraint_t", "flWeight0", true, value);
}
float GFeRodConstraint_t::GetRelaxationFactor() const {
    return GetSchemaValue<float>(m_ptr, "FeRodConstraint_t", "flRelaxationFactor");
}
void GFeRodConstraint_t::SetRelaxationFactor(float value) {
    SetSchemaValue(m_ptr, "FeRodConstraint_t", "flRelaxationFactor", true, value);
}
std::string GFeRodConstraint_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeRodConstraint_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeRodConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeRodConstraint_t>("FeRodConstraint_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeRodConstraint_t::GetNode, &GFeRodConstraint_t::SetNode)
        .addProperty("MaxDist", &GFeRodConstraint_t::GetMaxDist, &GFeRodConstraint_t::SetMaxDist)
        .addProperty("MinDist", &GFeRodConstraint_t::GetMinDist, &GFeRodConstraint_t::SetMinDist)
        .addProperty("Weight0", &GFeRodConstraint_t::GetWeight0, &GFeRodConstraint_t::SetWeight0)
        .addProperty("RelaxationFactor", &GFeRodConstraint_t::GetRelaxationFactor, &GFeRodConstraint_t::SetRelaxationFactor)
        .addFunction("ToPtr", &GFeRodConstraint_t::ToPtr)
        .addFunction("IsValid", &GFeRodConstraint_t::IsValid)
        .endClass();
}