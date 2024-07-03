#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseEntity::GCBaseEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseEntity::GCBaseEntity(void *ptr) {
    m_ptr = ptr;
}
void GCBaseEntity::Spawn() {
    ((Z_CBaseEntity*)m_ptr)->Spawn();
}
void GCBaseEntity::Despawn() {
    ((Z_CBaseEntity*)m_ptr)->Despawn();
}
void GCBaseEntity::AcceptInput(std::string input, GCEntityInstance activator, GCEntityInstance caller, std::string value, int outputID) {
    ((Z_CBaseEntity*)m_ptr)->AcceptInput(input.c_str(), (CEntityInstance*)(strtoul(activator.ToPtr().c_str(), nullptr, 16)), (CEntityInstance*)(strtoul(caller.ToPtr().c_str(), nullptr, 16)), value.c_str(), outputID);
}
std::string GCBaseEntity::GetClassname() {
    return ((Z_CBaseEntity*)m_ptr)->GetClassname();
}
GCEntitySubclassVDataBase GCBaseEntity::GetVData() {
    return GCEntitySubclassVDataBase(((Z_CBaseEntity*)m_ptr)->GetVData());
}
void GCBaseEntity::Teleport(Vector value) {
    ((Z_CBaseEntity*)m_ptr)->Teleport(&value, nullptr, nullptr);
}
GCBodyComponent GCBaseEntity::GetCBodyComponent() const {
    GCBodyComponent value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_CBodyComponent"));
    return value;
}
void GCBaseEntity::SetCBodyComponent(GCBodyComponent* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CBodyComponent' is not possible.\n");
}
GCNetworkTransmitComponent GCBaseEntity::GetNetworkTransmitComponent() const {
    GCNetworkTransmitComponent value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_NetworkTransmitComponent"));
    return value;
}
void GCBaseEntity::SetNetworkTransmitComponent(GCNetworkTransmitComponent value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_NetworkTransmitComponent", false, value);
}
std::vector<Gthinkfunc_t> GCBaseEntity::GetThinkFunctions() const {
    CUtlVector<Gthinkfunc_t>* vec = GetSchemaValue<CUtlVector<Gthinkfunc_t>*>(m_ptr, "CBaseEntity", "m_aThinkFunctions"); std::vector<Gthinkfunc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseEntity::SetThinkFunctions(std::vector<Gthinkfunc_t> value) {
    SetSchemaValueCUtlVector<Gthinkfunc_t>(m_ptr, "CBaseEntity", "m_aThinkFunctions", false, value);
}
int32_t GCBaseEntity::GetCurrentThinkContext() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iCurrentThinkContext");
}
void GCBaseEntity::SetCurrentThinkContext(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iCurrentThinkContext", false, value);
}
int32 GCBaseEntity::GetLastThinkTick() const {
    return GetSchemaValue<int32>(m_ptr, "CBaseEntity", "m_nLastThinkTick");
}
void GCBaseEntity::SetLastThinkTick(int32 value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nLastThinkTick", false, value);
}
bool GCBaseEntity::GetDisabledContextThinks() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bDisabledContextThinks");
}
void GCBaseEntity::SetDisabledContextThinks(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bDisabledContextThinks", false, value);
}
float GCBaseEntity::GetLastNetworkChange() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_lastNetworkChange");
}
void GCBaseEntity::SetLastNetworkChange(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_lastNetworkChange", false, value);
}
std::vector<GResponseContext_t> GCBaseEntity::GetResponseContexts() const {
    CUtlVector<GResponseContext_t>* vec = GetSchemaValue<CUtlVector<GResponseContext_t>*>(m_ptr, "CBaseEntity", "m_ResponseContexts"); std::vector<GResponseContext_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseEntity::SetResponseContexts(std::vector<GResponseContext_t> value) {
    SetSchemaValueCUtlVector<GResponseContext_t>(m_ptr, "CBaseEntity", "m_ResponseContexts", false, value);
}
std::string GCBaseEntity::GetResponseContext() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iszResponseContext").String();
}
void GCBaseEntity::SetResponseContext(std::string value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iszResponseContext", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCBaseEntity::GetHealth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iHealth");
}
void GCBaseEntity::SetHealth(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iHealth", false, value);
}
int32_t GCBaseEntity::GetMaxHealth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iMaxHealth");
}
void GCBaseEntity::SetMaxHealth(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iMaxHealth", false, value);
}
uint8_t GCBaseEntity::GetLifeState() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_lifeState");
}
void GCBaseEntity::SetLifeState(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_lifeState", false, value);
}
float GCBaseEntity::GetDamageAccumulator() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flDamageAccumulator");
}
void GCBaseEntity::SetDamageAccumulator(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flDamageAccumulator", false, value);
}
bool GCBaseEntity::GetTakesDamage() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bTakesDamage");
}
void GCBaseEntity::SetTakesDamage(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bTakesDamage", false, value);
}
uint64_t GCBaseEntity::GetTakeDamageFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseEntity", "m_nTakeDamageFlags");
}
void GCBaseEntity::SetTakeDamageFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nTakeDamageFlags", false, value);
}
bool GCBaseEntity::GetIsPlatform() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bIsPlatform");
}
void GCBaseEntity::SetIsPlatform(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bIsPlatform", false, value);
}
uint64_t GCBaseEntity::GetMoveCollide() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseEntity", "m_MoveCollide");
}
void GCBaseEntity::SetMoveCollide(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_MoveCollide", false, value);
}
uint64_t GCBaseEntity::GetMoveType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseEntity", "m_MoveType");
}
void GCBaseEntity::SetMoveType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_MoveType", false, value);
}
uint64_t GCBaseEntity::GetActualMoveType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseEntity", "m_nActualMoveType");
}
void GCBaseEntity::SetActualMoveType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nActualMoveType", false, value);
}
uint8_t GCBaseEntity::GetWaterTouch() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nWaterTouch");
}
void GCBaseEntity::SetWaterTouch(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nWaterTouch", false, value);
}
uint8_t GCBaseEntity::GetSlimeTouch() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nSlimeTouch");
}
void GCBaseEntity::SetSlimeTouch(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nSlimeTouch", false, value);
}
bool GCBaseEntity::GetRestoreInHierarchy() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bRestoreInHierarchy");
}
void GCBaseEntity::SetRestoreInHierarchy(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bRestoreInHierarchy", false, value);
}
std::string GCBaseEntity::GetTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_target").String();
}
void GCBaseEntity::SetTarget(std::string value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_target", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCBaseEntity::GetDamageFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_hDamageFilter"));
    return value;
}
void GCBaseEntity::SetDamageFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageFilter' is not possible.\n");
}
std::string GCBaseEntity::GetDamageFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iszDamageFilterName").String();
}
void GCBaseEntity::SetDamageFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iszDamageFilterName", false, CUtlSymbolLarge(value.c_str()));
}
float GCBaseEntity::GetMoveDoneTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flMoveDoneTime");
}
void GCBaseEntity::SetMoveDoneTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flMoveDoneTime", false, value);
}
CUtlStringToken GCBaseEntity::GetSubclassID() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CBaseEntity", "m_nSubclassID");
}
void GCBaseEntity::SetSubclassID(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nSubclassID", false, value);
}
float GCBaseEntity::GetAnimTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flAnimTime");
}
void GCBaseEntity::SetAnimTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flAnimTime", false, value);
}
float GCBaseEntity::GetSimulationTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flSimulationTime");
}
void GCBaseEntity::SetSimulationTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flSimulationTime", false, value);
}
float GCBaseEntity::GetCreateTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flCreateTime");
}
void GCBaseEntity::SetCreateTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flCreateTime", false, value);
}
bool GCBaseEntity::GetClientSideRagdoll() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bClientSideRagdoll");
}
void GCBaseEntity::SetClientSideRagdoll(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bClientSideRagdoll", false, value);
}
uint8_t GCBaseEntity::GetInterpolationFrame() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_ubInterpolationFrame");
}
void GCBaseEntity::SetInterpolationFrame(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_ubInterpolationFrame", false, value);
}
Vector GCBaseEntity::GetPrevVPhysicsUpdatePos() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vPrevVPhysicsUpdatePos");
}
void GCBaseEntity::SetPrevVPhysicsUpdatePos(Vector value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_vPrevVPhysicsUpdatePos", false, value);
}
uint8_t GCBaseEntity::GetTeamNum() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_iTeamNum");
}
void GCBaseEntity::SetTeamNum(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iTeamNum", false, value);
}
std::string GCBaseEntity::GetGlobalname() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iGlobalname").String();
}
void GCBaseEntity::SetGlobalname(std::string value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iGlobalname", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCBaseEntity::GetSentToClients() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iSentToClients");
}
void GCBaseEntity::SetSentToClients(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iSentToClients", false, value);
}
float GCBaseEntity::GetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flSpeed");
}
void GCBaseEntity::SetSpeed(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flSpeed", false, value);
}
std::string GCBaseEntity::GetUniqueHammerID() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBaseEntity", "m_sUniqueHammerID").Get();
}
void GCBaseEntity::SetUniqueHammerID(std::string value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_sUniqueHammerID", false, CUtlString(value.c_str()));
}
uint32_t GCBaseEntity::GetSpawnflags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_spawnflags");
}
void GCBaseEntity::SetSpawnflags(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_spawnflags", false, value);
}
int32 GCBaseEntity::GetNextThinkTick() const {
    return GetSchemaValue<int32>(m_ptr, "CBaseEntity", "m_nNextThinkTick");
}
void GCBaseEntity::SetNextThinkTick(int32 value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nNextThinkTick", false, value);
}
int32_t GCBaseEntity::GetSimulationTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nSimulationTick");
}
void GCBaseEntity::SetSimulationTick(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nSimulationTick", false, value);
}
GCEntityIOOutput GCBaseEntity::GetOnKilled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_OnKilled"));
    return value;
}
void GCBaseEntity::SetOnKilled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_OnKilled", false, value);
}
uint32_t GCBaseEntity::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_fFlags");
}
void GCBaseEntity::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_fFlags", false, value);
}
Vector GCBaseEntity::GetAbsVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vecAbsVelocity");
}
void GCBaseEntity::SetAbsVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_vecAbsVelocity", false, value);
}
GCNetworkVelocityVector GCBaseEntity::GetVelocity() const {
    GCNetworkVelocityVector value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_vecVelocity"));
    return value;
}
void GCBaseEntity::SetVelocity(GCNetworkVelocityVector value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_vecVelocity", false, value);
}
Vector GCBaseEntity::GetBaseVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vecBaseVelocity");
}
void GCBaseEntity::SetBaseVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_vecBaseVelocity", false, value);
}
int32_t GCBaseEntity::GetPushEnumCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nPushEnumCount");
}
void GCBaseEntity::SetPushEnumCount(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nPushEnumCount", false, value);
}
GCCollisionProperty GCBaseEntity::GetCollision() const {
    GCCollisionProperty value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_pCollision"));
    return value;
}
void GCBaseEntity::SetCollision(GCCollisionProperty* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Collision' is not possible.\n");
}
GCBaseEntity GCBaseEntity::GetEffectEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_hEffectEntity"));
    return value;
}
void GCBaseEntity::SetEffectEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EffectEntity' is not possible.\n");
}
GCBaseEntity GCBaseEntity::GetOwnerEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_hOwnerEntity"));
    return value;
}
void GCBaseEntity::SetOwnerEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwnerEntity' is not possible.\n");
}
uint32_t GCBaseEntity::GetEffects() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_fEffects");
}
void GCBaseEntity::SetEffects(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_fEffects", false, value);
}
GCBaseEntity GCBaseEntity::GetGroundEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_hGroundEntity"));
    return value;
}
void GCBaseEntity::SetGroundEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GroundEntity' is not possible.\n");
}
int32_t GCBaseEntity::GetGroundBodyIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nGroundBodyIndex");
}
void GCBaseEntity::SetGroundBodyIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nGroundBodyIndex", false, value);
}
float GCBaseEntity::GetFriction() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flFriction");
}
void GCBaseEntity::SetFriction(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flFriction", false, value);
}
float GCBaseEntity::GetElasticity() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flElasticity");
}
void GCBaseEntity::SetElasticity(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flElasticity", false, value);
}
float GCBaseEntity::GetGravityScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flGravityScale");
}
void GCBaseEntity::SetGravityScale(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flGravityScale", false, value);
}
float GCBaseEntity::GetTimeScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flTimeScale");
}
void GCBaseEntity::SetTimeScale(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flTimeScale", false, value);
}
float GCBaseEntity::GetWaterLevel() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flWaterLevel");
}
void GCBaseEntity::SetWaterLevel(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flWaterLevel", false, value);
}
bool GCBaseEntity::GetAnimatedEveryTick() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bAnimatedEveryTick");
}
void GCBaseEntity::SetAnimatedEveryTick(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bAnimatedEveryTick", false, value);
}
bool GCBaseEntity::GetDisableLowViolence() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bDisableLowViolence");
}
void GCBaseEntity::SetDisableLowViolence(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bDisableLowViolence", false, value);
}
uint8_t GCBaseEntity::GetWaterType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nWaterType");
}
void GCBaseEntity::SetWaterType(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nWaterType", false, value);
}
int32_t GCBaseEntity::GetEFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iEFlags");
}
void GCBaseEntity::SetEFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iEFlags", false, value);
}
GCEntityIOOutput GCBaseEntity::GetOnUser1() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_OnUser1"));
    return value;
}
void GCBaseEntity::SetOnUser1(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser1", false, value);
}
GCEntityIOOutput GCBaseEntity::GetOnUser2() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_OnUser2"));
    return value;
}
void GCBaseEntity::SetOnUser2(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser2", false, value);
}
GCEntityIOOutput GCBaseEntity::GetOnUser3() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_OnUser3"));
    return value;
}
void GCBaseEntity::SetOnUser3(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser3", false, value);
}
GCEntityIOOutput GCBaseEntity::GetOnUser4() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseEntity", "m_OnUser4"));
    return value;
}
void GCBaseEntity::SetOnUser4(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser4", false, value);
}
int32_t GCBaseEntity::GetInitialTeamNum() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iInitialTeamNum");
}
void GCBaseEntity::SetInitialTeamNum(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_iInitialTeamNum", false, value);
}
float GCBaseEntity::GetNavIgnoreUntilTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flNavIgnoreUntilTime");
}
void GCBaseEntity::SetNavIgnoreUntilTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flNavIgnoreUntilTime", false, value);
}
QAngle GCBaseEntity::GetAngVelocity() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseEntity", "m_vecAngVelocity");
}
void GCBaseEntity::SetAngVelocity(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_vecAngVelocity", false, value);
}
bool GCBaseEntity::GetNetworkQuantizeOriginAndAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bNetworkQuantizeOriginAndAngles");
}
void GCBaseEntity::SetNetworkQuantizeOriginAndAngles(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bNetworkQuantizeOriginAndAngles", false, value);
}
bool GCBaseEntity::GetLagCompensate() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bLagCompensate");
}
void GCBaseEntity::SetLagCompensate(bool value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_bLagCompensate", false, value);
}
float GCBaseEntity::GetOverriddenFriction() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flOverriddenFriction");
}
void GCBaseEntity::SetOverriddenFriction(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flOverriddenFriction", false, value);
}
GCBaseEntity GCBaseEntity::GetBlocker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseEntity", "m_pBlocker"));
    return value;
}
void GCBaseEntity::SetBlocker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Blocker' is not possible.\n");
}
float GCBaseEntity::GetLocalTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flLocalTime");
}
void GCBaseEntity::SetLocalTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flLocalTime", false, value);
}
float GCBaseEntity::GetVPhysicsUpdateLocalTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flVPhysicsUpdateLocalTime");
}
void GCBaseEntity::SetVPhysicsUpdateLocalTime(float value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_flVPhysicsUpdateLocalTime", false, value);
}
uint64_t GCBaseEntity::GetBloodType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseEntity", "m_nBloodType");
}
void GCBaseEntity::SetBloodType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseEntity", "m_nBloodType", false, value);
}
std::string GCBaseEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityInstance GCBaseEntity::GetParent() const {
    GCEntityInstance value(m_ptr);
    return value;
}
void GCBaseEntity::SetParent(GCEntityInstance value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseEntity>("CBaseEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CBodyComponent", &GCBaseEntity::GetCBodyComponent, &GCBaseEntity::SetCBodyComponent)
        .addProperty("NetworkTransmitComponent", &GCBaseEntity::GetNetworkTransmitComponent, &GCBaseEntity::SetNetworkTransmitComponent)
        .addProperty("ThinkFunctions", &GCBaseEntity::GetThinkFunctions, &GCBaseEntity::SetThinkFunctions)
        .addProperty("CurrentThinkContext", &GCBaseEntity::GetCurrentThinkContext, &GCBaseEntity::SetCurrentThinkContext)
        .addProperty("LastThinkTick", &GCBaseEntity::GetLastThinkTick, &GCBaseEntity::SetLastThinkTick)
        .addProperty("DisabledContextThinks", &GCBaseEntity::GetDisabledContextThinks, &GCBaseEntity::SetDisabledContextThinks)
        .addProperty("LastNetworkChange", &GCBaseEntity::GetLastNetworkChange, &GCBaseEntity::SetLastNetworkChange)
        .addProperty("ResponseContexts", &GCBaseEntity::GetResponseContexts, &GCBaseEntity::SetResponseContexts)
        .addProperty("ResponseContext", &GCBaseEntity::GetResponseContext, &GCBaseEntity::SetResponseContext)
        .addProperty("Health", &GCBaseEntity::GetHealth, &GCBaseEntity::SetHealth)
        .addProperty("MaxHealth", &GCBaseEntity::GetMaxHealth, &GCBaseEntity::SetMaxHealth)
        .addProperty("LifeState", &GCBaseEntity::GetLifeState, &GCBaseEntity::SetLifeState)
        .addProperty("DamageAccumulator", &GCBaseEntity::GetDamageAccumulator, &GCBaseEntity::SetDamageAccumulator)
        .addProperty("TakesDamage", &GCBaseEntity::GetTakesDamage, &GCBaseEntity::SetTakesDamage)
        .addProperty("TakeDamageFlags", &GCBaseEntity::GetTakeDamageFlags, &GCBaseEntity::SetTakeDamageFlags)
        .addProperty("IsPlatform", &GCBaseEntity::GetIsPlatform, &GCBaseEntity::SetIsPlatform)
        .addProperty("MoveCollide", &GCBaseEntity::GetMoveCollide, &GCBaseEntity::SetMoveCollide)
        .addProperty("MoveType", &GCBaseEntity::GetMoveType, &GCBaseEntity::SetMoveType)
        .addProperty("ActualMoveType", &GCBaseEntity::GetActualMoveType, &GCBaseEntity::SetActualMoveType)
        .addProperty("WaterTouch", &GCBaseEntity::GetWaterTouch, &GCBaseEntity::SetWaterTouch)
        .addProperty("SlimeTouch", &GCBaseEntity::GetSlimeTouch, &GCBaseEntity::SetSlimeTouch)
        .addProperty("RestoreInHierarchy", &GCBaseEntity::GetRestoreInHierarchy, &GCBaseEntity::SetRestoreInHierarchy)
        .addProperty("Target", &GCBaseEntity::GetTarget, &GCBaseEntity::SetTarget)
        .addProperty("DamageFilter", &GCBaseEntity::GetDamageFilter, &GCBaseEntity::SetDamageFilter)
        .addProperty("DamageFilterName", &GCBaseEntity::GetDamageFilterName, &GCBaseEntity::SetDamageFilterName)
        .addProperty("MoveDoneTime", &GCBaseEntity::GetMoveDoneTime, &GCBaseEntity::SetMoveDoneTime)
        .addProperty("SubclassID", &GCBaseEntity::GetSubclassID, &GCBaseEntity::SetSubclassID)
        .addProperty("AnimTime", &GCBaseEntity::GetAnimTime, &GCBaseEntity::SetAnimTime)
        .addProperty("SimulationTime", &GCBaseEntity::GetSimulationTime, &GCBaseEntity::SetSimulationTime)
        .addProperty("CreateTime", &GCBaseEntity::GetCreateTime, &GCBaseEntity::SetCreateTime)
        .addProperty("ClientSideRagdoll", &GCBaseEntity::GetClientSideRagdoll, &GCBaseEntity::SetClientSideRagdoll)
        .addProperty("InterpolationFrame", &GCBaseEntity::GetInterpolationFrame, &GCBaseEntity::SetInterpolationFrame)
        .addProperty("PrevVPhysicsUpdatePos", &GCBaseEntity::GetPrevVPhysicsUpdatePos, &GCBaseEntity::SetPrevVPhysicsUpdatePos)
        .addProperty("TeamNum", &GCBaseEntity::GetTeamNum, &GCBaseEntity::SetTeamNum)
        .addProperty("Globalname", &GCBaseEntity::GetGlobalname, &GCBaseEntity::SetGlobalname)
        .addProperty("SentToClients", &GCBaseEntity::GetSentToClients, &GCBaseEntity::SetSentToClients)
        .addProperty("Speed", &GCBaseEntity::GetSpeed, &GCBaseEntity::SetSpeed)
        .addProperty("UniqueHammerID", &GCBaseEntity::GetUniqueHammerID, &GCBaseEntity::SetUniqueHammerID)
        .addProperty("Spawnflags", &GCBaseEntity::GetSpawnflags, &GCBaseEntity::SetSpawnflags)
        .addProperty("NextThinkTick", &GCBaseEntity::GetNextThinkTick, &GCBaseEntity::SetNextThinkTick)
        .addProperty("SimulationTick", &GCBaseEntity::GetSimulationTick, &GCBaseEntity::SetSimulationTick)
        .addProperty("OnKilled", &GCBaseEntity::GetOnKilled, &GCBaseEntity::SetOnKilled)
        .addProperty("Flags", &GCBaseEntity::GetFlags, &GCBaseEntity::SetFlags)
        .addProperty("AbsVelocity", &GCBaseEntity::GetAbsVelocity, &GCBaseEntity::SetAbsVelocity)
        .addProperty("Velocity", &GCBaseEntity::GetVelocity, &GCBaseEntity::SetVelocity)
        .addProperty("BaseVelocity", &GCBaseEntity::GetBaseVelocity, &GCBaseEntity::SetBaseVelocity)
        .addProperty("PushEnumCount", &GCBaseEntity::GetPushEnumCount, &GCBaseEntity::SetPushEnumCount)
        .addProperty("Collision", &GCBaseEntity::GetCollision, &GCBaseEntity::SetCollision)
        .addProperty("EffectEntity", &GCBaseEntity::GetEffectEntity, &GCBaseEntity::SetEffectEntity)
        .addProperty("OwnerEntity", &GCBaseEntity::GetOwnerEntity, &GCBaseEntity::SetOwnerEntity)
        .addProperty("Effects", &GCBaseEntity::GetEffects, &GCBaseEntity::SetEffects)
        .addProperty("GroundEntity", &GCBaseEntity::GetGroundEntity, &GCBaseEntity::SetGroundEntity)
        .addProperty("GroundBodyIndex", &GCBaseEntity::GetGroundBodyIndex, &GCBaseEntity::SetGroundBodyIndex)
        .addProperty("Friction", &GCBaseEntity::GetFriction, &GCBaseEntity::SetFriction)
        .addProperty("Elasticity", &GCBaseEntity::GetElasticity, &GCBaseEntity::SetElasticity)
        .addProperty("GravityScale", &GCBaseEntity::GetGravityScale, &GCBaseEntity::SetGravityScale)
        .addProperty("TimeScale", &GCBaseEntity::GetTimeScale, &GCBaseEntity::SetTimeScale)
        .addProperty("WaterLevel", &GCBaseEntity::GetWaterLevel, &GCBaseEntity::SetWaterLevel)
        .addProperty("AnimatedEveryTick", &GCBaseEntity::GetAnimatedEveryTick, &GCBaseEntity::SetAnimatedEveryTick)
        .addProperty("DisableLowViolence", &GCBaseEntity::GetDisableLowViolence, &GCBaseEntity::SetDisableLowViolence)
        .addProperty("WaterType", &GCBaseEntity::GetWaterType, &GCBaseEntity::SetWaterType)
        .addProperty("EFlags", &GCBaseEntity::GetEFlags, &GCBaseEntity::SetEFlags)
        .addProperty("OnUser1", &GCBaseEntity::GetOnUser1, &GCBaseEntity::SetOnUser1)
        .addProperty("OnUser2", &GCBaseEntity::GetOnUser2, &GCBaseEntity::SetOnUser2)
        .addProperty("OnUser3", &GCBaseEntity::GetOnUser3, &GCBaseEntity::SetOnUser3)
        .addProperty("OnUser4", &GCBaseEntity::GetOnUser4, &GCBaseEntity::SetOnUser4)
        .addProperty("InitialTeamNum", &GCBaseEntity::GetInitialTeamNum, &GCBaseEntity::SetInitialTeamNum)
        .addProperty("NavIgnoreUntilTime", &GCBaseEntity::GetNavIgnoreUntilTime, &GCBaseEntity::SetNavIgnoreUntilTime)
        .addProperty("AngVelocity", &GCBaseEntity::GetAngVelocity, &GCBaseEntity::SetAngVelocity)
        .addProperty("NetworkQuantizeOriginAndAngles", &GCBaseEntity::GetNetworkQuantizeOriginAndAngles, &GCBaseEntity::SetNetworkQuantizeOriginAndAngles)
        .addProperty("LagCompensate", &GCBaseEntity::GetLagCompensate, &GCBaseEntity::SetLagCompensate)
        .addProperty("OverriddenFriction", &GCBaseEntity::GetOverriddenFriction, &GCBaseEntity::SetOverriddenFriction)
        .addProperty("Blocker", &GCBaseEntity::GetBlocker, &GCBaseEntity::SetBlocker)
        .addProperty("LocalTime", &GCBaseEntity::GetLocalTime, &GCBaseEntity::SetLocalTime)
        .addProperty("VPhysicsUpdateLocalTime", &GCBaseEntity::GetVPhysicsUpdateLocalTime, &GCBaseEntity::SetVPhysicsUpdateLocalTime)
        .addProperty("BloodType", &GCBaseEntity::GetBloodType, &GCBaseEntity::SetBloodType)
        .addProperty("Parent", &GCBaseEntity::GetParent, &GCBaseEntity::SetParent)
        .addFunction("Spawn", &GCBaseEntity::Spawn)
        .addFunction("Despawn", &GCBaseEntity::Despawn)
        .addFunction("AcceptInput", &GCBaseEntity::AcceptInput)
        .addFunction("GetClassname", &GCBaseEntity::GetClassname)
        .addFunction("GetVData", &GCBaseEntity::GetVData)
        .addFunction("Teleport", &GCBaseEntity::Teleport)
        .addFunction("ToPtr", &GCBaseEntity::ToPtr)
        .addFunction("IsValid", &GCBaseEntity::IsValid)
        .endClass();
}