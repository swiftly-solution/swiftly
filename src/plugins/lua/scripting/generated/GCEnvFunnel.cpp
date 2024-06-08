#include "../../../core/scripting/generated/classes/GCEnvFunnel.h"
#include "../core.h"

void SetupLuaClassGCEnvFunnel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFunnel>("CEnvFunnel")

        .endClass();
}