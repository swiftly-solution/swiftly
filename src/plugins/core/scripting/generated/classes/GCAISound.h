class GCAISound;

#ifndef _gccaisound_h
#define _gccaisound_h

#include "../../../scripting.h"

#include "../types/GSoundTypes_t.h"


class GCAISound
{
private:
    void *m_ptr;

public:
    GCAISound() {}
    GCAISound(void *ptr) : m_ptr(ptr) {}

    SoundTypes_t GetSoundType() const { return GetSchemaValue<SoundTypes_t>(m_ptr, "CAISound", "m_iSoundType"); }
    void SetSoundType(SoundTypes_t value) { SetSchemaValue(m_ptr, "CAISound", "m_iSoundType", false, value); }
    SoundFlags_t GetSoundFlags() const { return GetSchemaValue<SoundFlags_t>(m_ptr, "CAISound", "m_iSoundFlags"); }
    void SetSoundFlags(SoundFlags_t value) { SetSchemaValue(m_ptr, "CAISound", "m_iSoundFlags", false, value); }
    int32_t GetVolume() const { return GetSchemaValue<int32_t>(m_ptr, "CAISound", "m_iVolume"); }
    void SetVolume(int32_t value) { SetSchemaValue(m_ptr, "CAISound", "m_iVolume", false, value); }
    int32_t GetSoundIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAISound", "m_iSoundIndex"); }
    void SetSoundIndex(int32_t value) { SetSchemaValue(m_ptr, "CAISound", "m_iSoundIndex", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CAISound", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CAISound", "m_flDuration", false, value); }
    CUtlSymbolLarge GetProxyEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAISound", "m_iszProxyEntityName"); }
    void SetProxyEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAISound", "m_iszProxyEntityName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif