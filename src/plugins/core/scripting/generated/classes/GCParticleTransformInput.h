class GCParticleTransformInput;

#ifndef _gccparticletransforminput_h
#define _gccparticletransforminput_h

#include "../../../scripting.h"

#include "../types/GParticleTransformType_t.h"


class GCParticleTransformInput
{
private:
    void *m_ptr;

public:
    GCParticleTransformInput() {}
    GCParticleTransformInput(void *ptr) : m_ptr(ptr) {}

    ParticleTransformType_t GetType() const { return GetSchemaValue<ParticleTransformType_t>(m_ptr, "CParticleTransformInput", "m_nType"); }
    void SetType(ParticleTransformType_t value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nType", false, value); }
    bool GetFollowNamedValue() const { return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bFollowNamedValue"); }
    void SetFollowNamedValue(bool value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bFollowNamedValue", false, value); }
    bool GetSupportsDisabled() const { return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bSupportsDisabled"); }
    void SetSupportsDisabled(bool value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bSupportsDisabled", false, value); }
    bool GetUseOrientation() const { return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bUseOrientation"); }
    void SetUseOrientation(bool value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bUseOrientation", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleTransformInput", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nControlPoint", false, value); }
    int32_t GetControlPointRangeMax() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleTransformInput", "m_nControlPointRangeMax"); }
    void SetControlPointRangeMax(int32_t value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nControlPointRangeMax", false, value); }
    float GetEndCPGrowthTime() const { return GetSchemaValue<float>(m_ptr, "CParticleTransformInput", "m_flEndCPGrowthTime"); }
    void SetEndCPGrowthTime(float value) { SetSchemaValue(m_ptr, "CParticleTransformInput", "m_flEndCPGrowthTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif