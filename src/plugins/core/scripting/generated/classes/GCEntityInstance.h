class GCEntityInstance;

#ifndef _gccentityinstance_h
#define _gccentityinstance_h

#include "../../../scripting.h"


#include "GCEntityIdentity.h"
#include "GCScriptComponent.h"

class GCEntityInstance
{
private:
    void *m_ptr;

public:
    GCEntityInstance() {}
    GCEntityInstance(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetPrivateVScripts() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityInstance", "m_iszPrivateVScripts"); }
    void SetPrivateVScripts(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEntityInstance", "m_iszPrivateVScripts", false, value); }
    GCEntityIdentity* GetEntity() const { return GetSchemaValue<GCEntityIdentity*>(m_ptr, "CEntityInstance", "m_pEntity"); }
    void SetEntity(GCEntityIdentity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }
    GCScriptComponent* GetCScriptComponent() const { return GetSchemaValue<GCScriptComponent*>(m_ptr, "CEntityInstance", "m_CScriptComponent"); }
    void SetCScriptComponent(GCScriptComponent* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CScriptComponent' is not possible.\n"); }
    bool GetVisibleinPVS() const { return GetSchemaValue<bool>(m_ptr, "CEntityInstance", "m_bVisibleinPVS"); }
    void SetVisibleinPVS(bool value) { SetSchemaValue(m_ptr, "CEntityInstance", "m_bVisibleinPVS", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif