#include "../../../core/scripting/generated/classes/GCTriggerHostageReset.h"
#include "../core.h"

void SetupLuaClassGCTriggerHostageReset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerHostageReset>("CTriggerHostageReset")

        .endClass();
}