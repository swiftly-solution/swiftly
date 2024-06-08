class GCColorCorrection;

#ifndef _gcccolorcorrection_h
#define _gcccolorcorrection_h

#include "../../../scripting.h"




class GCColorCorrection
{
private:
    void *m_ptr;

public:
    GCColorCorrection() {}
    GCColorCorrection(void *ptr) : m_ptr(ptr) {}

    float GetFadeInDuration() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flFadeInDuration"); }
    void SetFadeInDuration(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flFadeInDuration", false, value); }
    float GetFadeOutDuration() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flFadeOutDuration"); }
    void SetFadeOutDuration(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flFadeOutDuration", false, value); }
    float GetStartFadeInWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flStartFadeInWeight"); }
    void SetStartFadeInWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flStartFadeInWeight", false, value); }
    float GetStartFadeOutWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flStartFadeOutWeight"); }
    void SetStartFadeOutWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flStartFadeOutWeight", false, value); }
    float GetMaxWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flMaxWeight"); }
    void SetMaxWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flMaxWeight", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_bStartDisabled", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_bEnabled", false, value); }
    bool GetMaster() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bMaster"); }
    void SetMaster(bool value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_bMaster", false, value); }
    bool GetClientSide() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bClientSide"); }
    void SetClientSide(bool value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_bClientSide", false, value); }
    bool GetExclusive() const { return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bExclusive"); }
    void SetExclusive(bool value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_bExclusive", false, value); }
    float GetMinFalloff() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_MinFalloff"); }
    void SetMinFalloff(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_MinFalloff", false, value); }
    float GetMaxFalloff() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_MaxFalloff"); }
    void SetMaxFalloff(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_MaxFalloff", false, value); }
    float GetCurWeight() const { return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flCurWeight"); }
    void SetCurWeight(float value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_flCurWeight", false, value); }
    std::string GetNetlookupFilename() const { return GetSchemaValue<char*>(m_ptr, "CColorCorrection", "m_netlookupFilename"); }
    void SetNetlookupFilename(std::string value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_netlookupFilename", false, value); }
    CUtlSymbolLarge GetLookupFilename() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CColorCorrection", "m_lookupFilename"); }
    void SetLookupFilename(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CColorCorrection", "m_lookupFilename", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif