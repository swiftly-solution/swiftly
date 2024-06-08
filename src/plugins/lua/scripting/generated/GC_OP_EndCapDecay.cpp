#include "../../../core/scripting/generated/classes/GC_OP_EndCapDecay.h"
#include "../core.h"

void SetupLuaClassGC_OP_EndCapDecay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_EndCapDecay>("C_OP_EndCapDecay")

        .endClass();
}