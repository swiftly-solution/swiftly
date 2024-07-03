#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_DamageReactServices::GCCSPlayer_DamageReactServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_DamageReactServices::GCCSPlayer_DamageReactServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPlayer_DamageReactServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_DamageReactServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_DamageReactServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_DamageReactServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_DamageReactServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_DamageReactServices>("CCSPlayer_DamageReactServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSPlayer_DamageReactServices::GetParent, &GCCSPlayer_DamageReactServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_DamageReactServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_DamageReactServices::IsValid)
        .endClass();
}