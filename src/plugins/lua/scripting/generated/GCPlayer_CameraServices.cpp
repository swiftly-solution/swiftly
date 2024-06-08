#include "../../../core/scripting/generated/classes/GCPlayer_CameraServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_CameraServices>("CPlayer_CameraServices")
        .addProperty("CsViewPunchAngle", &GCPlayer_CameraServices::GetCsViewPunchAngle, &GCPlayer_CameraServices::SetCsViewPunchAngle)
        .addProperty("CsViewPunchAngleTickRatio", &GCPlayer_CameraServices::GetCsViewPunchAngleTickRatio, &GCPlayer_CameraServices::SetCsViewPunchAngleTickRatio)
        .addProperty("PlayerFog", &GCPlayer_CameraServices::GetPlayerFog, &GCPlayer_CameraServices::SetPlayerFog)
        .addProperty("ColorCorrectionCtrl", &GCPlayer_CameraServices::GetColorCorrectionCtrl, &GCPlayer_CameraServices::SetColorCorrectionCtrl)
        .addProperty("ViewEntity", &GCPlayer_CameraServices::GetViewEntity, &GCPlayer_CameraServices::SetViewEntity)
        .addProperty("TonemapController", &GCPlayer_CameraServices::GetTonemapController, &GCPlayer_CameraServices::SetTonemapController)
        .addProperty("Audio", &GCPlayer_CameraServices::GetAudio, &GCPlayer_CameraServices::SetAudio)
        .addProperty("PostProcessingVolumes", &GCPlayer_CameraServices::GetPostProcessingVolumes, &GCPlayer_CameraServices::SetPostProcessingVolumes)
        .addProperty("OldPlayerZ", &GCPlayer_CameraServices::GetOldPlayerZ, &GCPlayer_CameraServices::SetOldPlayerZ)
        .addProperty("OldPlayerViewOffsetZ", &GCPlayer_CameraServices::GetOldPlayerViewOffsetZ, &GCPlayer_CameraServices::SetOldPlayerViewOffsetZ)
        .endClass();
}