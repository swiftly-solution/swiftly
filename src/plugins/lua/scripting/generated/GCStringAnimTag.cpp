#include "../../../core/scripting/generated/classes/GCStringAnimTag.h"
#include "../core.h"

void SetupLuaClassGCStringAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStringAnimTag>("CStringAnimTag")

        .endClass();
}