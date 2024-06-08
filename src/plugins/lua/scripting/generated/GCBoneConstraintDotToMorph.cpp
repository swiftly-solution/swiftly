#include "../../../core/scripting/generated/classes/GCBoneConstraintDotToMorph.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintDotToMorph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintDotToMorph>("CBoneConstraintDotToMorph")
        .addProperty("BoneName", &GCBoneConstraintDotToMorph::GetBoneName, &GCBoneConstraintDotToMorph::SetBoneName)
        .addProperty("TargetBoneName", &GCBoneConstraintDotToMorph::GetTargetBoneName, &GCBoneConstraintDotToMorph::SetTargetBoneName)
        .addProperty("MorphChannelName", &GCBoneConstraintDotToMorph::GetMorphChannelName, &GCBoneConstraintDotToMorph::SetMorphChannelName)
        .addProperty("Remap", &GCBoneConstraintDotToMorph::GetRemap, &GCBoneConstraintDotToMorph::SetRemap)
        .endClass();
}