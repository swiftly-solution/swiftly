#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerSphere.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerSphere>("CAnimationGraphVisualizerSphere")
        .addProperty("WsPosition", &GCAnimationGraphVisualizerSphere::GetWsPosition, &GCAnimationGraphVisualizerSphere::SetWsPosition)
        .addProperty("Radius", &GCAnimationGraphVisualizerSphere::GetRadius, &GCAnimationGraphVisualizerSphere::SetRadius)
        .addProperty("Color", &GCAnimationGraphVisualizerSphere::GetColor, &GCAnimationGraphVisualizerSphere::SetColor)
        .endClass();
}