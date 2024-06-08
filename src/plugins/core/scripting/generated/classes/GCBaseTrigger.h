class GCBaseTrigger;

#ifndef _gccbasetrigger_h
#define _gccbasetrigger_h

#include "../../../scripting.h"


#include "GCBaseFilter.h"
#include "GCEntityIOOutput.h"

class GCBaseTrigger
{
private:
    void *m_ptr;

public:
    GCBaseTrigger() {}
    GCBaseTrigger(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CBaseTrigger", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_bDisabled", false, value); }
    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseTrigger", "m_iFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_iFilterName", false, value); }
    GCBaseFilter* GetFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CBaseTrigger", "m_hFilter"); }
    void SetFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }
    GCEntityIOOutput GetOnStartTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnStartTouch"); }
    void SetOnStartTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnStartTouch", false, value); }
    GCEntityIOOutput GetOnStartTouchAll() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnStartTouchAll"); }
    void SetOnStartTouchAll(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnStartTouchAll", false, value); }
    GCEntityIOOutput GetOnEndTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnEndTouch"); }
    void SetOnEndTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnEndTouch", false, value); }
    GCEntityIOOutput GetOnEndTouchAll() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnEndTouchAll"); }
    void SetOnEndTouchAll(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnEndTouchAll", false, value); }
    GCEntityIOOutput GetOnTouching() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnTouching"); }
    void SetOnTouching(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnTouching", false, value); }
    GCEntityIOOutput GetOnTouchingEachEntity() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnTouchingEachEntity"); }
    void SetOnTouchingEachEntity(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnTouchingEachEntity", false, value); }
    GCEntityIOOutput GetOnNotTouching() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseTrigger", "m_OnNotTouching"); }
    void SetOnNotTouching(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnNotTouching", false, value); }
    bool GetClientSidePredicted() const { return GetSchemaValue<bool>(m_ptr, "CBaseTrigger", "m_bClientSidePredicted"); }
    void SetClientSidePredicted(bool value) { SetSchemaValue(m_ptr, "CBaseTrigger", "m_bClientSidePredicted", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif