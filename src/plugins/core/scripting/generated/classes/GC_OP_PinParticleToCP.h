class GC_OP_PinParticleToCP;

#ifndef _gcc_op_pinparticletocp_h
#define _gcc_op_pinparticletocp_h

#include "../../../scripting.h"

#include "../types/GParticleSelection_t.h"
#include "../types/GParticlePinDistance_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_PinParticleToCP
{
private:
    void *m_ptr;

public:
    GC_OP_PinParticleToCP() {}
    GC_OP_PinParticleToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PinParticleToCP", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nControlPointNumber", false, value); }
    bool GetOffsetLocal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PinParticleToCP", "m_bOffsetLocal"); }
    void SetOffsetLocal(bool value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_bOffsetLocal", false, value); }
    ParticleSelection_t GetParticleSelection() const { return GetSchemaValue<ParticleSelection_t>(m_ptr, "C_OP_PinParticleToCP", "m_nParticleSelection"); }
    void SetParticleSelection(ParticleSelection_t value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nParticleSelection", false, value); }
    GCParticleCollectionFloatInput GetParticleNumber() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_nParticleNumber"); }
    void SetParticleNumber(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nParticleNumber", false, value); }
    ParticlePinDistance_t GetPinBreakType() const { return GetSchemaValue<ParticlePinDistance_t>(m_ptr, "C_OP_PinParticleToCP", "m_nPinBreakType"); }
    void SetPinBreakType(ParticlePinDistance_t value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nPinBreakType", false, value); }
    GCParticleCollectionFloatInput GetBreakDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_flBreakDistance"); }
    void SetBreakDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_flBreakDistance", false, value); }
    GCParticleCollectionFloatInput GetBreakSpeed() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_flBreakSpeed"); }
    void SetBreakSpeed(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_flBreakSpeed", false, value); }
    GCParticleCollectionFloatInput GetAge() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_flAge"); }
    void SetAge(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_flAge", false, value); }
    int32_t GetBreakControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PinParticleToCP", "m_nBreakControlPointNumber"); }
    void SetBreakControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nBreakControlPointNumber", false, value); }
    int32_t GetBreakControlPointNumber2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PinParticleToCP", "m_nBreakControlPointNumber2"); }
    void SetBreakControlPointNumber2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_nBreakControlPointNumber2", false, value); }
    GCParticleCollectionFloatInput GetBreakValue() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_flBreakValue"); }
    void SetBreakValue(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_flBreakValue", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_PinParticleToCP", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PinParticleToCP", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif