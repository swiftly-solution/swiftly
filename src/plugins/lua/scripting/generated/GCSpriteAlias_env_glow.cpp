#include "../../../core/scripting/generated/classes/GCSpriteAlias_env_glow.h"
#include "../core.h"

void SetupLuaClassGCSpriteAlias_env_glow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpriteAlias_env_glow>("CSpriteAlias_env_glow")

        .endClass();
}