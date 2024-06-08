#include "../../../core/scripting/generated/classes/GCAnimEventListenerBase.h"
#include "../core.h"

void SetupLuaClassGCAnimEventListenerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventListenerBase>("CAnimEventListenerBase")

        .endClass();
}