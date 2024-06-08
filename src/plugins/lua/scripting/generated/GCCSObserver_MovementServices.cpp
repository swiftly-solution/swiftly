#include "../../../core/scripting/generated/classes/GCCSObserver_MovementServices.h"
#include "../core.h"

void SetupLuaClassGCCSObserver_MovementServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_MovementServices>("CCSObserver_MovementServices")

        .endClass();
}