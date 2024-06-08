#include "../../../core/scripting/generated/classes/GCStaticPoseCache.h"
#include "../core.h"

void SetupLuaClassGCStaticPoseCache(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStaticPoseCache>("CStaticPoseCache")
        .addProperty("Poses", &GCStaticPoseCache::GetPoses, &GCStaticPoseCache::SetPoses)
        .addProperty("BoneCount", &GCStaticPoseCache::GetBoneCount, &GCStaticPoseCache::SetBoneCount)
        .addProperty("MorphCount", &GCStaticPoseCache::GetMorphCount, &GCStaticPoseCache::SetMorphCount)
        .endClass();
}