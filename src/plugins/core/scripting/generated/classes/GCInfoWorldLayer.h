class GCInfoWorldLayer;

#ifndef _gccinfoworldlayer_h
#define _gccinfoworldlayer_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCInfoWorldLayer
{
private:
    void *m_ptr;

public:
    GCInfoWorldLayer() {}
    GCInfoWorldLayer(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOutputOnEntitiesSpawned() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CInfoWorldLayer", "m_pOutputOnEntitiesSpawned"); }
    void SetOutputOnEntitiesSpawned(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_pOutputOnEntitiesSpawned", false, value); }
    CUtlSymbolLarge GetWorldName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoWorldLayer", "m_worldName"); }
    void SetWorldName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_worldName", false, value); }
    CUtlSymbolLarge GetLayerName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoWorldLayer", "m_layerName"); }
    void SetLayerName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_layerName", false, value); }
    bool GetWorldLayerVisible() const { return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bWorldLayerVisible"); }
    void SetWorldLayerVisible(bool value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bWorldLayerVisible", false, value); }
    bool GetEntitiesSpawned() const { return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bEntitiesSpawned"); }
    void SetEntitiesSpawned(bool value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bEntitiesSpawned", false, value); }
    bool GetCreateAsChildSpawnGroup() const { return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bCreateAsChildSpawnGroup"); }
    void SetCreateAsChildSpawnGroup(bool value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bCreateAsChildSpawnGroup", false, value); }
    uint32_t GetLayerSpawnGroup() const { return GetSchemaValue<uint32_t>(m_ptr, "CInfoWorldLayer", "m_hLayerSpawnGroup"); }
    void SetLayerSpawnGroup(uint32_t value) { SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_hLayerSpawnGroup", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif