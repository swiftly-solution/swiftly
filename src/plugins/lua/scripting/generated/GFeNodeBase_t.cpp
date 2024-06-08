#include "../../../core/scripting/generated/classes/GFeNodeBase_t.h"
#include "../core.h"

void SetupLuaClassGFeNodeBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeBase_t>("FeNodeBase_t")
        .addProperty("Node", &GFeNodeBase_t::GetNode, &GFeNodeBase_t::SetNode)
        .addProperty("Dummy", &GFeNodeBase_t::GetDummy, &GFeNodeBase_t::SetDummy)
        .addProperty("NodeX0", &GFeNodeBase_t::GetNodeX0, &GFeNodeBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeNodeBase_t::GetNodeX1, &GFeNodeBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeNodeBase_t::GetNodeY0, &GFeNodeBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeNodeBase_t::GetNodeY1, &GFeNodeBase_t::SetNodeY1)
        .endClass();
}