#include "../../../core/scripting/generated/classes/GFeSimdAnimStrayRadius_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdAnimStrayRadius_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdAnimStrayRadius_t>("FeSimdAnimStrayRadius_t")
        .addProperty("MaxDist", &GFeSimdAnimStrayRadius_t::GetMaxDist, &GFeSimdAnimStrayRadius_t::SetMaxDist)
        .addProperty("RelaxationFactor", &GFeSimdAnimStrayRadius_t::GetRelaxationFactor, &GFeSimdAnimStrayRadius_t::SetRelaxationFactor)
        .endClass();
}