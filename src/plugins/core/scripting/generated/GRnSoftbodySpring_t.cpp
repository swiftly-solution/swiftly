#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnSoftbodySpring_t::GRnSoftbodySpring_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnSoftbodySpring_t::GRnSoftbodySpring_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GRnSoftbodySpring_t::GetParticle() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodySpring_t", "m_nParticle"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnSoftbodySpring_t::SetParticle(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodySpring_t", "m_nParticle"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodySpring_t", "m_nParticle", true, outValue);
}
float GRnSoftbodySpring_t::GetLength() const {
    return GetSchemaValue<float>(m_ptr, "RnSoftbodySpring_t", "m_flLength");
}
void GRnSoftbodySpring_t::SetLength(float value) {
    SetSchemaValue(m_ptr, "RnSoftbodySpring_t", "m_flLength", true, value);
}
std::string GRnSoftbodySpring_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnSoftbodySpring_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnSoftbodySpring_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodySpring_t>("RnSoftbodySpring_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Particle", &GRnSoftbodySpring_t::GetParticle, &GRnSoftbodySpring_t::SetParticle)
        .addProperty("Length", &GRnSoftbodySpring_t::GetLength, &GRnSoftbodySpring_t::SetLength)
        .addFunction("ToPtr", &GRnSoftbodySpring_t::ToPtr)
        .addFunction("IsValid", &GRnSoftbodySpring_t::IsValid)
        .endClass();
}