#include "../../../core/scripting/generated/classes/GFeEdgeDesc_t.h"
#include "../core.h"

void SetupLuaClassGFeEdgeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeEdgeDesc_t>("FeEdgeDesc_t")
        .addProperty("Edge", &GFeEdgeDesc_t::GetEdge, &GFeEdgeDesc_t::SetEdge)
        .addProperty("VirtElem", &GFeEdgeDesc_t::GetVirtElem, &GFeEdgeDesc_t::SetVirtElem)
        .endClass();
}