#include "../../../core/scripting/generated/classes/GWorldNode_t.h"
#include "../core.h"

void SetupLuaClassGWorldNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldNode_t>("WorldNode_t")
        .addProperty("SceneObjects", &GWorldNode_t::GetSceneObjects, &GWorldNode_t::SetSceneObjects)
        .addProperty("InfoOverlays", &GWorldNode_t::GetInfoOverlays, &GWorldNode_t::SetInfoOverlays)
        .addProperty("VisClusterMembership", &GWorldNode_t::GetVisClusterMembership, &GWorldNode_t::SetVisClusterMembership)
        .addProperty("AggregateSceneObjects", &GWorldNode_t::GetAggregateSceneObjects, &GWorldNode_t::SetAggregateSceneObjects)
        .addProperty("ClutterSceneObjects", &GWorldNode_t::GetClutterSceneObjects, &GWorldNode_t::SetClutterSceneObjects)
        .addProperty("ExtraVertexStreamOverrides", &GWorldNode_t::GetExtraVertexStreamOverrides, &GWorldNode_t::SetExtraVertexStreamOverrides)
        .addProperty("MaterialOverrides", &GWorldNode_t::GetMaterialOverrides, &GWorldNode_t::SetMaterialOverrides)
        .addProperty("ExtraVertexStreams", &GWorldNode_t::GetExtraVertexStreams, &GWorldNode_t::SetExtraVertexStreams)
        .addProperty("LayerNames", &GWorldNode_t::GetLayerNames, &GWorldNode_t::SetLayerNames)
        .addProperty("SceneObjectLayerIndices", &GWorldNode_t::GetSceneObjectLayerIndices, &GWorldNode_t::SetSceneObjectLayerIndices)
        .addProperty("OverlayLayerIndices", &GWorldNode_t::GetOverlayLayerIndices, &GWorldNode_t::SetOverlayLayerIndices)
        .addProperty("GrassFileName", &GWorldNode_t::GetGrassFileName, &GWorldNode_t::SetGrassFileName)
        .addProperty("NodeLightingInfo", &GWorldNode_t::GetNodeLightingInfo, &GWorldNode_t::SetNodeLightingInfo)
        .endClass();
}