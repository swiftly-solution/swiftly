#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_HostageServices::GCCSPlayer_HostageServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_HostageServices::GCCSPlayer_HostageServices(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCCSPlayer_HostageServices::GetCarriedHostage() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_HostageServices", "m_hCarriedHostage"));
    return value;
}
void GCCSPlayer_HostageServices::SetCarriedHostage(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarriedHostage' is not possible.\n");
}
GCBaseEntity GCCSPlayer_HostageServices::GetCarriedHostageProp() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_HostageServices", "m_hCarriedHostageProp"));
    return value;
}
void GCCSPlayer_HostageServices::SetCarriedHostageProp(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarriedHostageProp' is not possible.\n");
}
std::string GCCSPlayer_HostageServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_HostageServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_HostageServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_HostageServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_HostageServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_HostageServices>("CCSPlayer_HostageServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CarriedHostage", &GCCSPlayer_HostageServices::GetCarriedHostage, &GCCSPlayer_HostageServices::SetCarriedHostage)
        .addProperty("CarriedHostageProp", &GCCSPlayer_HostageServices::GetCarriedHostageProp, &GCCSPlayer_HostageServices::SetCarriedHostageProp)
        .addProperty("Parent", &GCCSPlayer_HostageServices::GetParent, &GCCSPlayer_HostageServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_HostageServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_HostageServices::IsValid)
        .endClass();
}