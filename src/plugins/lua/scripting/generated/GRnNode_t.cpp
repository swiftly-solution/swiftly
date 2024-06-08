#include "../../../core/scripting/generated/classes/GRnNode_t.h"
#include "../core.h"

void SetupLuaClassGRnNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnNode_t>("RnNode_t")
        .addProperty("Min", &GRnNode_t::GetMin, &GRnNode_t::SetMin)
        .addProperty("Children", &GRnNode_t::GetChildren, &GRnNode_t::SetChildren)
        .addProperty("Max", &GRnNode_t::GetMax, &GRnNode_t::SetMax)
        .addProperty("TriangleOffset", &GRnNode_t::GetTriangleOffset, &GRnNode_t::SetTriangleOffset)
        .endClass();
}