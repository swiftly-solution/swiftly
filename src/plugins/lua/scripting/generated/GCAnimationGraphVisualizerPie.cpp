#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerPie.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerPie(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerPie>("CAnimationGraphVisualizerPie")
        .addProperty("WsCenter", &GCAnimationGraphVisualizerPie::GetWsCenter, &GCAnimationGraphVisualizerPie::SetWsCenter)
        .addProperty("WsStart", &GCAnimationGraphVisualizerPie::GetWsStart, &GCAnimationGraphVisualizerPie::SetWsStart)
        .addProperty("WsEnd", &GCAnimationGraphVisualizerPie::GetWsEnd, &GCAnimationGraphVisualizerPie::SetWsEnd)
        .addProperty("Color", &GCAnimationGraphVisualizerPie::GetColor, &GCAnimationGraphVisualizerPie::SetColor)
        .endClass();
}