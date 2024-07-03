#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerControllerAPI::GCBasePlayerControllerAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerControllerAPI::GCBasePlayerControllerAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GCBasePlayerControllerAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerControllerAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBasePlayerControllerAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerControllerAPI>("CBasePlayerControllerAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCBasePlayerControllerAPI::ToPtr)
        .addFunction("IsValid", &GCBasePlayerControllerAPI::IsValid)
        .endClass();
}