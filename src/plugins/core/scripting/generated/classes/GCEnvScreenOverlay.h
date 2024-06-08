class GCEnvScreenOverlay;

#ifndef _gccenvscreenoverlay_h
#define _gccenvscreenoverlay_h

#include "../../../scripting.h"




class GCEnvScreenOverlay
{
private:
    void *m_ptr;

public:
    GCEnvScreenOverlay() {}
    GCEnvScreenOverlay(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlSymbolLarge> GetOverlayNames() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOverlayNames(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames", false, outValue); }
    std::vector<float> GetOverlayTimes() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes"); std::vector<float> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOverlayTimes(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes", false, outValue); }
    int32_t GetDesiredOverlay() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvScreenOverlay", "m_iDesiredOverlay"); }
    void SetDesiredOverlay(int32_t value) { SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_iDesiredOverlay", false, value); }
    bool GetIsActive() const { return GetSchemaValue<bool>(m_ptr, "CEnvScreenOverlay", "m_bIsActive"); }
    void SetIsActive(bool value) { SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_bIsActive", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif