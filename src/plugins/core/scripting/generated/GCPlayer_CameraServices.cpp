#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_CameraServices::GCPlayer_CameraServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_CameraServices::GCPlayer_CameraServices(void *ptr) {
    m_ptr = ptr;
}
QAngle GCPlayer_CameraServices::GetCsViewPunchAngle() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPlayer_CameraServices", "m_vecCsViewPunchAngle");
}
void GCPlayer_CameraServices::SetCsViewPunchAngle(QAngle value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_vecCsViewPunchAngle", false, value);
}
int32 GCPlayer_CameraServices::GetCsViewPunchAngleTick() const {
    return GetSchemaValue<int32>(m_ptr, "CPlayer_CameraServices", "m_nCsViewPunchAngleTick");
}
void GCPlayer_CameraServices::SetCsViewPunchAngleTick(int32 value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_nCsViewPunchAngleTick", false, value);
}
float GCPlayer_CameraServices::GetCsViewPunchAngleTickRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flCsViewPunchAngleTickRatio");
}
void GCPlayer_CameraServices::SetCsViewPunchAngleTickRatio(float value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flCsViewPunchAngleTickRatio", false, value);
}
Gfogplayerparams_t GCPlayer_CameraServices::GetPlayerFog() const {
    Gfogplayerparams_t value(GetSchemaPtr(m_ptr, "CPlayer_CameraServices", "m_PlayerFog"));
    return value;
}
void GCPlayer_CameraServices::SetPlayerFog(Gfogplayerparams_t value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_PlayerFog", false, value);
}
GCColorCorrection GCPlayer_CameraServices::GetColorCorrectionCtrl() const {
    GCColorCorrection value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_CameraServices", "m_hColorCorrectionCtrl"));
    return value;
}
void GCPlayer_CameraServices::SetColorCorrectionCtrl(GCColorCorrection* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ColorCorrectionCtrl' is not possible.\n");
}
GCBaseEntity GCPlayer_CameraServices::GetViewEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_CameraServices", "m_hViewEntity"));
    return value;
}
void GCPlayer_CameraServices::SetViewEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ViewEntity' is not possible.\n");
}
GCTonemapController2 GCPlayer_CameraServices::GetTonemapController() const {
    GCTonemapController2 value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_CameraServices", "m_hTonemapController"));
    return value;
}
void GCPlayer_CameraServices::SetTonemapController(GCTonemapController2* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TonemapController' is not possible.\n");
}
Gaudioparams_t GCPlayer_CameraServices::GetAudio() const {
    Gaudioparams_t value(GetSchemaPtr(m_ptr, "CPlayer_CameraServices", "m_audio"));
    return value;
}
void GCPlayer_CameraServices::SetAudio(Gaudioparams_t value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_audio", false, value);
}
std::vector<GCPostProcessingVolume*> GCPlayer_CameraServices::GetPostProcessingVolumes() const {
    CUtlVector<GCPostProcessingVolume*>* vec = GetSchemaValue<CUtlVector<GCPostProcessingVolume*>*>(m_ptr, "CPlayer_CameraServices", "m_PostProcessingVolumes"); std::vector<GCPostProcessingVolume*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPlayer_CameraServices::SetPostProcessingVolumes(std::vector<GCPostProcessingVolume*> value) {
    SetSchemaValueCUtlVector<GCPostProcessingVolume*>(m_ptr, "CPlayer_CameraServices", "m_PostProcessingVolumes", false, value);
}
float GCPlayer_CameraServices::GetOldPlayerZ() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerZ");
}
void GCPlayer_CameraServices::SetOldPlayerZ(float value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerZ", false, value);
}
float GCPlayer_CameraServices::GetOldPlayerViewOffsetZ() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ");
}
void GCPlayer_CameraServices::SetOldPlayerViewOffsetZ(float value) {
    SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ", false, value);
}
std::string GCPlayer_CameraServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_CameraServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_CameraServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_CameraServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_CameraServices>("CPlayer_CameraServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CsViewPunchAngle", &GCPlayer_CameraServices::GetCsViewPunchAngle, &GCPlayer_CameraServices::SetCsViewPunchAngle)
        .addProperty("CsViewPunchAngleTick", &GCPlayer_CameraServices::GetCsViewPunchAngleTick, &GCPlayer_CameraServices::SetCsViewPunchAngleTick)
        .addProperty("CsViewPunchAngleTickRatio", &GCPlayer_CameraServices::GetCsViewPunchAngleTickRatio, &GCPlayer_CameraServices::SetCsViewPunchAngleTickRatio)
        .addProperty("PlayerFog", &GCPlayer_CameraServices::GetPlayerFog, &GCPlayer_CameraServices::SetPlayerFog)
        .addProperty("ColorCorrectionCtrl", &GCPlayer_CameraServices::GetColorCorrectionCtrl, &GCPlayer_CameraServices::SetColorCorrectionCtrl)
        .addProperty("ViewEntity", &GCPlayer_CameraServices::GetViewEntity, &GCPlayer_CameraServices::SetViewEntity)
        .addProperty("TonemapController", &GCPlayer_CameraServices::GetTonemapController, &GCPlayer_CameraServices::SetTonemapController)
        .addProperty("Audio", &GCPlayer_CameraServices::GetAudio, &GCPlayer_CameraServices::SetAudio)
        .addProperty("PostProcessingVolumes", &GCPlayer_CameraServices::GetPostProcessingVolumes, &GCPlayer_CameraServices::SetPostProcessingVolumes)
        .addProperty("OldPlayerZ", &GCPlayer_CameraServices::GetOldPlayerZ, &GCPlayer_CameraServices::SetOldPlayerZ)
        .addProperty("OldPlayerViewOffsetZ", &GCPlayer_CameraServices::GetOldPlayerViewOffsetZ, &GCPlayer_CameraServices::SetOldPlayerViewOffsetZ)
        .addProperty("Parent", &GCPlayer_CameraServices::GetParent, &GCPlayer_CameraServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_CameraServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_CameraServices::IsValid)
        .endClass();
}