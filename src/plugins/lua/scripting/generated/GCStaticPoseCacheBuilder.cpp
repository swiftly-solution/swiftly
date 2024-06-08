#include "../../../core/scripting/generated/classes/GCStaticPoseCacheBuilder.h"
#include "../core.h"

void SetupLuaClassGCStaticPoseCacheBuilder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStaticPoseCacheBuilder>("CStaticPoseCacheBuilder")

        .endClass();
}