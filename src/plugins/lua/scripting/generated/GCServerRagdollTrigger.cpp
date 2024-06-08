#include "../../../core/scripting/generated/classes/GCServerRagdollTrigger.h"
#include "../core.h"

void SetupLuaClassGCServerRagdollTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerRagdollTrigger>("CServerRagdollTrigger")

        .endClass();
}