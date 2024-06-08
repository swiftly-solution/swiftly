class GCAttributeManager;

#ifndef _gccattributemanager_h
#define _gccattributemanager_h

#include "../../../scripting.h"

#include "../types/Gattributeprovidertypes_t.h"
#include "GCBaseEntity.h"
#include "GCAttributeManager.h"

class GCAttributeManager
{
private:
    void *m_ptr;

public:
    GCAttributeManager() {}
    GCAttributeManager(void *ptr) : m_ptr(ptr) {}

    int32_t GetReapplyProvisionParity() const { return GetSchemaValue<int32_t>(m_ptr, "CAttributeManager", "m_iReapplyProvisionParity"); }
    void SetReapplyProvisionParity(int32_t value) { SetSchemaValue(m_ptr, "CAttributeManager", "m_iReapplyProvisionParity", false, value); }
    GCBaseEntity* GetOuter() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CAttributeManager", "m_hOuter"); }
    void SetOuter(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Outer' is not possible.\n"); }
    bool GetPreventLoopback() const { return GetSchemaValue<bool>(m_ptr, "CAttributeManager", "m_bPreventLoopback"); }
    void SetPreventLoopback(bool value) { SetSchemaValue(m_ptr, "CAttributeManager", "m_bPreventLoopback", false, value); }
    attributeprovidertypes_t GetProviderType() const { return GetSchemaValue<attributeprovidertypes_t>(m_ptr, "CAttributeManager", "m_ProviderType"); }
    void SetProviderType(attributeprovidertypes_t value) { SetSchemaValue(m_ptr, "CAttributeManager", "m_ProviderType", false, value); }
    std::vector<GCAttributeManager> GetCachedResults() const { CUtlVector<GCAttributeManager>* vec = GetSchemaValue<CUtlVector<GCAttributeManager>*>(m_ptr, "CAttributeManager", "m_CachedResults"); std::vector<GCAttributeManager> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCachedResults(std::vector<GCAttributeManager> value) { SetSchemaValueCUtlVector<GCAttributeManager>(m_ptr, "CAttributeManager", "m_CachedResults", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif