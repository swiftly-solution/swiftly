#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEventListenerBase::GCAnimEventListenerBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEventListenerBase::GCAnimEventListenerBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimEventListenerBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEventListenerBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimEventListenerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventListenerBase>("CAnimEventListenerBase")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimEventListenerBase::ToPtr)
        .addFunction("IsValid", &GCAnimEventListenerBase::IsValid)
        .endClass();
}