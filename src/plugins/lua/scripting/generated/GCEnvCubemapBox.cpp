#include "../../../core/scripting/generated/classes/GCEnvCubemapBox.h"
#include "../core.h"

void SetupLuaClassGCEnvCubemapBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemapBox>("CEnvCubemapBox")

        .endClass();
}