#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPhysSoftbodyDesc_t::GPhysSoftbodyDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPhysSoftbodyDesc_t::GPhysSoftbodyDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint32> GPhysSoftbodyDesc_t::GetParticleBoneHash() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysSoftbodyDesc_t::SetParticleBoneHash(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneHash", true, value);
}
std::vector<GRnSoftbodyParticle_t> GPhysSoftbodyDesc_t::GetParticles() const {
    CUtlVector<GRnSoftbodyParticle_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodyParticle_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Particles"); std::vector<GRnSoftbodyParticle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysSoftbodyDesc_t::SetParticles(std::vector<GRnSoftbodyParticle_t> value) {
    SetSchemaValueCUtlVector<GRnSoftbodyParticle_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Particles", true, value);
}
std::vector<GRnSoftbodySpring_t> GPhysSoftbodyDesc_t::GetSprings() const {
    CUtlVector<GRnSoftbodySpring_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodySpring_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Springs"); std::vector<GRnSoftbodySpring_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysSoftbodyDesc_t::SetSprings(std::vector<GRnSoftbodySpring_t> value) {
    SetSchemaValueCUtlVector<GRnSoftbodySpring_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Springs", true, value);
}
std::vector<GRnSoftbodyCapsule_t> GPhysSoftbodyDesc_t::GetCapsules() const {
    CUtlVector<GRnSoftbodyCapsule_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodyCapsule_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Capsules"); std::vector<GRnSoftbodyCapsule_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysSoftbodyDesc_t::SetCapsules(std::vector<GRnSoftbodyCapsule_t> value) {
    SetSchemaValueCUtlVector<GRnSoftbodyCapsule_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Capsules", true, value);
}
std::vector<CUtlString> GPhysSoftbodyDesc_t::GetParticleBoneName() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysSoftbodyDesc_t::SetParticleBoneName(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneName", true, value);
}
std::string GPhysSoftbodyDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPhysSoftbodyDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPhysSoftbodyDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPhysSoftbodyDesc_t>("PhysSoftbodyDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParticleBoneHash", &GPhysSoftbodyDesc_t::GetParticleBoneHash, &GPhysSoftbodyDesc_t::SetParticleBoneHash)
        .addProperty("Particles", &GPhysSoftbodyDesc_t::GetParticles, &GPhysSoftbodyDesc_t::SetParticles)
        .addProperty("Springs", &GPhysSoftbodyDesc_t::GetSprings, &GPhysSoftbodyDesc_t::SetSprings)
        .addProperty("Capsules", &GPhysSoftbodyDesc_t::GetCapsules, &GPhysSoftbodyDesc_t::SetCapsules)
        .addProperty("ParticleBoneName", &GPhysSoftbodyDesc_t::GetParticleBoneName, &GPhysSoftbodyDesc_t::SetParticleBoneName)
        .addFunction("ToPtr", &GPhysSoftbodyDesc_t::ToPtr)
        .addFunction("IsValid", &GPhysSoftbodyDesc_t::IsValid)
        .endClass();
}