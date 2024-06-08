#include "../../../core/scripting/generated/classes/GCEditableMotionGraph.h"
#include "../core.h"

void SetupLuaClassGCEditableMotionGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEditableMotionGraph>("CEditableMotionGraph")

        .endClass();
}