#include "../../../core/scripting/generated/classes/GC_INIT_MoveBetweenPoints.h"
#include "../core.h"

void SetupLuaClassGC_INIT_MoveBetweenPoints(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_MoveBetweenPoints>("C_INIT_MoveBetweenPoints")
        .addProperty("SpeedMin", &GC_INIT_MoveBetweenPoints::GetSpeedMin, &GC_INIT_MoveBetweenPoints::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_MoveBetweenPoints::GetSpeedMax, &GC_INIT_MoveBetweenPoints::SetSpeedMax)
        .addProperty("EndSpread", &GC_INIT_MoveBetweenPoints::GetEndSpread, &GC_INIT_MoveBetweenPoints::SetEndSpread)
        .addProperty("StartOffset", &GC_INIT_MoveBetweenPoints::GetStartOffset, &GC_INIT_MoveBetweenPoints::SetStartOffset)
        .addProperty("EndOffset", &GC_INIT_MoveBetweenPoints::GetEndOffset, &GC_INIT_MoveBetweenPoints::SetEndOffset)
        .addProperty("EndControlPointNumber", &GC_INIT_MoveBetweenPoints::GetEndControlPointNumber, &GC_INIT_MoveBetweenPoints::SetEndControlPointNumber)
        .addProperty("TrailBias", &GC_INIT_MoveBetweenPoints::GetTrailBias, &GC_INIT_MoveBetweenPoints::SetTrailBias)
        .endClass();
}