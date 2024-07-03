#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_BulletServices::GCCSPlayer_BulletServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_BulletServices::GCCSPlayer_BulletServices(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCSPlayer_BulletServices::GetTotalHitsOnServer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_BulletServices", "m_totalHitsOnServer");
}
void GCCSPlayer_BulletServices::SetTotalHitsOnServer(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_BulletServices", "m_totalHitsOnServer", false, value);
}
std::string GCCSPlayer_BulletServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_BulletServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_BulletServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_BulletServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_BulletServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_BulletServices>("CCSPlayer_BulletServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TotalHitsOnServer", &GCCSPlayer_BulletServices::GetTotalHitsOnServer, &GCCSPlayer_BulletServices::SetTotalHitsOnServer)
        .addProperty("Parent", &GCCSPlayer_BulletServices::GetParent, &GCCSPlayer_BulletServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_BulletServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_BulletServices::IsValid)
        .endClass();
}