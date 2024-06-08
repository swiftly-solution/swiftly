#include "../../../core/scripting/generated/classes/GC_INIT_RandomRotationSpeed.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomRotationSpeed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomRotationSpeed>("C_INIT_RandomRotationSpeed")

        .endClass();
}