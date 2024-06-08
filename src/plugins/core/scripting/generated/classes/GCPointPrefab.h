class GCPointPrefab;

#ifndef _gccpointprefab_h
#define _gccpointprefab_h

#include "../../../scripting.h"


#include "GCPointPrefab.h"

class GCPointPrefab
{
private:
    void *m_ptr;

public:
    GCPointPrefab() {}
    GCPointPrefab(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetTargetMapName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_targetMapName"); }
    void SetTargetMapName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointPrefab", "m_targetMapName", false, value); }
    CUtlSymbolLarge GetForceWorldGroupID() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_forceWorldGroupID"); }
    void SetForceWorldGroupID(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointPrefab", "m_forceWorldGroupID", false, value); }
    CUtlSymbolLarge GetAssociatedRelayTargetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_associatedRelayTargetName"); }
    void SetAssociatedRelayTargetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointPrefab", "m_associatedRelayTargetName", false, value); }
    bool GetFixupNames() const { return GetSchemaValue<bool>(m_ptr, "CPointPrefab", "m_fixupNames"); }
    void SetFixupNames(bool value) { SetSchemaValue(m_ptr, "CPointPrefab", "m_fixupNames", false, value); }
    bool GetLoadDynamic() const { return GetSchemaValue<bool>(m_ptr, "CPointPrefab", "m_bLoadDynamic"); }
    void SetLoadDynamic(bool value) { SetSchemaValue(m_ptr, "CPointPrefab", "m_bLoadDynamic", false, value); }
    GCPointPrefab* GetAssociatedRelayEntity() const { return GetSchemaValue<GCPointPrefab*>(m_ptr, "CPointPrefab", "m_associatedRelayEntity"); }
    void SetAssociatedRelayEntity(GCPointPrefab* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AssociatedRelayEntity' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif