#include "../../../core/scripting/generated/classes/GCPrecipitationBlocker.h"
#include "../core.h"

void SetupLuaClassGCPrecipitationBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitationBlocker>("CPrecipitationBlocker")

        .endClass();
}