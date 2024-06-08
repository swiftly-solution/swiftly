#include "../../../core/scripting/generated/classes/GCTaskStatusAnimTag.h"
#include "../core.h"

void SetupLuaClassGCTaskStatusAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTaskStatusAnimTag>("CTaskStatusAnimTag")

        .endClass();
}