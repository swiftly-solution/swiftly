class GC_OP_SetControlPointToImpactPoint;

#ifndef _gcc_op_setcontrolpointtoimpactpoint_h
#define _gcc_op_setcontrolpointtoimpactpoint_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetControlPointToImpactPoint
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToImpactPoint() {}
    GC_OP_SetControlPointToImpactPoint(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPOut() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nCPOut"); }
    void SetCPOut(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nCPOut", false, value); }
    int32_t GetCPIn() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nCPIn"); }
    void SetCPIn(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nCPIn", false, value); }
    float GetUpdateRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flUpdateRate"); }
    void SetUpdateRate(float value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flUpdateRate", false, value); }
    GCParticleCollectionFloatInput GetTraceLength() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flTraceLength"); }
    void SetTraceLength(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flTraceLength", false, value); }
    float GetStartOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flStartOffset"); }
    void SetStartOffset(float value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flStartOffset", false, value); }
    float GetOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flOffset"); }
    void SetOffset(float value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_flOffset", false, value); }
    Vector GetTraceDir() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_vecTraceDir"); }
    void SetTraceDir(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_vecTraceDir", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_nTraceSet", false, value); }
    bool GetSetToEndpoint() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bSetToEndpoint"); }
    void SetSetToEndpoint(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bSetToEndpoint", false, value); }
    bool GetTraceToClosestSurface() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bTraceToClosestSurface"); }
    void SetTraceToClosestSurface(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bTraceToClosestSurface", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToImpactPoint", "m_bIncludeWater", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif