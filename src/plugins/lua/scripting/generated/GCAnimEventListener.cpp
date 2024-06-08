#include "../../../core/scripting/generated/classes/GCAnimEventListener.h"
#include "../core.h"

void SetupLuaClassGCAnimEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventListener>("CAnimEventListener")

        .endClass();
}