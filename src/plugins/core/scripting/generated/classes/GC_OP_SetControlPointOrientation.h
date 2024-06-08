class GC_OP_SetControlPointOrientation;

#ifndef _gcc_op_setcontrolpointorientation_h
#define _gcc_op_setcontrolpointorientation_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetControlPointOrientation
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointOrientation() {}
    GC_OP_SetControlPointOrientation(void *ptr) : m_ptr(ptr) {}

    bool GetUseWorldLocation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointOrientation", "m_bUseWorldLocation"); }
    void SetUseWorldLocation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_bUseWorldLocation", false, value); }
    bool GetRandomize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointOrientation", "m_bRandomize"); }
    void SetRandomize(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_bRandomize", false, value); }
    bool GetSetOnce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointOrientation", "m_bSetOnce"); }
    void SetSetOnce(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_bSetOnce", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointOrientation", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_nCP", false, value); }
    int32_t GetHeadLocation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointOrientation", "m_nHeadLocation"); }
    void SetHeadLocation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_nHeadLocation", false, value); }
    QAngle GetRotation() const { return GetSchemaValue<QAngle>(m_ptr, "C_OP_SetControlPointOrientation", "m_vecRotation"); }
    void SetRotation(QAngle value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_vecRotation", false, value); }
    QAngle GetRotationB() const { return GetSchemaValue<QAngle>(m_ptr, "C_OP_SetControlPointOrientation", "m_vecRotationB"); }
    void SetRotationB(QAngle value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_vecRotationB", false, value); }
    GCParticleCollectionFloatInput GetInterpolation() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointOrientation", "m_flInterpolation"); }
    void SetInterpolation(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointOrientation", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif