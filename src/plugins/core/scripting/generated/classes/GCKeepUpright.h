class GCKeepUpright;

#ifndef _gcckeepupright_h
#define _gcckeepupright_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCKeepUpright
{
private:
    void *m_ptr;

public:
    GCKeepUpright() {}
    GCKeepUpright(void *ptr) : m_ptr(ptr) {}

    Vector GetWorldGoalAxis() const { return GetSchemaValue<Vector>(m_ptr, "CKeepUpright", "m_worldGoalAxis"); }
    void SetWorldGoalAxis(Vector value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_worldGoalAxis", false, value); }
    Vector GetLocalTestAxis() const { return GetSchemaValue<Vector>(m_ptr, "CKeepUpright", "m_localTestAxis"); }
    void SetLocalTestAxis(Vector value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_localTestAxis", false, value); }
    CUtlSymbolLarge GetNameAttach() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CKeepUpright", "m_nameAttach"); }
    void SetNameAttach(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_nameAttach", false, value); }
    GCBaseEntity* GetAttachedObject() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CKeepUpright", "m_attachedObject"); }
    void SetAttachedObject(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n"); }
    float GetAngularLimit() const { return GetSchemaValue<float>(m_ptr, "CKeepUpright", "m_angularLimit"); }
    void SetAngularLimit(float value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_angularLimit", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CKeepUpright", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_bActive", false, value); }
    bool GetDampAllRotation() const { return GetSchemaValue<bool>(m_ptr, "CKeepUpright", "m_bDampAllRotation"); }
    void SetDampAllRotation(bool value) { SetSchemaValue(m_ptr, "CKeepUpright", "m_bDampAllRotation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif