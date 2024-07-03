#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIRagdoll::GIRagdoll(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIRagdoll::GIRagdoll(void *ptr) {
    m_ptr = ptr;
}
std::string GIRagdoll::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIRagdoll::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIRagdoll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIRagdoll>("IRagdoll")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIRagdoll::ToPtr)
        .addFunction("IsValid", &GIRagdoll::IsValid)
        .endClass();
}