#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointsToParticle.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointsToParticle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointsToParticle>("C_OP_SetControlPointsToParticle")
        .addProperty("ChildGroupID", &GC_OP_SetControlPointsToParticle::GetChildGroupID, &GC_OP_SetControlPointsToParticle::SetChildGroupID)
        .addProperty("FirstControlPoint", &GC_OP_SetControlPointsToParticle::GetFirstControlPoint, &GC_OP_SetControlPointsToParticle::SetFirstControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetControlPointsToParticle::GetNumControlPoints, &GC_OP_SetControlPointsToParticle::SetNumControlPoints)
        .addProperty("FirstSourcePoint", &GC_OP_SetControlPointsToParticle::GetFirstSourcePoint, &GC_OP_SetControlPointsToParticle::SetFirstSourcePoint)
        .addProperty("SetOrientation", &GC_OP_SetControlPointsToParticle::GetSetOrientation, &GC_OP_SetControlPointsToParticle::SetSetOrientation)
        .addProperty("OrientationMode", &GC_OP_SetControlPointsToParticle::GetOrientationMode, &GC_OP_SetControlPointsToParticle::SetOrientationMode)
        .addProperty("SetParent", &GC_OP_SetControlPointsToParticle::GetSetParent, &GC_OP_SetControlPointsToParticle::SetSetParent)
        .endClass();
}