#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerBase_CameraServices::GCCSPlayerBase_CameraServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerBase_CameraServices::GCCSPlayerBase_CameraServices(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCCSPlayerBase_CameraServices::GetFOV() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOV");
}
void GCCSPlayerBase_CameraServices::SetFOV(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOV", false, value);
}
uint32_t GCCSPlayerBase_CameraServices::GetFOVStart() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOVStart");
}
void GCCSPlayerBase_CameraServices::SetFOVStart(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOVStart", false, value);
}
float GCCSPlayerBase_CameraServices::GetFOVTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVTime");
}
void GCCSPlayerBase_CameraServices::SetFOVTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVTime", false, value);
}
float GCCSPlayerBase_CameraServices::GetFOVRate() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVRate");
}
void GCCSPlayerBase_CameraServices::SetFOVRate(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVRate", false, value);
}
GCBaseEntity GCCSPlayerBase_CameraServices::GetZoomOwner() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerBase_CameraServices", "m_hZoomOwner"));
    return value;
}
void GCCSPlayerBase_CameraServices::SetZoomOwner(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ZoomOwner' is not possible.\n");
}
GCBaseEntity GCCSPlayerBase_CameraServices::GetLastFogTrigger() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerBase_CameraServices", "m_hLastFogTrigger"));
    return value;
}
void GCCSPlayerBase_CameraServices::SetLastFogTrigger(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastFogTrigger' is not possible.\n");
}
std::string GCCSPlayerBase_CameraServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerBase_CameraServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_CameraServices GCCSPlayerBase_CameraServices::GetParent() const {
    GCPlayer_CameraServices value(m_ptr);
    return value;
}
void GCCSPlayerBase_CameraServices::SetParent(GCPlayer_CameraServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerBase_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerBase_CameraServices>("CCSPlayerBase_CameraServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FOV", &GCCSPlayerBase_CameraServices::GetFOV, &GCCSPlayerBase_CameraServices::SetFOV)
        .addProperty("FOVStart", &GCCSPlayerBase_CameraServices::GetFOVStart, &GCCSPlayerBase_CameraServices::SetFOVStart)
        .addProperty("FOVTime", &GCCSPlayerBase_CameraServices::GetFOVTime, &GCCSPlayerBase_CameraServices::SetFOVTime)
        .addProperty("FOVRate", &GCCSPlayerBase_CameraServices::GetFOVRate, &GCCSPlayerBase_CameraServices::SetFOVRate)
        .addProperty("ZoomOwner", &GCCSPlayerBase_CameraServices::GetZoomOwner, &GCCSPlayerBase_CameraServices::SetZoomOwner)
        .addProperty("LastFogTrigger", &GCCSPlayerBase_CameraServices::GetLastFogTrigger, &GCCSPlayerBase_CameraServices::SetLastFogTrigger)
        .addProperty("Parent", &GCCSPlayerBase_CameraServices::GetParent, &GCCSPlayerBase_CameraServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayerBase_CameraServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayerBase_CameraServices::IsValid)
        .endClass();
}