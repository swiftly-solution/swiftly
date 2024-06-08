class GCEnvMicrophone;

#ifndef _gccenvmicrophone_h
#define _gccenvmicrophone_h

#include "../../../scripting.h"

#include "../types/GSoundTypes_t.h"
#include "GCBaseEntity.h"
#include "GCBaseFilter.h"
#include "GCEntityIOOutput.h"

class GCEnvMicrophone
{
private:
    void *m_ptr;

public:
    GCEnvMicrophone() {}
    GCEnvMicrophone(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvMicrophone", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_bDisabled", false, value); }
    GCBaseEntity* GetMeasureTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvMicrophone", "m_hMeasureTarget"); }
    void SetMeasureTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n"); }
    SoundTypes_t GetSoundType() const { return GetSchemaValue<SoundTypes_t>(m_ptr, "CEnvMicrophone", "m_nSoundType"); }
    void SetSoundType(SoundTypes_t value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_nSoundType", false, value); }
    SoundFlags_t GetSoundFlags() const { return GetSchemaValue<SoundFlags_t>(m_ptr, "CEnvMicrophone", "m_nSoundFlags"); }
    void SetSoundFlags(SoundFlags_t value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_nSoundFlags", false, value); }
    float GetSensitivity() const { return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flSensitivity"); }
    void SetSensitivity(float value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flSensitivity", false, value); }
    float GetSmoothFactor() const { return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flSmoothFactor"); }
    void SetSmoothFactor(float value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flSmoothFactor", false, value); }
    float GetMaxRange() const { return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flMaxRange"); }
    void SetMaxRange(float value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flMaxRange", false, value); }
    CUtlSymbolLarge GetSpeakerName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMicrophone", "m_iszSpeakerName"); }
    void SetSpeakerName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iszSpeakerName", false, value); }
    GCBaseEntity* GetSpeaker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvMicrophone", "m_hSpeaker"); }
    void SetSpeaker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Speaker' is not possible.\n"); }
    bool GetAvoidFeedback() const { return GetSchemaValue<bool>(m_ptr, "CEnvMicrophone", "m_bAvoidFeedback"); }
    void SetAvoidFeedback(bool value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_bAvoidFeedback", false, value); }
    int32_t GetSpeakerDSPPreset() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvMicrophone", "m_iSpeakerDSPPreset"); }
    void SetSpeakerDSPPreset(int32_t value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iSpeakerDSPPreset", false, value); }
    CUtlSymbolLarge GetListenFilter() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMicrophone", "m_iszListenFilter"); }
    void SetListenFilter(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iszListenFilter", false, value); }
    GCBaseFilter* GetListenFilter1() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CEnvMicrophone", "m_hListenFilter"); }
    void SetListenFilter1(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ListenFilter1' is not possible.\n"); }
    GCEntityIOOutput GetOnRoutedSound() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvMicrophone", "m_OnRoutedSound"); }
    void SetOnRoutedSound(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_OnRoutedSound", false, value); }
    GCEntityIOOutput GetOnHeardSound() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvMicrophone", "m_OnHeardSound"); }
    void SetOnHeardSound(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_OnHeardSound", false, value); }
    std::string GetLastSound() const { return GetSchemaValue<char*>(m_ptr, "CEnvMicrophone", "m_szLastSound"); }
    void SetLastSound(std::string value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_szLastSound", false, value); }
    int32_t GetLastRoutedFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvMicrophone", "m_iLastRoutedFrame"); }
    void SetLastRoutedFrame(int32_t value) { SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iLastRoutedFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif