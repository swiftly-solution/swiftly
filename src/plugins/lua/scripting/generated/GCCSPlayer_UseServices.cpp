#include "../../../core/scripting/generated/classes/GCCSPlayer_UseServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_UseServices>("CCSPlayer_UseServices")
        .addProperty("LastKnownUseEntity", &GCCSPlayer_UseServices::GetLastKnownUseEntity, &GCCSPlayer_UseServices::SetLastKnownUseEntity)
        .endClass();
}