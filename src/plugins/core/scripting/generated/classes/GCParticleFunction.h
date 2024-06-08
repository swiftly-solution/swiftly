class GCParticleFunction;

#ifndef _gccparticlefunction_h
#define _gccparticlefunction_h

#include "../../../scripting.h"

#include "../types/GParticleEndcapMode_t.h"
#include "GCParticleCollectionFloatInput.h"

class GCParticleFunction
{
private:
    void *m_ptr;

public:
    GCParticleFunction() {}
    GCParticleFunction(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetOpStrength() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "CParticleFunction", "m_flOpStrength"); }
    void SetOpStrength(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStrength", false, value); }
    ParticleEndcapMode_t GetOpEndCapState() const { return GetSchemaValue<ParticleEndcapMode_t>(m_ptr, "CParticleFunction", "m_nOpEndCapState"); }
    void SetOpEndCapState(ParticleEndcapMode_t value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpEndCapState", false, value); }
    float GetOpStartFadeInTime() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpStartFadeInTime"); }
    void SetOpStartFadeInTime(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStartFadeInTime", false, value); }
    float GetOpEndFadeInTime() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpEndFadeInTime"); }
    void SetOpEndFadeInTime(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpEndFadeInTime", false, value); }
    float GetOpStartFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpStartFadeOutTime"); }
    void SetOpStartFadeOutTime(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStartFadeOutTime", false, value); }
    float GetOpEndFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpEndFadeOutTime"); }
    void SetOpEndFadeOutTime(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpEndFadeOutTime", false, value); }
    float GetOpFadeOscillatePeriod() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpFadeOscillatePeriod"); }
    void SetOpFadeOscillatePeriod(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpFadeOscillatePeriod", false, value); }
    bool GetNormalizeToStopTime() const { return GetSchemaValue<bool>(m_ptr, "CParticleFunction", "m_bNormalizeToStopTime"); }
    void SetNormalizeToStopTime(bool value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_bNormalizeToStopTime", false, value); }
    float GetOpTimeOffsetMin() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMin"); }
    void SetOpTimeOffsetMin(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMin", false, value); }
    float GetOpTimeOffsetMax() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMax"); }
    void SetOpTimeOffsetMax(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMax", false, value); }
    int32_t GetOpTimeOffsetSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFunction", "m_nOpTimeOffsetSeed"); }
    void SetOpTimeOffsetSeed(int32_t value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpTimeOffsetSeed", false, value); }
    int32_t GetOpTimeScaleSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFunction", "m_nOpTimeScaleSeed"); }
    void SetOpTimeScaleSeed(int32_t value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpTimeScaleSeed", false, value); }
    float GetOpTimeScaleMin() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeScaleMin"); }
    void SetOpTimeScaleMin(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeScaleMin", false, value); }
    float GetOpTimeScaleMax() const { return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeScaleMax"); }
    void SetOpTimeScaleMax(float value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeScaleMax", false, value); }
    bool GetDisableOperator() const { return GetSchemaValue<bool>(m_ptr, "CParticleFunction", "m_bDisableOperator"); }
    void SetDisableOperator(bool value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_bDisableOperator", false, value); }
    CUtlString GetNotes() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleFunction", "m_Notes"); }
    void SetNotes(CUtlString value) { SetSchemaValue(m_ptr, "CParticleFunction", "m_Notes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif