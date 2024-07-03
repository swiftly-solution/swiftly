#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMessageEntity::GCMessageEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMessageEntity::GCMessageEntity(void *ptr) {
    m_ptr = ptr;
}
int32_t GCMessageEntity::GetRadius() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMessageEntity", "m_radius");
}
void GCMessageEntity::SetRadius(int32_t value) {
    SetSchemaValue(m_ptr, "CMessageEntity", "m_radius", false, value);
}
std::string GCMessageEntity::GetMessageText() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessageEntity", "m_messageText").String();
}
void GCMessageEntity::SetMessageText(std::string value) {
    SetSchemaValue(m_ptr, "CMessageEntity", "m_messageText", false, CUtlSymbolLarge(value.c_str()));
}
bool GCMessageEntity::GetDrawText() const {
    return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_drawText");
}
void GCMessageEntity::SetDrawText(bool value) {
    SetSchemaValue(m_ptr, "CMessageEntity", "m_drawText", false, value);
}
bool GCMessageEntity::GetDeveloperOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_bDeveloperOnly");
}
void GCMessageEntity::SetDeveloperOnly(bool value) {
    SetSchemaValue(m_ptr, "CMessageEntity", "m_bDeveloperOnly", false, value);
}
bool GCMessageEntity::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_bEnabled");
}
void GCMessageEntity::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CMessageEntity", "m_bEnabled", false, value);
}
std::string GCMessageEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMessageEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCMessageEntity::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCMessageEntity::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMessageEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMessageEntity>("CMessageEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCMessageEntity::GetRadius, &GCMessageEntity::SetRadius)
        .addProperty("MessageText", &GCMessageEntity::GetMessageText, &GCMessageEntity::SetMessageText)
        .addProperty("DrawText", &GCMessageEntity::GetDrawText, &GCMessageEntity::SetDrawText)
        .addProperty("DeveloperOnly", &GCMessageEntity::GetDeveloperOnly, &GCMessageEntity::SetDeveloperOnly)
        .addProperty("Enabled", &GCMessageEntity::GetEnabled, &GCMessageEntity::SetEnabled)
        .addProperty("Parent", &GCMessageEntity::GetParent, &GCMessageEntity::SetParent)
        .addFunction("ToPtr", &GCMessageEntity::ToPtr)
        .addFunction("IsValid", &GCMessageEntity::IsValid)
        .endClass();
}