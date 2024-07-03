#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolume::GCNavVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolume::GCNavVolume(void *ptr) {
    m_ptr = ptr;
}
std::string GCNavVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolume::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNavVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolume>("CNavVolume")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCNavVolume::ToPtr)
        .addFunction("IsValid", &GCNavVolume::IsValid)
        .endClass();
}