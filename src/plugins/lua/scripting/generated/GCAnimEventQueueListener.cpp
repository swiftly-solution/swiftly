#include "../../../core/scripting/generated/classes/GCAnimEventQueueListener.h"
#include "../core.h"

void SetupLuaClassGCAnimEventQueueListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventQueueListener>("CAnimEventQueueListener")

        .endClass();
}