#include "../../../core/scripting/generated/classes/GCRotButton.h"
#include "../core.h"

void SetupLuaClassGCRotButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRotButton>("CRotButton")

        .endClass();
}