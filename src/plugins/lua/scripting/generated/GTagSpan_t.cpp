#include "../../../core/scripting/generated/classes/GTagSpan_t.h"
#include "../core.h"

void SetupLuaClassGTagSpan_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTagSpan_t>("TagSpan_t")
        .addProperty("TagIndex", &GTagSpan_t::GetTagIndex, &GTagSpan_t::SetTagIndex)
        .addProperty("StartCycle", &GTagSpan_t::GetStartCycle, &GTagSpan_t::SetStartCycle)
        .addProperty("EndCycle", &GTagSpan_t::GetEndCycle, &GTagSpan_t::SetEndCycle)
        .endClass();
}