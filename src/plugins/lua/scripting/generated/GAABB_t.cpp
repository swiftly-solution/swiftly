#include "../../../core/scripting/generated/classes/GAABB_t.h"
#include "../core.h"

void SetupLuaClassGAABB_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAABB_t>("AABB_t")
        .addProperty("MinBounds", &GAABB_t::GetMinBounds, &GAABB_t::SetMinBounds)
        .addProperty("MaxBounds", &GAABB_t::GetMaxBounds, &GAABB_t::SetMaxBounds)
        .endClass();
}