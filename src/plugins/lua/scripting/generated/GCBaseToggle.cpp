#include "../../../core/scripting/generated/classes/GCBaseToggle.h"
#include "../core.h"

void SetupLuaClassGCBaseToggle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseToggle>("CBaseToggle")
        .addProperty("Toggle_state", &GCBaseToggle::GetToggle_state, &GCBaseToggle::SetToggle_state)
        .addProperty("MoveDistance", &GCBaseToggle::GetMoveDistance, &GCBaseToggle::SetMoveDistance)
        .addProperty("Wait", &GCBaseToggle::GetWait, &GCBaseToggle::SetWait)
        .addProperty("Lip", &GCBaseToggle::GetLip, &GCBaseToggle::SetLip)
        .addProperty("AlwaysFireBlockedOutputs", &GCBaseToggle::GetAlwaysFireBlockedOutputs, &GCBaseToggle::SetAlwaysFireBlockedOutputs)
        .addProperty("Position1", &GCBaseToggle::GetPosition1, &GCBaseToggle::SetPosition1)
        .addProperty("Position2", &GCBaseToggle::GetPosition2, &GCBaseToggle::SetPosition2)
        .addProperty("MoveAng", &GCBaseToggle::GetMoveAng, &GCBaseToggle::SetMoveAng)
        .addProperty("Angle1", &GCBaseToggle::GetAngle1, &GCBaseToggle::SetAngle1)
        .addProperty("Angle2", &GCBaseToggle::GetAngle2, &GCBaseToggle::SetAngle2)
        .addProperty("Height", &GCBaseToggle::GetHeight, &GCBaseToggle::SetHeight)
        .addProperty("Activator", &GCBaseToggle::GetActivator, &GCBaseToggle::SetActivator)
        .addProperty("FinalDest", &GCBaseToggle::GetFinalDest, &GCBaseToggle::SetFinalDest)
        .addProperty("FinalAngle", &GCBaseToggle::GetFinalAngle, &GCBaseToggle::SetFinalAngle)
        .addProperty("MovementType", &GCBaseToggle::GetMovementType, &GCBaseToggle::SetMovementType)
        .addProperty("Master", &GCBaseToggle::GetMaster, &GCBaseToggle::SetMaster)
        .endClass();
}