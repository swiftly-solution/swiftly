#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointServerCommand::GCPointServerCommand(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointServerCommand::GCPointServerCommand(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointServerCommand::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointServerCommand::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointServerCommand::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointServerCommand::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointServerCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointServerCommand>("CPointServerCommand")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPointServerCommand::GetParent, &GCPointServerCommand::SetParent)
        .addFunction("ToPtr", &GCPointServerCommand::ToPtr)
        .addFunction("IsValid", &GCPointServerCommand::IsValid)
        .endClass();
}