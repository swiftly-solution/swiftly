class GCSoundPatch;

#ifndef _gccsoundpatch_h
#define _gccsoundpatch_h

#include "../../../scripting.h"


#include "GCSoundEnvelope.h"
#include "GCSound.h"
#include "GCBaseEntity.h"
#include "GCCopyRecipientFilter.h"

class GCSoundPatch
{
private:
    void *m_ptr;

public:
    GCSoundPatch() {}
    GCSoundPatch(void *ptr) : m_ptr(ptr) {}

    GCSoundEnvelope GetPitch() const { return GetSchemaValue<GCSoundEnvelope>(m_ptr, "CSoundPatch", "m_pitch"); }
    void SetPitch(GCSoundEnvelope value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_pitch", false, value); }
    GCSoundEnvelope GetVolume() const { return GetSchemaValue<GCSoundEnvelope>(m_ptr, "CSoundPatch", "m_volume"); }
    void SetVolume(GCSoundEnvelope value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_volume", false, value); }
    float GetShutdownTime() const { return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_shutdownTime"); }
    void SetShutdownTime(float value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_shutdownTime", false, value); }
    float GetLastTime() const { return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_flLastTime"); }
    void SetLastTime(float value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_flLastTime", false, value); }
    CUtlSymbolLarge GetSoundScriptName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundPatch", "m_iszSoundScriptName"); }
    void SetSoundScriptName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_iszSoundScriptName", false, value); }
    GCBaseEntity* GetEnt() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSoundPatch", "m_hEnt"); }
    void SetEnt(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ent' is not possible.\n"); }
    CEntityIndex GetSoundEntityIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CSoundPatch", "m_soundEntityIndex"); }
    void SetSoundEntityIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_soundEntityIndex", false, value); }
    Vector GetSoundOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CSoundPatch", "m_soundOrigin"); }
    void SetSoundOrigin(Vector value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_soundOrigin", false, value); }
    int32_t GetIsPlaying() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundPatch", "m_isPlaying"); }
    void SetIsPlaying(int32_t value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_isPlaying", false, value); }
    GCCopyRecipientFilter GetFilter() const { return GetSchemaValue<GCCopyRecipientFilter>(m_ptr, "CSoundPatch", "m_Filter"); }
    void SetFilter(GCCopyRecipientFilter value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_Filter", false, value); }
    float GetCloseCaptionDuration() const { return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_flCloseCaptionDuration"); }
    void SetCloseCaptionDuration(float value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_flCloseCaptionDuration", false, value); }
    bool GetUpdatedSoundOrigin() const { return GetSchemaValue<bool>(m_ptr, "CSoundPatch", "m_bUpdatedSoundOrigin"); }
    void SetUpdatedSoundOrigin(bool value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_bUpdatedSoundOrigin", false, value); }
    CUtlSymbolLarge GetClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundPatch", "m_iszClassName"); }
    void SetClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundPatch", "m_iszClassName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif