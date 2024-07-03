#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_ViewModelServices::GCPlayer_ViewModelServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_ViewModelServices::GCPlayer_ViewModelServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_ViewModelServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_ViewModelServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_ViewModelServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_ViewModelServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ViewModelServices>("CPlayer_ViewModelServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_ViewModelServices::GetParent, &GCPlayer_ViewModelServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_ViewModelServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_ViewModelServices::IsValid)
        .endClass();
}