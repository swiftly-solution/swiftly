#include "../../../core/scripting/generated/classes/GC_OP_SpinUpdate.h"
#include "../core.h"

void SetupLuaClassGC_OP_SpinUpdate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SpinUpdate>("C_OP_SpinUpdate")

        .endClass();
}