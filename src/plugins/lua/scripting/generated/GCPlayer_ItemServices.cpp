#include "../../../core/scripting/generated/classes/GCPlayer_ItemServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_ItemServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ItemServices>("CPlayer_ItemServices")

        .endClass();
}