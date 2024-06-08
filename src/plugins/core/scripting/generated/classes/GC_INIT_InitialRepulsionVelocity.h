class GC_INIT_InitialRepulsionVelocity;

#ifndef _gcc_init_initialrepulsionvelocity_h
#define _gcc_init_initialrepulsionvelocity_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"


class GC_INIT_InitialRepulsionVelocity
{
private:
    void *m_ptr;

public:
    GC_INIT_InitialRepulsionVelocity() {}
    GC_INIT_InitialRepulsionVelocity(void *ptr) : m_ptr(ptr) {}

    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nTraceSet", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_vecOutputMax", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nControlPointNumber", false, value); }
    bool GetPerParticle() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bPerParticle"); }
    void SetPerParticle(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bPerParticle", false, value); }
    bool GetTranslate() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bTranslate"); }
    void SetTranslate(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bTranslate", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bProportional", false, value); }
    float GetTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_flTraceLength"); }
    void SetTraceLength(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_flTraceLength", false, value); }
    bool GetPerParticleTR() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bPerParticleTR"); }
    void SetPerParticleTR(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bPerParticleTR", false, value); }
    bool GetInherit() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bInherit"); }
    void SetInherit(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_bInherit", false, value); }
    int32_t GetChildCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nChildCP"); }
    void SetChildCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nChildCP", false, value); }
    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialRepulsionVelocity", "m_nChildGroupID", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif