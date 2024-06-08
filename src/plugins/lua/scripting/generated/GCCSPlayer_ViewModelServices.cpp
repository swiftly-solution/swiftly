#include "../../../core/scripting/generated/classes/GCCSPlayer_ViewModelServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ViewModelServices>("CCSPlayer_ViewModelServices")
        .addProperty("ViewModel", &GCCSPlayer_ViewModelServices::GetViewModel, &GCCSPlayer_ViewModelServices::SetViewModel)
        .endClass();
}