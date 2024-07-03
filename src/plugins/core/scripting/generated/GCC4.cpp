#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCC4::GCC4(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCC4::GCC4(void *ptr) {
    m_ptr = ptr;
}
Vector GCC4::GetLastValidPlayerHeldPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CC4", "m_vecLastValidPlayerHeldPosition");
}
void GCC4::SetLastValidPlayerHeldPosition(Vector value) {
    SetSchemaValue(m_ptr, "CC4", "m_vecLastValidPlayerHeldPosition", false, value);
}
Vector GCC4::GetLastValidDroppedPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CC4", "m_vecLastValidDroppedPosition");
}
void GCC4::SetLastValidDroppedPosition(Vector value) {
    SetSchemaValue(m_ptr, "CC4", "m_vecLastValidDroppedPosition", false, value);
}
bool GCC4::GetDoValidDroppedPositionCheck() const {
    return GetSchemaValue<bool>(m_ptr, "CC4", "m_bDoValidDroppedPositionCheck");
}
void GCC4::SetDoValidDroppedPositionCheck(bool value) {
    SetSchemaValue(m_ptr, "CC4", "m_bDoValidDroppedPositionCheck", false, value);
}
bool GCC4::GetStartedArming() const {
    return GetSchemaValue<bool>(m_ptr, "CC4", "m_bStartedArming");
}
void GCC4::SetStartedArming(bool value) {
    SetSchemaValue(m_ptr, "CC4", "m_bStartedArming", false, value);
}
float GCC4::GetArmedTime() const {
    return GetSchemaValue<float>(m_ptr, "CC4", "m_fArmedTime");
}
void GCC4::SetArmedTime(float value) {
    SetSchemaValue(m_ptr, "CC4", "m_fArmedTime", false, value);
}
bool GCC4::GetBombPlacedAnimation() const {
    return GetSchemaValue<bool>(m_ptr, "CC4", "m_bBombPlacedAnimation");
}
void GCC4::SetBombPlacedAnimation(bool value) {
    SetSchemaValue(m_ptr, "CC4", "m_bBombPlacedAnimation", false, value);
}
bool GCC4::GetIsPlantingViaUse() const {
    return GetSchemaValue<bool>(m_ptr, "CC4", "m_bIsPlantingViaUse");
}
void GCC4::SetIsPlantingViaUse(bool value) {
    SetSchemaValue(m_ptr, "CC4", "m_bIsPlantingViaUse", false, value);
}
GEntitySpottedState_t GCC4::GetEntitySpottedState() const {
    GEntitySpottedState_t value(GetSchemaPtr(m_ptr, "CC4", "m_entitySpottedState"));
    return value;
}
void GCC4::SetEntitySpottedState(GEntitySpottedState_t value) {
    SetSchemaValue(m_ptr, "CC4", "m_entitySpottedState", false, value);
}
int32_t GCC4::GetSpotRules() const {
    return GetSchemaValue<int32_t>(m_ptr, "CC4", "m_nSpotRules");
}
void GCC4::SetSpotRules(int32_t value) {
    SetSchemaValue(m_ptr, "CC4", "m_nSpotRules", false, value);
}
std::vector<bool> GCC4::GetPlayedArmingBeeps() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CC4", "m_bPlayedArmingBeeps"); std::vector<bool> ret; for(int i = 0; i < 7; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCC4::SetPlayedArmingBeeps(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CC4", "m_bPlayedArmingBeeps"); for(int i = 0; i < 7; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CC4", "m_bPlayedArmingBeeps", false, outValue);
}
bool GCC4::GetBombPlanted() const {
    return GetSchemaValue<bool>(m_ptr, "CC4", "m_bBombPlanted");
}
void GCC4::SetBombPlanted(bool value) {
    SetSchemaValue(m_ptr, "CC4", "m_bBombPlanted", false, value);
}
std::string GCC4::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCC4::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCC4::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCC4::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCC4(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCC4>("CC4")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LastValidPlayerHeldPosition", &GCC4::GetLastValidPlayerHeldPosition, &GCC4::SetLastValidPlayerHeldPosition)
        .addProperty("LastValidDroppedPosition", &GCC4::GetLastValidDroppedPosition, &GCC4::SetLastValidDroppedPosition)
        .addProperty("DoValidDroppedPositionCheck", &GCC4::GetDoValidDroppedPositionCheck, &GCC4::SetDoValidDroppedPositionCheck)
        .addProperty("StartedArming", &GCC4::GetStartedArming, &GCC4::SetStartedArming)
        .addProperty("ArmedTime", &GCC4::GetArmedTime, &GCC4::SetArmedTime)
        .addProperty("BombPlacedAnimation", &GCC4::GetBombPlacedAnimation, &GCC4::SetBombPlacedAnimation)
        .addProperty("IsPlantingViaUse", &GCC4::GetIsPlantingViaUse, &GCC4::SetIsPlantingViaUse)
        .addProperty("EntitySpottedState", &GCC4::GetEntitySpottedState, &GCC4::SetEntitySpottedState)
        .addProperty("SpotRules", &GCC4::GetSpotRules, &GCC4::SetSpotRules)
        .addProperty("PlayedArmingBeeps", &GCC4::GetPlayedArmingBeeps, &GCC4::SetPlayedArmingBeeps)
        .addProperty("BombPlanted", &GCC4::GetBombPlanted, &GCC4::SetBombPlanted)
        .addProperty("Parent", &GCC4::GetParent, &GCC4::SetParent)
        .addFunction("ToPtr", &GCC4::ToPtr)
        .addFunction("IsValid", &GCC4::IsValid)
        .endClass();
}