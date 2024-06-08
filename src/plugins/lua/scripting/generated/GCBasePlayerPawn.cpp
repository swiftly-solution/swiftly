#include "../../../core/scripting/generated/classes/GCBasePlayerPawn.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerPawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerPawn>("CBasePlayerPawn")
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
        .addProperty("InitHUD", &GCBasePlayerPawn::GetInitHUD, &GCBasePlayerPawn::SetInitHUD)
        .addProperty("Expresser", &GCBasePlayerPawn::GetExpresser, &GCBasePlayerPawn::SetExpresser)
        .addProperty("Controller", &GCBasePlayerPawn::GetController, &GCBasePlayerPawn::SetController)
        .addProperty("HltvReplayDelay", &GCBasePlayerPawn::GetHltvReplayDelay, &GCBasePlayerPawn::SetHltvReplayDelay)
        .addProperty("HltvReplayEnd", &GCBasePlayerPawn::GetHltvReplayEnd, &GCBasePlayerPawn::SetHltvReplayEnd)
        .addProperty("HltvReplayEntity", &GCBasePlayerPawn::GetHltvReplayEntity, &GCBasePlayerPawn::SetHltvReplayEntity)
        .addProperty("SndOpvarLatchData", &GCBasePlayerPawn::GetSndOpvarLatchData, &GCBasePlayerPawn::SetSndOpvarLatchData)
        .endClass();
}