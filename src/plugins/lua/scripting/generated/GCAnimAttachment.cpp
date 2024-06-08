#include "../../../core/scripting/generated/classes/GCAnimAttachment.h"
#include "../core.h"

void SetupLuaClassGCAnimAttachment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimAttachment>("CAnimAttachment")
        .addProperty("InfluenceRotations", &GCAnimAttachment::GetInfluenceRotations, &GCAnimAttachment::SetInfluenceRotations)
        .addProperty("InfluenceOffsets", &GCAnimAttachment::GetInfluenceOffsets, &GCAnimAttachment::SetInfluenceOffsets)
        .addProperty("InfluenceIndices", &GCAnimAttachment::GetInfluenceIndices, &GCAnimAttachment::SetInfluenceIndices)
        .addProperty("InfluenceWeights", &GCAnimAttachment::GetInfluenceWeights, &GCAnimAttachment::SetInfluenceWeights)
        .addProperty("NumInfluences", &GCAnimAttachment::GetNumInfluences, &GCAnimAttachment::SetNumInfluences)
        .endClass();
}