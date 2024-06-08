#include "../../../core/scripting/generated/classes/GCCSGO_TeamIntroTerroristPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamIntroTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroTerroristPosition>("CCSGO_TeamIntroTerroristPosition")

        .endClass();
}