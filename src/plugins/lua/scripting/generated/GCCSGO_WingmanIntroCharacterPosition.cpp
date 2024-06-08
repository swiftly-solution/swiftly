#include "../../../core/scripting/generated/classes/GCCSGO_WingmanIntroCharacterPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_WingmanIntroCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroCharacterPosition>("CCSGO_WingmanIntroCharacterPosition")

        .endClass();
}