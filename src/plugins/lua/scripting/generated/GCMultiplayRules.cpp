#include "../../../core/scripting/generated/classes/GCMultiplayRules.h"
#include "../core.h"

void SetupLuaClassGCMultiplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiplayRules>("CMultiplayRules")

        .endClass();
}