#include "../../../core/scripting/generated/classes/GCRenderSkeleton.h"
#include "../core.h"

void SetupLuaClassGCRenderSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderSkeleton>("CRenderSkeleton")
        .addProperty("Bones", &GCRenderSkeleton::GetBones, &GCRenderSkeleton::SetBones)
        .addProperty("BoneParents", &GCRenderSkeleton::GetBoneParents, &GCRenderSkeleton::SetBoneParents)
        .addProperty("BoneWeightCount", &GCRenderSkeleton::GetBoneWeightCount, &GCRenderSkeleton::SetBoneWeightCount)
        .endClass();
}