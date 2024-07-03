#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimParamHandleMap::GCAnimParamHandleMap(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimParamHandleMap::GCAnimParamHandleMap(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimParamHandleMap::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimParamHandleMap::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimParamHandleMap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParamHandleMap>("CAnimParamHandleMap")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimParamHandleMap::ToPtr)
        .addFunction("IsValid", &GCAnimParamHandleMap::IsValid)
        .endClass();
}