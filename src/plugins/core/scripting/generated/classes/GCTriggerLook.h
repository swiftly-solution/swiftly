class GCTriggerLook;

#ifndef _gcctriggerlook_h
#define _gcctriggerlook_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCTriggerLook
{
private:
    void *m_ptr;

public:
    GCTriggerLook() {}
    GCTriggerLook(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetLookTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTriggerLook", "m_hLookTarget"); }
    void SetLookTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LookTarget' is not possible.\n"); }
    float GetFieldOfView() const { return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flFieldOfView"); }
    void SetFieldOfView(float value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_flFieldOfView", false, value); }
    float GetLookTime() const { return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flLookTime"); }
    void SetLookTime(float value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_flLookTime", false, value); }
    float GetLookTimeTotal() const { return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flLookTimeTotal"); }
    void SetLookTimeTotal(float value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_flLookTimeTotal", false, value); }
    float GetTimeoutDuration() const { return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flTimeoutDuration"); }
    void SetTimeoutDuration(float value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_flTimeoutDuration", false, value); }
    bool GetTimeoutFired() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bTimeoutFired"); }
    void SetTimeoutFired(bool value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_bTimeoutFired", false, value); }
    bool GetIsLooking() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bIsLooking"); }
    void SetIsLooking(bool value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_bIsLooking", false, value); }
    bool Get2DFOV() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_b2DFOV"); }
    void Set2DFOV(bool value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_b2DFOV", false, value); }
    bool GetUseVelocity() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bUseVelocity"); }
    void SetUseVelocity(bool value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_bUseVelocity", false, value); }
    bool GetTestOcclusion() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bTestOcclusion"); }
    void SetTestOcclusion(bool value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_bTestOcclusion", false, value); }
    GCEntityIOOutput GetOnTimeout() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerLook", "m_OnTimeout"); }
    void SetOnTimeout(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_OnTimeout", false, value); }
    GCEntityIOOutput GetOnStartLook() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerLook", "m_OnStartLook"); }
    void SetOnStartLook(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_OnStartLook", false, value); }
    GCEntityIOOutput GetOnEndLook() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerLook", "m_OnEndLook"); }
    void SetOnEndLook(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerLook", "m_OnEndLook", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif