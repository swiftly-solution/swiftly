#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFakeEntityDerivedA_tAPI::GFakeEntityDerivedA_tAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFakeEntityDerivedA_tAPI::GFakeEntityDerivedA_tAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GFakeEntityDerivedA_tAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFakeEntityDerivedA_tAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFakeEntityDerivedA_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntityDerivedA_tAPI>("FakeEntityDerivedA_tAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GFakeEntityDerivedA_tAPI::ToPtr)
        .addFunction("IsValid", &GFakeEntityDerivedA_tAPI::IsValid)
        .endClass();
}