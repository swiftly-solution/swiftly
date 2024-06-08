#include "../../../core/scripting/generated/classes/GCCSGO_WingmanIntroCounterTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_WingmanIntroCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroCounterTerroristPosition>("CCSGO_WingmanIntroCounterTerroristPosition")

        .endClass();
}