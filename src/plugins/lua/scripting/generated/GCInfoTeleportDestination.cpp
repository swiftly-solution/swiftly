#include "../../../core/scripting/generated/classes/GCInfoTeleportDestination.h"
#include "../core.h"

void SetupLuaClassGCInfoTeleportDestination(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTeleportDestination>("CInfoTeleportDestination")

        .endClass();
}