#include "../../../core/scripting/generated/classes/GCEmptyEntityInstance.h"
#include "../core.h"

void SetupLuaClassGCEmptyEntityInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEmptyEntityInstance>("CEmptyEntityInstance")

        .endClass();
}