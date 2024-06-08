#include "../../../core/scripting/generated/classes/GC_OP_Spin.h"
#include "../core.h"

void SetupLuaClassGC_OP_Spin(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Spin>("C_OP_Spin")

        .endClass();
}