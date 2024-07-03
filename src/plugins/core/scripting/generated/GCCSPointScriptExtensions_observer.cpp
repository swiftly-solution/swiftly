#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_observer::GCCSPointScriptExtensions_observer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_observer::GCCSPointScriptExtensions_observer(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_observer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_observer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_observer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_observer>("CCSPointScriptExtensions_observer")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_observer::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_observer::IsValid)
        .endClass();
}