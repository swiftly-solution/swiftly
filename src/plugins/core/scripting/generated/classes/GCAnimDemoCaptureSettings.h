class GCAnimDemoCaptureSettings;

#ifndef _gccanimdemocapturesettings_h
#define _gccanimdemocapturesettings_h

#include "../../../scripting.h"

#include "../types/GEDemoBoneSelectionMode.h"
#include "GBoneDemoCaptureSettings_t.h"
#include "GIKDemoCaptureSettings_t.h"

class GCAnimDemoCaptureSettings
{
private:
    void *m_ptr;

public:
    GCAnimDemoCaptureSettings() {}
    GCAnimDemoCaptureSettings(void *ptr) : m_ptr(ptr) {}

    Vector2D GetErrorRangeSplineRotation() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineRotation"); }
    void SetErrorRangeSplineRotation(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineRotation", false, value); }
    Vector2D GetErrorRangeSplineTranslation() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineTranslation"); }
    void SetErrorRangeSplineTranslation(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineTranslation", false, value); }
    Vector2D GetErrorRangeSplineScale() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineScale"); }
    void SetErrorRangeSplineScale(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeSplineScale", false, value); }
    float GetIkRotation_MaxSplineError() const { return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxSplineError"); }
    void SetIkRotation_MaxSplineError(float value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxSplineError", false, value); }
    float GetIkTranslation_MaxSplineError() const { return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxSplineError"); }
    void SetIkTranslation_MaxSplineError(float value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxSplineError", false, value); }
    Vector2D GetErrorRangeQuantizationRotation() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationRotation"); }
    void SetErrorRangeQuantizationRotation(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationRotation", false, value); }
    Vector2D GetErrorRangeQuantizationTranslation() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationTranslation"); }
    void SetErrorRangeQuantizationTranslation(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationTranslation", false, value); }
    Vector2D GetErrorRangeQuantizationScale() const { return GetSchemaValue<Vector2D>(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationScale"); }
    void SetErrorRangeQuantizationScale(Vector2D value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_vecErrorRangeQuantizationScale", false, value); }
    float GetIkRotation_MaxQuantizationError() const { return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxQuantizationError"); }
    void SetIkRotation_MaxQuantizationError(float value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkRotation_MaxQuantizationError", false, value); }
    float GetIkTranslation_MaxQuantizationError() const { return GetSchemaValue<float>(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxQuantizationError"); }
    void SetIkTranslation_MaxQuantizationError(float value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_flIkTranslation_MaxQuantizationError", false, value); }
    CUtlString GetBaseSequence() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimDemoCaptureSettings", "m_baseSequence"); }
    void SetBaseSequence(CUtlString value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_baseSequence", false, value); }
    int32_t GetBaseSequenceFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimDemoCaptureSettings", "m_nBaseSequenceFrame"); }
    void SetBaseSequenceFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_nBaseSequenceFrame", false, value); }
    EDemoBoneSelectionMode GetBoneSelectionMode() const { return GetSchemaValue<EDemoBoneSelectionMode>(m_ptr, "CAnimDemoCaptureSettings", "m_boneSelectionMode"); }
    void SetBoneSelectionMode(EDemoBoneSelectionMode value) { SetSchemaValue(m_ptr, "CAnimDemoCaptureSettings", "m_boneSelectionMode", false, value); }
    std::vector<GBoneDemoCaptureSettings_t> GetBones() const { CUtlVector<GBoneDemoCaptureSettings_t>* vec = GetSchemaValue<CUtlVector<GBoneDemoCaptureSettings_t>*>(m_ptr, "CAnimDemoCaptureSettings", "m_bones"); std::vector<GBoneDemoCaptureSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBones(std::vector<GBoneDemoCaptureSettings_t> value) { SetSchemaValueCUtlVector<GBoneDemoCaptureSettings_t>(m_ptr, "CAnimDemoCaptureSettings", "m_bones", false, value); }
    std::vector<GIKDemoCaptureSettings_t> GetIkChains() const { CUtlVector<GIKDemoCaptureSettings_t>* vec = GetSchemaValue<CUtlVector<GIKDemoCaptureSettings_t>*>(m_ptr, "CAnimDemoCaptureSettings", "m_ikChains"); std::vector<GIKDemoCaptureSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIkChains(std::vector<GIKDemoCaptureSettings_t> value) { SetSchemaValueCUtlVector<GIKDemoCaptureSettings_t>(m_ptr, "CAnimDemoCaptureSettings", "m_ikChains", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif