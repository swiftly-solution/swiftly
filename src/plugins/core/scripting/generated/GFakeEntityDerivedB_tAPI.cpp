#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFakeEntityDerivedB_tAPI::GFakeEntityDerivedB_tAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFakeEntityDerivedB_tAPI::GFakeEntityDerivedB_tAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GFakeEntityDerivedB_tAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFakeEntityDerivedB_tAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFakeEntityDerivedB_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntityDerivedB_tAPI>("FakeEntityDerivedB_tAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GFakeEntityDerivedB_tAPI::ToPtr)
        .addFunction("IsValid", &GFakeEntityDerivedB_tAPI::IsValid)
        .endClass();
}