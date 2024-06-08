#include "../../../core/scripting/generated/classes/GCTaskHandshakeAnimTag.h"
#include "../core.h"

void SetupLuaClassGCTaskHandshakeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTaskHandshakeAnimTag>("CTaskHandshakeAnimTag")

        .endClass();
}