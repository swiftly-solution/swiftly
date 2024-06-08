#include "../../../core/scripting/generated/classes/GCAnimSkeleton.h"
#include "../core.h"

void SetupLuaClassGCAnimSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimSkeleton>("CAnimSkeleton")
        .addProperty("BoneNames", &GCAnimSkeleton::GetBoneNames, &GCAnimSkeleton::SetBoneNames)
        .addProperty("Parents", &GCAnimSkeleton::GetParents, &GCAnimSkeleton::SetParents)
        .addProperty("Feet", &GCAnimSkeleton::GetFeet, &GCAnimSkeleton::SetFeet)
        .addProperty("MorphNames", &GCAnimSkeleton::GetMorphNames, &GCAnimSkeleton::SetMorphNames)
        .addProperty("LodBoneCounts", &GCAnimSkeleton::GetLodBoneCounts, &GCAnimSkeleton::SetLodBoneCounts)
        .endClass();
}