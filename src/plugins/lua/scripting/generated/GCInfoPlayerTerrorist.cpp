#include "../../../core/scripting/generated/classes/GCInfoPlayerTerrorist.h"
#include "../core.h"

void SetupLuaClassGCInfoPlayerTerrorist(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerTerrorist>("CInfoPlayerTerrorist")

        .endClass();
}