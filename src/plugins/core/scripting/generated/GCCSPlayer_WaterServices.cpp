#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_WaterServices::GCCSPlayer_WaterServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_WaterServices::GCCSPlayer_WaterServices(void *ptr) {
    m_ptr = ptr;
}
float GCCSPlayer_WaterServices::GetNextDrownDamageTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_NextDrownDamageTime");
}
void GCCSPlayer_WaterServices::SetNextDrownDamageTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_NextDrownDamageTime", false, value);
}
int32_t GCCSPlayer_WaterServices::GetDrownDmgRate() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WaterServices", "m_nDrownDmgRate");
}
void GCCSPlayer_WaterServices::SetDrownDmgRate(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_nDrownDmgRate", false, value);
}
float GCCSPlayer_WaterServices::GetAirFinishedTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_AirFinishedTime");
}
void GCCSPlayer_WaterServices::SetAirFinishedTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_AirFinishedTime", false, value);
}
float GCCSPlayer_WaterServices::GetWaterJumpTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_flWaterJumpTime");
}
void GCCSPlayer_WaterServices::SetWaterJumpTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_flWaterJumpTime", false, value);
}
Vector GCCSPlayer_WaterServices::GetWaterJumpVel() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_WaterServices", "m_vecWaterJumpVel");
}
void GCCSPlayer_WaterServices::SetWaterJumpVel(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_vecWaterJumpVel", false, value);
}
float GCCSPlayer_WaterServices::GetSwimSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_flSwimSoundTime");
}
void GCCSPlayer_WaterServices::SetSwimSoundTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_flSwimSoundTime", false, value);
}
std::string GCCSPlayer_WaterServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_WaterServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_WaterServices GCCSPlayer_WaterServices::GetParent() const {
    GCPlayer_WaterServices value(m_ptr);
    return value;
}
void GCCSPlayer_WaterServices::SetParent(GCPlayer_WaterServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_WaterServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_WaterServices>("CCSPlayer_WaterServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NextDrownDamageTime", &GCCSPlayer_WaterServices::GetNextDrownDamageTime, &GCCSPlayer_WaterServices::SetNextDrownDamageTime)
        .addProperty("DrownDmgRate", &GCCSPlayer_WaterServices::GetDrownDmgRate, &GCCSPlayer_WaterServices::SetDrownDmgRate)
        .addProperty("AirFinishedTime", &GCCSPlayer_WaterServices::GetAirFinishedTime, &GCCSPlayer_WaterServices::SetAirFinishedTime)
        .addProperty("WaterJumpTime", &GCCSPlayer_WaterServices::GetWaterJumpTime, &GCCSPlayer_WaterServices::SetWaterJumpTime)
        .addProperty("WaterJumpVel", &GCCSPlayer_WaterServices::GetWaterJumpVel, &GCCSPlayer_WaterServices::SetWaterJumpVel)
        .addProperty("SwimSoundTime", &GCCSPlayer_WaterServices::GetSwimSoundTime, &GCCSPlayer_WaterServices::SetSwimSoundTime)
        .addProperty("Parent", &GCCSPlayer_WaterServices::GetParent, &GCCSPlayer_WaterServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_WaterServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_WaterServices::IsValid)
        .endClass();
}