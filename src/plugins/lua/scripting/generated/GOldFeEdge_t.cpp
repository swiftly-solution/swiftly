#include "../../../core/scripting/generated/classes/GOldFeEdge_t.h"
#include "../core.h"

void SetupLuaClassGOldFeEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GOldFeEdge_t>("OldFeEdge_t")
        .addProperty("K", &GOldFeEdge_t::GetK, &GOldFeEdge_t::SetK)
        .addProperty("InvA", &GOldFeEdge_t::GetInvA, &GOldFeEdge_t::SetInvA)
        .addProperty("T", &GOldFeEdge_t::GetT, &GOldFeEdge_t::SetT)
        .addProperty("ThetaRelaxed", &GOldFeEdge_t::GetThetaRelaxed, &GOldFeEdge_t::SetThetaRelaxed)
        .addProperty("ThetaFactor", &GOldFeEdge_t::GetThetaFactor, &GOldFeEdge_t::SetThetaFactor)
        .addProperty("C01", &GOldFeEdge_t::GetC01, &GOldFeEdge_t::SetC01)
        .addProperty("C02", &GOldFeEdge_t::GetC02, &GOldFeEdge_t::SetC02)
        .addProperty("C03", &GOldFeEdge_t::GetC03, &GOldFeEdge_t::SetC03)
        .addProperty("C04", &GOldFeEdge_t::GetC04, &GOldFeEdge_t::SetC04)
        .addProperty("AxialModelDist", &GOldFeEdge_t::GetAxialModelDist, &GOldFeEdge_t::SetAxialModelDist)
        .addProperty("AxialModelWeights", &GOldFeEdge_t::GetAxialModelWeights, &GOldFeEdge_t::SetAxialModelWeights)
        .addProperty("Node", &GOldFeEdge_t::GetNode, &GOldFeEdge_t::SetNode)
        .endClass();
}