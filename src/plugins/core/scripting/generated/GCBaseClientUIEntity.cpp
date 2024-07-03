#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseClientUIEntity::GCBaseClientUIEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseClientUIEntity::GCBaseClientUIEntity(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseClientUIEntity::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseClientUIEntity", "m_bEnabled");
}
void GCBaseClientUIEntity::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_bEnabled", false, value);
}
std::string GCBaseClientUIEntity::GetDialogXMLName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_DialogXMLName").String();
}
void GCBaseClientUIEntity::SetDialogXMLName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_DialogXMLName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseClientUIEntity::GetPanelClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_PanelClassName").String();
}
void GCBaseClientUIEntity::SetPanelClassName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_PanelClassName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseClientUIEntity::GetPanelID() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseClientUIEntity", "m_PanelID").String();
}
void GCBaseClientUIEntity::SetPanelID(std::string value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_PanelID", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput0() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput0"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput0(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput0", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput1() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput1"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput1(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput1", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput2() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput2"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput2(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput2", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput3() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput3"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput3(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput3", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput4() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput4"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput4(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput4", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput5() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput5"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput5(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput5", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput6() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput6"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput6(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput6", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput7() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput7"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput7(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput7", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput8() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput8"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput8(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput8", false, value);
}
GCEntityIOOutput GCBaseClientUIEntity::GetCustomOutput9() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseClientUIEntity", "m_CustomOutput9"));
    return value;
}
void GCBaseClientUIEntity::SetCustomOutput9(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseClientUIEntity", "m_CustomOutput9", false, value);
}
std::string GCBaseClientUIEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseClientUIEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBaseClientUIEntity::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBaseClientUIEntity::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseClientUIEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseClientUIEntity>("CBaseClientUIEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCBaseClientUIEntity::GetEnabled, &GCBaseClientUIEntity::SetEnabled)
        .addProperty("DialogXMLName", &GCBaseClientUIEntity::GetDialogXMLName, &GCBaseClientUIEntity::SetDialogXMLName)
        .addProperty("PanelClassName", &GCBaseClientUIEntity::GetPanelClassName, &GCBaseClientUIEntity::SetPanelClassName)
        .addProperty("PanelID", &GCBaseClientUIEntity::GetPanelID, &GCBaseClientUIEntity::SetPanelID)
        .addProperty("CustomOutput0", &GCBaseClientUIEntity::GetCustomOutput0, &GCBaseClientUIEntity::SetCustomOutput0)
        .addProperty("CustomOutput1", &GCBaseClientUIEntity::GetCustomOutput1, &GCBaseClientUIEntity::SetCustomOutput1)
        .addProperty("CustomOutput2", &GCBaseClientUIEntity::GetCustomOutput2, &GCBaseClientUIEntity::SetCustomOutput2)
        .addProperty("CustomOutput3", &GCBaseClientUIEntity::GetCustomOutput3, &GCBaseClientUIEntity::SetCustomOutput3)
        .addProperty("CustomOutput4", &GCBaseClientUIEntity::GetCustomOutput4, &GCBaseClientUIEntity::SetCustomOutput4)
        .addProperty("CustomOutput5", &GCBaseClientUIEntity::GetCustomOutput5, &GCBaseClientUIEntity::SetCustomOutput5)
        .addProperty("CustomOutput6", &GCBaseClientUIEntity::GetCustomOutput6, &GCBaseClientUIEntity::SetCustomOutput6)
        .addProperty("CustomOutput7", &GCBaseClientUIEntity::GetCustomOutput7, &GCBaseClientUIEntity::SetCustomOutput7)
        .addProperty("CustomOutput8", &GCBaseClientUIEntity::GetCustomOutput8, &GCBaseClientUIEntity::SetCustomOutput8)
        .addProperty("CustomOutput9", &GCBaseClientUIEntity::GetCustomOutput9, &GCBaseClientUIEntity::SetCustomOutput9)
        .addProperty("Parent", &GCBaseClientUIEntity::GetParent, &GCBaseClientUIEntity::SetParent)
        .addFunction("ToPtr", &GCBaseClientUIEntity::ToPtr)
        .addFunction("IsValid", &GCBaseClientUIEntity::IsValid)
        .endClass();
}