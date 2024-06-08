#include "../../../core/scripting/generated/classes/GCCSGO_WingmanIntroTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_WingmanIntroTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroTerroristPosition>("CCSGO_WingmanIntroTerroristPosition")

        .endClass();
}