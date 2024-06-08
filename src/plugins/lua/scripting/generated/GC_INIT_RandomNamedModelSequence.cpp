#include "../../../core/scripting/generated/classes/GC_INIT_RandomNamedModelSequence.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomNamedModelSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomNamedModelSequence>("C_INIT_RandomNamedModelSequence")

        .endClass();
}