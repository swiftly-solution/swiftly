#include "../../../core/scripting/generated/classes/GCBodyComponentBaseAnimGraph.h"
#include "../core.h"

void SetupLuaClassGCBodyComponentBaseAnimGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentBaseAnimGraph>("CBodyComponentBaseAnimGraph")
        .addProperty("AnimationController", &GCBodyComponentBaseAnimGraph::GetAnimationController, &GCBodyComponentBaseAnimGraph::SetAnimationController)
        .endClass();
}