#include "../../../core/scripting/generated/classes/GCFish.h"
#include "../core.h"

void SetupLuaClassGCFish(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFish>("CFish")
        .addProperty("Pool", &GCFish::GetPool, &GCFish::SetPool)
        .addProperty("Id", &GCFish::GetId, &GCFish::SetId)
        .addProperty("X", &GCFish::GetX, &GCFish::SetX)
        .addProperty("Y", &GCFish::GetY, &GCFish::SetY)
        .addProperty("Z", &GCFish::GetZ, &GCFish::SetZ)
        .addProperty("Angle", &GCFish::GetAngle, &GCFish::SetAngle)
        .addProperty("AngleChange", &GCFish::GetAngleChange, &GCFish::SetAngleChange)
        .addProperty("Forward", &GCFish::GetForward, &GCFish::SetForward)
        .addProperty("Perp", &GCFish::GetPerp, &GCFish::SetPerp)
        .addProperty("PoolOrigin", &GCFish::GetPoolOrigin, &GCFish::SetPoolOrigin)
        .addProperty("WaterLevel", &GCFish::GetWaterLevel, &GCFish::SetWaterLevel)
        .addProperty("Speed", &GCFish::GetSpeed, &GCFish::SetSpeed)
        .addProperty("DesiredSpeed", &GCFish::GetDesiredSpeed, &GCFish::SetDesiredSpeed)
        .addProperty("CalmSpeed", &GCFish::GetCalmSpeed, &GCFish::SetCalmSpeed)
        .addProperty("PanicSpeed", &GCFish::GetPanicSpeed, &GCFish::SetPanicSpeed)
        .addProperty("AvoidRange", &GCFish::GetAvoidRange, &GCFish::SetAvoidRange)
        .addProperty("TurnTimer", &GCFish::GetTurnTimer, &GCFish::SetTurnTimer)
        .addProperty("TurnClockwise", &GCFish::GetTurnClockwise, &GCFish::SetTurnClockwise)
        .addProperty("GoTimer", &GCFish::GetGoTimer, &GCFish::SetGoTimer)
        .addProperty("MoveTimer", &GCFish::GetMoveTimer, &GCFish::SetMoveTimer)
        .addProperty("PanicTimer", &GCFish::GetPanicTimer, &GCFish::SetPanicTimer)
        .addProperty("DisperseTimer", &GCFish::GetDisperseTimer, &GCFish::SetDisperseTimer)
        .addProperty("ProximityTimer", &GCFish::GetProximityTimer, &GCFish::SetProximityTimer)
        .addProperty("Visible", &GCFish::GetVisible, &GCFish::SetVisible)
        .endClass();
}