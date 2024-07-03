#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicAuto::GCLogicAuto(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicAuto::GCLogicAuto(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCLogicAuto::GetOnMapSpawn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnMapSpawn"));
    return value;
}
void GCLogicAuto::SetOnMapSpawn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMapSpawn", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnDemoMapSpawn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnDemoMapSpawn"));
    return value;
}
void GCLogicAuto::SetOnDemoMapSpawn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnDemoMapSpawn", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnNewGame() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnNewGame"));
    return value;
}
void GCLogicAuto::SetOnNewGame(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnNewGame", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnLoadGame() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnLoadGame"));
    return value;
}
void GCLogicAuto::SetOnLoadGame(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnLoadGame", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnMapTransition() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnMapTransition"));
    return value;
}
void GCLogicAuto::SetOnMapTransition(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMapTransition", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnBackgroundMap() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnBackgroundMap"));
    return value;
}
void GCLogicAuto::SetOnBackgroundMap(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnBackgroundMap", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnMultiNewMap() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnMultiNewMap"));
    return value;
}
void GCLogicAuto::SetOnMultiNewMap(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMultiNewMap", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnMultiNewRound() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnMultiNewRound"));
    return value;
}
void GCLogicAuto::SetOnMultiNewRound(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnMultiNewRound", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnVREnabled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnVREnabled"));
    return value;
}
void GCLogicAuto::SetOnVREnabled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnVREnabled", false, value);
}
GCEntityIOOutput GCLogicAuto::GetOnVRNotEnabled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAuto", "m_OnVRNotEnabled"));
    return value;
}
void GCLogicAuto::SetOnVRNotEnabled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_OnVRNotEnabled", false, value);
}
std::string GCLogicAuto::GetGlobalstate() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicAuto", "m_globalstate").String();
}
void GCLogicAuto::SetGlobalstate(std::string value) {
    SetSchemaValue(m_ptr, "CLogicAuto", "m_globalstate", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicAuto::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicAuto::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCLogicAuto::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCLogicAuto::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAuto>("CLogicAuto")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnMapSpawn", &GCLogicAuto::GetOnMapSpawn, &GCLogicAuto::SetOnMapSpawn)
        .addProperty("OnDemoMapSpawn", &GCLogicAuto::GetOnDemoMapSpawn, &GCLogicAuto::SetOnDemoMapSpawn)
        .addProperty("OnNewGame", &GCLogicAuto::GetOnNewGame, &GCLogicAuto::SetOnNewGame)
        .addProperty("OnLoadGame", &GCLogicAuto::GetOnLoadGame, &GCLogicAuto::SetOnLoadGame)
        .addProperty("OnMapTransition", &GCLogicAuto::GetOnMapTransition, &GCLogicAuto::SetOnMapTransition)
        .addProperty("OnBackgroundMap", &GCLogicAuto::GetOnBackgroundMap, &GCLogicAuto::SetOnBackgroundMap)
        .addProperty("OnMultiNewMap", &GCLogicAuto::GetOnMultiNewMap, &GCLogicAuto::SetOnMultiNewMap)
        .addProperty("OnMultiNewRound", &GCLogicAuto::GetOnMultiNewRound, &GCLogicAuto::SetOnMultiNewRound)
        .addProperty("OnVREnabled", &GCLogicAuto::GetOnVREnabled, &GCLogicAuto::SetOnVREnabled)
        .addProperty("OnVRNotEnabled", &GCLogicAuto::GetOnVRNotEnabled, &GCLogicAuto::SetOnVRNotEnabled)
        .addProperty("Globalstate", &GCLogicAuto::GetGlobalstate, &GCLogicAuto::SetGlobalstate)
        .addProperty("Parent", &GCLogicAuto::GetParent, &GCLogicAuto::SetParent)
        .addFunction("ToPtr", &GCLogicAuto::ToPtr)
        .addFunction("IsValid", &GCLogicAuto::IsValid)
        .endClass();
}