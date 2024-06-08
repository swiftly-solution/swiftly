#include "../../../core/scripting/generated/classes/GCBindPoseUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCBindPoseUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBindPoseUpdateNode>("CBindPoseUpdateNode")

        .endClass();
}