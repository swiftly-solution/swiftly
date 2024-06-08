#include "../../../core/scripting/generated/classes/GCCSPlayer_HostageServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_HostageServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_HostageServices>("CCSPlayer_HostageServices")
        .addProperty("CarriedHostage", &GCCSPlayer_HostageServices::GetCarriedHostage, &GCCSPlayer_HostageServices::SetCarriedHostage)
        .addProperty("CarriedHostageProp", &GCCSPlayer_HostageServices::GetCarriedHostageProp, &GCCSPlayer_HostageServices::SetCarriedHostageProp)
        .endClass();
}