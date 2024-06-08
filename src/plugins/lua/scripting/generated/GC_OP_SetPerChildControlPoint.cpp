#include "../../../core/scripting/generated/classes/GC_OP_SetPerChildControlPoint.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetPerChildControlPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetPerChildControlPoint>("C_OP_SetPerChildControlPoint")
        .addProperty("ChildGroupID", &GC_OP_SetPerChildControlPoint::GetChildGroupID, &GC_OP_SetPerChildControlPoint::SetChildGroupID)
        .addProperty("FirstControlPoint", &GC_OP_SetPerChildControlPoint::GetFirstControlPoint, &GC_OP_SetPerChildControlPoint::SetFirstControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetPerChildControlPoint::GetNumControlPoints, &GC_OP_SetPerChildControlPoint::SetNumControlPoints)
        .addProperty("ParticleIncrement", &GC_OP_SetPerChildControlPoint::GetParticleIncrement, &GC_OP_SetPerChildControlPoint::SetParticleIncrement)
        .addProperty("FirstSourcePoint", &GC_OP_SetPerChildControlPoint::GetFirstSourcePoint, &GC_OP_SetPerChildControlPoint::SetFirstSourcePoint)
        .addProperty("SetOrientation", &GC_OP_SetPerChildControlPoint::GetSetOrientation, &GC_OP_SetPerChildControlPoint::SetSetOrientation)
        .addProperty("OrientationField", &GC_OP_SetPerChildControlPoint::GetOrientationField, &GC_OP_SetPerChildControlPoint::SetOrientationField)
        .addProperty("NumBasedOnParticleCount", &GC_OP_SetPerChildControlPoint::GetNumBasedOnParticleCount, &GC_OP_SetPerChildControlPoint::SetNumBasedOnParticleCount)
        .endClass();
}