#include "../../../core/scripting/generated/classes/GSkeletonAnimCapture_t__Bone_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonAnimCapture_t__Bone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Bone_t>("SkeletonAnimCapture_t__Bone_t")
        .addProperty("Name", &GSkeletonAnimCapture_t__Bone_t::GetName, &GSkeletonAnimCapture_t__Bone_t::SetName)
        .addProperty("Parent", &GSkeletonAnimCapture_t__Bone_t::GetParent, &GSkeletonAnimCapture_t__Bone_t::SetParent)
        .endClass();
}