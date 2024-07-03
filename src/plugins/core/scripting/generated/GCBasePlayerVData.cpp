#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerVData::GCBasePlayerVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerVData::GCBasePlayerVData(void *ptr) {
    m_ptr = ptr;
}
GCSkillFloat GCBasePlayerVData::GetHeadDamageMultiplier() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CBasePlayerVData", "m_flHeadDamageMultiplier"));
    return value;
}
void GCBasePlayerVData::SetHeadDamageMultiplier(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flHeadDamageMultiplier", false, value);
}
GCSkillFloat GCBasePlayerVData::GetChestDamageMultiplier() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CBasePlayerVData", "m_flChestDamageMultiplier"));
    return value;
}
void GCBasePlayerVData::SetChestDamageMultiplier(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flChestDamageMultiplier", false, value);
}
GCSkillFloat GCBasePlayerVData::GetStomachDamageMultiplier() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CBasePlayerVData", "m_flStomachDamageMultiplier"));
    return value;
}
void GCBasePlayerVData::SetStomachDamageMultiplier(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flStomachDamageMultiplier", false, value);
}
GCSkillFloat GCBasePlayerVData::GetArmDamageMultiplier() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CBasePlayerVData", "m_flArmDamageMultiplier"));
    return value;
}
void GCBasePlayerVData::SetArmDamageMultiplier(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flArmDamageMultiplier", false, value);
}
GCSkillFloat GCBasePlayerVData::GetLegDamageMultiplier() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CBasePlayerVData", "m_flLegDamageMultiplier"));
    return value;
}
void GCBasePlayerVData::SetLegDamageMultiplier(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flLegDamageMultiplier", false, value);
}
float GCBasePlayerVData::GetHoldBreathTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flHoldBreathTime");
}
void GCBasePlayerVData::SetHoldBreathTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flHoldBreathTime", false, value);
}
float GCBasePlayerVData::GetDrowningDamageInterval() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flDrowningDamageInterval");
}
void GCBasePlayerVData::SetDrowningDamageInterval(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flDrowningDamageInterval", false, value);
}
int32_t GCBasePlayerVData::GetDrowningDamageInitial() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nDrowningDamageInitial");
}
void GCBasePlayerVData::SetDrowningDamageInitial(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nDrowningDamageInitial", false, value);
}
int32_t GCBasePlayerVData::GetDrowningDamageMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nDrowningDamageMax");
}
void GCBasePlayerVData::SetDrowningDamageMax(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nDrowningDamageMax", false, value);
}
int32_t GCBasePlayerVData::GetWaterSpeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nWaterSpeed");
}
void GCBasePlayerVData::SetWaterSpeed(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nWaterSpeed", false, value);
}
float GCBasePlayerVData::GetUseRange() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flUseRange");
}
void GCBasePlayerVData::SetUseRange(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flUseRange", false, value);
}
float GCBasePlayerVData::GetUseAngleTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flUseAngleTolerance");
}
void GCBasePlayerVData::SetUseAngleTolerance(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flUseAngleTolerance", false, value);
}
float GCBasePlayerVData::GetCrouchTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flCrouchTime");
}
void GCBasePlayerVData::SetCrouchTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flCrouchTime", false, value);
}
std::string GCBasePlayerVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerVData::IsValid() {
    return (m_ptr != nullptr);
}
GCEntitySubclassVDataBase GCBasePlayerVData::GetParent() const {
    GCEntitySubclassVDataBase value(m_ptr);
    return value;
}
void GCBasePlayerVData::SetParent(GCEntitySubclassVDataBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlayerVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerVData>("CBasePlayerVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HeadDamageMultiplier", &GCBasePlayerVData::GetHeadDamageMultiplier, &GCBasePlayerVData::SetHeadDamageMultiplier)
        .addProperty("ChestDamageMultiplier", &GCBasePlayerVData::GetChestDamageMultiplier, &GCBasePlayerVData::SetChestDamageMultiplier)
        .addProperty("StomachDamageMultiplier", &GCBasePlayerVData::GetStomachDamageMultiplier, &GCBasePlayerVData::SetStomachDamageMultiplier)
        .addProperty("ArmDamageMultiplier", &GCBasePlayerVData::GetArmDamageMultiplier, &GCBasePlayerVData::SetArmDamageMultiplier)
        .addProperty("LegDamageMultiplier", &GCBasePlayerVData::GetLegDamageMultiplier, &GCBasePlayerVData::SetLegDamageMultiplier)
        .addProperty("HoldBreathTime", &GCBasePlayerVData::GetHoldBreathTime, &GCBasePlayerVData::SetHoldBreathTime)
        .addProperty("DrowningDamageInterval", &GCBasePlayerVData::GetDrowningDamageInterval, &GCBasePlayerVData::SetDrowningDamageInterval)
        .addProperty("DrowningDamageInitial", &GCBasePlayerVData::GetDrowningDamageInitial, &GCBasePlayerVData::SetDrowningDamageInitial)
        .addProperty("DrowningDamageMax", &GCBasePlayerVData::GetDrowningDamageMax, &GCBasePlayerVData::SetDrowningDamageMax)
        .addProperty("WaterSpeed", &GCBasePlayerVData::GetWaterSpeed, &GCBasePlayerVData::SetWaterSpeed)
        .addProperty("UseRange", &GCBasePlayerVData::GetUseRange, &GCBasePlayerVData::SetUseRange)
        .addProperty("UseAngleTolerance", &GCBasePlayerVData::GetUseAngleTolerance, &GCBasePlayerVData::SetUseAngleTolerance)
        .addProperty("CrouchTime", &GCBasePlayerVData::GetCrouchTime, &GCBasePlayerVData::SetCrouchTime)
        .addProperty("Parent", &GCBasePlayerVData::GetParent, &GCBasePlayerVData::SetParent)
        .addFunction("ToPtr", &GCBasePlayerVData::ToPtr)
        .addFunction("IsValid", &GCBasePlayerVData::IsValid)
        .endClass();
}