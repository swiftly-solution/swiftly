#include "../../../core/scripting/generated/classes/GCTriggerCallback.h"
#include "../core.h"

void SetupLuaClassGCTriggerCallback(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerCallback>("CTriggerCallback")

        .endClass();
}