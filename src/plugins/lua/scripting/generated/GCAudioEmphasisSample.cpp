#include "../../../core/scripting/generated/classes/GCAudioEmphasisSample.h"
#include "../core.h"

void SetupLuaClassGCAudioEmphasisSample(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioEmphasisSample>("CAudioEmphasisSample")
        .addProperty("Time", &GCAudioEmphasisSample::GetTime, &GCAudioEmphasisSample::SetTime)
        .addProperty("Value", &GCAudioEmphasisSample::GetValue, &GCAudioEmphasisSample::SetValue)
        .endClass();
}