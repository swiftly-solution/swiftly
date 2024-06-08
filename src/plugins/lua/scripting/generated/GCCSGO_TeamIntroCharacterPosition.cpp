#include "../../../core/scripting/generated/classes/GCCSGO_TeamIntroCharacterPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamIntroCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroCharacterPosition>("CCSGO_TeamIntroCharacterPosition")

        .endClass();
}