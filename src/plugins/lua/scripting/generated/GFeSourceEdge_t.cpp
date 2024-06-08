#include "../../../core/scripting/generated/classes/GFeSourceEdge_t.h"
#include "../core.h"

void SetupLuaClassGFeSourceEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSourceEdge_t>("FeSourceEdge_t")
        .addProperty("Node", &GFeSourceEdge_t::GetNode, &GFeSourceEdge_t::SetNode)
        .endClass();
}