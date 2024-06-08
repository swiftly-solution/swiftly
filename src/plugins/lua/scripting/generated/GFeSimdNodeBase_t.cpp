#include "../../../core/scripting/generated/classes/GFeSimdNodeBase_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdNodeBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdNodeBase_t>("FeSimdNodeBase_t")
        .addProperty("Node", &GFeSimdNodeBase_t::GetNode, &GFeSimdNodeBase_t::SetNode)
        .addProperty("NodeX0", &GFeSimdNodeBase_t::GetNodeX0, &GFeSimdNodeBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeSimdNodeBase_t::GetNodeX1, &GFeSimdNodeBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeSimdNodeBase_t::GetNodeY0, &GFeSimdNodeBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeSimdNodeBase_t::GetNodeY1, &GFeSimdNodeBase_t::SetNodeY1)
        .addProperty("Dummy", &GFeSimdNodeBase_t::GetDummy, &GFeSimdNodeBase_t::SetDummy)
        .addProperty("Adjust", &GFeSimdNodeBase_t::GetAdjust, &GFeSimdNodeBase_t::SetAdjust)
        .endClass();
}