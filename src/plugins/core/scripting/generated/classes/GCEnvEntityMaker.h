class GCEnvEntityMaker;

#ifndef _gccenventitymaker_h
#define _gccenventitymaker_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCEnvEntityMaker
{
private:
    void *m_ptr;

public:
    GCEnvEntityMaker() {}
    GCEnvEntityMaker(void *ptr) : m_ptr(ptr) {}

    Vector GetEntityMins() const { return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecEntityMins"); }
    void SetEntityMins(Vector value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecEntityMins", false, value); }
    Vector GetEntityMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecEntityMaxs"); }
    void SetEntityMaxs(Vector value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecEntityMaxs", false, value); }
    GCBaseEntity* GetCurrentInstance() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvEntityMaker", "m_hCurrentInstance"); }
    void SetCurrentInstance(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentInstance' is not possible.\n"); }
    GCBaseEntity* GetCurrentBlocker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvEntityMaker", "m_hCurrentBlocker"); }
    void SetCurrentBlocker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentBlocker' is not possible.\n"); }
    Vector GetBlockerOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecBlockerOrigin"); }
    void SetBlockerOrigin(Vector value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecBlockerOrigin", false, value); }
    QAngle GetPostSpawnDirection() const { return GetSchemaValue<QAngle>(m_ptr, "CEnvEntityMaker", "m_angPostSpawnDirection"); }
    void SetPostSpawnDirection(QAngle value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_angPostSpawnDirection", false, value); }
    float GetPostSpawnDirectionVariance() const { return GetSchemaValue<float>(m_ptr, "CEnvEntityMaker", "m_flPostSpawnDirectionVariance"); }
    void SetPostSpawnDirectionVariance(float value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_flPostSpawnDirectionVariance", false, value); }
    float GetPostSpawnSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvEntityMaker", "m_flPostSpawnSpeed"); }
    void SetPostSpawnSpeed(float value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_flPostSpawnSpeed", false, value); }
    bool GetPostSpawnUseAngles() const { return GetSchemaValue<bool>(m_ptr, "CEnvEntityMaker", "m_bPostSpawnUseAngles"); }
    void SetPostSpawnUseAngles(bool value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_bPostSpawnUseAngles", false, value); }
    CUtlSymbolLarge GetTemplate() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvEntityMaker", "m_iszTemplate"); }
    void SetTemplate(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_iszTemplate", false, value); }
    GCEntityIOOutput GetOutputOnSpawned() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvEntityMaker", "m_pOutputOnSpawned"); }
    void SetOutputOnSpawned(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_pOutputOnSpawned", false, value); }
    GCEntityIOOutput GetOutputOnFailedSpawn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvEntityMaker", "m_pOutputOnFailedSpawn"); }
    void SetOutputOnFailedSpawn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_pOutputOnFailedSpawn", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif