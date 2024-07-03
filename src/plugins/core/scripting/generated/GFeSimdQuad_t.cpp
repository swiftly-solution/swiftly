#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdQuad_t::GFeSimdQuad_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdQuad_t::GFeSimdQuad_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdQuad_t::Get4Slack() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdQuad_t", "f4Slack");
}
void GFeSimdQuad_t::Set4Slack(float value) {
    SetSchemaValue(m_ptr, "FeSimdQuad_t", "f4Slack", true, value);
}
std::vector<float> GFeSimdQuad_t::Get4Weights() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeSimdQuad_t", "f4Weights"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdQuad_t::Set4Weights(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeSimdQuad_t", "f4Weights"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdQuad_t", "f4Weights", true, outValue);
}
std::string GFeSimdQuad_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdQuad_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdQuad_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdQuad_t>("FeSimdQuad_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("4Slack", &GFeSimdQuad_t::Get4Slack, &GFeSimdQuad_t::Set4Slack)
        .addProperty("4Weights", &GFeSimdQuad_t::Get4Weights, &GFeSimdQuad_t::Set4Weights)
        .addFunction("ToPtr", &GFeSimdQuad_t::ToPtr)
        .addFunction("IsValid", &GFeSimdQuad_t::IsValid)
        .endClass();
}