#include "../../../core/scripting/generated/classes/GCMovementComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCMovementComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMovementComponentUpdater>("CMovementComponentUpdater")
        .addProperty("FacingDamping", &GCMovementComponentUpdater::GetFacingDamping, &GCMovementComponentUpdater::SetFacingDamping)
        .addProperty("DefaultMotorIndex", &GCMovementComponentUpdater::GetDefaultMotorIndex, &GCMovementComponentUpdater::SetDefaultMotorIndex)
        .addProperty("DefaultRunSpeed", &GCMovementComponentUpdater::GetDefaultRunSpeed, &GCMovementComponentUpdater::SetDefaultRunSpeed)
        .addProperty("MoveVarsDisabled", &GCMovementComponentUpdater::GetMoveVarsDisabled, &GCMovementComponentUpdater::SetMoveVarsDisabled)
        .addProperty("NetworkPath", &GCMovementComponentUpdater::GetNetworkPath, &GCMovementComponentUpdater::SetNetworkPath)
        .addProperty("NetworkFacing", &GCMovementComponentUpdater::GetNetworkFacing, &GCMovementComponentUpdater::SetNetworkFacing)
        .addProperty("ParamHandles", &GCMovementComponentUpdater::GetParamHandles, &GCMovementComponentUpdater::SetParamHandles)
        .endClass();
}