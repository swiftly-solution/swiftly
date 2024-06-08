#include "../../../core/scripting/generated/classes/GClutterTile_t.h"
#include "../core.h"

void SetupLuaClassGClutterTile_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GClutterTile_t>("ClutterTile_t")
        .addProperty("FirstInstance", &GClutterTile_t::GetFirstInstance, &GClutterTile_t::SetFirstInstance)
        .addProperty("LastInstance", &GClutterTile_t::GetLastInstance, &GClutterTile_t::SetLastInstance)
        .addProperty("BoundsWs", &GClutterTile_t::GetBoundsWs, &GClutterTile_t::SetBoundsWs)
        .endClass();
}