#include "../../../core/scripting/generated/classes/GCNmTarget.h"
#include "../core.h"

void SetupLuaClassGCNmTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTarget>("CNmTarget")
        .addProperty("IsBoneTarget", &GCNmTarget::GetIsBoneTarget, &GCNmTarget::SetIsBoneTarget)
        .addProperty("IsUsingBoneSpaceOffsets", &GCNmTarget::GetIsUsingBoneSpaceOffsets, &GCNmTarget::SetIsUsingBoneSpaceOffsets)
        .addProperty("HasOffsets", &GCNmTarget::GetHasOffsets, &GCNmTarget::SetHasOffsets)
        .addProperty("IsSet", &GCNmTarget::GetIsSet, &GCNmTarget::SetIsSet)
        .endClass();
}