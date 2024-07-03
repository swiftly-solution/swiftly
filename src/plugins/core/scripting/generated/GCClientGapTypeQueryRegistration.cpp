#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCClientGapTypeQueryRegistration::GCClientGapTypeQueryRegistration(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCClientGapTypeQueryRegistration::GCClientGapTypeQueryRegistration(void *ptr) {
    m_ptr = ptr;
}
std::string GCClientGapTypeQueryRegistration::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCClientGapTypeQueryRegistration::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCClientGapTypeQueryRegistration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClientGapTypeQueryRegistration>("CClientGapTypeQueryRegistration")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCClientGapTypeQueryRegistration::ToPtr)
        .addFunction("IsValid", &GCClientGapTypeQueryRegistration::IsValid)
        .endClass();
}