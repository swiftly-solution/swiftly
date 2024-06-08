class GC_INIT_LifespanFromVelocity;

#ifndef _gcc_init_lifespanfromvelocity_h
#define _gcc_init_lifespanfromvelocity_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"


class GC_INIT_LifespanFromVelocity
{
private:
    void *m_ptr;

public:
    GC_INIT_LifespanFromVelocity() {}
    GC_INIT_LifespanFromVelocity(void *ptr) : m_ptr(ptr) {}

    Vector GetComponentScale() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_LifespanFromVelocity", "m_vecComponentScale"); }
    void SetComponentScale(Vector value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_vecComponentScale", false, value); }
    float GetTraceOffset() const { return GetSchemaValue<float>(m_ptr, "C_INIT_LifespanFromVelocity", "m_flTraceOffset"); }
    void SetTraceOffset(float value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_flTraceOffset", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_INIT_LifespanFromVelocity", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_flMaxTraceLength", false, value); }
    float GetTraceTolerance() const { return GetSchemaValue<float>(m_ptr, "C_INIT_LifespanFromVelocity", "m_flTraceTolerance"); }
    void SetTraceTolerance(float value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_flTraceTolerance", false, value); }
    int32_t GetMaxPlanes() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_LifespanFromVelocity", "m_nMaxPlanes"); }
    void SetMaxPlanes(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_nMaxPlanes", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_LifespanFromVelocity", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_INIT_LifespanFromVelocity", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_nTraceSet", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_LifespanFromVelocity", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_INIT_LifespanFromVelocity", "m_bIncludeWater", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif