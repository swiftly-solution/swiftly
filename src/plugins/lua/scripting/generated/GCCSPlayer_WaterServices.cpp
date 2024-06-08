#include "../../../core/scripting/generated/classes/GCCSPlayer_WaterServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_WaterServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_WaterServices>("CCSPlayer_WaterServices")
        .addProperty("NextDrownDamageTime", &GCCSPlayer_WaterServices::GetNextDrownDamageTime, &GCCSPlayer_WaterServices::SetNextDrownDamageTime)
        .addProperty("DrownDmgRate", &GCCSPlayer_WaterServices::GetDrownDmgRate, &GCCSPlayer_WaterServices::SetDrownDmgRate)
        .addProperty("WaterJumpTime", &GCCSPlayer_WaterServices::GetWaterJumpTime, &GCCSPlayer_WaterServices::SetWaterJumpTime)
        .addProperty("WaterJumpVel", &GCCSPlayer_WaterServices::GetWaterJumpVel, &GCCSPlayer_WaterServices::SetWaterJumpVel)
        .addProperty("SwimSoundTime", &GCCSPlayer_WaterServices::GetSwimSoundTime, &GCCSPlayer_WaterServices::SetSwimSoundTime)
        .endClass();
}