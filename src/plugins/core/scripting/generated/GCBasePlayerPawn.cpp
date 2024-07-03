#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerPawn::GCBasePlayerPawn(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerPawn::GCBasePlayerPawn(void *ptr) {
    m_ptr = ptr;
}
GCPlayer_WeaponServices GCBasePlayerPawn::GetWeaponServices() const {
    GCPlayer_WeaponServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pWeaponServices"));
    return value;
}
void GCBasePlayerPawn::SetWeaponServices(GCPlayer_WeaponServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponServices' is not possible.\n");
}
GCPlayer_ItemServices GCBasePlayerPawn::GetItemServices() const {
    GCPlayer_ItemServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pItemServices"));
    return value;
}
void GCBasePlayerPawn::SetItemServices(GCPlayer_ItemServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ItemServices' is not possible.\n");
}
GCPlayer_AutoaimServices GCBasePlayerPawn::GetAutoaimServices() const {
    GCPlayer_AutoaimServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pAutoaimServices"));
    return value;
}
void GCBasePlayerPawn::SetAutoaimServices(GCPlayer_AutoaimServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AutoaimServices' is not possible.\n");
}
GCPlayer_ObserverServices GCBasePlayerPawn::GetObserverServices() const {
    GCPlayer_ObserverServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pObserverServices"));
    return value;
}
void GCBasePlayerPawn::SetObserverServices(GCPlayer_ObserverServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverServices' is not possible.\n");
}
GCPlayer_WaterServices GCBasePlayerPawn::GetWaterServices() const {
    GCPlayer_WaterServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pWaterServices"));
    return value;
}
void GCBasePlayerPawn::SetWaterServices(GCPlayer_WaterServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'WaterServices' is not possible.\n");
}
GCPlayer_UseServices GCBasePlayerPawn::GetUseServices() const {
    GCPlayer_UseServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pUseServices"));
    return value;
}
void GCBasePlayerPawn::SetUseServices(GCPlayer_UseServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'UseServices' is not possible.\n");
}
GCPlayer_FlashlightServices GCBasePlayerPawn::GetFlashlightServices() const {
    GCPlayer_FlashlightServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pFlashlightServices"));
    return value;
}
void GCBasePlayerPawn::SetFlashlightServices(GCPlayer_FlashlightServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'FlashlightServices' is not possible.\n");
}
GCPlayer_CameraServices GCBasePlayerPawn::GetCameraServices() const {
    GCPlayer_CameraServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pCameraServices"));
    return value;
}
void GCBasePlayerPawn::SetCameraServices(GCPlayer_CameraServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CameraServices' is not possible.\n");
}
GCPlayer_MovementServices GCBasePlayerPawn::GetMovementServices() const {
    GCPlayer_MovementServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pMovementServices"));
    return value;
}
void GCBasePlayerPawn::SetMovementServices(GCPlayer_MovementServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MovementServices' is not possible.\n");
}
std::vector<GViewAngleServerChange_t> GCBasePlayerPawn::GetServerViewAngleChanges() const {
    CUtlVector<GViewAngleServerChange_t>* vec = GetSchemaValue<CUtlVector<GViewAngleServerChange_t>*>(m_ptr, "CBasePlayerPawn", "m_ServerViewAngleChanges"); std::vector<GViewAngleServerChange_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBasePlayerPawn::SetServerViewAngleChanges(std::vector<GViewAngleServerChange_t> value) {
    SetSchemaValueCUtlVector<GViewAngleServerChange_t>(m_ptr, "CBasePlayerPawn", "m_ServerViewAngleChanges", false, value);
}
uint32_t GCBasePlayerPawn::GetHighestGeneratedServerViewAngleChangeIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerPawn", "m_nHighestGeneratedServerViewAngleChangeIndex");
}
void GCBasePlayerPawn::SetHighestGeneratedServerViewAngleChangeIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_nHighestGeneratedServerViewAngleChangeIndex", false, value);
}
QAngle GCBasePlayerPawn::Get_angle() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBasePlayerPawn", "v_angle");
}
void GCBasePlayerPawn::Set_angle(QAngle value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "v_angle", false, value);
}
QAngle GCBasePlayerPawn::Get_anglePrevious() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBasePlayerPawn", "v_anglePrevious");
}
void GCBasePlayerPawn::Set_anglePrevious(QAngle value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "v_anglePrevious", false, value);
}
uint32_t GCBasePlayerPawn::GetHideHUD() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerPawn", "m_iHideHUD");
}
void GCBasePlayerPawn::SetHideHUD(uint32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_iHideHUD", false, value);
}
Gsky3dparams_t GCBasePlayerPawn::GetSkybox3d() const {
    Gsky3dparams_t value(GetSchemaPtr(m_ptr, "CBasePlayerPawn", "m_skybox3d"));
    return value;
}
void GCBasePlayerPawn::SetSkybox3d(Gsky3dparams_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_skybox3d", false, value);
}
float GCBasePlayerPawn::GetTimeLastHurt() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fTimeLastHurt");
}
void GCBasePlayerPawn::SetTimeLastHurt(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fTimeLastHurt", false, value);
}
float GCBasePlayerPawn::GetDeathTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_flDeathTime");
}
void GCBasePlayerPawn::SetDeathTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_flDeathTime", false, value);
}
float GCBasePlayerPawn::GetNextSuicideTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fNextSuicideTime");
}
void GCBasePlayerPawn::SetNextSuicideTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fNextSuicideTime", false, value);
}
bool GCBasePlayerPawn::GetInitHUD() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerPawn", "m_fInitHUD");
}
void GCBasePlayerPawn::SetInitHUD(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fInitHUD", false, value);
}
GCAI_Expresser GCBasePlayerPawn::GetExpresser() const {
    GCAI_Expresser value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_pExpresser"));
    return value;
}
void GCBasePlayerPawn::SetExpresser(GCAI_Expresser* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Expresser' is not possible.\n");
}
GCBasePlayerController GCBasePlayerPawn::GetController() const {
    GCBasePlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerPawn", "m_hController"));
    return value;
}
void GCBasePlayerPawn::SetController(GCBasePlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Controller' is not possible.\n");
}
float GCBasePlayerPawn::GetHltvReplayDelay() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fHltvReplayDelay");
}
void GCBasePlayerPawn::SetHltvReplayDelay(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fHltvReplayDelay", false, value);
}
float GCBasePlayerPawn::GetHltvReplayEnd() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fHltvReplayEnd");
}
void GCBasePlayerPawn::SetHltvReplayEnd(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fHltvReplayEnd", false, value);
}
CEntityIndex GCBasePlayerPawn::GetHltvReplayEntity() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CBasePlayerPawn", "m_iHltvReplayEntity");
}
void GCBasePlayerPawn::SetHltvReplayEntity(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_iHltvReplayEntity", false, value);
}
std::vector<Gsndopvarlatchdata_t> GCBasePlayerPawn::GetSndOpvarLatchData() const {
    CUtlVector<Gsndopvarlatchdata_t>* vec = GetSchemaValue<CUtlVector<Gsndopvarlatchdata_t>*>(m_ptr, "CBasePlayerPawn", "m_sndOpvarLatchData"); std::vector<Gsndopvarlatchdata_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBasePlayerPawn::SetSndOpvarLatchData(std::vector<Gsndopvarlatchdata_t> value) {
    SetSchemaValueCUtlVector<Gsndopvarlatchdata_t>(m_ptr, "CBasePlayerPawn", "m_sndOpvarLatchData", false, value);
}
std::string GCBasePlayerPawn::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerPawn::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCombatCharacter GCBasePlayerPawn::GetParent() const {
    GCBaseCombatCharacter value(m_ptr);
    return value;
}
void GCBasePlayerPawn::SetParent(GCBaseCombatCharacter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlayerPawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerPawn>("CBasePlayerPawn")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeaponServices", &GCBasePlayerPawn::GetWeaponServices, &GCBasePlayerPawn::SetWeaponServices)
        .addProperty("ItemServices", &GCBasePlayerPawn::GetItemServices, &GCBasePlayerPawn::SetItemServices)
        .addProperty("AutoaimServices", &GCBasePlayerPawn::GetAutoaimServices, &GCBasePlayerPawn::SetAutoaimServices)
        .addProperty("ObserverServices", &GCBasePlayerPawn::GetObserverServices, &GCBasePlayerPawn::SetObserverServices)
        .addProperty("WaterServices", &GCBasePlayerPawn::GetWaterServices, &GCBasePlayerPawn::SetWaterServices)
        .addProperty("UseServices", &GCBasePlayerPawn::GetUseServices, &GCBasePlayerPawn::SetUseServices)
        .addProperty("FlashlightServices", &GCBasePlayerPawn::GetFlashlightServices, &GCBasePlayerPawn::SetFlashlightServices)
        .addProperty("CameraServices", &GCBasePlayerPawn::GetCameraServices, &GCBasePlayerPawn::SetCameraServices)
        .addProperty("MovementServices", &GCBasePlayerPawn::GetMovementServices, &GCBasePlayerPawn::SetMovementServices)
        .addProperty("ServerViewAngleChanges", &GCBasePlayerPawn::GetServerViewAngleChanges, &GCBasePlayerPawn::SetServerViewAngleChanges)
        .addProperty("HighestGeneratedServerViewAngleChangeIndex", &GCBasePlayerPawn::GetHighestGeneratedServerViewAngleChangeIndex, &GCBasePlayerPawn::SetHighestGeneratedServerViewAngleChangeIndex)
        .addProperty("_angle", &GCBasePlayerPawn::Get_angle, &GCBasePlayerPawn::Set_angle)
        .addProperty("_anglePrevious", &GCBasePlayerPawn::Get_anglePrevious, &GCBasePlayerPawn::Set_anglePrevious)
        .addProperty("HideHUD", &GCBasePlayerPawn::GetHideHUD, &GCBasePlayerPawn::SetHideHUD)
        .addProperty("Skybox3d", &GCBasePlayerPawn::GetSkybox3d, &GCBasePlayerPawn::SetSkybox3d)
        .addProperty("TimeLastHurt", &GCBasePlayerPawn::GetTimeLastHurt, &GCBasePlayerPawn::SetTimeLastHurt)
        .addProperty("DeathTime", &GCBasePlayerPawn::GetDeathTime, &GCBasePlayerPawn::SetDeathTime)
        .addProperty("NextSuicideTime", &GCBasePlayerPawn::GetNextSuicideTime, &GCBasePlayerPawn::SetNextSuicideTime)
        .addProperty("InitHUD", &GCBasePlayerPawn::GetInitHUD, &GCBasePlayerPawn::SetInitHUD)
        .addProperty("Expresser", &GCBasePlayerPawn::GetExpresser, &GCBasePlayerPawn::SetExpresser)
        .addProperty("Controller", &GCBasePlayerPawn::GetController, &GCBasePlayerPawn::SetController)
        .addProperty("HltvReplayDelay", &GCBasePlayerPawn::GetHltvReplayDelay, &GCBasePlayerPawn::SetHltvReplayDelay)
        .addProperty("HltvReplayEnd", &GCBasePlayerPawn::GetHltvReplayEnd, &GCBasePlayerPawn::SetHltvReplayEnd)
        .addProperty("HltvReplayEntity", &GCBasePlayerPawn::GetHltvReplayEntity, &GCBasePlayerPawn::SetHltvReplayEntity)
        .addProperty("SndOpvarLatchData", &GCBasePlayerPawn::GetSndOpvarLatchData, &GCBasePlayerPawn::SetSndOpvarLatchData)
        .addProperty("Parent", &GCBasePlayerPawn::GetParent, &GCBasePlayerPawn::SetParent)
        .addFunction("ToPtr", &GCBasePlayerPawn::ToPtr)
        .addFunction("IsValid", &GCBasePlayerPawn::IsValid)
        .endClass();
}