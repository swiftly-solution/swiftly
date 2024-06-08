class GCBaseTrailRenderer;

#ifndef _gccbasetrailrenderer_h
#define _gccbasetrailrenderer_h

#include "../../../scripting.h"

#include "../types/GParticleOrientationChoiceList_t.h"
#include "GCParticleCollectionRendererFloatInput.h"

class GCBaseTrailRenderer
{
private:
    void *m_ptr;

public:
    GCBaseTrailRenderer() {}
    GCBaseTrailRenderer(void *ptr) : m_ptr(ptr) {}

    ParticleOrientationChoiceList_t GetOrientationType() const { return GetSchemaValue<ParticleOrientationChoiceList_t>(m_ptr, "CBaseTrailRenderer", "m_nOrientationType"); }
    void SetOrientationType(ParticleOrientationChoiceList_t value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_nOrientationType", false, value); }
    int32_t GetOrientationControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseTrailRenderer", "m_nOrientationControlPoint"); }
    void SetOrientationControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_nOrientationControlPoint", false, value); }
    float GetMinSize() const { return GetSchemaValue<float>(m_ptr, "CBaseTrailRenderer", "m_flMinSize"); }
    void SetMinSize(float value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flMinSize", false, value); }
    float GetMaxSize() const { return GetSchemaValue<float>(m_ptr, "CBaseTrailRenderer", "m_flMaxSize"); }
    void SetMaxSize(float value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flMaxSize", false, value); }
    GCParticleCollectionRendererFloatInput GetStartFadeSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseTrailRenderer", "m_flStartFadeSize"); }
    void SetStartFadeSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flStartFadeSize", false, value); }
    GCParticleCollectionRendererFloatInput GetEndFadeSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseTrailRenderer", "m_flEndFadeSize"); }
    void SetEndFadeSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flEndFadeSize", false, value); }
    bool GetClampV() const { return GetSchemaValue<bool>(m_ptr, "CBaseTrailRenderer", "m_bClampV"); }
    void SetClampV(bool value) { SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_bClampV", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif