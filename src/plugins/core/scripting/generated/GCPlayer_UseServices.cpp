#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_UseServices::GCPlayer_UseServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_UseServices::GCPlayer_UseServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_UseServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_UseServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_UseServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_UseServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_UseServices>("CPlayer_UseServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_UseServices::GetParent, &GCPlayer_UseServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_UseServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_UseServices::IsValid)
        .endClass();
}