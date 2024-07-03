#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_ItemServices::GCPlayer_ItemServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_ItemServices::GCPlayer_ItemServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_ItemServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_ItemServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_ItemServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_ItemServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_ItemServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ItemServices>("CPlayer_ItemServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_ItemServices::GetParent, &GCPlayer_ItemServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_ItemServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_ItemServices::IsValid)
        .endClass();
}