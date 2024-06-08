#include "../../../core/scripting/generated/classes/GFakeEntityDerivedA_tAPI.h"
#include "../core.h"

void SetupLuaClassGFakeEntityDerivedA_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntityDerivedA_tAPI>("FakeEntityDerivedA_tAPI")

        .endClass();
}