#include "../../../core/scripting/generated/classes/GRenderSkeletonBone_t.h"
#include "../core.h"

void SetupLuaClassGRenderSkeletonBone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderSkeletonBone_t>("RenderSkeletonBone_t")
        .addProperty("BoneName", &GRenderSkeletonBone_t::GetBoneName, &GRenderSkeletonBone_t::SetBoneName)
        .addProperty("ParentName", &GRenderSkeletonBone_t::GetParentName, &GRenderSkeletonBone_t::SetParentName)
        .addProperty("InvBindPose", &GRenderSkeletonBone_t::GetInvBindPose, &GRenderSkeletonBone_t::SetInvBindPose)
        .addProperty("Bbox", &GRenderSkeletonBone_t::GetBbox, &GRenderSkeletonBone_t::SetBbox)
        .addProperty("SphereRadius", &GRenderSkeletonBone_t::GetSphereRadius, &GRenderSkeletonBone_t::SetSphereRadius)
        .endClass();
}