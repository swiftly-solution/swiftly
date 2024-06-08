#include "../../../core/scripting/generated/classes/GFeRodConstraint_t.h"
#include "../core.h"

void SetupLuaClassGFeRodConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeRodConstraint_t>("FeRodConstraint_t")
        .addProperty("Node", &GFeRodConstraint_t::GetNode, &GFeRodConstraint_t::SetNode)
        .addProperty("MaxDist", &GFeRodConstraint_t::GetMaxDist, &GFeRodConstraint_t::SetMaxDist)
        .addProperty("MinDist", &GFeRodConstraint_t::GetMinDist, &GFeRodConstraint_t::SetMinDist)
        .addProperty("Weight0", &GFeRodConstraint_t::GetWeight0, &GFeRodConstraint_t::SetWeight0)
        .addProperty("RelaxationFactor", &GFeRodConstraint_t::GetRelaxationFactor, &GFeRodConstraint_t::SetRelaxationFactor)
        .endClass();
}