#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootstepTableHandle::GCFootstepTableHandle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootstepTableHandle::GCFootstepTableHandle(void *ptr) {
    m_ptr = ptr;
}
std::string GCFootstepTableHandle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootstepTableHandle::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootstepTableHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepTableHandle>("CFootstepTableHandle")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCFootstepTableHandle::ToPtr)
        .addFunction("IsValid", &GCFootstepTableHandle::IsValid)
        .endClass();
}