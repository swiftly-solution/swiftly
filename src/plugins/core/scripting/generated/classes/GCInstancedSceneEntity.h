class GCInstancedSceneEntity;

#ifndef _gccinstancedsceneentity_h
#define _gccinstancedsceneentity_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCInstancedSceneEntity
{
private:
    void *m_ptr;

public:
    GCInstancedSceneEntity() {}
    GCInstancedSceneEntity(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetOwner() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CInstancedSceneEntity", "m_hOwner"); }
    void SetOwner(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    bool GetHadOwner() const { return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bHadOwner"); }
    void SetHadOwner(bool value) { SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bHadOwner", false, value); }
    float GetPostSpeakDelay() const { return GetSchemaValue<float>(m_ptr, "CInstancedSceneEntity", "m_flPostSpeakDelay"); }
    void SetPostSpeakDelay(float value) { SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_flPostSpeakDelay", false, value); }
    float GetPreDelay() const { return GetSchemaValue<float>(m_ptr, "CInstancedSceneEntity", "m_flPreDelay"); }
    void SetPreDelay(float value) { SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_flPreDelay", false, value); }
    bool GetIsBackground() const { return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bIsBackground"); }
    void SetIsBackground(bool value) { SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bIsBackground", false, value); }
    bool GetRemoveOnCompletion() const { return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bRemoveOnCompletion"); }
    void SetRemoveOnCompletion(bool value) { SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bRemoveOnCompletion", false, value); }
    GCBaseEntity* GetTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CInstancedSceneEntity", "m_hTarget"); }
    void SetTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif