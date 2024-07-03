#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_Command::GCModelConfigElement_Command(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_Command::GCModelConfigElement_Command(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_Command::GetCommand() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_Command", "m_Command").Get();
}
void GCModelConfigElement_Command::SetCommand(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_Command", "m_Command", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_Command::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_Command::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_Command::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_Command::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_Command(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_Command>("CModelConfigElement_Command")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Command", &GCModelConfigElement_Command::GetCommand, &GCModelConfigElement_Command::SetCommand)
        .addProperty("Parent", &GCModelConfigElement_Command::GetParent, &GCModelConfigElement_Command::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_Command::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_Command::IsValid)
        .endClass();
}