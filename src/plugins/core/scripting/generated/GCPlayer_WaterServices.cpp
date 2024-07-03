#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_WaterServices::GCPlayer_WaterServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_WaterServices::GCPlayer_WaterServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayer_WaterServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_WaterServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_WaterServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_WaterServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_WaterServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_WaterServices>("CPlayer_WaterServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPlayer_WaterServices::GetParent, &GCPlayer_WaterServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_WaterServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_WaterServices::IsValid)
        .endClass();
}