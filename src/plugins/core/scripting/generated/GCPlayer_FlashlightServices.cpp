#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_FlashlightServices::GCPlayer_FlashlightServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_FlashlightServices::GCPlayer_FlashlightServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_FlashlightServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_FlashlightServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_FlashlightServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_FlashlightServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_FlashlightServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_FlashlightServices>("CPlayer_FlashlightServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_FlashlightServices::GetParent, &GCPlayer_FlashlightServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_FlashlightServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_FlashlightServices::IsValid)
        .endClass();
}