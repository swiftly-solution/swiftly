#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_CameraServices::GCCSPlayer_CameraServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_CameraServices::GCCSPlayer_CameraServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPlayer_CameraServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_CameraServices::IsValid() {
    return (m_ptr != nullptr);
}
GCCSPlayerBase_CameraServices GCCSPlayer_CameraServices::GetParent() const {
    GCCSPlayerBase_CameraServices value(m_ptr);
    return value;
}
void GCCSPlayer_CameraServices::SetParent(GCCSPlayerBase_CameraServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_CameraServices>("CCSPlayer_CameraServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSPlayer_CameraServices::GetParent, &GCCSPlayer_CameraServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_CameraServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_CameraServices::IsValid)
        .endClass();
}