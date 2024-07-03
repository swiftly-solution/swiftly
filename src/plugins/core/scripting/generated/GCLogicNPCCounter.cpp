#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicNPCCounter::GCLogicNPCCounter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicNPCCounter::GCLogicNPCCounter(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMinCountAll() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMinCountAll"));
    return value;
}
void GCLogicNPCCounter::SetOnMinCountAll(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCountAll", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMaxCountAll() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMaxCountAll"));
    return value;
}
void GCLogicNPCCounter::SetOnMaxCountAll(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCountAll", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMinCount_1() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMinCount_1"));
    return value;
}
void GCLogicNPCCounter::SetOnMinCount_1(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_1", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMaxCount_1() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_1"));
    return value;
}
void GCLogicNPCCounter::SetOnMaxCount_1(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_1", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMinCount_2() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMinCount_2"));
    return value;
}
void GCLogicNPCCounter::SetOnMinCount_2(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_2", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMaxCount_2() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_2"));
    return value;
}
void GCLogicNPCCounter::SetOnMaxCount_2(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_2", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMinCount_3() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMinCount_3"));
    return value;
}
void GCLogicNPCCounter::SetOnMinCount_3(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMinCount_3", false, value);
}
GCEntityIOOutput GCLogicNPCCounter::GetOnMaxCount_3() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_3"));
    return value;
}
void GCLogicNPCCounter::SetOnMaxCount_3(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_OnMaxCount_3", false, value);
}
GCEntityInstance GCLogicNPCCounter::GetSource() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicNPCCounter", "m_hSource"));
    return value;
}
void GCLogicNPCCounter::SetSource(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n");
}
std::string GCLogicNPCCounter::GetSourceEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszSourceEntityName").String();
}
void GCLogicNPCCounter::SetSourceEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszSourceEntityName", false, CUtlSymbolLarge(value.c_str()));
}
float GCLogicNPCCounter::GetDistanceMax() const {
    return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDistanceMax");
}
void GCLogicNPCCounter::SetDistanceMax(float value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDistanceMax", false, value);
}
bool GCLogicNPCCounter::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bDisabled");
}
void GCLogicNPCCounter::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bDisabled", false, value);
}
int32_t GCLogicNPCCounter::GetMinCountAll() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCountAll");
}
void GCLogicNPCCounter::SetMinCountAll(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCountAll", false, value);
}
int32_t GCLogicNPCCounter::GetMaxCountAll() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCountAll");
}
void GCLogicNPCCounter::SetMaxCountAll(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCountAll", false, value);
}
int32_t GCLogicNPCCounter::GetMinFactorAll() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactorAll");
}
void GCLogicNPCCounter::SetMinFactorAll(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactorAll", false, value);
}
int32_t GCLogicNPCCounter::GetMaxFactorAll() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactorAll");
}
void GCLogicNPCCounter::SetMaxFactorAll(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactorAll", false, value);
}
std::string GCLogicNPCCounter::GetNPCClassname_1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_1").String();
}
void GCLogicNPCCounter::SetNPCClassname_1(std::string value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_1", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCLogicNPCCounter::GetNPCState_1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_1");
}
void GCLogicNPCCounter::SetNPCState_1(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_1", false, value);
}
bool GCLogicNPCCounter::GetInvertState_1() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_1");
}
void GCLogicNPCCounter::SetInvertState_1(bool value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_1", false, value);
}
int32_t GCLogicNPCCounter::GetMinCount_1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_1");
}
void GCLogicNPCCounter::SetMinCount_1(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_1", false, value);
}
int32_t GCLogicNPCCounter::GetMaxCount_1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_1");
}
void GCLogicNPCCounter::SetMaxCount_1(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_1", false, value);
}
int32_t GCLogicNPCCounter::GetMinFactor_1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_1");
}
void GCLogicNPCCounter::SetMinFactor_1(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_1", false, value);
}
int32_t GCLogicNPCCounter::GetMaxFactor_1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_1");
}
void GCLogicNPCCounter::SetMaxFactor_1(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_1", false, value);
}
float GCLogicNPCCounter::GetDefaultDist_1() const {
    return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_1");
}
void GCLogicNPCCounter::SetDefaultDist_1(float value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_1", false, value);
}
std::string GCLogicNPCCounter::GetNPCClassname_2() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_2").String();
}
void GCLogicNPCCounter::SetNPCClassname_2(std::string value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_2", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCLogicNPCCounter::GetNPCState_2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_2");
}
void GCLogicNPCCounter::SetNPCState_2(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_2", false, value);
}
bool GCLogicNPCCounter::GetInvertState_2() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_2");
}
void GCLogicNPCCounter::SetInvertState_2(bool value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_2", false, value);
}
int32_t GCLogicNPCCounter::GetMinCount_2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_2");
}
void GCLogicNPCCounter::SetMinCount_2(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_2", false, value);
}
int32_t GCLogicNPCCounter::GetMaxCount_2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_2");
}
void GCLogicNPCCounter::SetMaxCount_2(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_2", false, value);
}
int32_t GCLogicNPCCounter::GetMinFactor_2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_2");
}
void GCLogicNPCCounter::SetMinFactor_2(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_2", false, value);
}
int32_t GCLogicNPCCounter::GetMaxFactor_2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_2");
}
void GCLogicNPCCounter::SetMaxFactor_2(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_2", false, value);
}
float GCLogicNPCCounter::GetDefaultDist_2() const {
    return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_2");
}
void GCLogicNPCCounter::SetDefaultDist_2(float value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_2", false, value);
}
std::string GCLogicNPCCounter::GetNPCClassname_3() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_3").String();
}
void GCLogicNPCCounter::SetNPCClassname_3(std::string value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_iszNPCClassname_3", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCLogicNPCCounter::GetNPCState_3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nNPCState_3");
}
void GCLogicNPCCounter::SetNPCState_3(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nNPCState_3", false, value);
}
bool GCLogicNPCCounter::GetInvertState_3() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicNPCCounter", "m_bInvertState_3");
}
void GCLogicNPCCounter::SetInvertState_3(bool value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_bInvertState_3", false, value);
}
int32_t GCLogicNPCCounter::GetMinCount_3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinCount_3");
}
void GCLogicNPCCounter::SetMinCount_3(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinCount_3", false, value);
}
int32_t GCLogicNPCCounter::GetMaxCount_3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxCount_3");
}
void GCLogicNPCCounter::SetMaxCount_3(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxCount_3", false, value);
}
int32_t GCLogicNPCCounter::GetMinFactor_3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMinFactor_3");
}
void GCLogicNPCCounter::SetMinFactor_3(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMinFactor_3", false, value);
}
int32_t GCLogicNPCCounter::GetMaxFactor_3() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_3");
}
void GCLogicNPCCounter::SetMaxFactor_3(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_nMaxFactor_3", false, value);
}
float GCLogicNPCCounter::GetDefaultDist_3() const {
    return GetSchemaValue<float>(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_3");
}
void GCLogicNPCCounter::SetDefaultDist_3(float value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounter", "m_flDefaultDist_3", false, value);
}
std::string GCLogicNPCCounter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicNPCCounter::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCLogicNPCCounter::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCLogicNPCCounter::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicNPCCounter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNPCCounter>("CLogicNPCCounter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnMinCountAll", &GCLogicNPCCounter::GetOnMinCountAll, &GCLogicNPCCounter::SetOnMinCountAll)
        .addProperty("OnMaxCountAll", &GCLogicNPCCounter::GetOnMaxCountAll, &GCLogicNPCCounter::SetOnMaxCountAll)
        .addProperty("OnMinCount_1", &GCLogicNPCCounter::GetOnMinCount_1, &GCLogicNPCCounter::SetOnMinCount_1)
        .addProperty("OnMaxCount_1", &GCLogicNPCCounter::GetOnMaxCount_1, &GCLogicNPCCounter::SetOnMaxCount_1)
        .addProperty("OnMinCount_2", &GCLogicNPCCounter::GetOnMinCount_2, &GCLogicNPCCounter::SetOnMinCount_2)
        .addProperty("OnMaxCount_2", &GCLogicNPCCounter::GetOnMaxCount_2, &GCLogicNPCCounter::SetOnMaxCount_2)
        .addProperty("OnMinCount_3", &GCLogicNPCCounter::GetOnMinCount_3, &GCLogicNPCCounter::SetOnMinCount_3)
        .addProperty("OnMaxCount_3", &GCLogicNPCCounter::GetOnMaxCount_3, &GCLogicNPCCounter::SetOnMaxCount_3)
        .addProperty("Source", &GCLogicNPCCounter::GetSource, &GCLogicNPCCounter::SetSource)
        .addProperty("SourceEntityName", &GCLogicNPCCounter::GetSourceEntityName, &GCLogicNPCCounter::SetSourceEntityName)
        .addProperty("DistanceMax", &GCLogicNPCCounter::GetDistanceMax, &GCLogicNPCCounter::SetDistanceMax)
        .addProperty("Disabled", &GCLogicNPCCounter::GetDisabled, &GCLogicNPCCounter::SetDisabled)
        .addProperty("MinCountAll", &GCLogicNPCCounter::GetMinCountAll, &GCLogicNPCCounter::SetMinCountAll)
        .addProperty("MaxCountAll", &GCLogicNPCCounter::GetMaxCountAll, &GCLogicNPCCounter::SetMaxCountAll)
        .addProperty("MinFactorAll", &GCLogicNPCCounter::GetMinFactorAll, &GCLogicNPCCounter::SetMinFactorAll)
        .addProperty("MaxFactorAll", &GCLogicNPCCounter::GetMaxFactorAll, &GCLogicNPCCounter::SetMaxFactorAll)
        .addProperty("NPCClassname_1", &GCLogicNPCCounter::GetNPCClassname_1, &GCLogicNPCCounter::SetNPCClassname_1)
        .addProperty("NPCState_1", &GCLogicNPCCounter::GetNPCState_1, &GCLogicNPCCounter::SetNPCState_1)
        .addProperty("InvertState_1", &GCLogicNPCCounter::GetInvertState_1, &GCLogicNPCCounter::SetInvertState_1)
        .addProperty("MinCount_1", &GCLogicNPCCounter::GetMinCount_1, &GCLogicNPCCounter::SetMinCount_1)
        .addProperty("MaxCount_1", &GCLogicNPCCounter::GetMaxCount_1, &GCLogicNPCCounter::SetMaxCount_1)
        .addProperty("MinFactor_1", &GCLogicNPCCounter::GetMinFactor_1, &GCLogicNPCCounter::SetMinFactor_1)
        .addProperty("MaxFactor_1", &GCLogicNPCCounter::GetMaxFactor_1, &GCLogicNPCCounter::SetMaxFactor_1)
        .addProperty("DefaultDist_1", &GCLogicNPCCounter::GetDefaultDist_1, &GCLogicNPCCounter::SetDefaultDist_1)
        .addProperty("NPCClassname_2", &GCLogicNPCCounter::GetNPCClassname_2, &GCLogicNPCCounter::SetNPCClassname_2)
        .addProperty("NPCState_2", &GCLogicNPCCounter::GetNPCState_2, &GCLogicNPCCounter::SetNPCState_2)
        .addProperty("InvertState_2", &GCLogicNPCCounter::GetInvertState_2, &GCLogicNPCCounter::SetInvertState_2)
        .addProperty("MinCount_2", &GCLogicNPCCounter::GetMinCount_2, &GCLogicNPCCounter::SetMinCount_2)
        .addProperty("MaxCount_2", &GCLogicNPCCounter::GetMaxCount_2, &GCLogicNPCCounter::SetMaxCount_2)
        .addProperty("MinFactor_2", &GCLogicNPCCounter::GetMinFactor_2, &GCLogicNPCCounter::SetMinFactor_2)
        .addProperty("MaxFactor_2", &GCLogicNPCCounter::GetMaxFactor_2, &GCLogicNPCCounter::SetMaxFactor_2)
        .addProperty("DefaultDist_2", &GCLogicNPCCounter::GetDefaultDist_2, &GCLogicNPCCounter::SetDefaultDist_2)
        .addProperty("NPCClassname_3", &GCLogicNPCCounter::GetNPCClassname_3, &GCLogicNPCCounter::SetNPCClassname_3)
        .addProperty("NPCState_3", &GCLogicNPCCounter::GetNPCState_3, &GCLogicNPCCounter::SetNPCState_3)
        .addProperty("InvertState_3", &GCLogicNPCCounter::GetInvertState_3, &GCLogicNPCCounter::SetInvertState_3)
        .addProperty("MinCount_3", &GCLogicNPCCounter::GetMinCount_3, &GCLogicNPCCounter::SetMinCount_3)
        .addProperty("MaxCount_3", &GCLogicNPCCounter::GetMaxCount_3, &GCLogicNPCCounter::SetMaxCount_3)
        .addProperty("MinFactor_3", &GCLogicNPCCounter::GetMinFactor_3, &GCLogicNPCCounter::SetMinFactor_3)
        .addProperty("MaxFactor_3", &GCLogicNPCCounter::GetMaxFactor_3, &GCLogicNPCCounter::SetMaxFactor_3)
        .addProperty("DefaultDist_3", &GCLogicNPCCounter::GetDefaultDist_3, &GCLogicNPCCounter::SetDefaultDist_3)
        .addProperty("Parent", &GCLogicNPCCounter::GetParent, &GCLogicNPCCounter::SetParent)
        .addFunction("ToPtr", &GCLogicNPCCounter::ToPtr)
        .addFunction("IsValid", &GCLogicNPCCounter::IsValid)
        .endClass();
}