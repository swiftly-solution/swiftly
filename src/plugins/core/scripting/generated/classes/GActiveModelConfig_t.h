class GActiveModelConfig_t;

#ifndef _gcactivemodelconfig_t_h
#define _gcactivemodelconfig_t_h

#include "../../../scripting.h"


#include "GModelConfigHandle_t.h"
#include "GCBaseModelEntity.h"

class GActiveModelConfig_t
{
private:
    void *m_ptr;

public:
    GActiveModelConfig_t() {}
    GActiveModelConfig_t(void *ptr) : m_ptr(ptr) {}

    GModelConfigHandle_t GetHandle() const { return GetSchemaValue<GModelConfigHandle_t>(m_ptr, "ActiveModelConfig_t", "m_Handle"); }
    void SetHandle(GModelConfigHandle_t value) { SetSchemaValue(m_ptr, "ActiveModelConfig_t", "m_Handle", true, value); }
    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ActiveModelConfig_t", "m_Name"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "ActiveModelConfig_t", "m_Name", true, value); }
    GCBaseModelEntity* GetAssociatedEntities() const { return GetSchemaValue<GCBaseModelEntity*>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntities"); }
    void SetAssociatedEntities(GCBaseModelEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AssociatedEntities' is not possible.\n"); }
    std::vector<CUtlSymbolLarge> GetAssociatedEntityNames() const { CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntityNames"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAssociatedEntityNames(std::vector<CUtlSymbolLarge> value) { SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntityNames", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif