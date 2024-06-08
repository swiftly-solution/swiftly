#include "../../../core/scripting/generated/classes/GRnVertex_t.h"
#include "../core.h"

void SetupLuaClassGRnVertex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnVertex_t>("RnVertex_t")
        .addProperty("Edge", &GRnVertex_t::GetEdge, &GRnVertex_t::SetEdge)
        .endClass();
}