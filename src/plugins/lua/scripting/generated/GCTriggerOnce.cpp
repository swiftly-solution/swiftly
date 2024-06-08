#include "../../../core/scripting/generated/classes/GCTriggerOnce.h"
#include "../core.h"

void SetupLuaClassGCTriggerOnce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerOnce>("CTriggerOnce")

        .endClass();
}