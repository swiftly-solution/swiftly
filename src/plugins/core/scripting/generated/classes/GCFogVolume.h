class GCFogVolume;

#ifndef _gccfogvolume_h
#define _gccfogvolume_h

#include "../../../scripting.h"




class GCFogVolume
{
private:
    void *m_ptr;

public:
    GCFogVolume() {}
    GCFogVolume(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFogName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_fogName"); }
    void SetFogName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFogVolume", "m_fogName", false, value); }
    CUtlSymbolLarge GetPostProcessName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_postProcessName"); }
    void SetPostProcessName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFogVolume", "m_postProcessName", false, value); }
    CUtlSymbolLarge GetColorCorrectionName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_colorCorrectionName"); }
    void SetColorCorrectionName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFogVolume", "m_colorCorrectionName", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFogVolume", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFogVolume", "m_bDisabled", false, value); }
    bool GetInFogVolumesList() const { return GetSchemaValue<bool>(m_ptr, "CFogVolume", "m_bInFogVolumesList"); }
    void SetInFogVolumesList(bool value) { SetSchemaValue(m_ptr, "CFogVolume", "m_bInFogVolumesList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif