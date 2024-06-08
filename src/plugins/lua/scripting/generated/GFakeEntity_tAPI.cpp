#include "../../../core/scripting/generated/classes/GFakeEntity_tAPI.h"
#include "../core.h"

void SetupLuaClassGFakeEntity_tAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFakeEntity_tAPI>("FakeEntity_tAPI")

        .endClass();
}