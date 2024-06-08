#include "../../../core/scripting/generated/classes/GCBaseEntityAPI.h"
#include "../core.h"

void SetupLuaClassGCBaseEntityAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseEntityAPI>("CBaseEntityAPI")

        .endClass();
}