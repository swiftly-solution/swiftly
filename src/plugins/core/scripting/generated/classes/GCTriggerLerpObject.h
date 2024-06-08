class GCTriggerLerpObject;

#ifndef _gcctriggerlerpobject_h
#define _gcctriggerlerpobject_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "Glerpdata_t.h"
#include "GCEntityIOOutput.h"

class GCTriggerLerpObject
{
private:
    void *m_ptr;

public:
    GCTriggerLerpObject() {}
    GCTriggerLerpObject(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLerpTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpTarget"); }
    void SetLerpTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpTarget", false, value); }
    GCBaseEntity* GetLerpTarget1() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTriggerLerpObject", "m_hLerpTarget"); }
    void SetLerpTarget1(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LerpTarget1' is not possible.\n"); }
    CUtlSymbolLarge GetLerpTargetAttachment() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpTargetAttachment"); }
    void SetLerpTargetAttachment(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpTargetAttachment", false, value); }
    float GetLerpDuration() const { return GetSchemaValue<float>(m_ptr, "CTriggerLerpObject", "m_flLerpDuration"); }
    void SetLerpDuration(float value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_flLerpDuration", false, value); }
    bool GetLerpRestoreMoveType() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bLerpRestoreMoveType"); }
    void SetLerpRestoreMoveType(bool value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bLerpRestoreMoveType", false, value); }
    bool GetSingleLerpObject() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bSingleLerpObject"); }
    void SetSingleLerpObject(bool value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bSingleLerpObject", false, value); }
    std::vector<Glerpdata_t> GetLerpingObjects() const { CUtlVector<Glerpdata_t>* vec = GetSchemaValue<CUtlVector<Glerpdata_t>*>(m_ptr, "CTriggerLerpObject", "m_vecLerpingObjects"); std::vector<Glerpdata_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLerpingObjects(std::vector<Glerpdata_t> value) { SetSchemaValueCUtlVector<Glerpdata_t>(m_ptr, "CTriggerLerpObject", "m_vecLerpingObjects", false, value); }
    CUtlSymbolLarge GetLerpEffect() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpEffect"); }
    void SetLerpEffect(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpEffect", false, value); }
    CUtlSymbolLarge GetLerpSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpSound"); }
    void SetLerpSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpSound", false, value); }
    bool GetAttachTouchingObject() const { return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bAttachTouchingObject"); }
    void SetAttachTouchingObject(bool value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bAttachTouchingObject", false, value); }
    GCBaseEntity* GetEntityToWaitForDisconnect() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTriggerLerpObject", "m_hEntityToWaitForDisconnect"); }
    void SetEntityToWaitForDisconnect(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityToWaitForDisconnect' is not possible.\n"); }
    GCEntityIOOutput GetOnLerpStarted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerLerpObject", "m_OnLerpStarted"); }
    void SetOnLerpStarted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_OnLerpStarted", false, value); }
    GCEntityIOOutput GetOnLerpFinished() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerLerpObject", "m_OnLerpFinished"); }
    void SetOnLerpFinished(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_OnLerpFinished", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif