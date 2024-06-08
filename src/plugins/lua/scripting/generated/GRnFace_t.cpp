#include "../../../core/scripting/generated/classes/GRnFace_t.h"
#include "../core.h"

void SetupLuaClassGRnFace_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnFace_t>("RnFace_t")
        .addProperty("Edge", &GRnFace_t::GetEdge, &GRnFace_t::SetEdge)
        .endClass();
}