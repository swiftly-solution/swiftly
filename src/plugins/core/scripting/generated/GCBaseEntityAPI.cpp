#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseEntityAPI::GCBaseEntityAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseEntityAPI::GCBaseEntityAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GCBaseEntityAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseEntityAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBaseEntityAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseEntityAPI>("CBaseEntityAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCBaseEntityAPI::ToPtr)
        .addFunction("IsValid", &GCBaseEntityAPI::IsValid)
        .endClass();
}