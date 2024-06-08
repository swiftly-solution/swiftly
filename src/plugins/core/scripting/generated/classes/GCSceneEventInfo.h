class GCSceneEventInfo;

#ifndef _gccsceneeventinfo_h
#define _gccsceneeventinfo_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GSceneEventId_t.h"

class GCSceneEventInfo
{
private:
    void *m_ptr;

public:
    GCSceneEventInfo() {}
    GCSceneEventInfo(void *ptr) : m_ptr(ptr) {}

    int32_t GetLayer() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_iLayer"); }
    void SetLayer(int32_t value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_iLayer", false, value); }
    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_iPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_iPriority", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CSceneEventInfo", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_flWeight", false, value); }
    bool GetHasArrived() const { return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bHasArrived"); }
    void SetHasArrived(bool value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bHasArrived", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_nType", false, value); }
    bool GetIsGesture() const { return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bIsGesture"); }
    void SetIsGesture(bool value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bIsGesture", false, value); }
    bool GetShouldRemove() const { return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bShouldRemove"); }
    void SetShouldRemove(bool value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bShouldRemove", false, value); }
    GCBaseEntity* GetTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEventInfo", "m_hTarget"); }
    void SetTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n"); }
    GSceneEventId_t GetSceneEventId() const { return GetSchemaValue<GSceneEventId_t>(m_ptr, "CSceneEventInfo", "m_nSceneEventId"); }
    void SetSceneEventId(GSceneEventId_t value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_nSceneEventId", false, value); }
    bool GetClientSide() const { return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bClientSide"); }
    void SetClientSide(bool value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bClientSide", false, value); }
    bool GetStarted() const { return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bStarted"); }
    void SetStarted(bool value) { SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bStarted", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif