#include "../../../core/scripting/generated/classes/GFeAxialEdgeBend_t.h"
#include "../core.h"

void SetupLuaClassGFeAxialEdgeBend_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeAxialEdgeBend_t>("FeAxialEdgeBend_t")
        .addProperty("Te", &GFeAxialEdgeBend_t::GetTe, &GFeAxialEdgeBend_t::SetTe)
        .addProperty("Tv", &GFeAxialEdgeBend_t::GetTv, &GFeAxialEdgeBend_t::SetTv)
        .addProperty("Dist", &GFeAxialEdgeBend_t::GetDist, &GFeAxialEdgeBend_t::SetDist)
        .addProperty("Weight", &GFeAxialEdgeBend_t::GetWeight, &GFeAxialEdgeBend_t::SetWeight)
        .addProperty("Node", &GFeAxialEdgeBend_t::GetNode, &GFeAxialEdgeBend_t::SetNode)
        .endClass();
}