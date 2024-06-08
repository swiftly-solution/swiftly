#include "../../../core/scripting/generated/classes/GCNmLayerBlendNode__LayerDefinition_t.h"
#include "../core.h"

void SetupLuaClassGCNmLayerBlendNode__LayerDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLayerBlendNode__LayerDefinition_t>("CNmLayerBlendNode__LayerDefinition_t")
        .addProperty("InputNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetInputNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetInputNodeIdx)
        .addProperty("WeightValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetWeightValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetWeightValueNodeIdx)
        .addProperty("BoneMaskValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetBoneMaskValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetBoneMaskValueNodeIdx)
        .addProperty("RootMotionWeightValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetRootMotionWeightValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetRootMotionWeightValueNodeIdx)
        .addProperty("IsSynchronized", &GCNmLayerBlendNode__LayerDefinition_t::GetIsSynchronized, &GCNmLayerBlendNode__LayerDefinition_t::SetIsSynchronized)
        .addProperty("IgnoreEvents", &GCNmLayerBlendNode__LayerDefinition_t::GetIgnoreEvents, &GCNmLayerBlendNode__LayerDefinition_t::SetIgnoreEvents)
        .addProperty("IsStateMachineLayer", &GCNmLayerBlendNode__LayerDefinition_t::GetIsStateMachineLayer, &GCNmLayerBlendNode__LayerDefinition_t::SetIsStateMachineLayer)
        .addProperty("BlendMode", &GCNmLayerBlendNode__LayerDefinition_t::GetBlendMode, &GCNmLayerBlendNode__LayerDefinition_t::SetBlendMode)
        .endClass();
}