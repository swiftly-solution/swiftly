#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeAnimStrayRadius_t::GFeAnimStrayRadius_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeAnimStrayRadius_t::GFeAnimStrayRadius_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeAnimStrayRadius_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAnimStrayRadius_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeAnimStrayRadius_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAnimStrayRadius_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "nNode", true, outValue);
}
float GFeAnimStrayRadius_t::GetMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "FeAnimStrayRadius_t", "flMaxDist");
}
void GFeAnimStrayRadius_t::SetMaxDist(float value) {
    SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "flMaxDist", true, value);
}
float GFeAnimStrayRadius_t::GetRelaxationFactor() const {
    return GetSchemaValue<float>(m_ptr, "FeAnimStrayRadius_t", "flRelaxationFactor");
}
void GFeAnimStrayRadius_t::SetRelaxationFactor(float value) {
    SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "flRelaxationFactor", true, value);
}
std::string GFeAnimStrayRadius_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeAnimStrayRadius_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeAnimStrayRadius_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeAnimStrayRadius_t>("FeAnimStrayRadius_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeAnimStrayRadius_t::GetNode, &GFeAnimStrayRadius_t::SetNode)
        .addProperty("MaxDist", &GFeAnimStrayRadius_t::GetMaxDist, &GFeAnimStrayRadius_t::SetMaxDist)
        .addProperty("RelaxationFactor", &GFeAnimStrayRadius_t::GetRelaxationFactor, &GFeAnimStrayRadius_t::SetRelaxationFactor)
        .addFunction("ToPtr", &GFeAnimStrayRadius_t::ToPtr)
        .addFunction("IsValid", &GFeAnimStrayRadius_t::IsValid)
        .endClass();
}