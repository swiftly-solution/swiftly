class GC_INIT_PositionWarpScalar;

#ifndef _gcc_init_positionwarpscalar_h
#define _gcc_init_positionwarpscalar_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_INIT_PositionWarpScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_PositionWarpScalar() {}
    GC_INIT_PositionWarpScalar(void *ptr) : m_ptr(ptr) {}

    Vector GetWarpMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_PositionWarpScalar", "m_vecWarpMin"); }
    void SetWarpMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_vecWarpMin", false, value); }
    Vector GetWarpMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_PositionWarpScalar", "m_vecWarpMax"); }
    void SetWarpMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_vecWarpMax", false, value); }
    GCPerParticleFloatInput GetInputValue() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_PositionWarpScalar", "m_InputValue"); }
    void SetInputValue(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_InputValue", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_PositionWarpScalar", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_flPrevPosScale", false, value); }
    int32_t GetScaleControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionWarpScalar", "m_nScaleControlPointNumber"); }
    void SetScaleControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_nScaleControlPointNumber", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionWarpScalar", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarpScalar", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif