#include "../../../core/scripting/generated/classes/GC_INIT_RandomYaw.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomYaw(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomYaw>("C_INIT_RandomYaw")

        .endClass();
}