#include "../../../core/scripting/generated/classes/GCTakeDamageInfoAPI.h"
#include "../core.h"

void SetupLuaClassGCTakeDamageInfoAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageInfoAPI>("CTakeDamageInfoAPI")

        .endClass();
}