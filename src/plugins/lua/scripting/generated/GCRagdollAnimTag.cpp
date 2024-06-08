#include "../../../core/scripting/generated/classes/GCRagdollAnimTag.h"
#include "../core.h"

void SetupLuaClassGCRagdollAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollAnimTag>("CRagdollAnimTag")
        .addProperty("PoseControl", &GCRagdollAnimTag::GetPoseControl, &GCRagdollAnimTag::SetPoseControl)
        .addProperty("Frequency", &GCRagdollAnimTag::GetFrequency, &GCRagdollAnimTag::SetFrequency)
        .addProperty("DampingRatio", &GCRagdollAnimTag::GetDampingRatio, &GCRagdollAnimTag::SetDampingRatio)
        .addProperty("DecayDuration", &GCRagdollAnimTag::GetDecayDuration, &GCRagdollAnimTag::SetDecayDuration)
        .addProperty("DecayBias", &GCRagdollAnimTag::GetDecayBias, &GCRagdollAnimTag::SetDecayBias)
        .addProperty("Destroy", &GCRagdollAnimTag::GetDestroy, &GCRagdollAnimTag::SetDestroy)
        .endClass();
}