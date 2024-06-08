#include "../../../core/scripting/generated/classes/GCCSPlayer_CameraServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_CameraServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_CameraServices>("CCSPlayer_CameraServices")

        .endClass();
}