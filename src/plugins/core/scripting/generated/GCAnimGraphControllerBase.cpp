#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphControllerBase::GCAnimGraphControllerBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphControllerBase::GCAnimGraphControllerBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimGraphControllerBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphControllerBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphControllerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphControllerBase>("CAnimGraphControllerBase")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimGraphControllerBase::ToPtr)
        .addFunction("IsValid", &GCAnimGraphControllerBase::IsValid)
        .endClass();
}