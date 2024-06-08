#include "../../../core/scripting/generated/classes/GModelSkeletonData_t.h"
#include "../core.h"

void SetupLuaClassGModelSkeletonData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelSkeletonData_t>("ModelSkeletonData_t")
        .addProperty("BoneName", &GModelSkeletonData_t::GetBoneName, &GModelSkeletonData_t::SetBoneName)
        .addProperty("Parent", &GModelSkeletonData_t::GetParent, &GModelSkeletonData_t::SetParent)
        .addProperty("BoneSphere", &GModelSkeletonData_t::GetBoneSphere, &GModelSkeletonData_t::SetBoneSphere)
        .addProperty("Flag", &GModelSkeletonData_t::GetFlag, &GModelSkeletonData_t::SetFlag)
        .addProperty("BonePosParent", &GModelSkeletonData_t::GetBonePosParent, &GModelSkeletonData_t::SetBonePosParent)
        .addProperty("BoneScaleParent", &GModelSkeletonData_t::GetBoneScaleParent, &GModelSkeletonData_t::SetBoneScaleParent)
        .endClass();
}