#include "../../../core/scripting/generated/classes/GC_INIT_CreatePhyllotaxis.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreatePhyllotaxis(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreatePhyllotaxis>("C_INIT_CreatePhyllotaxis")
        .addProperty("ControlPointNumber", &GC_INIT_CreatePhyllotaxis::GetControlPointNumber, &GC_INIT_CreatePhyllotaxis::SetControlPointNumber)
        .addProperty("ScaleCP", &GC_INIT_CreatePhyllotaxis::GetScaleCP, &GC_INIT_CreatePhyllotaxis::SetScaleCP)
        .addProperty("Component", &GC_INIT_CreatePhyllotaxis::GetComponent, &GC_INIT_CreatePhyllotaxis::SetComponent)
        .addProperty("RadCentCore", &GC_INIT_CreatePhyllotaxis::GetRadCentCore, &GC_INIT_CreatePhyllotaxis::SetRadCentCore)
        .addProperty("RadPerPoint", &GC_INIT_CreatePhyllotaxis::GetRadPerPoint, &GC_INIT_CreatePhyllotaxis::SetRadPerPoint)
        .addProperty("RadPerPointTo", &GC_INIT_CreatePhyllotaxis::GetRadPerPointTo, &GC_INIT_CreatePhyllotaxis::SetRadPerPointTo)
        .addProperty("FpointAngle", &GC_INIT_CreatePhyllotaxis::GetFpointAngle, &GC_INIT_CreatePhyllotaxis::SetFpointAngle)
        .addProperty("FsizeOverall", &GC_INIT_CreatePhyllotaxis::GetFsizeOverall, &GC_INIT_CreatePhyllotaxis::SetFsizeOverall)
        .addProperty("RadBias", &GC_INIT_CreatePhyllotaxis::GetRadBias, &GC_INIT_CreatePhyllotaxis::SetRadBias)
        .addProperty("MinRad", &GC_INIT_CreatePhyllotaxis::GetMinRad, &GC_INIT_CreatePhyllotaxis::SetMinRad)
        .addProperty("DistBias", &GC_INIT_CreatePhyllotaxis::GetDistBias, &GC_INIT_CreatePhyllotaxis::SetDistBias)
        .addProperty("UseLocalCoords", &GC_INIT_CreatePhyllotaxis::GetUseLocalCoords, &GC_INIT_CreatePhyllotaxis::SetUseLocalCoords)
        .addProperty("UseWithContEmit", &GC_INIT_CreatePhyllotaxis::GetUseWithContEmit, &GC_INIT_CreatePhyllotaxis::SetUseWithContEmit)
        .addProperty("UseOrigRadius", &GC_INIT_CreatePhyllotaxis::GetUseOrigRadius, &GC_INIT_CreatePhyllotaxis::SetUseOrigRadius)
        .endClass();
}