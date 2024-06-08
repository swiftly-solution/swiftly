#include "../../../core/scripting/generated/classes/GCClientGapTypeQueryRegistration.h"
#include "../core.h"

void SetupLuaClassGCClientGapTypeQueryRegistration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClientGapTypeQueryRegistration>("CClientGapTypeQueryRegistration")

        .endClass();
}