class GCLogicNPCCounter;

#ifndef _gcclogicnpccounter_h
#define _gcclogicnpccounter_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCEntityInstance.h"

class GCLogicNPCCounter
{
private:
    void *m_ptr;

public:
    GCLogicNPCCounter() {}
    GCLogicNPCCounter(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnMinCountAll() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMinCountAll"); }
    void SetOnMinCountAll(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCountAll", false, value); }
    GCEntityIOOutput GetOnMaxCountAll() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMaxCountAll"); }
    void SetOnMaxCountAll(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCountAll", false, value); }
    GCEntityIOOutput GetOnMinCount_1() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMinCount_1"); }
    void SetOnMinCount_1(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_1", false, value); }
    GCEntityIOOutput GetOnMaxCount_1() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_1"); }
    void SetOnMaxCount_1(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_1", false, value); }
    GCEntityIOOutput GetOnMinCount_2() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMinCount_2"); }
    void SetOnMinCount_2(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_2", false, value); }
    GCEntityIOOutput GetOnMaxCount_2() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_2"); }
    void SetOnMaxCount_2(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_2", false, value); }
    GCEntityIOOutput GetOnMinCount_3() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMinCount_3"); }
    void SetOnMinCount_3(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_3", false, value); }
    GCEntityIOOutput GetOnMaxCount_3() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_3"); }
    void SetOnMaxCount_3(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_3", false, value); }
    GCEntityInstance* GetSource() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CLogicNPCCounter", "m_hSource"); }
    void SetSource(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n"); }
    CUtlSymbolLarge GetSourceEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszSourceEntityName"); }
    void SetSourceEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszSourceEntityName", false, value); }
    float GetDistanceMax() const { return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDistanceMax"); }
    void SetDistanceMax(float value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDistanceMax", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bDisabled", false, value); }
    int32_t GetMinCountAll() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCountAll"); }
    void SetMinCountAll(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCountAll", false, value); }
    int32_t GetMaxCountAll() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCountAll"); }
    void SetMaxCountAll(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCountAll", false, value); }
    int32_t GetMinFactorAll() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactorAll"); }
    void SetMinFactorAll(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactorAll", false, value); }
    int32_t GetMaxFactorAll() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactorAll"); }
    void SetMaxFactorAll(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactorAll", false, value); }
    CUtlSymbolLarge GetNPCClassname_1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_1"); }
    void SetNPCClassname_1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_1", false, value); }
    int32_t GetNPCState_1() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_1"); }
    void SetNPCState_1(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_1", false, value); }
    bool GetInvertState_1() const { return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_1"); }
    void SetInvertState_1(bool value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_1", false, value); }
    int32_t GetMinCount_1() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_1"); }
    void SetMinCount_1(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_1", false, value); }
    int32_t GetMaxCount_1() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_1"); }
    void SetMaxCount_1(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_1", false, value); }
    int32_t GetMinFactor_1() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_1"); }
    void SetMinFactor_1(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_1", false, value); }
    int32_t GetMaxFactor_1() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_1"); }
    void SetMaxFactor_1(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_1", false, value); }
    float GetDefaultDist_1() const { return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_1"); }
    void SetDefaultDist_1(float value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_1", false, value); }
    CUtlSymbolLarge GetNPCClassname_2() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_2"); }
    void SetNPCClassname_2(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_2", false, value); }
    int32_t GetNPCState_2() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_2"); }
    void SetNPCState_2(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_2", false, value); }
    bool GetInvertState_2() const { return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_2"); }
    void SetInvertState_2(bool value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_2", false, value); }
    int32_t GetMinCount_2() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_2"); }
    void SetMinCount_2(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_2", false, value); }
    int32_t GetMaxCount_2() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_2"); }
    void SetMaxCount_2(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_2", false, value); }
    int32_t GetMinFactor_2() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_2"); }
    void SetMinFactor_2(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_2", false, value); }
    int32_t GetMaxFactor_2() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_2"); }
    void SetMaxFactor_2(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_2", false, value); }
    float GetDefaultDist_2() const { return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_2"); }
    void SetDefaultDist_2(float value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_2", false, value); }
    CUtlSymbolLarge GetNPCClassname_3() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_3"); }
    void SetNPCClassname_3(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_3", false, value); }
    int32_t GetNPCState_3() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_3"); }
    void SetNPCState_3(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_3", false, value); }
    bool GetInvertState_3() const { return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_3"); }
    void SetInvertState_3(bool value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_3", false, value); }
    int32_t GetMinCount_3() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_3"); }
    void SetMinCount_3(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_3", false, value); }
    int32_t GetMaxCount_3() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_3"); }
    void SetMaxCount_3(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_3", false, value); }
    int32_t GetMinFactor_3() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_3"); }
    void SetMinFactor_3(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_3", false, value); }
    int32_t GetMaxFactor_3() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_3"); }
    void SetMaxFactor_3(int32_t value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_3", false, value); }
    float GetDefaultDist_3() const { return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_3"); }
    void SetDefaultDist_3(float value) { SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_3", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif