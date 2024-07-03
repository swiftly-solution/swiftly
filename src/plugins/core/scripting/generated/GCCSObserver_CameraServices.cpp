#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserver_CameraServices::GCCSObserver_CameraServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserver_CameraServices::GCCSObserver_CameraServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserver_CameraServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserver_CameraServices::IsValid() {
    return (m_ptr != nullptr);
}
GCCSPlayerBase_CameraServices GCCSObserver_CameraServices::GetParent() const {
    GCCSPlayerBase_CameraServices value(m_ptr);
    return value;
}
void GCCSObserver_CameraServices::SetParent(GCCSPlayerBase_CameraServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserver_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_CameraServices>("CCSObserver_CameraServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserver_CameraServices::GetParent, &GCCSObserver_CameraServices::SetParent)
        .addFunction("ToPtr", &GCCSObserver_CameraServices::ToPtr)
        .addFunction("IsValid", &GCCSObserver_CameraServices::IsValid)
        .endClass();
}