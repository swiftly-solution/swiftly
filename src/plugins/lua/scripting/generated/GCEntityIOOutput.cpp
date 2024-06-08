#include "../../../core/scripting/generated/classes/GCEntityIOOutput.h"
#include "../core.h"

void SetupLuaClassGCEntityIOOutput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityIOOutput>("CEntityIOOutput")

        .endClass();
}