#include "../../../core/scripting/generated/classes/GCFuncTimescale.h"
#include "../core.h"

void SetupLuaClassGCFuncTimescale(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTimescale>("CFuncTimescale")
        .addProperty("DesiredTimescale", &GCFuncTimescale::GetDesiredTimescale, &GCFuncTimescale::SetDesiredTimescale)
        .addProperty("Acceleration", &GCFuncTimescale::GetAcceleration, &GCFuncTimescale::SetAcceleration)
        .addProperty("MinBlendRate", &GCFuncTimescale::GetMinBlendRate, &GCFuncTimescale::SetMinBlendRate)
        .addProperty("BlendDeltaMultiplier", &GCFuncTimescale::GetBlendDeltaMultiplier, &GCFuncTimescale::SetBlendDeltaMultiplier)
        .addProperty("IsStarted", &GCFuncTimescale::GetIsStarted, &GCFuncTimescale::SetIsStarted)
        .endClass();
}