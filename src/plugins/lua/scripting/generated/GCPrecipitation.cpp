#include "../../../core/scripting/generated/classes/GCPrecipitation.h"
#include "../core.h"

void SetupLuaClassGCPrecipitation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitation>("CPrecipitation")

        .endClass();
}