#include "../../../core/scripting/generated/classes/GCPlayer_ViewModelServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ViewModelServices>("CPlayer_ViewModelServices")

        .endClass();
}