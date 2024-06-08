#include "../../../core/scripting/generated/classes/GC_OP_Callback.h"
#include "../core.h"

void SetupLuaClassGC_OP_Callback(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Callback>("C_OP_Callback")

        .endClass();
}