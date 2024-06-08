#include "../../../core/scripting/generated/classes/GCNmLegacyEvent.h"
#include "../core.h"

void SetupLuaClassGCNmLegacyEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLegacyEvent>("CNmLegacyEvent")

        .endClass();
}