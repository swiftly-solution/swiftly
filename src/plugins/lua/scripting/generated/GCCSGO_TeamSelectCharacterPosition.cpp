#include "../../../core/scripting/generated/classes/GCCSGO_TeamSelectCharacterPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamSelectCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectCharacterPosition>("CCSGO_TeamSelectCharacterPosition")

        .endClass();
}