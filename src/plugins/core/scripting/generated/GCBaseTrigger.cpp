#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseTrigger::GCBaseTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseTrigger::GCBaseTrigger(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseTrigger::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseTrigger", "m_bDisabled");
}
void GCBaseTrigger::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_bDisabled", false, value);
}
std::string GCBaseTrigger::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseTrigger", "m_iFilterName").String();
}
void GCBaseTrigger::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_iFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCBaseTrigger::GetFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseTrigger", "m_hFilter"));
    return value;
}
void GCBaseTrigger::SetFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
GCEntityIOOutput GCBaseTrigger::GetOnStartTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnStartTouch"));
    return value;
}
void GCBaseTrigger::SetOnStartTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnStartTouch", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnStartTouchAll() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnStartTouchAll"));
    return value;
}
void GCBaseTrigger::SetOnStartTouchAll(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnStartTouchAll", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnEndTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnEndTouch"));
    return value;
}
void GCBaseTrigger::SetOnEndTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnEndTouch", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnEndTouchAll() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnEndTouchAll"));
    return value;
}
void GCBaseTrigger::SetOnEndTouchAll(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnEndTouchAll", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnTouching() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnTouching"));
    return value;
}
void GCBaseTrigger::SetOnTouching(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnTouching", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnTouchingEachEntity() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnTouchingEachEntity"));
    return value;
}
void GCBaseTrigger::SetOnTouchingEachEntity(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnTouchingEachEntity", false, value);
}
GCEntityIOOutput GCBaseTrigger::GetOnNotTouching() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseTrigger", "m_OnNotTouching"));
    return value;
}
void GCBaseTrigger::SetOnNotTouching(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_OnNotTouching", false, value);
}
bool GCBaseTrigger::GetClientSidePredicted() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseTrigger", "m_bClientSidePredicted");
}
void GCBaseTrigger::SetClientSidePredicted(bool value) {
    SetSchemaValue(m_ptr, "CBaseTrigger", "m_bClientSidePredicted", false, value);
}
std::string GCBaseTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseTrigger::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCBaseTrigger::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCBaseTrigger::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseTrigger>("CBaseTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCBaseTrigger::GetDisabled, &GCBaseTrigger::SetDisabled)
        .addProperty("FilterName", &GCBaseTrigger::GetFilterName, &GCBaseTrigger::SetFilterName)
        .addProperty("Filter", &GCBaseTrigger::GetFilter, &GCBaseTrigger::SetFilter)
        .addProperty("OnStartTouch", &GCBaseTrigger::GetOnStartTouch, &GCBaseTrigger::SetOnStartTouch)
        .addProperty("OnStartTouchAll", &GCBaseTrigger::GetOnStartTouchAll, &GCBaseTrigger::SetOnStartTouchAll)
        .addProperty("OnEndTouch", &GCBaseTrigger::GetOnEndTouch, &GCBaseTrigger::SetOnEndTouch)
        .addProperty("OnEndTouchAll", &GCBaseTrigger::GetOnEndTouchAll, &GCBaseTrigger::SetOnEndTouchAll)
        .addProperty("OnTouching", &GCBaseTrigger::GetOnTouching, &GCBaseTrigger::SetOnTouching)
        .addProperty("OnTouchingEachEntity", &GCBaseTrigger::GetOnTouchingEachEntity, &GCBaseTrigger::SetOnTouchingEachEntity)
        .addProperty("OnNotTouching", &GCBaseTrigger::GetOnNotTouching, &GCBaseTrigger::SetOnNotTouching)
        .addProperty("ClientSidePredicted", &GCBaseTrigger::GetClientSidePredicted, &GCBaseTrigger::SetClientSidePredicted)
        .addProperty("Parent", &GCBaseTrigger::GetParent, &GCBaseTrigger::SetParent)
        .addFunction("ToPtr", &GCBaseTrigger::ToPtr)
        .addFunction("IsValid", &GCBaseTrigger::IsValid)
        .endClass();
}