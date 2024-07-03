#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoTeleportDestination::GCInfoTeleportDestination(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoTeleportDestination::GCInfoTeleportDestination(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoTeleportDestination::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoTeleportDestination::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoTeleportDestination::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoTeleportDestination::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoTeleportDestination(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTeleportDestination>("CInfoTeleportDestination")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoTeleportDestination::GetParent, &GCInfoTeleportDestination::SetParent)
        .addFunction("ToPtr", &GCInfoTeleportDestination::ToPtr)
        .addFunction("IsValid", &GCInfoTeleportDestination::IsValid)
        .endClass();
}