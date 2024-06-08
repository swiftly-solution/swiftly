#include "../../../core/scripting/generated/classes/GFeFitInfluence_t.h"
#include "../core.h"

void SetupLuaClassGFeFitInfluence_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitInfluence_t>("FeFitInfluence_t")
        .addProperty("VertexNode", &GFeFitInfluence_t::GetVertexNode, &GFeFitInfluence_t::SetVertexNode)
        .addProperty("Weight", &GFeFitInfluence_t::GetWeight, &GFeFitInfluence_t::SetWeight)
        .addProperty("MatrixNode", &GFeFitInfluence_t::GetMatrixNode, &GFeFitInfluence_t::SetMatrixNode)
        .endClass();
}