#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_AutoaimServices::GCPlayer_AutoaimServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_AutoaimServices::GCPlayer_AutoaimServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_AutoaimServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_AutoaimServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_AutoaimServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_AutoaimServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_AutoaimServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_AutoaimServices>("CPlayer_AutoaimServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_AutoaimServices::GetParent, &GCPlayer_AutoaimServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_AutoaimServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_AutoaimServices::IsValid)
        .endClass();
}