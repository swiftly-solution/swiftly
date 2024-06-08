#include "../../../core/scripting/generated/classes/GCCSPlayerBase_CameraServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerBase_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerBase_CameraServices>("CCSPlayerBase_CameraServices")
        .addProperty("FOV", &GCCSPlayerBase_CameraServices::GetFOV, &GCCSPlayerBase_CameraServices::SetFOV)
        .addProperty("FOVStart", &GCCSPlayerBase_CameraServices::GetFOVStart, &GCCSPlayerBase_CameraServices::SetFOVStart)
        .addProperty("FOVRate", &GCCSPlayerBase_CameraServices::GetFOVRate, &GCCSPlayerBase_CameraServices::SetFOVRate)
        .addProperty("ZoomOwner", &GCCSPlayerBase_CameraServices::GetZoomOwner, &GCCSPlayerBase_CameraServices::SetZoomOwner)
        .addProperty("LastFogTrigger", &GCCSPlayerBase_CameraServices::GetLastFogTrigger, &GCCSPlayerBase_CameraServices::SetLastFogTrigger)
        .endClass();
}