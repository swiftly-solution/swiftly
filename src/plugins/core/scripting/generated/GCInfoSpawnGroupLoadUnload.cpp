#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoSpawnGroupLoadUnload::GCInfoSpawnGroupLoadUnload(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoSpawnGroupLoadUnload::GCInfoSpawnGroupLoadUnload(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadStarted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadStarted"));
    return value;
}
void GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadStarted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadStarted", false, value);
}
GCEntityIOOutput GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadFinished() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadFinished"));
    return value;
}
void GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadFinished(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupLoadFinished", false, value);
}
GCEntityIOOutput GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadStarted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadStarted"));
    return value;
}
void GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadStarted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadStarted", false, value);
}
GCEntityIOOutput GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadFinished() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadFinished"));
    return value;
}
void GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadFinished(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_OnSpawnGroupUnloadFinished", false, value);
}
std::string GCInfoSpawnGroupLoadUnload::GetSpawnGroupName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupName").String();
}
void GCInfoSpawnGroupLoadUnload::SetSpawnGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoSpawnGroupLoadUnload::GetSpawnGroupFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupFilterName").String();
}
void GCInfoSpawnGroupLoadUnload::SetSpawnGroupFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszSpawnGroupFilterName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoSpawnGroupLoadUnload::GetLandmarkName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszLandmarkName").String();
}
void GCInfoSpawnGroupLoadUnload::SetLandmarkName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_iszLandmarkName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoSpawnGroupLoadUnload::GetFixedSpawnGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_sFixedSpawnGroupName").Get();
}
void GCInfoSpawnGroupLoadUnload::SetFixedSpawnGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_sFixedSpawnGroupName", false, CUtlString(value.c_str()));
}
float GCInfoSpawnGroupLoadUnload::GetTimeoutInterval() const {
    return GetSchemaValue<float>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_flTimeoutInterval");
}
void GCInfoSpawnGroupLoadUnload::SetTimeoutInterval(float value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_flTimeoutInterval", false, value);
}
bool GCInfoSpawnGroupLoadUnload::GetStreamingStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bStreamingStarted");
}
void GCInfoSpawnGroupLoadUnload::SetStreamingStarted(bool value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bStreamingStarted", false, value);
}
bool GCInfoSpawnGroupLoadUnload::GetUnloadingStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bUnloadingStarted");
}
void GCInfoSpawnGroupLoadUnload::SetUnloadingStarted(bool value) {
    SetSchemaValue(m_ptr, "CInfoSpawnGroupLoadUnload", "m_bUnloadingStarted", false, value);
}
std::string GCInfoSpawnGroupLoadUnload::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoSpawnGroupLoadUnload::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCInfoSpawnGroupLoadUnload::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCInfoSpawnGroupLoadUnload::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoSpawnGroupLoadUnload(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoSpawnGroupLoadUnload>("CInfoSpawnGroupLoadUnload")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnSpawnGroupLoadStarted", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadStarted, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadStarted)
        .addProperty("OnSpawnGroupLoadFinished", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadFinished, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadFinished)
        .addProperty("OnSpawnGroupUnloadStarted", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadStarted, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadStarted)
        .addProperty("OnSpawnGroupUnloadFinished", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadFinished, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadFinished)
        .addProperty("SpawnGroupName", &GCInfoSpawnGroupLoadUnload::GetSpawnGroupName, &GCInfoSpawnGroupLoadUnload::SetSpawnGroupName)
        .addProperty("SpawnGroupFilterName", &GCInfoSpawnGroupLoadUnload::GetSpawnGroupFilterName, &GCInfoSpawnGroupLoadUnload::SetSpawnGroupFilterName)
        .addProperty("LandmarkName", &GCInfoSpawnGroupLoadUnload::GetLandmarkName, &GCInfoSpawnGroupLoadUnload::SetLandmarkName)
        .addProperty("FixedSpawnGroupName", &GCInfoSpawnGroupLoadUnload::GetFixedSpawnGroupName, &GCInfoSpawnGroupLoadUnload::SetFixedSpawnGroupName)
        .addProperty("TimeoutInterval", &GCInfoSpawnGroupLoadUnload::GetTimeoutInterval, &GCInfoSpawnGroupLoadUnload::SetTimeoutInterval)
        .addProperty("StreamingStarted", &GCInfoSpawnGroupLoadUnload::GetStreamingStarted, &GCInfoSpawnGroupLoadUnload::SetStreamingStarted)
        .addProperty("UnloadingStarted", &GCInfoSpawnGroupLoadUnload::GetUnloadingStarted, &GCInfoSpawnGroupLoadUnload::SetUnloadingStarted)
        .addProperty("Parent", &GCInfoSpawnGroupLoadUnload::GetParent, &GCInfoSpawnGroupLoadUnload::SetParent)
        .addFunction("ToPtr", &GCInfoSpawnGroupLoadUnload::ToPtr)
        .addFunction("IsValid", &GCInfoSpawnGroupLoadUnload::IsValid)
        .endClass();
}