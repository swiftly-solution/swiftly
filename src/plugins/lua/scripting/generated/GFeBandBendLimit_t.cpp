#include "../../../core/scripting/generated/classes/GFeBandBendLimit_t.h"
#include "../core.h"

void SetupLuaClassGFeBandBendLimit_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBandBendLimit_t>("FeBandBendLimit_t")
        .addProperty("DistMin", &GFeBandBendLimit_t::GetDistMin, &GFeBandBendLimit_t::SetDistMin)
        .addProperty("DistMax", &GFeBandBendLimit_t::GetDistMax, &GFeBandBendLimit_t::SetDistMax)
        .addProperty("Node", &GFeBandBendLimit_t::GetNode, &GFeBandBendLimit_t::SetNode)
        .endClass();
}