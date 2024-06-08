#include "../../../core/scripting/generated/classes/GModelBoneFlexDriverControl_t.h"
#include "../core.h"

void SetupLuaClassGModelBoneFlexDriverControl_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelBoneFlexDriverControl_t>("ModelBoneFlexDriverControl_t")
        .addProperty("BoneComponent", &GModelBoneFlexDriverControl_t::GetBoneComponent, &GModelBoneFlexDriverControl_t::SetBoneComponent)
        .addProperty("FlexController", &GModelBoneFlexDriverControl_t::GetFlexController, &GModelBoneFlexDriverControl_t::SetFlexController)
        .addProperty("FlexControllerToken", &GModelBoneFlexDriverControl_t::GetFlexControllerToken, &GModelBoneFlexDriverControl_t::SetFlexControllerToken)
        .addProperty("Min", &GModelBoneFlexDriverControl_t::GetMin, &GModelBoneFlexDriverControl_t::SetMin)
        .addProperty("Max", &GModelBoneFlexDriverControl_t::GetMax, &GModelBoneFlexDriverControl_t::SetMax)
        .endClass();
}