class GPhysSoftbodyDesc_t;

#ifndef _gcphyssoftbodydesc_t_h
#define _gcphyssoftbodydesc_t_h

#include "../../../scripting.h"


#include "GRnSoftbodyParticle_t.h"
#include "GRnSoftbodySpring_t.h"
#include "GRnSoftbodyCapsule_t.h"

class GPhysSoftbodyDesc_t
{
private:
    void *m_ptr;

public:
    GPhysSoftbodyDesc_t() {}
    GPhysSoftbodyDesc_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint32> GetParticleBoneHash() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParticleBoneHash(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneHash", true, value); }
    std::vector<GRnSoftbodyParticle_t> GetParticles() const { CUtlVector<GRnSoftbodyParticle_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodyParticle_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Particles"); std::vector<GRnSoftbodyParticle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParticles(std::vector<GRnSoftbodyParticle_t> value) { SetSchemaValueCUtlVector<GRnSoftbodyParticle_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Particles", true, value); }
    std::vector<GRnSoftbodySpring_t> GetSprings() const { CUtlVector<GRnSoftbodySpring_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodySpring_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Springs"); std::vector<GRnSoftbodySpring_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSprings(std::vector<GRnSoftbodySpring_t> value) { SetSchemaValueCUtlVector<GRnSoftbodySpring_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Springs", true, value); }
    std::vector<GRnSoftbodyCapsule_t> GetCapsules() const { CUtlVector<GRnSoftbodyCapsule_t>* vec = GetSchemaValue<CUtlVector<GRnSoftbodyCapsule_t>*>(m_ptr, "PhysSoftbodyDesc_t", "m_Capsules"); std::vector<GRnSoftbodyCapsule_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCapsules(std::vector<GRnSoftbodyCapsule_t> value) { SetSchemaValueCUtlVector<GRnSoftbodyCapsule_t>(m_ptr, "PhysSoftbodyDesc_t", "m_Capsules", true, value); }
    std::vector<CUtlString> GetParticleBoneName() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParticleBoneName(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PhysSoftbodyDesc_t", "m_ParticleBoneName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif