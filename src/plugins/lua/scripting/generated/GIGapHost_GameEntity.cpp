#include "../../../core/scripting/generated/classes/GIGapHost_GameEntity.h"
#include "../core.h"

void SetupLuaClassGIGapHost_GameEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIGapHost_GameEntity>("IGapHost_GameEntity")

        .endClass();
}