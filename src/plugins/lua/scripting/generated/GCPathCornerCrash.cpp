#include "../../../core/scripting/generated/classes/GCPathCornerCrash.h"
#include "../core.h"

void SetupLuaClassGCPathCornerCrash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathCornerCrash>("CPathCornerCrash")

        .endClass();
}