#include "../../../core/scripting/generated/classes/GCCSSprite.h"
#include "../core.h"

void SetupLuaClassGCCSSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSSprite>("CCSSprite")

        .endClass();
}