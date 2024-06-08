#include "../../../core/scripting/generated/classes/GRnHullDesc_t.h"
#include "../core.h"

void SetupLuaClassGRnHullDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHullDesc_t>("RnHullDesc_t")
        .addProperty("Hull", &GRnHullDesc_t::GetHull, &GRnHullDesc_t::SetHull)
        .endClass();
}