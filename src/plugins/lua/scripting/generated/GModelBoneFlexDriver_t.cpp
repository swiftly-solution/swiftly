#include "../../../core/scripting/generated/classes/GModelBoneFlexDriver_t.h"
#include "../core.h"

void SetupLuaClassGModelBoneFlexDriver_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelBoneFlexDriver_t>("ModelBoneFlexDriver_t")
        .addProperty("BoneName", &GModelBoneFlexDriver_t::GetBoneName, &GModelBoneFlexDriver_t::SetBoneName)
        .addProperty("BoneNameToken", &GModelBoneFlexDriver_t::GetBoneNameToken, &GModelBoneFlexDriver_t::SetBoneNameToken)
        .addProperty("Controls", &GModelBoneFlexDriver_t::GetControls, &GModelBoneFlexDriver_t::SetControls)
        .endClass();
}