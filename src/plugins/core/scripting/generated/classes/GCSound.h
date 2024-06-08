class GCSound;

#ifndef _gccsound_h
#define _gccsound_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCSound
{
private:
    void *m_ptr;

public:
    GCSound() {}
    GCSound(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetOwner() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSound", "m_hOwner"); }
    void SetOwner(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    GCBaseEntity* GetTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSound", "m_hTarget"); }
    void SetTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n"); }
    int32_t GetVolume() const { return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_iVolume"); }
    void SetVolume(int32_t value) { SetSchemaValue(m_ptr, "CSound", "m_iVolume", false, value); }
    float GetOcclusionScale() const { return GetSchemaValue<float>(m_ptr, "CSound", "m_flOcclusionScale"); }
    void SetOcclusionScale(float value) { SetSchemaValue(m_ptr, "CSound", "m_flOcclusionScale", false, value); }
    int32_t GetNextAudible() const { return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_iNextAudible"); }
    void SetNextAudible(int32_t value) { SetSchemaValue(m_ptr, "CSound", "m_iNextAudible", false, value); }
    int16_t GetNext() const { return GetSchemaValue<int16_t>(m_ptr, "CSound", "m_iNext"); }
    void SetNext(int16_t value) { SetSchemaValue(m_ptr, "CSound", "m_iNext", false, value); }
    bool GetNoExpirationTime() const { return GetSchemaValue<bool>(m_ptr, "CSound", "m_bNoExpirationTime"); }
    void SetNoExpirationTime(bool value) { SetSchemaValue(m_ptr, "CSound", "m_bNoExpirationTime", false, value); }
    int32_t GetOwnerChannelIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_ownerChannelIndex"); }
    void SetOwnerChannelIndex(int32_t value) { SetSchemaValue(m_ptr, "CSound", "m_ownerChannelIndex", false, value); }
    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CSound", "m_vecOrigin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "CSound", "m_vecOrigin", false, value); }
    bool GetHasOwner() const { return GetSchemaValue<bool>(m_ptr, "CSound", "m_bHasOwner"); }
    void SetHasOwner(bool value) { SetSchemaValue(m_ptr, "CSound", "m_bHasOwner", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif