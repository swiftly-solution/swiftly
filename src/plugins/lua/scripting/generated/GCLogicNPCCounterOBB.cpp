#include "../../../core/scripting/generated/classes/GCLogicNPCCounterOBB.h"
#include "../core.h"

void SetupLuaClassGCLogicNPCCounterOBB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNPCCounterOBB>("CLogicNPCCounterOBB")

        .endClass();
}