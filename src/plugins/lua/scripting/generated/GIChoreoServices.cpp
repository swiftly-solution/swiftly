#include "../../../core/scripting/generated/classes/GIChoreoServices.h"
#include "../core.h"

void SetupLuaClassGIChoreoServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIChoreoServices>("IChoreoServices")

        .endClass();
}