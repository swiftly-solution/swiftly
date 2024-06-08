#include "../../../core/scripting/generated/classes/GCPlayerControllerComponent.h"
#include "../core.h"

void SetupLuaClassGCPlayerControllerComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerControllerComponent>("CPlayerControllerComponent")
        .addProperty("__pChainEntity", &GCPlayerControllerComponent::Get__pChainEntity, &GCPlayerControllerComponent::Set__pChainEntity)
        .endClass();
}