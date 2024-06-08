#include "../../../core/scripting/generated/classes/GCCSObserver_ObserverServices.h"
#include "../core.h"

void SetupLuaClassGCCSObserver_ObserverServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_ObserverServices>("CCSObserver_ObserverServices")

        .endClass();
}