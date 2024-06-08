#include "../../../core/scripting/generated/classes/GCTriggerGravity.h"
#include "../core.h"

void SetupLuaClassGCTriggerGravity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerGravity>("CTriggerGravity")

        .endClass();
}