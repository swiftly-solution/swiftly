#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSharedGapTypeQueryRegistration::GCSharedGapTypeQueryRegistration(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSharedGapTypeQueryRegistration::GCSharedGapTypeQueryRegistration(void *ptr) {
    m_ptr = ptr;
}
std::string GCSharedGapTypeQueryRegistration::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSharedGapTypeQueryRegistration::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSharedGapTypeQueryRegistration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSharedGapTypeQueryRegistration>("CSharedGapTypeQueryRegistration")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCSharedGapTypeQueryRegistration::ToPtr)
        .addFunction("IsValid", &GCSharedGapTypeQueryRegistration::IsValid)
        .endClass();
}