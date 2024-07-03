#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointBroadcastClientCommand::GCPointBroadcastClientCommand(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointBroadcastClientCommand::GCPointBroadcastClientCommand(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointBroadcastClientCommand::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointBroadcastClientCommand::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointBroadcastClientCommand::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointBroadcastClientCommand::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointBroadcastClientCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointBroadcastClientCommand>("CPointBroadcastClientCommand")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPointBroadcastClientCommand::GetParent, &GCPointBroadcastClientCommand::SetParent)
        .addFunction("ToPtr", &GCPointBroadcastClientCommand::ToPtr)
        .addFunction("IsValid", &GCPointBroadcastClientCommand::IsValid)
        .endClass();
}