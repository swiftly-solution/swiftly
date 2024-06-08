#include "../../../core/scripting/generated/classes/GCCSObserverPawn.h"
#include "../core.h"

void SetupLuaClassGCCSObserverPawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserverPawn>("CCSObserverPawn")

        .endClass();
}