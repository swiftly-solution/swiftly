#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityIOOutput::GCEntityIOOutput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityIOOutput::GCEntityIOOutput(void *ptr) {
    m_ptr = ptr;
}
std::string GCEntityIOOutput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityIOOutput::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntityIOOutput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityIOOutput>("CEntityIOOutput")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCEntityIOOutput::ToPtr)
        .addFunction("IsValid", &GCEntityIOOutput::IsValid)
        .endClass();
}