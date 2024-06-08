#include "../../../core/scripting/generated/classes/GCNmGraphVariation.h"
#include "../core.h"

void SetupLuaClassGCNmGraphVariation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphVariation>("CNmGraphVariation")

        .endClass();
}