class GCEnvInstructorVRHint;

#ifndef _gccenvinstructorvrhint_h
#define _gccenvinstructorvrhint_h

#include "../../../scripting.h"




class GCEnvInstructorVRHint
{
private:
    void *m_ptr;

public:
    GCEnvInstructorVRHint() {}
    GCEnvInstructorVRHint(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszName"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszName", false, value); }
    CUtlSymbolLarge GetHintTargetEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszHintTargetEntity"); }
    void SetHintTargetEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszHintTargetEntity", false, value); }
    int32_t GetTimeout() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iTimeout"); }
    void SetTimeout(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iTimeout", false, value); }
    CUtlSymbolLarge GetCaption() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszCaption"); }
    void SetCaption(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszCaption", false, value); }
    CUtlSymbolLarge GetStartSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszStartSound"); }
    void SetStartSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszStartSound", false, value); }
    int32_t GetLayoutFileType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iLayoutFileType"); }
    void SetLayoutFileType(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iLayoutFileType", false, value); }
    CUtlSymbolLarge GetCustomLayoutFile() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszCustomLayoutFile"); }
    void SetCustomLayoutFile(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszCustomLayoutFile", false, value); }
    int32_t GetAttachType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iAttachType"); }
    void SetAttachType(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iAttachType", false, value); }
    float GetHeightOffset() const { return GetSchemaValue<float>(m_ptr, "CEnvInstructorVRHint", "m_flHeightOffset"); }
    void SetHeightOffset(float value) { SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_flHeightOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif