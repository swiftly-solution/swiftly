#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTakeDamageInfoAPI::GCTakeDamageInfoAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTakeDamageInfoAPI::GCTakeDamageInfoAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GCTakeDamageInfoAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTakeDamageInfoAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTakeDamageInfoAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageInfoAPI>("CTakeDamageInfoAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCTakeDamageInfoAPI::ToPtr)
        .addFunction("IsValid", &GCTakeDamageInfoAPI::IsValid)
        .endClass();
}