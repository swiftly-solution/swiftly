#include "../../../core/scripting/generated/classes/GParamSpan_t.h"
#include "../core.h"

void SetupLuaClassGParamSpan_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParamSpan_t>("ParamSpan_t")
        .addProperty("Samples", &GParamSpan_t::GetSamples, &GParamSpan_t::SetSamples)
        .addProperty("Param", &GParamSpan_t::GetParam, &GParamSpan_t::SetParam)
        .addProperty("ParamType", &GParamSpan_t::GetParamType, &GParamSpan_t::SetParamType)
        .addProperty("StartCycle", &GParamSpan_t::GetStartCycle, &GParamSpan_t::SetStartCycle)
        .addProperty("EndCycle", &GParamSpan_t::GetEndCycle, &GParamSpan_t::SetEndCycle)
        .endClass();
}