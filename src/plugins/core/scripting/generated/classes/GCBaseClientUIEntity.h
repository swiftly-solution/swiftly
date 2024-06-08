class GCBaseClientUIEntity;

#ifndef _gccbaseclientuientity_h
#define _gccbaseclientuientity_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCBaseClientUIEntity
{
private:
    void *m_ptr;

public:
    GCBaseClientUIEntity() {}
    GCBaseClientUIEntity(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CBaseClientUIEntity", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_bEnabled", false, value); }
    CUtlSymbolLarge GetDialogXMLName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_DialogXMLName"); }
    void SetDialogXMLName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_DialogXMLName", false, value); }
    CUtlSymbolLarge GetPanelClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_PanelClassName"); }
    void SetPanelClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_PanelClassName", false, value); }
    CUtlSymbolLarge GetPanelID() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_PanelID"); }
    void SetPanelID(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_PanelID", false, value); }
    GCEntityIOOutput GetCustomOutput0() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput0"); }
    void SetCustomOutput0(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput0", false, value); }
    GCEntityIOOutput GetCustomOutput1() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput1"); }
    void SetCustomOutput1(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput1", false, value); }
    GCEntityIOOutput GetCustomOutput2() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput2"); }
    void SetCustomOutput2(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput2", false, value); }
    GCEntityIOOutput GetCustomOutput3() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput3"); }
    void SetCustomOutput3(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput3", false, value); }
    GCEntityIOOutput GetCustomOutput4() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput4"); }
    void SetCustomOutput4(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput4", false, value); }
    GCEntityIOOutput GetCustomOutput5() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput5"); }
    void SetCustomOutput5(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput5", false, value); }
    GCEntityIOOutput GetCustomOutput6() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput6"); }
    void SetCustomOutput6(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput6", false, value); }
    GCEntityIOOutput GetCustomOutput7() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput7"); }
    void SetCustomOutput7(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput7", false, value); }
    GCEntityIOOutput GetCustomOutput8() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput8"); }
    void SetCustomOutput8(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput8", false, value); }
    GCEntityIOOutput GetCustomOutput9() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseClientUIEntity", "m_CustomOutput9"); }
    void SetCustomOutput9(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput9", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif