#include "../../../core/scripting/generated/classes/GFeSimdRodConstraint_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdRodConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdRodConstraint_t>("FeSimdRodConstraint_t")
        .addProperty("4MaxDist", &GFeSimdRodConstraint_t::Get4MaxDist, &GFeSimdRodConstraint_t::Set4MaxDist)
        .addProperty("4MinDist", &GFeSimdRodConstraint_t::Get4MinDist, &GFeSimdRodConstraint_t::Set4MinDist)
        .addProperty("4Weight0", &GFeSimdRodConstraint_t::Get4Weight0, &GFeSimdRodConstraint_t::Set4Weight0)
        .addProperty("4RelaxationFactor", &GFeSimdRodConstraint_t::Get4RelaxationFactor, &GFeSimdRodConstraint_t::Set4RelaxationFactor)
        .endClass();
}