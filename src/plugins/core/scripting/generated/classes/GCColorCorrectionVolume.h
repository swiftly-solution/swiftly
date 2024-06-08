class GCColorCorrectionVolume;

#ifndef _gcccolorcorrectionvolume_h
#define _gcccolorcorrectionvolume_h

#include "../../../scripting.h"




class GCColorCorrectionVolume
{
private:
    void *m_ptr;

public:
    GCColorCorrectionVolume() {}
    GCColorCorrectionVolume(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrectionVolume", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_bEnabled", false, value); }
    float GetMaxWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_MaxWeight"); }
    void SetMaxWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_MaxWeight", false, value); }
    float GetFadeDuration() const { return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_FadeDuration"); }
    void SetFadeDuration(float value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_FadeDuration", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrectionVolume", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_bStartDisabled", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_Weight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_Weight", false, value); }
    std::string GetLookupFilename() const { return GetSchemaValue<char*>(m_ptr, "CColorCorrectionVolume", "m_lookupFilename"); }
    void SetLookupFilename(std::string value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_lookupFilename", false, value); }
    float GetLastEnterWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastEnterWeight"); }
    void SetLastEnterWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastEnterWeight", false, value); }
    float GetLastExitWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastExitWeight"); }
    void SetLastExitWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastExitWeight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif