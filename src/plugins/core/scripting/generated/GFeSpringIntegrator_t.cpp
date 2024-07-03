#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSpringIntegrator_t::GFeSpringIntegrator_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSpringIntegrator_t::GFeSpringIntegrator_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeSpringIntegrator_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSpringIntegrator_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSpringIntegrator_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSpringIntegrator_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "nNode", true, outValue);
}
float GFeSpringIntegrator_t::GetSpringRestLength() const {
    return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringRestLength");
}
void GFeSpringIntegrator_t::SetSpringRestLength(float value) {
    SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringRestLength", true, value);
}
float GFeSpringIntegrator_t::GetSpringConstant() const {
    return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringConstant");
}
void GFeSpringIntegrator_t::SetSpringConstant(float value) {
    SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringConstant", true, value);
}
float GFeSpringIntegrator_t::GetSpringDamping() const {
    return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringDamping");
}
void GFeSpringIntegrator_t::SetSpringDamping(float value) {
    SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringDamping", true, value);
}
float GFeSpringIntegrator_t::GetNodeWeight0() const {
    return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flNodeWeight0");
}
void GFeSpringIntegrator_t::SetNodeWeight0(float value) {
    SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flNodeWeight0", true, value);
}
std::string GFeSpringIntegrator_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSpringIntegrator_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSpringIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSpringIntegrator_t>("FeSpringIntegrator_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeSpringIntegrator_t::GetNode, &GFeSpringIntegrator_t::SetNode)
        .addProperty("SpringRestLength", &GFeSpringIntegrator_t::GetSpringRestLength, &GFeSpringIntegrator_t::SetSpringRestLength)
        .addProperty("SpringConstant", &GFeSpringIntegrator_t::GetSpringConstant, &GFeSpringIntegrator_t::SetSpringConstant)
        .addProperty("SpringDamping", &GFeSpringIntegrator_t::GetSpringDamping, &GFeSpringIntegrator_t::SetSpringDamping)
        .addProperty("NodeWeight0", &GFeSpringIntegrator_t::GetNodeWeight0, &GFeSpringIntegrator_t::SetNodeWeight0)
        .addFunction("ToPtr", &GFeSpringIntegrator_t::ToPtr)
        .addFunction("IsValid", &GFeSpringIntegrator_t::IsValid)
        .endClass();
}