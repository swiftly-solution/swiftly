class GCPointTemplate;

#ifndef _gccpointtemplate_h
#define _gccpointtemplate_h

#include "../../../scripting.h"

#include "../types/GPointTemplateClientOnlyEntityBehavior_t.h"
#include "../types/GPointTemplateOwnerSpawnGroupType_t.h"
#include "GCEntityIOOutput.h"
#include "GCEntityInstance.h"

class GCPointTemplate
{
private:
    void *m_ptr;

public:
    GCPointTemplate() {}
    GCPointTemplate(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetWorldName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszWorldName"); }
    void SetWorldName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_iszWorldName", false, value); }
    CUtlSymbolLarge GetSource2EntityLumpName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszSource2EntityLumpName"); }
    void SetSource2EntityLumpName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_iszSource2EntityLumpName", false, value); }
    CUtlSymbolLarge GetEntityFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszEntityFilterName"); }
    void SetEntityFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_iszEntityFilterName", false, value); }
    float GetTimeoutInterval() const { return GetSchemaValue<float>(m_ptr, "CPointTemplate", "m_flTimeoutInterval"); }
    void SetTimeoutInterval(float value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_flTimeoutInterval", false, value); }
    bool GetAsynchronouslySpawnEntities() const { return GetSchemaValue<bool>(m_ptr, "CPointTemplate", "m_bAsynchronouslySpawnEntities"); }
    void SetAsynchronouslySpawnEntities(bool value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_bAsynchronouslySpawnEntities", false, value); }
    GCEntityIOOutput GetOutputOnSpawned() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointTemplate", "m_pOutputOnSpawned"); }
    void SetOutputOnSpawned(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_pOutputOnSpawned", false, value); }
    PointTemplateClientOnlyEntityBehavior_t GetClientOnlyEntityBehavior() const { return GetSchemaValue<PointTemplateClientOnlyEntityBehavior_t>(m_ptr, "CPointTemplate", "m_clientOnlyEntityBehavior"); }
    void SetClientOnlyEntityBehavior(PointTemplateClientOnlyEntityBehavior_t value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_clientOnlyEntityBehavior", false, value); }
    PointTemplateOwnerSpawnGroupType_t GetOwnerSpawnGroupType() const { return GetSchemaValue<PointTemplateOwnerSpawnGroupType_t>(m_ptr, "CPointTemplate", "m_ownerSpawnGroupType"); }
    void SetOwnerSpawnGroupType(PointTemplateOwnerSpawnGroupType_t value) { SetSchemaValue(m_ptr, "CPointTemplate", "m_ownerSpawnGroupType", false, value); }
    std::vector<uint32> GetCreatedSpawnGroupHandles() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CPointTemplate", "m_createdSpawnGroupHandles"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCreatedSpawnGroupHandles(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CPointTemplate", "m_createdSpawnGroupHandles", false, value); }
    GCEntityInstance* GetSpawnedEntityHandles() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CPointTemplate", "m_SpawnedEntityHandles"); }
    void SetSpawnedEntityHandles(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SpawnedEntityHandles' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif