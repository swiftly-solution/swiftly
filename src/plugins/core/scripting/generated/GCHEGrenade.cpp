#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHEGrenade::GCHEGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHEGrenade::GCHEGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCHEGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHEGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCHEGrenade::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCHEGrenade::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHEGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHEGrenade>("CHEGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHEGrenade::GetParent, &GCHEGrenade::SetParent)
        .addFunction("ToPtr", &GCHEGrenade::ToPtr)
        .addFunction("IsValid", &GCHEGrenade::IsValid)
        .endClass();
}