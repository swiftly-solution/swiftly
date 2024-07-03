#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeKelagerBend2_t::GFeKelagerBend2_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeKelagerBend2_t::GFeKelagerBend2_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GFeKelagerBend2_t::GetWeight() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeKelagerBend2_t", "flWeight"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeKelagerBend2_t::SetWeight(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeKelagerBend2_t", "flWeight"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeKelagerBend2_t", "flWeight", true, outValue);
}
float GFeKelagerBend2_t::GetHeight0() const {
    return GetSchemaValue<float>(m_ptr, "FeKelagerBend2_t", "flHeight0");
}
void GFeKelagerBend2_t::SetHeight0(float value) {
    SetSchemaValue(m_ptr, "FeKelagerBend2_t", "flHeight0", true, value);
}
std::vector<uint16_t> GFeKelagerBend2_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeKelagerBend2_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeKelagerBend2_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeKelagerBend2_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeKelagerBend2_t", "nNode", true, outValue);
}
uint16_t GFeKelagerBend2_t::GetReserved() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeKelagerBend2_t", "nReserved");
}
void GFeKelagerBend2_t::SetReserved(uint16_t value) {
    SetSchemaValue(m_ptr, "FeKelagerBend2_t", "nReserved", true, value);
}
std::string GFeKelagerBend2_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeKelagerBend2_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeKelagerBend2_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeKelagerBend2_t>("FeKelagerBend2_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Weight", &GFeKelagerBend2_t::GetWeight, &GFeKelagerBend2_t::SetWeight)
        .addProperty("Height0", &GFeKelagerBend2_t::GetHeight0, &GFeKelagerBend2_t::SetHeight0)
        .addProperty("Node", &GFeKelagerBend2_t::GetNode, &GFeKelagerBend2_t::SetNode)
        .addProperty("Reserved", &GFeKelagerBend2_t::GetReserved, &GFeKelagerBend2_t::SetReserved)
        .addFunction("ToPtr", &GFeKelagerBend2_t::ToPtr)
        .addFunction("IsValid", &GFeKelagerBend2_t::IsValid)
        .endClass();
}