#include "../../../core/scripting/generated/classes/GCEntityBlocker.h"
#include "../core.h"

void SetupLuaClassGCEntityBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityBlocker>("CEntityBlocker")

        .endClass();
}