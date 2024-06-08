#include "../../../core/scripting/generated/classes/GCNmIDEvent.h"
#include "../core.h"

void SetupLuaClassGCNmIDEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmIDEvent>("CNmIDEvent")

        .endClass();
}