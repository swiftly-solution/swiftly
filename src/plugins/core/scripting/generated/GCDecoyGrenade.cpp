#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDecoyGrenade::GCDecoyGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDecoyGrenade::GCDecoyGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCDecoyGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDecoyGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCDecoyGrenade::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCDecoyGrenade::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDecoyGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecoyGrenade>("CDecoyGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCDecoyGrenade::GetParent, &GCDecoyGrenade::SetParent)
        .addFunction("ToPtr", &GCDecoyGrenade::ToPtr)
        .addFunction("IsValid", &GCDecoyGrenade::IsValid)
        .endClass();
}