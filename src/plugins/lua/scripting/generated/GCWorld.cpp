#include "../../../core/scripting/generated/classes/GCWorld.h"
#include "../core.h"

void SetupLuaClassGCWorld(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWorld>("CWorld")

        .endClass();
}