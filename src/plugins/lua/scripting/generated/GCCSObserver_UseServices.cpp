#include "../../../core/scripting/generated/classes/GCCSObserver_UseServices.h"
#include "../core.h"

void SetupLuaClassGCCSObserver_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_UseServices>("CCSObserver_UseServices")

        .endClass();
}