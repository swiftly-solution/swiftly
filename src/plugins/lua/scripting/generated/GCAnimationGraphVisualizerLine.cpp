#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerLine.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerLine(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerLine>("CAnimationGraphVisualizerLine")
        .addProperty("WsPositionStart", &GCAnimationGraphVisualizerLine::GetWsPositionStart, &GCAnimationGraphVisualizerLine::SetWsPositionStart)
        .addProperty("WsPositionEnd", &GCAnimationGraphVisualizerLine::GetWsPositionEnd, &GCAnimationGraphVisualizerLine::SetWsPositionEnd)
        .addProperty("Color", &GCAnimationGraphVisualizerLine::GetColor, &GCAnimationGraphVisualizerLine::SetColor)
        .endClass();
}