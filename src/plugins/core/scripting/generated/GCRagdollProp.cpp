#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollProp::GCRagdollProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollProp::GCRagdollProp(void *ptr) {
    m_ptr = ptr;
}
Gragdoll_t GCRagdollProp::GetRagdoll() const {
    Gragdoll_t value(GetSchemaPtr(m_ptr, "CRagdollProp", "m_ragdoll"));
    return value;
}
void GCRagdollProp::SetRagdoll(Gragdoll_t value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_ragdoll", false, value);
}
bool GCRagdollProp::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bStartDisabled");
}
void GCRagdollProp::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bStartDisabled", false, value);
}
std::vector<Vector> GCRagdollProp::GetRagPos() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollProp::SetRagPos(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragPos", false, value);
}
std::vector<QAngle> GCRagdollProp::GetRagAngles() const {
    CUtlVector<QAngle>* vec = GetSchemaValue<CUtlVector<QAngle>*>(m_ptr, "CRagdollProp", "m_ragAngles"); std::vector<QAngle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollProp::SetRagAngles(std::vector<QAngle> value) {
    SetSchemaValueCUtlVector<QAngle>(m_ptr, "CRagdollProp", "m_ragAngles", false, value);
}
GCBaseEntity GCRagdollProp::GetRagdollSource() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRagdollProp", "m_hRagdollSource"));
    return value;
}
void GCRagdollProp::SetRagdollSource(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RagdollSource' is not possible.\n");
}
uint32_t GCRagdollProp::GetLastUpdateTickCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CRagdollProp", "m_lastUpdateTickCount");
}
void GCRagdollProp::SetLastUpdateTickCount(uint32_t value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_lastUpdateTickCount", false, value);
}
bool GCRagdollProp::GetAllAsleep() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_allAsleep");
}
void GCRagdollProp::SetAllAsleep(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_allAsleep", false, value);
}
bool GCRagdollProp::GetFirstCollisionAfterLaunch() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bFirstCollisionAfterLaunch");
}
void GCRagdollProp::SetFirstCollisionAfterLaunch(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bFirstCollisionAfterLaunch", false, value);
}
GCBaseEntity GCRagdollProp::GetDamageEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRagdollProp", "m_hDamageEntity"));
    return value;
}
void GCRagdollProp::SetDamageEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageEntity' is not possible.\n");
}
GCBaseEntity GCRagdollProp::GetKiller() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRagdollProp", "m_hKiller"));
    return value;
}
void GCRagdollProp::SetKiller(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Killer' is not possible.\n");
}
GCBasePlayerPawn GCRagdollProp::GetPhysicsAttacker() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CRagdollProp", "m_hPhysicsAttacker"));
    return value;
}
void GCRagdollProp::SetPhysicsAttacker(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n");
}
float GCRagdollProp::GetLastPhysicsInfluenceTime() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flLastPhysicsInfluenceTime");
}
void GCRagdollProp::SetLastPhysicsInfluenceTime(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flLastPhysicsInfluenceTime", false, value);
}
float GCRagdollProp::GetFadeOutStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flFadeOutStartTime");
}
void GCRagdollProp::SetFadeOutStartTime(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flFadeOutStartTime", false, value);
}
float GCRagdollProp::GetFadeTime() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flFadeTime");
}
void GCRagdollProp::SetFadeTime(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flFadeTime", false, value);
}
Vector GCRagdollProp::GetLastOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CRagdollProp", "m_vecLastOrigin");
}
void GCRagdollProp::SetLastOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_vecLastOrigin", false, value);
}
float GCRagdollProp::GetAwakeTime() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flAwakeTime");
}
void GCRagdollProp::SetAwakeTime(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flAwakeTime", false, value);
}
float GCRagdollProp::GetLastOriginChangeTime() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flLastOriginChangeTime");
}
void GCRagdollProp::SetLastOriginChangeTime(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flLastOriginChangeTime", false, value);
}
std::string GCRagdollProp::GetStrOriginClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRagdollProp", "m_strOriginClassName").String();
}
void GCRagdollProp::SetStrOriginClassName(std::string value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_strOriginClassName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCRagdollProp::GetStrSourceClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRagdollProp", "m_strSourceClassName").String();
}
void GCRagdollProp::SetStrSourceClassName(std::string value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_strSourceClassName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCRagdollProp::GetHasBeenPhysgunned() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bHasBeenPhysgunned");
}
void GCRagdollProp::SetHasBeenPhysgunned(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bHasBeenPhysgunned", false, value);
}
bool GCRagdollProp::GetShouldTeleportPhysics() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bShouldTeleportPhysics");
}
void GCRagdollProp::SetShouldTeleportPhysics(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bShouldTeleportPhysics", false, value);
}
float GCRagdollProp::GetBlendWeight() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flBlendWeight");
}
void GCRagdollProp::SetBlendWeight(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flBlendWeight", false, value);
}
float GCRagdollProp::GetDefaultFadeScale() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flDefaultFadeScale");
}
void GCRagdollProp::SetDefaultFadeScale(float value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_flDefaultFadeScale", false, value);
}
std::vector<Vector> GCRagdollProp::GetRagdollMins() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragdollMins"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollProp::SetRagdollMins(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragdollMins", false, value);
}
std::vector<Vector> GCRagdollProp::GetRagdollMaxs() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragdollMaxs"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollProp::SetRagdollMaxs(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragdollMaxs", false, value);
}
bool GCRagdollProp::GetShouldDeleteActivationRecord() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bShouldDeleteActivationRecord");
}
void GCRagdollProp::SetShouldDeleteActivationRecord(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bShouldDeleteActivationRecord", false, value);
}
bool GCRagdollProp::GetValidatePoweredRagdollPose() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bValidatePoweredRagdollPose");
}
void GCRagdollProp::SetValidatePoweredRagdollPose(bool value) {
    SetSchemaValue(m_ptr, "CRagdollProp", "m_bValidatePoweredRagdollPose", false, value);
}
std::string GCRagdollProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCRagdollProp::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCRagdollProp::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollProp>("CRagdollProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Ragdoll", &GCRagdollProp::GetRagdoll, &GCRagdollProp::SetRagdoll)
        .addProperty("StartDisabled", &GCRagdollProp::GetStartDisabled, &GCRagdollProp::SetStartDisabled)
        .addProperty("RagPos", &GCRagdollProp::GetRagPos, &GCRagdollProp::SetRagPos)
        .addProperty("RagAngles", &GCRagdollProp::GetRagAngles, &GCRagdollProp::SetRagAngles)
        .addProperty("RagdollSource", &GCRagdollProp::GetRagdollSource, &GCRagdollProp::SetRagdollSource)
        .addProperty("LastUpdateTickCount", &GCRagdollProp::GetLastUpdateTickCount, &GCRagdollProp::SetLastUpdateTickCount)
        .addProperty("AllAsleep", &GCRagdollProp::GetAllAsleep, &GCRagdollProp::SetAllAsleep)
        .addProperty("FirstCollisionAfterLaunch", &GCRagdollProp::GetFirstCollisionAfterLaunch, &GCRagdollProp::SetFirstCollisionAfterLaunch)
        .addProperty("DamageEntity", &GCRagdollProp::GetDamageEntity, &GCRagdollProp::SetDamageEntity)
        .addProperty("Killer", &GCRagdollProp::GetKiller, &GCRagdollProp::SetKiller)
        .addProperty("PhysicsAttacker", &GCRagdollProp::GetPhysicsAttacker, &GCRagdollProp::SetPhysicsAttacker)
        .addProperty("LastPhysicsInfluenceTime", &GCRagdollProp::GetLastPhysicsInfluenceTime, &GCRagdollProp::SetLastPhysicsInfluenceTime)
        .addProperty("FadeOutStartTime", &GCRagdollProp::GetFadeOutStartTime, &GCRagdollProp::SetFadeOutStartTime)
        .addProperty("FadeTime", &GCRagdollProp::GetFadeTime, &GCRagdollProp::SetFadeTime)
        .addProperty("LastOrigin", &GCRagdollProp::GetLastOrigin, &GCRagdollProp::SetLastOrigin)
        .addProperty("AwakeTime", &GCRagdollProp::GetAwakeTime, &GCRagdollProp::SetAwakeTime)
        .addProperty("LastOriginChangeTime", &GCRagdollProp::GetLastOriginChangeTime, &GCRagdollProp::SetLastOriginChangeTime)
        .addProperty("StrOriginClassName", &GCRagdollProp::GetStrOriginClassName, &GCRagdollProp::SetStrOriginClassName)
        .addProperty("StrSourceClassName", &GCRagdollProp::GetStrSourceClassName, &GCRagdollProp::SetStrSourceClassName)
        .addProperty("HasBeenPhysgunned", &GCRagdollProp::GetHasBeenPhysgunned, &GCRagdollProp::SetHasBeenPhysgunned)
        .addProperty("ShouldTeleportPhysics", &GCRagdollProp::GetShouldTeleportPhysics, &GCRagdollProp::SetShouldTeleportPhysics)
        .addProperty("BlendWeight", &GCRagdollProp::GetBlendWeight, &GCRagdollProp::SetBlendWeight)
        .addProperty("DefaultFadeScale", &GCRagdollProp::GetDefaultFadeScale, &GCRagdollProp::SetDefaultFadeScale)
        .addProperty("RagdollMins", &GCRagdollProp::GetRagdollMins, &GCRagdollProp::SetRagdollMins)
        .addProperty("RagdollMaxs", &GCRagdollProp::GetRagdollMaxs, &GCRagdollProp::SetRagdollMaxs)
        .addProperty("ShouldDeleteActivationRecord", &GCRagdollProp::GetShouldDeleteActivationRecord, &GCRagdollProp::SetShouldDeleteActivationRecord)
        .addProperty("ValidatePoweredRagdollPose", &GCRagdollProp::GetValidatePoweredRagdollPose, &GCRagdollProp::SetValidatePoweredRagdollPose)
        .addProperty("Parent", &GCRagdollProp::GetParent, &GCRagdollProp::SetParent)
        .addFunction("ToPtr", &GCRagdollProp::ToPtr)
        .addFunction("IsValid", &GCRagdollProp::IsValid)
        .endClass();
}