#include "../../../core/scripting/generated/classes/GCCSGOPlayerAnimGraphState.h"
#include "../core.h"

void SetupLuaClassGCCSGOPlayerAnimGraphState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGOPlayerAnimGraphState>("CCSGOPlayerAnimGraphState")

        .endClass();
}