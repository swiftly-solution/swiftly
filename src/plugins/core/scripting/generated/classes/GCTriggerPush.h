class GCTriggerPush;

#ifndef _gcctriggerpush_h
#define _gcctriggerpush_h

#include "../../../scripting.h"


#include "GCPathSimple.h"

class GCTriggerPush
{
private:
    void *m_ptr;

public:
    GCTriggerPush() {}
    GCTriggerPush(void *ptr) : m_ptr(ptr) {}

    QAngle GetPushEntitySpace() const { return GetSchemaValue<QAngle>(m_ptr, "CTriggerPush", "m_angPushEntitySpace"); }
    void SetPushEntitySpace(QAngle value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_angPushEntitySpace", false, value); }
    Vector GetPushDirEntitySpace() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerPush", "m_vecPushDirEntitySpace"); }
    void SetPushDirEntitySpace(Vector value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_vecPushDirEntitySpace", false, value); }
    bool GetTriggerOnStartTouch() const { return GetSchemaValue<bool>(m_ptr, "CTriggerPush", "m_bTriggerOnStartTouch"); }
    void SetTriggerOnStartTouch(bool value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_bTriggerOnStartTouch", false, value); }
    bool GetUsePathSimple() const { return GetSchemaValue<bool>(m_ptr, "CTriggerPush", "m_bUsePathSimple"); }
    void SetUsePathSimple(bool value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_bUsePathSimple", false, value); }
    CUtlSymbolLarge GetPathSimpleName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerPush", "m_iszPathSimpleName"); }
    void SetPathSimpleName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_iszPathSimpleName", false, value); }
    GCPathSimple* GetPathSimple() const { return GetSchemaValue<GCPathSimple*>(m_ptr, "CTriggerPush", "m_PathSimple"); }
    void SetPathSimple(GCPathSimple* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PathSimple' is not possible.\n"); }
    uint32_t GetSplinePushType() const { return GetSchemaValue<uint32_t>(m_ptr, "CTriggerPush", "m_splinePushType"); }
    void SetSplinePushType(uint32_t value) { SetSchemaValue(m_ptr, "CTriggerPush", "m_splinePushType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif