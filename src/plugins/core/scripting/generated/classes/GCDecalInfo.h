class GCDecalInfo;

#ifndef _gccdecalinfo_h
#define _gccdecalinfo_h

#include "../../../scripting.h"


#include "GCDecalInfo.h"

class GCDecalInfo
{
private:
    void *m_ptr;

public:
    GCDecalInfo() {}
    GCDecalInfo(void *ptr) : m_ptr(ptr) {}

    float GetAnimationScale() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flAnimationScale"); }
    void SetAnimationScale(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flAnimationScale", false, value); }
    float GetAnimationLifeSpan() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flAnimationLifeSpan"); }
    void SetAnimationLifeSpan(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flAnimationLifeSpan", false, value); }
    float GetPlaceTime() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flPlaceTime"); }
    void SetPlaceTime(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flPlaceTime", false, value); }
    float GetFadeStartTime() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flFadeStartTime"); }
    void SetFadeStartTime(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flFadeStartTime", false, value); }
    float GetFadeDuration() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flFadeDuration"); }
    void SetFadeDuration(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flFadeDuration", false, value); }
    int32_t GetVBSlot() const { return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nVBSlot"); }
    void SetVBSlot(int32_t value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_nVBSlot", false, value); }
    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nBoneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_nBoneIndex", false, value); }
    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "CDecalInfo", "m_vPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_vPosition", false, value); }
    float GetBoundingRadiusSqr() const { return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flBoundingRadiusSqr"); }
    void SetBoundingRadiusSqr(float value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_flBoundingRadiusSqr", false, value); }
    GCDecalInfo* GetNext() const { return GetSchemaValue<GCDecalInfo*>(m_ptr, "CDecalInfo", "m_pNext"); }
    void SetNext(GCDecalInfo* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }
    GCDecalInfo* GetPrev() const { return GetSchemaValue<GCDecalInfo*>(m_ptr, "CDecalInfo", "m_pPrev"); }
    void SetPrev(GCDecalInfo* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n"); }
    int32_t GetDecalMaterialIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nDecalMaterialIndex"); }
    void SetDecalMaterialIndex(int32_t value) { SetSchemaValue(m_ptr, "CDecalInfo", "m_nDecalMaterialIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif