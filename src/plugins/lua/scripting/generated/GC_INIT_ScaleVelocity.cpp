#include "../../../core/scripting/generated/classes/GC_INIT_ScaleVelocity.h"
#include "../core.h"

void SetupLuaClassGC_INIT_ScaleVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_ScaleVelocity>("C_INIT_ScaleVelocity")

        .endClass();
}