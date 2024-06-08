class GCBombTarget;

#ifndef _gccbombtarget_h
#define _gccbombtarget_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCBaseEntity.h"

class GCBombTarget
{
private:
    void *m_ptr;

public:
    GCBombTarget() {}
    GCBombTarget(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnBombExplode() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBombTarget", "m_OnBombExplode"); }
    void SetOnBombExplode(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombExplode", false, value); }
    GCEntityIOOutput GetOnBombPlanted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBombTarget", "m_OnBombPlanted"); }
    void SetOnBombPlanted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombPlanted", false, value); }
    GCEntityIOOutput GetOnBombDefused() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBombTarget", "m_OnBombDefused"); }
    void SetOnBombDefused(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBombTarget", "m_OnBombDefused", false, value); }
    bool GetIsBombSiteB() const { return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bIsBombSiteB"); }
    void SetIsBombSiteB(bool value) { SetSchemaValue(m_ptr, "CBombTarget", "m_bIsBombSiteB", false, value); }
    bool GetIsHeistBombTarget() const { return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bIsHeistBombTarget"); }
    void SetIsHeistBombTarget(bool value) { SetSchemaValue(m_ptr, "CBombTarget", "m_bIsHeistBombTarget", false, value); }
    bool GetBombPlantedHere() const { return GetSchemaValue<bool>(m_ptr, "CBombTarget", "m_bBombPlantedHere"); }
    void SetBombPlantedHere(bool value) { SetSchemaValue(m_ptr, "CBombTarget", "m_bBombPlantedHere", false, value); }
    CUtlSymbolLarge GetMountTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBombTarget", "m_szMountTarget"); }
    void SetMountTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBombTarget", "m_szMountTarget", false, value); }
    GCBaseEntity* GetInstructorHint() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBombTarget", "m_hInstructorHint"); }
    void SetInstructorHint(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'InstructorHint' is not possible.\n"); }
    int32_t GetBombSiteDesignation() const { return GetSchemaValue<int32_t>(m_ptr, "CBombTarget", "m_nBombSiteDesignation"); }
    void SetBombSiteDesignation(int32_t value) { SetSchemaValue(m_ptr, "CBombTarget", "m_nBombSiteDesignation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif