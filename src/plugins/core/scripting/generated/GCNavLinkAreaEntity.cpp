#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavLinkAreaEntity::GCNavLinkAreaEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavLinkAreaEntity::GCNavLinkAreaEntity(void *ptr) {
    m_ptr = ptr;
}
float GCNavLinkAreaEntity::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "CNavLinkAreaEntity", "m_flWidth");
}
void GCNavLinkAreaEntity::SetWidth(float value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_flWidth", false, value);
}
Vector GCNavLinkAreaEntity::GetLocatorOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CNavLinkAreaEntity", "m_vLocatorOffset");
}
void GCNavLinkAreaEntity::SetLocatorOffset(Vector value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_vLocatorOffset", false, value);
}
QAngle GCNavLinkAreaEntity::GetLocatorAnglesOffset() const {
    return GetSchemaValue<QAngle>(m_ptr, "CNavLinkAreaEntity", "m_qLocatorAnglesOffset");
}
void GCNavLinkAreaEntity::SetLocatorAnglesOffset(QAngle value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_qLocatorAnglesOffset", false, value);
}
std::string GCNavLinkAreaEntity::GetStrMovementForward() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strMovementForward").String();
}
void GCNavLinkAreaEntity::SetStrMovementForward(std::string value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strMovementForward", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCNavLinkAreaEntity::GetStrMovementReverse() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strMovementReverse").String();
}
void GCNavLinkAreaEntity::SetStrMovementReverse(std::string value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strMovementReverse", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCNavLinkAreaEntity::GetNavLinkIdForward() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdForward");
}
void GCNavLinkAreaEntity::SetNavLinkIdForward(int32_t value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdForward", false, value);
}
int32_t GCNavLinkAreaEntity::GetNavLinkIdReverse() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdReverse");
}
void GCNavLinkAreaEntity::SetNavLinkIdReverse(int32_t value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdReverse", false, value);
}
bool GCNavLinkAreaEntity::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CNavLinkAreaEntity", "m_bEnabled");
}
void GCNavLinkAreaEntity::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_bEnabled", false, value);
}
std::string GCNavLinkAreaEntity::GetStrFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strFilterName").String();
}
void GCNavLinkAreaEntity::SetStrFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCNavLinkAreaEntity::GetFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CNavLinkAreaEntity", "m_hFilter"));
    return value;
}
void GCNavLinkAreaEntity::SetFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
GCEntityIOOutput GCNavLinkAreaEntity::GetOnNavLinkStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkStart"));
    return value;
}
void GCNavLinkAreaEntity::SetOnNavLinkStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkStart", false, value);
}
GCEntityIOOutput GCNavLinkAreaEntity::GetOnNavLinkFinish() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkFinish"));
    return value;
}
void GCNavLinkAreaEntity::SetOnNavLinkFinish(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkFinish", false, value);
}
bool GCNavLinkAreaEntity::GetIsTerminus() const {
    return GetSchemaValue<bool>(m_ptr, "CNavLinkAreaEntity", "m_bIsTerminus");
}
void GCNavLinkAreaEntity::SetIsTerminus(bool value) {
    SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_bIsTerminus", false, value);
}
std::string GCNavLinkAreaEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavLinkAreaEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCNavLinkAreaEntity::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCNavLinkAreaEntity::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavLinkAreaEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkAreaEntity>("CNavLinkAreaEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Width", &GCNavLinkAreaEntity::GetWidth, &GCNavLinkAreaEntity::SetWidth)
        .addProperty("LocatorOffset", &GCNavLinkAreaEntity::GetLocatorOffset, &GCNavLinkAreaEntity::SetLocatorOffset)
        .addProperty("LocatorAnglesOffset", &GCNavLinkAreaEntity::GetLocatorAnglesOffset, &GCNavLinkAreaEntity::SetLocatorAnglesOffset)
        .addProperty("StrMovementForward", &GCNavLinkAreaEntity::GetStrMovementForward, &GCNavLinkAreaEntity::SetStrMovementForward)
        .addProperty("StrMovementReverse", &GCNavLinkAreaEntity::GetStrMovementReverse, &GCNavLinkAreaEntity::SetStrMovementReverse)
        .addProperty("NavLinkIdForward", &GCNavLinkAreaEntity::GetNavLinkIdForward, &GCNavLinkAreaEntity::SetNavLinkIdForward)
        .addProperty("NavLinkIdReverse", &GCNavLinkAreaEntity::GetNavLinkIdReverse, &GCNavLinkAreaEntity::SetNavLinkIdReverse)
        .addProperty("Enabled", &GCNavLinkAreaEntity::GetEnabled, &GCNavLinkAreaEntity::SetEnabled)
        .addProperty("StrFilterName", &GCNavLinkAreaEntity::GetStrFilterName, &GCNavLinkAreaEntity::SetStrFilterName)
        .addProperty("Filter", &GCNavLinkAreaEntity::GetFilter, &GCNavLinkAreaEntity::SetFilter)
        .addProperty("OnNavLinkStart", &GCNavLinkAreaEntity::GetOnNavLinkStart, &GCNavLinkAreaEntity::SetOnNavLinkStart)
        .addProperty("OnNavLinkFinish", &GCNavLinkAreaEntity::GetOnNavLinkFinish, &GCNavLinkAreaEntity::SetOnNavLinkFinish)
        .addProperty("IsTerminus", &GCNavLinkAreaEntity::GetIsTerminus, &GCNavLinkAreaEntity::SetIsTerminus)
        .addProperty("Parent", &GCNavLinkAreaEntity::GetParent, &GCNavLinkAreaEntity::SetParent)
        .addFunction("ToPtr", &GCNavLinkAreaEntity::ToPtr)
        .addFunction("IsValid", &GCNavLinkAreaEntity::IsValid)
        .endClass();
}