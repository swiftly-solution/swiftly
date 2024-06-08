#include "../../../core/scripting/generated/classes/GCCSGO_TeamSelectCounterTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamSelectCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectCounterTerroristPosition>("CCSGO_TeamSelectCounterTerroristPosition")

        .endClass();
}