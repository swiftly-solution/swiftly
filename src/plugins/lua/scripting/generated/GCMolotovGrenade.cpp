#include "../../../core/scripting/generated/classes/GCMolotovGrenade.h"
#include "../core.h"

void SetupLuaClassGCMolotovGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMolotovGrenade>("CMolotovGrenade")

        .endClass();
}