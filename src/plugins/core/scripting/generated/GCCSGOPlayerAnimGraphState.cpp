#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGOPlayerAnimGraphState::GCCSGOPlayerAnimGraphState(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGOPlayerAnimGraphState::GCCSGOPlayerAnimGraphState(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGOPlayerAnimGraphState::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGOPlayerAnimGraphState::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSGOPlayerAnimGraphState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGOPlayerAnimGraphState>("CCSGOPlayerAnimGraphState")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSGOPlayerAnimGraphState::ToPtr)
        .addFunction("IsValid", &GCCSGOPlayerAnimGraphState::IsValid)
        .endClass();
}