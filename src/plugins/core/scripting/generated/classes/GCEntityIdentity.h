class GCEntityIdentity;

#ifndef _gccentityidentity_h
#define _gccentityidentity_h

#include "../../../scripting.h"


#include "GChangeAccessorFieldPathIndex_t.h"
#include "GCEntityIdentity.h"

class GCEntityIdentity
{
private:
    void *m_ptr;

public:
    GCEntityIdentity() {}
    GCEntityIdentity(void *ptr) : m_ptr(ptr) {}

    int32_t GetNameStringableIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CEntityIdentity", "m_nameStringableIndex"); }
    void SetNameStringableIndex(int32_t value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_nameStringableIndex", false, value); }
    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityIdentity", "m_name"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_name", false, value); }
    CUtlSymbolLarge GetDesignerName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityIdentity", "m_designerName"); }
    void SetDesignerName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_designerName", false, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CEntityIdentity", "m_flags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_flags", false, value); }
    WorldGroupId_t GetWorldGroupId() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "CEntityIdentity", "m_worldGroupId"); }
    void SetWorldGroupId(WorldGroupId_t value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_worldGroupId", false, value); }
    uint32_t GetDataObjectTypes() const { return GetSchemaValue<uint32_t>(m_ptr, "CEntityIdentity", "m_fDataObjectTypes"); }
    void SetDataObjectTypes(uint32_t value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_fDataObjectTypes", false, value); }
    GChangeAccessorFieldPathIndex_t GetPathIndex() const { return GetSchemaValue<GChangeAccessorFieldPathIndex_t>(m_ptr, "CEntityIdentity", "m_PathIndex"); }
    void SetPathIndex(GChangeAccessorFieldPathIndex_t value) { SetSchemaValue(m_ptr, "CEntityIdentity", "m_PathIndex", false, value); }
    GCEntityIdentity* GetPrev() const { return GetSchemaValue<GCEntityIdentity*>(m_ptr, "CEntityIdentity", "m_pPrev"); }
    void SetPrev(GCEntityIdentity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n"); }
    GCEntityIdentity* GetNext() const { return GetSchemaValue<GCEntityIdentity*>(m_ptr, "CEntityIdentity", "m_pNext"); }
    void SetNext(GCEntityIdentity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }
    GCEntityIdentity* GetPrevByClass() const { return GetSchemaValue<GCEntityIdentity*>(m_ptr, "CEntityIdentity", "m_pPrevByClass"); }
    void SetPrevByClass(GCEntityIdentity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevByClass' is not possible.\n"); }
    GCEntityIdentity* GetNextByClass() const { return GetSchemaValue<GCEntityIdentity*>(m_ptr, "CEntityIdentity", "m_pNextByClass"); }
    void SetNextByClass(GCEntityIdentity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextByClass' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif