#include "../../../core/scripting/generated/classes/GFeFitMatrix_t.h"
#include "../core.h"

void SetupLuaClassGFeFitMatrix_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitMatrix_t>("FeFitMatrix_t")
        .addProperty("Center", &GFeFitMatrix_t::GetCenter, &GFeFitMatrix_t::SetCenter)
        .addProperty("End", &GFeFitMatrix_t::GetEnd, &GFeFitMatrix_t::SetEnd)
        .addProperty("Node", &GFeFitMatrix_t::GetNode, &GFeFitMatrix_t::SetNode)
        .addProperty("BeginDynamic", &GFeFitMatrix_t::GetBeginDynamic, &GFeFitMatrix_t::SetBeginDynamic)
        .endClass();
}