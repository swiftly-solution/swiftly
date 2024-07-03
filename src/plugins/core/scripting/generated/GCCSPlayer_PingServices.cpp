#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_PingServices::GCCSPlayer_PingServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_PingServices::GCCSPlayer_PingServices(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCCSPlayer_PingServices::GetPlayerPingTokens() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSPlayer_PingServices", "m_flPlayerPingTokens"); std::vector<float> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayer_PingServices::SetPlayerPingTokens(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSPlayer_PingServices", "m_flPlayerPingTokens"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayer_PingServices", "m_flPlayerPingTokens", false, outValue);
}
GCBaseEntity GCCSPlayer_PingServices::GetPlayerPing() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayer_PingServices", "m_hPlayerPing"));
    return value;
}
void GCCSPlayer_PingServices::SetPlayerPing(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerPing' is not possible.\n");
}
std::string GCCSPlayer_PingServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_PingServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_PingServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_PingServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_PingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_PingServices>("CCSPlayer_PingServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayerPingTokens", &GCCSPlayer_PingServices::GetPlayerPingTokens, &GCCSPlayer_PingServices::SetPlayerPingTokens)
        .addProperty("PlayerPing", &GCCSPlayer_PingServices::GetPlayerPing, &GCCSPlayer_PingServices::SetPlayerPing)
        .addProperty("Parent", &GCCSPlayer_PingServices::GetParent, &GCCSPlayer_PingServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_PingServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_PingServices::IsValid)
        .endClass();
}