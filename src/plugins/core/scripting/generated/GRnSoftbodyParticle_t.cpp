#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnSoftbodyParticle_t::GRnSoftbodyParticle_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnSoftbodyParticle_t::GRnSoftbodyParticle_t(void *ptr) {
    m_ptr = ptr;
}
float GRnSoftbodyParticle_t::GetMassInv() const {
    return GetSchemaValue<float>(m_ptr, "RnSoftbodyParticle_t", "m_flMassInv");
}
void GRnSoftbodyParticle_t::SetMassInv(float value) {
    SetSchemaValue(m_ptr, "RnSoftbodyParticle_t", "m_flMassInv", true, value);
}
std::string GRnSoftbodyParticle_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnSoftbodyParticle_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnSoftbodyParticle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodyParticle_t>("RnSoftbodyParticle_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MassInv", &GRnSoftbodyParticle_t::GetMassInv, &GRnSoftbodyParticle_t::SetMassInv)
        .addFunction("ToPtr", &GRnSoftbodyParticle_t::ToPtr)
        .addFunction("IsValid", &GRnSoftbodyParticle_t::IsValid)
        .endClass();
}