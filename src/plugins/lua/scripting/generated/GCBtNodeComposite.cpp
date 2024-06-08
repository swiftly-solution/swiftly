#include "../../../core/scripting/generated/classes/GCBtNodeComposite.h"
#include "../core.h"

void SetupLuaClassGCBtNodeComposite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeComposite>("CBtNodeComposite")

        .endClass();
}