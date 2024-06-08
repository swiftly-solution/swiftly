class GC_OP_SetCPOrientationToGroundNormal;

#ifndef _gcc_op_setcporientationtogroundnormal_h
#define _gcc_op_setcporientationtogroundnormal_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"


class GC_OP_SetCPOrientationToGroundNormal
{
private:
    void *m_ptr;

public:
    GC_OP_SetCPOrientationToGroundNormal() {}
    GC_OP_SetCPOrientationToGroundNormal(void *ptr) : m_ptr(ptr) {}

    float GetInterpRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flInterpRate"); }
    void SetInterpRate(float value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flInterpRate", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flMaxTraceLength", false, value); }
    float GetTolerance() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flTolerance"); }
    void SetTolerance(float value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flTolerance", false, value); }
    float GetTraceOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flTraceOffset"); }
    void SetTraceOffset(float value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_flTraceOffset", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nTraceSet", false, value); }
    int32_t GetInputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nInputCP"); }
    void SetInputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nInputCP", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_nOutputCP", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToGroundNormal", "m_bIncludeWater", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif