#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInferno::GCInferno(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInferno::GCInferno(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> GCInferno::GetFirePositions() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_firePositions"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCInferno::SetFirePositions(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_firePositions"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_firePositions", false, outValue);
}
std::vector<Vector> GCInferno::GetFireParentPositions() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_fireParentPositions"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCInferno::SetFireParentPositions(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_fireParentPositions"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_fireParentPositions", false, outValue);
}
std::vector<bool> GCInferno::GetFireIsBurning() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CInferno", "m_bFireIsBurning"); std::vector<bool> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCInferno::SetFireIsBurning(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CInferno", "m_bFireIsBurning"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_bFireIsBurning", false, outValue);
}
std::vector<Vector> GCInferno::GetBurnNormal() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_BurnNormal"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCInferno::SetBurnNormal(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_BurnNormal"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_BurnNormal", false, outValue);
}
int32_t GCInferno::GetFireCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_fireCount");
}
void GCInferno::SetFireCount(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_fireCount", false, value);
}
int32_t GCInferno::GetInfernoType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nInfernoType");
}
void GCInferno::SetInfernoType(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nInfernoType", false, value);
}
int32_t GCInferno::GetFireEffectTickBegin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nFireEffectTickBegin");
}
void GCInferno::SetFireEffectTickBegin(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nFireEffectTickBegin", false, value);
}
float GCInferno::GetFireLifetime() const {
    return GetSchemaValue<float>(m_ptr, "CInferno", "m_nFireLifetime");
}
void GCInferno::SetFireLifetime(float value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nFireLifetime", false, value);
}
bool GCInferno::GetInPostEffectTime() const {
    return GetSchemaValue<bool>(m_ptr, "CInferno", "m_bInPostEffectTime");
}
void GCInferno::SetInPostEffectTime(bool value) {
    SetSchemaValue(m_ptr, "CInferno", "m_bInPostEffectTime", false, value);
}
int32_t GCInferno::GetFiresExtinguishCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nFiresExtinguishCount");
}
void GCInferno::SetFiresExtinguishCount(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nFiresExtinguishCount", false, value);
}
bool GCInferno::GetWasCreatedInSmoke() const {
    return GetSchemaValue<bool>(m_ptr, "CInferno", "m_bWasCreatedInSmoke");
}
void GCInferno::SetWasCreatedInSmoke(bool value) {
    SetSchemaValue(m_ptr, "CInferno", "m_bWasCreatedInSmoke", false, value);
}
GExtent GCInferno::GetExtent() const {
    GExtent value(GetSchemaPtr(m_ptr, "CInferno", "m_extent"));
    return value;
}
void GCInferno::SetExtent(GExtent value) {
    SetSchemaValue(m_ptr, "CInferno", "m_extent", false, value);
}
GCountdownTimer GCInferno::GetDamageTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CInferno", "m_damageTimer"));
    return value;
}
void GCInferno::SetDamageTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CInferno", "m_damageTimer", false, value);
}
GCountdownTimer GCInferno::GetDamageRampTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CInferno", "m_damageRampTimer"));
    return value;
}
void GCInferno::SetDamageRampTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CInferno", "m_damageRampTimer", false, value);
}
Vector GCInferno::GetSplashVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_splashVelocity");
}
void GCInferno::SetSplashVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CInferno", "m_splashVelocity", false, value);
}
Vector GCInferno::GetInitialSplashVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_InitialSplashVelocity");
}
void GCInferno::SetInitialSplashVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CInferno", "m_InitialSplashVelocity", false, value);
}
Vector GCInferno::GetStartPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_startPos");
}
void GCInferno::SetStartPos(Vector value) {
    SetSchemaValue(m_ptr, "CInferno", "m_startPos", false, value);
}
Vector GCInferno::GetOriginalSpawnLocation() const {
    return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_vecOriginalSpawnLocation");
}
void GCInferno::SetOriginalSpawnLocation(Vector value) {
    SetSchemaValue(m_ptr, "CInferno", "m_vecOriginalSpawnLocation", false, value);
}
GIntervalTimer GCInferno::GetActiveTimer() const {
    GIntervalTimer value(GetSchemaPtr(m_ptr, "CInferno", "m_activeTimer"));
    return value;
}
void GCInferno::SetActiveTimer(GIntervalTimer value) {
    SetSchemaValue(m_ptr, "CInferno", "m_activeTimer", false, value);
}
int32_t GCInferno::GetFireSpawnOffset() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_fireSpawnOffset");
}
void GCInferno::SetFireSpawnOffset(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_fireSpawnOffset", false, value);
}
int32_t GCInferno::GetMaxFlames() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nMaxFlames");
}
void GCInferno::SetMaxFlames(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nMaxFlames", false, value);
}
int32_t GCInferno::GetSpreadCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nSpreadCount");
}
void GCInferno::SetSpreadCount(int32_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nSpreadCount", false, value);
}
GCountdownTimer GCInferno::GetBookkeepingTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CInferno", "m_BookkeepingTimer"));
    return value;
}
void GCInferno::SetBookkeepingTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CInferno", "m_BookkeepingTimer", false, value);
}
GCountdownTimer GCInferno::GetNextSpreadTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CInferno", "m_NextSpreadTimer"));
    return value;
}
void GCInferno::SetNextSpreadTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CInferno", "m_NextSpreadTimer", false, value);
}
uint16_t GCInferno::GetSourceItemDefIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CInferno", "m_nSourceItemDefIndex");
}
void GCInferno::SetSourceItemDefIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CInferno", "m_nSourceItemDefIndex", false, value);
}
std::string GCInferno::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInferno::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCInferno::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCInferno::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInferno(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInferno>("CInferno")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FirePositions", &GCInferno::GetFirePositions, &GCInferno::SetFirePositions)
        .addProperty("FireParentPositions", &GCInferno::GetFireParentPositions, &GCInferno::SetFireParentPositions)
        .addProperty("FireIsBurning", &GCInferno::GetFireIsBurning, &GCInferno::SetFireIsBurning)
        .addProperty("BurnNormal", &GCInferno::GetBurnNormal, &GCInferno::SetBurnNormal)
        .addProperty("FireCount", &GCInferno::GetFireCount, &GCInferno::SetFireCount)
        .addProperty("InfernoType", &GCInferno::GetInfernoType, &GCInferno::SetInfernoType)
        .addProperty("FireEffectTickBegin", &GCInferno::GetFireEffectTickBegin, &GCInferno::SetFireEffectTickBegin)
        .addProperty("FireLifetime", &GCInferno::GetFireLifetime, &GCInferno::SetFireLifetime)
        .addProperty("InPostEffectTime", &GCInferno::GetInPostEffectTime, &GCInferno::SetInPostEffectTime)
        .addProperty("FiresExtinguishCount", &GCInferno::GetFiresExtinguishCount, &GCInferno::SetFiresExtinguishCount)
        .addProperty("WasCreatedInSmoke", &GCInferno::GetWasCreatedInSmoke, &GCInferno::SetWasCreatedInSmoke)
        .addProperty("Extent", &GCInferno::GetExtent, &GCInferno::SetExtent)
        .addProperty("DamageTimer", &GCInferno::GetDamageTimer, &GCInferno::SetDamageTimer)
        .addProperty("DamageRampTimer", &GCInferno::GetDamageRampTimer, &GCInferno::SetDamageRampTimer)
        .addProperty("SplashVelocity", &GCInferno::GetSplashVelocity, &GCInferno::SetSplashVelocity)
        .addProperty("InitialSplashVelocity", &GCInferno::GetInitialSplashVelocity, &GCInferno::SetInitialSplashVelocity)
        .addProperty("StartPos", &GCInferno::GetStartPos, &GCInferno::SetStartPos)
        .addProperty("OriginalSpawnLocation", &GCInferno::GetOriginalSpawnLocation, &GCInferno::SetOriginalSpawnLocation)
        .addProperty("ActiveTimer", &GCInferno::GetActiveTimer, &GCInferno::SetActiveTimer)
        .addProperty("FireSpawnOffset", &GCInferno::GetFireSpawnOffset, &GCInferno::SetFireSpawnOffset)
        .addProperty("MaxFlames", &GCInferno::GetMaxFlames, &GCInferno::SetMaxFlames)
        .addProperty("SpreadCount", &GCInferno::GetSpreadCount, &GCInferno::SetSpreadCount)
        .addProperty("BookkeepingTimer", &GCInferno::GetBookkeepingTimer, &GCInferno::SetBookkeepingTimer)
        .addProperty("NextSpreadTimer", &GCInferno::GetNextSpreadTimer, &GCInferno::SetNextSpreadTimer)
        .addProperty("SourceItemDefIndex", &GCInferno::GetSourceItemDefIndex, &GCInferno::SetSourceItemDefIndex)
        .addProperty("Parent", &GCInferno::GetParent, &GCInferno::SetParent)
        .addFunction("ToPtr", &GCInferno::ToPtr)
        .addFunction("IsValid", &GCInferno::IsValid)
        .endClass();
}