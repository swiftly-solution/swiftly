#include "../../../core/scripting/generated/classes/GCAK47.h"
#include "../core.h"

void SetupLuaClassGCAK47(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAK47>("CAK47")

        .endClass();
}