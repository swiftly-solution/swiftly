#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEmptyEntityInstance::GCEmptyEntityInstance(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEmptyEntityInstance::GCEmptyEntityInstance(void *ptr) {
    m_ptr = ptr;
}
std::string GCEmptyEntityInstance::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEmptyEntityInstance::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEmptyEntityInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEmptyEntityInstance>("CEmptyEntityInstance")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCEmptyEntityInstance::ToPtr)
        .addFunction("IsValid", &GCEmptyEntityInstance::IsValid)
        .endClass();
}