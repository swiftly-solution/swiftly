class GCEnvSoundscape;

#ifndef _gccenvsoundscape_h
#define _gccenvsoundscape_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCEnvSoundscape.h"

class GCEnvSoundscape
{
private:
    void *m_ptr;

public:
    GCEnvSoundscape() {}
    GCEnvSoundscape(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnPlay() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvSoundscape", "m_OnPlay"); }
    void SetOnPlay(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_OnPlay", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvSoundscape", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_flRadius", false, value); }
    CUtlSymbolLarge GetSoundscapeName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscape", "m_soundscapeName"); }
    void SetSoundscapeName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeName", false, value); }
    CUtlSymbolLarge GetSoundEventName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscape", "m_soundEventName"); }
    void SetSoundEventName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundEventName", false, value); }
    bool GetOverrideWithEvent() const { return GetSchemaValue<bool>(m_ptr, "CEnvSoundscape", "m_bOverrideWithEvent"); }
    void SetOverrideWithEvent(bool value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_bOverrideWithEvent", false, value); }
    int32_t GetSoundscapeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSoundscape", "m_soundscapeIndex"); }
    void SetSoundscapeIndex(int32_t value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeIndex", false, value); }
    int32_t GetSoundscapeEntityListId() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSoundscape", "m_soundscapeEntityListId"); }
    void SetSoundscapeEntityListId(int32_t value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeEntityListId", false, value); }
    uint32_t GetSoundEventHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CEnvSoundscape", "m_soundEventHash"); }
    void SetSoundEventHash(uint32_t value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundEventHash", false, value); }
    std::vector<CUtlSymbolLarge> GetPositionNames() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvSoundscape", "m_positionNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPositionNames(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvSoundscape", "m_positionNames"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvSoundscape", "m_positionNames", false, outValue); }
    GCEnvSoundscape* GetProxySoundscape() const { return GetSchemaValue<GCEnvSoundscape*>(m_ptr, "CEnvSoundscape", "m_hProxySoundscape"); }
    void SetProxySoundscape(GCEnvSoundscape* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ProxySoundscape' is not possible.\n"); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvSoundscape", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvSoundscape", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif