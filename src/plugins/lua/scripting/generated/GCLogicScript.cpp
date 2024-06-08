#include "../../../core/scripting/generated/classes/GCLogicScript.h"
#include "../core.h"

void SetupLuaClassGCLogicScript(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicScript>("CLogicScript")

        .endClass();
}