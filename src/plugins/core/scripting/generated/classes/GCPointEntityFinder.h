class GCPointEntityFinder;

#ifndef _gccpointentityfinder_h
#define _gccpointentityfinder_h

#include "../../../scripting.h"

#include "../types/GEntFinderMethod_t.h"
#include "GCBaseEntity.h"
#include "GCBaseFilter.h"
#include "GCEntityIOOutput.h"

class GCPointEntityFinder
{
private:
    void *m_ptr;

public:
    GCPointEntityFinder() {}
    GCPointEntityFinder(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointEntityFinder", "m_hEntity"); }
    void SetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }
    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointEntityFinder", "m_iFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointEntityFinder", "m_iFilterName", false, value); }
    GCBaseFilter* GetFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CPointEntityFinder", "m_hFilter"); }
    void SetFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }
    CUtlSymbolLarge GetRefName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointEntityFinder", "m_iRefName"); }
    void SetRefName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointEntityFinder", "m_iRefName", false, value); }
    GCBaseEntity* GetReference() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointEntityFinder", "m_hReference"); }
    void SetReference(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Reference' is not possible.\n"); }
    EntFinderMethod_t GetFindMethod() const { return GetSchemaValue<EntFinderMethod_t>(m_ptr, "CPointEntityFinder", "m_FindMethod"); }
    void SetFindMethod(EntFinderMethod_t value) { SetSchemaValue(m_ptr, "CPointEntityFinder", "m_FindMethod", false, value); }
    GCEntityIOOutput GetOnFoundEntity() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointEntityFinder", "m_OnFoundEntity"); }
    void SetOnFoundEntity(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointEntityFinder", "m_OnFoundEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif