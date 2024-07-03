#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointClientUIWorldTextPanel::GCPointClientUIWorldTextPanel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointClientUIWorldTextPanel::GCPointClientUIWorldTextPanel(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointClientUIWorldTextPanel::GetMessageText() const {
    return GetSchemaValuePtr<char>(m_ptr, "CPointClientUIWorldTextPanel", "m_messageText");
}
void GCPointClientUIWorldTextPanel::SetMessageText(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CPointClientUIWorldTextPanel", "m_messageText", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCPointClientUIWorldTextPanel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointClientUIWorldTextPanel::IsValid() {
    return (m_ptr != nullptr);
}
GCPointClientUIWorldPanel GCPointClientUIWorldTextPanel::GetParent() const {
    GCPointClientUIWorldPanel value(m_ptr);
    return value;
}
void GCPointClientUIWorldTextPanel::SetParent(GCPointClientUIWorldPanel value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointClientUIWorldTextPanel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIWorldTextPanel>("CPointClientUIWorldTextPanel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MessageText", &GCPointClientUIWorldTextPanel::GetMessageText, &GCPointClientUIWorldTextPanel::SetMessageText)
        .addProperty("Parent", &GCPointClientUIWorldTextPanel::GetParent, &GCPointClientUIWorldTextPanel::SetParent)
        .addFunction("ToPtr", &GCPointClientUIWorldTextPanel::ToPtr)
        .addFunction("IsValid", &GCPointClientUIWorldTextPanel::IsValid)
        .endClass();
}