class GCInfoSpawnGroupLoadUnload;

#ifndef _gccinfospawngrouploadunload_h
#define _gccinfospawngrouploadunload_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCInfoSpawnGroupLoadUnload
{
private:
    void *m_ptr;

public:
    GCInfoSpawnGroupLoadUnload() {}
    GCInfoSpawnGroupLoadUnload(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnSpawnGroupLoadStarted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadStarted"); }
    void SetOnSpawnGroupLoadStarted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadStarted", false, value); }
    GCEntityIOOutput GetOnSpawnGroupLoadFinished() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadFinished"); }
    void SetOnSpawnGroupLoadFinished(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadFinished", false, value); }
    GCEntityIOOutput GetOnSpawnGroupUnloadStarted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadStarted"); }
    void SetOnSpawnGroupUnloadStarted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadStarted", false, value); }
    GCEntityIOOutput GetOnSpawnGroupUnloadFinished() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadFinished"); }
    void SetOnSpawnGroupUnloadFinished(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadFinished", false, value); }
    CUtlSymbolLarge GetSpawnGroupName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupName"); }
    void SetSpawnGroupName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupName", false, value); }
    CUtlSymbolLarge GetSpawnGroupFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupFilterName"); }
    void SetSpawnGroupFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupFilterName", false, value); }
    CUtlSymbolLarge GetLandmarkName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszLandmarkName"); }
    void SetLandmarkName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszLandmarkName", false, value); }
    CUtlString GetFixedSpawnGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_sFixedSpawnGroupName"); }
    void SetFixedSpawnGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_sFixedSpawnGroupName", false, value); }
    float GetTimeoutInterval() const { return GetSchemaValue<float>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_flTimeoutInterval"); }
    void SetTimeoutInterval(float value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_flTimeoutInterval", false, value); }
    bool GetStreamingStarted() const { return GetSchemaValue<bool>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bStreamingStarted"); }
    void SetStreamingStarted(bool value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bStreamingStarted", false, value); }
    bool GetUnloadingStarted() const { return GetSchemaValue<bool>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bUnloadingStarted"); }
    void SetUnloadingStarted(bool value) { SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bUnloadingStarted", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif