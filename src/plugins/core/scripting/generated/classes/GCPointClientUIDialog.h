class GCPointClientUIDialog;

#ifndef _gccpointclientuidialog_h
#define _gccpointclientuidialog_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPointClientUIDialog
{
private:
    void *m_ptr;

public:
    GCPointClientUIDialog() {}
    GCPointClientUIDialog(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointClientUIDialog", "m_hActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }
    bool GetStartEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIDialog", "m_bStartEnabled"); }
    void SetStartEnabled(bool value) { SetSchemaValue(m_ptr, "CPointClientUIDialog", "m_bStartEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif