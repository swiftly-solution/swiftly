#include "../../../core/scripting/generated/classes/GCInfoTarget.h"
#include "../core.h"

void SetupLuaClassGCInfoTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTarget>("CInfoTarget")

        .endClass();
}