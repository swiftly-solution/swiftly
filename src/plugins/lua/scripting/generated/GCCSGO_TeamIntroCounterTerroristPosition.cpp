#include "../../../core/scripting/generated/classes/GCCSGO_TeamIntroCounterTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamIntroCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroCounterTerroristPosition>("CCSGO_TeamIntroCounterTerroristPosition")

        .endClass();
}