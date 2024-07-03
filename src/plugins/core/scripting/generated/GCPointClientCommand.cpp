#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointClientCommand::GCPointClientCommand(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointClientCommand::GCPointClientCommand(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointClientCommand::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointClientCommand::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointClientCommand::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointClientCommand::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointClientCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientCommand>("CPointClientCommand")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPointClientCommand::GetParent, &GCPointClientCommand::SetParent)
        .addFunction("ToPtr", &GCPointClientCommand::ToPtr)
        .addFunction("IsValid", &GCPointClientCommand::IsValid)
        .endClass();
}