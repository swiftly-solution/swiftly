#include "../../../core/scripting/generated/classes/GCMotionGraphUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCMotionGraphUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphUpdateNode>("CMotionGraphUpdateNode")

        .endClass();
}