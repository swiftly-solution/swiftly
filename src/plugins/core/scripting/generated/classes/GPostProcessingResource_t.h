class GPostProcessingResource_t;

#ifndef _gcpostprocessingresource_t_h
#define _gcpostprocessingresource_t_h

#include "../../../scripting.h"


#include "GPostProcessingTonemapParameters_t.h"
#include "GPostProcessingBloomParameters_t.h"
#include "GPostProcessingVignetteParameters_t.h"
#include "GPostProcessingLocalContrastParameters_t.h"

class GPostProcessingResource_t
{
private:
    void *m_ptr;

public:
    GPostProcessingResource_t() {}
    GPostProcessingResource_t(void *ptr) : m_ptr(ptr) {}

    bool GetHasTonemapParams() const { return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasTonemapParams"); }
    void SetHasTonemapParams(bool value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasTonemapParams", true, value); }
    GPostProcessingTonemapParameters_t GetToneMapParams() const { return GetSchemaValue<GPostProcessingTonemapParameters_t>(m_ptr, "PostProcessingResource_t", "m_toneMapParams"); }
    void SetToneMapParams(GPostProcessingTonemapParameters_t value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_toneMapParams", true, value); }
    bool GetHasBloomParams() const { return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasBloomParams"); }
    void SetHasBloomParams(bool value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasBloomParams", true, value); }
    GPostProcessingBloomParameters_t GetBloomParams() const { return GetSchemaValue<GPostProcessingBloomParameters_t>(m_ptr, "PostProcessingResource_t", "m_bloomParams"); }
    void SetBloomParams(GPostProcessingBloomParameters_t value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bloomParams", true, value); }
    bool GetHasVignetteParams() const { return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasVignetteParams"); }
    void SetHasVignetteParams(bool value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasVignetteParams", true, value); }
    GPostProcessingVignetteParameters_t GetVignetteParams() const { return GetSchemaValue<GPostProcessingVignetteParameters_t>(m_ptr, "PostProcessingResource_t", "m_vignetteParams"); }
    void SetVignetteParams(GPostProcessingVignetteParameters_t value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_vignetteParams", true, value); }
    bool GetHasLocalContrastParams() const { return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasLocalContrastParams"); }
    void SetHasLocalContrastParams(bool value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasLocalContrastParams", true, value); }
    GPostProcessingLocalContrastParameters_t GetLocalConstrastParams() const { return GetSchemaValue<GPostProcessingLocalContrastParameters_t>(m_ptr, "PostProcessingResource_t", "m_localConstrastParams"); }
    void SetLocalConstrastParams(GPostProcessingLocalContrastParameters_t value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_localConstrastParams", true, value); }
    int32_t GetColorCorrectionVolumeDim() const { return GetSchemaValue<int32_t>(m_ptr, "PostProcessingResource_t", "m_nColorCorrectionVolumeDim"); }
    void SetColorCorrectionVolumeDim(int32_t value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_nColorCorrectionVolumeDim", true, value); }
    bool GetHasColorCorrection() const { return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasColorCorrection"); }
    void SetHasColorCorrection(bool value) { SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasColorCorrection", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif