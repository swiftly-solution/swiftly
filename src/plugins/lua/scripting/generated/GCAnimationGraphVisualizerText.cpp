#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerText.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerText>("CAnimationGraphVisualizerText")
        .addProperty("WsPosition", &GCAnimationGraphVisualizerText::GetWsPosition, &GCAnimationGraphVisualizerText::SetWsPosition)
        .addProperty("Color", &GCAnimationGraphVisualizerText::GetColor, &GCAnimationGraphVisualizerText::SetColor)
        .addProperty("Text", &GCAnimationGraphVisualizerText::GetText, &GCAnimationGraphVisualizerText::SetText)
        .endClass();
}