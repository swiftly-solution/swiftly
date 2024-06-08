#include "../../../core/scripting/generated/classes/GCFuncMover.h"
#include "../core.h"

void SetupLuaClassGCFuncMover(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMover>("CFuncMover")
        .addProperty("PathName", &GCFuncMover::GetPathName, &GCFuncMover::SetPathName)
        .addProperty("PathMover", &GCFuncMover::GetPathMover, &GCFuncMover::SetPathMover)
        .addProperty("PathNodeStart", &GCFuncMover::GetPathNodeStart, &GCFuncMover::SetPathNodeStart)
        .addProperty("MoveType", &GCFuncMover::GetMoveType, &GCFuncMover::SetMoveType)
        .addProperty("IsReversing", &GCFuncMover::GetIsReversing, &GCFuncMover::SetIsReversing)
        .addProperty("Target", &GCFuncMover::GetTarget, &GCFuncMover::SetTarget)
        .addProperty("StartSpeed", &GCFuncMover::GetStartSpeed, &GCFuncMover::SetStartSpeed)
        .addProperty("PathLocation", &GCFuncMover::GetPathLocation, &GCFuncMover::SetPathLocation)
        .addProperty("T", &GCFuncMover::GetT, &GCFuncMover::SetT)
        .addProperty("CurrentNodeIndex", &GCFuncMover::GetCurrentNodeIndex, &GCFuncMover::SetCurrentNodeIndex)
        .addProperty("PreviousNodeIndex", &GCFuncMover::GetPreviousNodeIndex, &GCFuncMover::SetPreviousNodeIndex)
        .addProperty("FixedOrientation", &GCFuncMover::GetFixedOrientation, &GCFuncMover::SetFixedOrientation)
        .addProperty("FixedPitch", &GCFuncMover::GetFixedPitch, &GCFuncMover::SetFixedPitch)
        .addProperty("SolidType", &GCFuncMover::GetSolidType, &GCFuncMover::SetSolidType)
        .addProperty("IsMoving", &GCFuncMover::GetIsMoving, &GCFuncMover::SetIsMoving)
        .addProperty("TimeToReachMaxSpeed", &GCFuncMover::GetTimeToReachMaxSpeed, &GCFuncMover::SetTimeToReachMaxSpeed)
        .addProperty("TimeToReachZeroSpeed", &GCFuncMover::GetTimeToReachZeroSpeed, &GCFuncMover::SetTimeToReachZeroSpeed)
        .addProperty("StopAtNode", &GCFuncMover::GetStopAtNode, &GCFuncMover::SetStopAtNode)
        .addProperty("PathLocationToBeginStop", &GCFuncMover::GetPathLocationToBeginStop, &GCFuncMover::SetPathLocationToBeginStop)
        .addProperty("MatchPathNodeUp", &GCFuncMover::GetMatchPathNodeUp, &GCFuncMover::SetMatchPathNodeUp)
        .addProperty("FacePlayer", &GCFuncMover::GetFacePlayer, &GCFuncMover::SetFacePlayer)
        .addProperty("OriginalUp", &GCFuncMover::GetOriginalUp, &GCFuncMover::SetOriginalUp)
        .addProperty("TimeToRollToNewUp", &GCFuncMover::GetTimeToRollToNewUp, &GCFuncMover::SetTimeToRollToNewUp)
        .endClass();
}