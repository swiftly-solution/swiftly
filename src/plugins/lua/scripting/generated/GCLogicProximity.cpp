#include "../../../core/scripting/generated/classes/GCLogicProximity.h"
#include "../core.h"

void SetupLuaClassGCLogicProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicProximity>("CLogicProximity")

        .endClass();
}