#include "../../../core/scripting/generated/classes/GParamSpanSample_t.h"
#include "../core.h"

void SetupLuaClassGParamSpanSample_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParamSpanSample_t>("ParamSpanSample_t")
        .addProperty("Cycle", &GParamSpanSample_t::GetCycle, &GParamSpanSample_t::SetCycle)
        .endClass();
}