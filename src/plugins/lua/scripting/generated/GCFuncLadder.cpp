#include "../../../core/scripting/generated/classes/GCFuncLadder.h"
#include "../core.h"

void SetupLuaClassGCFuncLadder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncLadder>("CFuncLadder")
        .addProperty("LadderDir", &GCFuncLadder::GetLadderDir, &GCFuncLadder::SetLadderDir)
        .addProperty("LocalTop", &GCFuncLadder::GetLocalTop, &GCFuncLadder::SetLocalTop)
        .addProperty("PlayerMountPositionTop", &GCFuncLadder::GetPlayerMountPositionTop, &GCFuncLadder::SetPlayerMountPositionTop)
        .addProperty("PlayerMountPositionBottom", &GCFuncLadder::GetPlayerMountPositionBottom, &GCFuncLadder::SetPlayerMountPositionBottom)
        .addProperty("AutoRideSpeed", &GCFuncLadder::GetAutoRideSpeed, &GCFuncLadder::SetAutoRideSpeed)
        .addProperty("Disabled", &GCFuncLadder::GetDisabled, &GCFuncLadder::SetDisabled)
        .addProperty("FakeLadder", &GCFuncLadder::GetFakeLadder, &GCFuncLadder::SetFakeLadder)
        .addProperty("HasSlack", &GCFuncLadder::GetHasSlack, &GCFuncLadder::SetHasSlack)
        .addProperty("SurfacePropName", &GCFuncLadder::GetSurfacePropName, &GCFuncLadder::SetSurfacePropName)
        .addProperty("OnPlayerGotOnLadder", &GCFuncLadder::GetOnPlayerGotOnLadder, &GCFuncLadder::SetOnPlayerGotOnLadder)
        .addProperty("OnPlayerGotOffLadder", &GCFuncLadder::GetOnPlayerGotOffLadder, &GCFuncLadder::SetOnPlayerGotOffLadder)
        .endClass();
}