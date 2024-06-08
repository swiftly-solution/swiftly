class GCLogicAuto;

#ifndef _gcclogicauto_h
#define _gcclogicauto_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicAuto
{
private:
    void *m_ptr;

public:
    GCLogicAuto() {}
    GCLogicAuto(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnMapSpawn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnMapSpawn"); }
    void SetOnMapSpawn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMapSpawn", false, value); }
    GCEntityIOOutput GetOnDemoMapSpawn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnDemoMapSpawn"); }
    void SetOnDemoMapSpawn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnDemoMapSpawn", false, value); }
    GCEntityIOOutput GetOnNewGame() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnNewGame"); }
    void SetOnNewGame(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnNewGame", false, value); }
    GCEntityIOOutput GetOnLoadGame() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnLoadGame"); }
    void SetOnLoadGame(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnLoadGame", false, value); }
    GCEntityIOOutput GetOnMapTransition() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnMapTransition"); }
    void SetOnMapTransition(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMapTransition", false, value); }
    GCEntityIOOutput GetOnBackgroundMap() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnBackgroundMap"); }
    void SetOnBackgroundMap(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnBackgroundMap", false, value); }
    GCEntityIOOutput GetOnMultiNewMap() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnMultiNewMap"); }
    void SetOnMultiNewMap(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMultiNewMap", false, value); }
    GCEntityIOOutput GetOnMultiNewRound() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnMultiNewRound"); }
    void SetOnMultiNewRound(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMultiNewRound", false, value); }
    GCEntityIOOutput GetOnVREnabled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnVREnabled"); }
    void SetOnVREnabled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnVREnabled", false, value); }
    GCEntityIOOutput GetOnVRNotEnabled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAuto", "m_OnVRNotEnabled"); }
    void SetOnVRNotEnabled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_OnVRNotEnabled", false, value); }
    CUtlSymbolLarge GetGlobalstate() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicAuto", "m_globalstate"); }
    void SetGlobalstate(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicAuto", "m_globalstate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif