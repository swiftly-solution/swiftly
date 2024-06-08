#include "../../../core/scripting/generated/classes/GC_INIT_InitialRepulsionVelocity.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitialRepulsionVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitialRepulsionVelocity>("C_INIT_InitialRepulsionVelocity")
        .addProperty("CollisionGroupName", &GC_INIT_InitialRepulsionVelocity::GetCollisionGroupName, &GC_INIT_InitialRepulsionVelocity::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_INIT_InitialRepulsionVelocity::GetTraceSet, &GC_INIT_InitialRepulsionVelocity::SetTraceSet)
        .addProperty("OutputMin", &GC_INIT_InitialRepulsionVelocity::GetOutputMin, &GC_INIT_InitialRepulsionVelocity::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_InitialRepulsionVelocity::GetOutputMax, &GC_INIT_InitialRepulsionVelocity::SetOutputMax)
        .addProperty("ControlPointNumber", &GC_INIT_InitialRepulsionVelocity::GetControlPointNumber, &GC_INIT_InitialRepulsionVelocity::SetControlPointNumber)
        .addProperty("PerParticle", &GC_INIT_InitialRepulsionVelocity::GetPerParticle, &GC_INIT_InitialRepulsionVelocity::SetPerParticle)
        .addProperty("Translate", &GC_INIT_InitialRepulsionVelocity::GetTranslate, &GC_INIT_InitialRepulsionVelocity::SetTranslate)
        .addProperty("Proportional", &GC_INIT_InitialRepulsionVelocity::GetProportional, &GC_INIT_InitialRepulsionVelocity::SetProportional)
        .addProperty("TraceLength", &GC_INIT_InitialRepulsionVelocity::GetTraceLength, &GC_INIT_InitialRepulsionVelocity::SetTraceLength)
        .addProperty("PerParticleTR", &GC_INIT_InitialRepulsionVelocity::GetPerParticleTR, &GC_INIT_InitialRepulsionVelocity::SetPerParticleTR)
        .addProperty("Inherit", &GC_INIT_InitialRepulsionVelocity::GetInherit, &GC_INIT_InitialRepulsionVelocity::SetInherit)
        .addProperty("ChildCP", &GC_INIT_InitialRepulsionVelocity::GetChildCP, &GC_INIT_InitialRepulsionVelocity::SetChildCP)
        .addProperty("ChildGroupID", &GC_INIT_InitialRepulsionVelocity::GetChildGroupID, &GC_INIT_InitialRepulsionVelocity::SetChildGroupID)
        .endClass();
}