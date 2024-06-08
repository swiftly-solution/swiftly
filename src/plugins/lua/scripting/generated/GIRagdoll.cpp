#include "../../../core/scripting/generated/classes/GIRagdoll.h"
#include "../core.h"

void SetupLuaClassGIRagdoll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIRagdoll>("IRagdoll")

        .endClass();
}