#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerAxis.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerAxis(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerAxis>("CAnimationGraphVisualizerAxis")
        .addProperty("AxisSize", &GCAnimationGraphVisualizerAxis::GetAxisSize, &GCAnimationGraphVisualizerAxis::SetAxisSize)
        .endClass();
}