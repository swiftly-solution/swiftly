#include "../../../core/scripting/generated/classes/GCBodyComponent.h"
#include "../core.h"

void SetupLuaClassGCBodyComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponent>("CBodyComponent")
        .addProperty("SceneNode", &GCBodyComponent::GetSceneNode, &GCBodyComponent::SetSceneNode)
        .addProperty("__pChainEntity", &GCBodyComponent::Get__pChainEntity, &GCBodyComponent::Set__pChainEntity)
        .endClass();
}