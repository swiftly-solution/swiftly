class GCSoundEventEntity;

#ifndef _gccsoundevententity_h
#define _gccsoundevententity_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCEntityInstance.h"

class GCSoundEventEntity
{
private:
    void *m_ptr;

public:
    GCSoundEventEntity() {}
    GCSoundEventEntity(void *ptr) : m_ptr(ptr) {}

    bool GetStartOnSpawn() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bStartOnSpawn"); }
    void SetStartOnSpawn(bool value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bStartOnSpawn", false, value); }
    bool GetToLocalPlayer() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bToLocalPlayer"); }
    void SetToLocalPlayer(bool value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bToLocalPlayer", false, value); }
    bool GetStopOnNew() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bStopOnNew"); }
    void SetStopOnNew(bool value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bStopOnNew", false, value); }
    bool GetSaveRestore() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bSaveRestore"); }
    void SetSaveRestore(bool value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bSaveRestore", false, value); }
    bool GetSavedIsPlaying() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bSavedIsPlaying"); }
    void SetSavedIsPlaying(bool value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bSavedIsPlaying", false, value); }
    float GetSavedElapsedTime() const { return GetSchemaValue<float>(m_ptr, "CSoundEventEntity", "m_flSavedElapsedTime"); }
    void SetSavedElapsedTime(float value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_flSavedElapsedTime", false, value); }
    CUtlSymbolLarge GetSourceEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszSourceEntityName"); }
    void SetSourceEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszSourceEntityName", false, value); }
    CUtlSymbolLarge GetAttachmentName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszAttachmentName"); }
    void SetAttachmentName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszAttachmentName", false, value); }
    GCEntityIOOutput GetOnSoundFinished() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSoundEventEntity", "m_onSoundFinished"); }
    void SetOnSoundFinished(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_onSoundFinished", false, value); }
    CUtlSymbolLarge GetSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszSoundName"); }
    void SetSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszSoundName", false, value); }
    GCEntityInstance* GetSource() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CSoundEventEntity", "m_hSource"); }
    void SetSource(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n"); }
    int32_t GetEntityIndexSelection() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundEventEntity", "m_nEntityIndexSelection"); }
    void SetEntityIndexSelection(int32_t value) { SetSchemaValue(m_ptr, "CSoundEventEntity", "m_nEntityIndexSelection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif