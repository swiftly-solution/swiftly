#include "../../../core/scripting/generated/classes/GFeAnimStrayRadius_t.h"
#include "../core.h"

void SetupLuaClassGFeAnimStrayRadius_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeAnimStrayRadius_t>("FeAnimStrayRadius_t")
        .addProperty("Node", &GFeAnimStrayRadius_t::GetNode, &GFeAnimStrayRadius_t::SetNode)
        .addProperty("MaxDist", &GFeAnimStrayRadius_t::GetMaxDist, &GFeAnimStrayRadius_t::SetMaxDist)
        .addProperty("RelaxationFactor", &GFeAnimStrayRadius_t::GetRelaxationFactor, &GFeAnimStrayRadius_t::SetRelaxationFactor)
        .endClass();
}