#include "../../../core/scripting/generated/classes/GCCSObserver_CameraServices.h"
#include "../core.h"

void SetupLuaClassGCCSObserver_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_CameraServices>("CCSObserver_CameraServices")

        .endClass();
}