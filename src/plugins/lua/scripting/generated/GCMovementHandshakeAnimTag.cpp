#include "../../../core/scripting/generated/classes/GCMovementHandshakeAnimTag.h"
#include "../core.h"

void SetupLuaClassGCMovementHandshakeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMovementHandshakeAnimTag>("CMovementHandshakeAnimTag")

        .endClass();
}