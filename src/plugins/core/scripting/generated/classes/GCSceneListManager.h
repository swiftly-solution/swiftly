class GCSceneListManager;

#ifndef _gccscenelistmanager_h
#define _gccscenelistmanager_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCSceneListManager
{
private:
    void *m_ptr;

public:
    GCSceneListManager() {}
    GCSceneListManager(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlSymbolLarge> GetScenes() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CSceneListManager", "m_iszScenes"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetScenes(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CSceneListManager", "m_iszScenes"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSceneListManager", "m_iszScenes", false, outValue); }
    GCBaseEntity* GetScenes1() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneListManager", "m_hScenes"); }
    void SetScenes1(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Scenes1' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif