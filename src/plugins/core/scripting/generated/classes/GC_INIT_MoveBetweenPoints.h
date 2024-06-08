class GC_INIT_MoveBetweenPoints;

#ifndef _gcc_init_movebetweenpoints_h
#define _gcc_init_movebetweenpoints_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_INIT_MoveBetweenPoints
{
private:
    void *m_ptr;

public:
    GC_INIT_MoveBetweenPoints() {}
    GC_INIT_MoveBetweenPoints(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetSpeedMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_MoveBetweenPoints", "m_flSpeedMin"); }
    void SetSpeedMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_flSpeedMin", false, value); }
    GCPerParticleFloatInput GetSpeedMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_MoveBetweenPoints", "m_flSpeedMax"); }
    void SetSpeedMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_flSpeedMax", false, value); }
    GCPerParticleFloatInput GetEndSpread() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_MoveBetweenPoints", "m_flEndSpread"); }
    void SetEndSpread(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_flEndSpread", false, value); }
    GCPerParticleFloatInput GetStartOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_MoveBetweenPoints", "m_flStartOffset"); }
    void SetStartOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_flStartOffset", false, value); }
    GCPerParticleFloatInput GetEndOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_MoveBetweenPoints", "m_flEndOffset"); }
    void SetEndOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_flEndOffset", false, value); }
    int32_t GetEndControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_MoveBetweenPoints", "m_nEndControlPointNumber"); }
    void SetEndControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_nEndControlPointNumber", false, value); }
    bool GetTrailBias() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_MoveBetweenPoints", "m_bTrailBias"); }
    void SetTrailBias(bool value) { SetSchemaValue(m_ptr, "C_INIT_MoveBetweenPoints", "m_bTrailBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif