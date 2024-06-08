#include "../../../core/scripting/generated/classes/GCCSGO_TeamSelectTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamSelectTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectTerroristPosition>("CCSGO_TeamSelectTerroristPosition")

        .endClass();
}