#include "../../../core/scripting/generated/classes/GFakeEntityDerivedB_tAPI.h"
#include "../core.h"

void SetupLuaClassGFakeEntityDerivedB_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntityDerivedB_tAPI>("FakeEntityDerivedB_tAPI")

        .endClass();
}