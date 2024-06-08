#include "../../../core/scripting/generated/classes/GCGameScriptedMoveData.h"
#include "../core.h"

void SetupLuaClassGCGameScriptedMoveData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameScriptedMoveData>("CGameScriptedMoveData")
        .addProperty("AccumulatedRootMotion", &GCGameScriptedMoveData::GetAccumulatedRootMotion, &GCGameScriptedMoveData::SetAccumulatedRootMotion)
        .addProperty("Dest", &GCGameScriptedMoveData::GetDest, &GCGameScriptedMoveData::SetDest)
        .addProperty("Src", &GCGameScriptedMoveData::GetSrc, &GCGameScriptedMoveData::SetSrc)
        .addProperty("Src1", &GCGameScriptedMoveData::GetSrc1, &GCGameScriptedMoveData::SetSrc1)
        .addProperty("Dst", &GCGameScriptedMoveData::GetDst, &GCGameScriptedMoveData::SetDst)
        .addProperty("Current", &GCGameScriptedMoveData::GetCurrent, &GCGameScriptedMoveData::SetCurrent)
        .addProperty("AngRate", &GCGameScriptedMoveData::GetAngRate, &GCGameScriptedMoveData::SetAngRate)
        .addProperty("Duration", &GCGameScriptedMoveData::GetDuration, &GCGameScriptedMoveData::SetDuration)
        .addProperty("Active", &GCGameScriptedMoveData::GetActive, &GCGameScriptedMoveData::SetActive)
        .addProperty("TeleportOnEnd", &GCGameScriptedMoveData::GetTeleportOnEnd, &GCGameScriptedMoveData::SetTeleportOnEnd)
        .addProperty("IgnoreRotation", &GCGameScriptedMoveData::GetIgnoreRotation, &GCGameScriptedMoveData::SetIgnoreRotation)
        .addProperty("Type", &GCGameScriptedMoveData::GetType, &GCGameScriptedMoveData::SetType)
        .addProperty("Success", &GCGameScriptedMoveData::GetSuccess, &GCGameScriptedMoveData::SetSuccess)
        .addProperty("ForcedCrouchState", &GCGameScriptedMoveData::GetForcedCrouchState, &GCGameScriptedMoveData::SetForcedCrouchState)
        .addProperty("IgnoreCollisions", &GCGameScriptedMoveData::GetIgnoreCollisions, &GCGameScriptedMoveData::SetIgnoreCollisions)
        .endClass();
}