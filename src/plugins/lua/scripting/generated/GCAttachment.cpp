#include "../../../core/scripting/generated/classes/GCAttachment.h"
#include "../core.h"

void SetupLuaClassGCAttachment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttachment>("CAttachment")
        .addProperty("Name", &GCAttachment::GetName, &GCAttachment::SetName)
        .addProperty("InfluenceNames", &GCAttachment::GetInfluenceNames, &GCAttachment::SetInfluenceNames)
        .addProperty("InfluenceRotations", &GCAttachment::GetInfluenceRotations, &GCAttachment::SetInfluenceRotations)
        .addProperty("InfluenceOffsets", &GCAttachment::GetInfluenceOffsets, &GCAttachment::SetInfluenceOffsets)
        .addProperty("InfluenceWeights", &GCAttachment::GetInfluenceWeights, &GCAttachment::SetInfluenceWeights)
        .addProperty("InfluenceRootTransform", &GCAttachment::GetInfluenceRootTransform, &GCAttachment::SetInfluenceRootTransform)
        .addProperty("Influences", &GCAttachment::GetInfluences, &GCAttachment::SetInfluences)
        .addProperty("IgnoreRotation", &GCAttachment::GetIgnoreRotation, &GCAttachment::SetIgnoreRotation)
        .endClass();
}