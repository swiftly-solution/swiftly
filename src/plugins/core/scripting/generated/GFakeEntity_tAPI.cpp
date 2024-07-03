#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFakeEntity_tAPI::GFakeEntity_tAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFakeEntity_tAPI::GFakeEntity_tAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GFakeEntity_tAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFakeEntity_tAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFakeEntity_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntity_tAPI>("FakeEntity_tAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GFakeEntity_tAPI::ToPtr)
        .addFunction("IsValid", &GFakeEntity_tAPI::IsValid)
        .endClass();
}