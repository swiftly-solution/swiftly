#include "../../../core/scripting/generated/classes/GCAnimationGraphVisualizerPrimitiveBase.h"
#include "../core.h"

void SetupLuaClassGCAnimationGraphVisualizerPrimitiveBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerPrimitiveBase>("CAnimationGraphVisualizerPrimitiveBase")
        .addProperty("Type", &GCAnimationGraphVisualizerPrimitiveBase::GetType, &GCAnimationGraphVisualizerPrimitiveBase::SetType)
        .addProperty("OwningAnimNodePaths", &GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePaths, &GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePaths)
        .addProperty("OwningAnimNodePathCount", &GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePathCount, &GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePathCount)
        .endClass();
}