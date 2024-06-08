#include "../../../core/scripting/generated/classes/GC_INIT_RandomRotation.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomRotation>("C_INIT_RandomRotation")

        .endClass();
}