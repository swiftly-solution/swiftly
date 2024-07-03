#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnSoftbodyCapsule_t::GRnSoftbodyCapsule_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnSoftbodyCapsule_t::GRnSoftbodyCapsule_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> GRnSoftbodyCapsule_t::GetCenter() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnSoftbodyCapsule_t::SetCenter(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter", true, outValue);
}
float GRnSoftbodyCapsule_t::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "RnSoftbodyCapsule_t", "m_flRadius");
}
void GRnSoftbodyCapsule_t::SetRadius(float value) {
    SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_flRadius", true, value);
}
std::vector<uint16_t> GRnSoftbodyCapsule_t::GetParticle() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnSoftbodyCapsule_t::SetParticle(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle", true, outValue);
}
std::string GRnSoftbodyCapsule_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnSoftbodyCapsule_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnSoftbodyCapsule_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodyCapsule_t>("RnSoftbodyCapsule_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Center", &GRnSoftbodyCapsule_t::GetCenter, &GRnSoftbodyCapsule_t::SetCenter)
        .addProperty("Radius", &GRnSoftbodyCapsule_t::GetRadius, &GRnSoftbodyCapsule_t::SetRadius)
        .addProperty("Particle", &GRnSoftbodyCapsule_t::GetParticle, &GRnSoftbodyCapsule_t::SetParticle)
        .addFunction("ToPtr", &GRnSoftbodyCapsule_t::ToPtr)
        .addFunction("IsValid", &GRnSoftbodyCapsule_t::IsValid)
        .endClass();
}