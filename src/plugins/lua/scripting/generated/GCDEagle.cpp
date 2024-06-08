#include "../../../core/scripting/generated/classes/GCDEagle.h"
#include "../core.h"

void SetupLuaClassGCDEagle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDEagle>("CDEagle")

        .endClass();
}