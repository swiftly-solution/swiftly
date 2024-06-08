#include "../../../core/scripting/generated/classes/GC_INIT_RandomNamedModelBodyPart.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomNamedModelBodyPart(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomNamedModelBodyPart>("C_INIT_RandomNamedModelBodyPart")

        .endClass();
}