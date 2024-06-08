#include "../../../core/scripting/generated/classes/GIEconItemInterface.h"
#include "../core.h"

void SetupLuaClassGIEconItemInterface(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIEconItemInterface>("IEconItemInterface")

        .endClass();
}