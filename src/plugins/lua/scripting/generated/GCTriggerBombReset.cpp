#include "../../../core/scripting/generated/classes/GCTriggerBombReset.h"
#include "../core.h"

void SetupLuaClassGCTriggerBombReset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBombReset>("CTriggerBombReset")

        .endClass();
}