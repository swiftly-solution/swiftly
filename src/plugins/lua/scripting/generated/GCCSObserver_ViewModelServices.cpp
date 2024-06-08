#include "../../../core/scripting/generated/classes/GCCSObserver_ViewModelServices.h"
#include "../core.h"

void SetupLuaClassGCCSObserver_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_ViewModelServices>("CCSObserver_ViewModelServices")

        .endClass();
}