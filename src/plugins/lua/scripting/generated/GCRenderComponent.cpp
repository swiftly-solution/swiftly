#include "../../../core/scripting/generated/classes/GCRenderComponent.h"
#include "../core.h"

void SetupLuaClassGCRenderComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderComponent>("CRenderComponent")
        .addProperty("__pChainEntity", &GCRenderComponent::Get__pChainEntity, &GCRenderComponent::Set__pChainEntity)
        .addProperty("IsRenderingWithViewModels", &GCRenderComponent::GetIsRenderingWithViewModels, &GCRenderComponent::SetIsRenderingWithViewModels)
        .addProperty("SplitscreenFlags", &GCRenderComponent::GetSplitscreenFlags, &GCRenderComponent::SetSplitscreenFlags)
        .addProperty("EnableRendering", &GCRenderComponent::GetEnableRendering, &GCRenderComponent::SetEnableRendering)
        .addProperty("InterpolationReadyToDraw", &GCRenderComponent::GetInterpolationReadyToDraw, &GCRenderComponent::SetInterpolationReadyToDraw)
        .endClass();
}