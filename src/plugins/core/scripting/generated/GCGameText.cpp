#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameText::GCGameText(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameText::GCGameText(void *ptr) {
    m_ptr = ptr;
}
std::string GCGameText::GetMessage() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CGameText", "m_iszMessage").String();
}
void GCGameText::SetMessage(std::string value) {
    SetSchemaValue(m_ptr, "CGameText", "m_iszMessage", false, CUtlSymbolLarge(value.c_str()));
}
Ghudtextparms_t GCGameText::GetTextParms() const {
    Ghudtextparms_t value(GetSchemaPtr(m_ptr, "CGameText", "m_textParms"));
    return value;
}
void GCGameText::SetTextParms(Ghudtextparms_t value) {
    SetSchemaValue(m_ptr, "CGameText", "m_textParms", false, value);
}
std::string GCGameText::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameText::IsValid() {
    return (m_ptr != nullptr);
}
GCRulePointEntity GCGameText::GetParent() const {
    GCRulePointEntity value(m_ptr);
    return value;
}
void GCGameText::SetParent(GCRulePointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameText>("CGameText")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Message", &GCGameText::GetMessage, &GCGameText::SetMessage)
        .addProperty("TextParms", &GCGameText::GetTextParms, &GCGameText::SetTextParms)
        .addProperty("Parent", &GCGameText::GetParent, &GCGameText::SetParent)
        .addFunction("ToPtr", &GCGameText::ToPtr)
        .addFunction("IsValid", &GCGameText::IsValid)
        .endClass();
}