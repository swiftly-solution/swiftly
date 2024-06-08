#include "../../../core/scripting/generated/classes/GCPlayerPawnComponent.h"
#include "../core.h"

void SetupLuaClassGCPlayerPawnComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerPawnComponent>("CPlayerPawnComponent")
        .addProperty("__pChainEntity", &GCPlayerPawnComponent::Get__pChainEntity, &GCPlayerPawnComponent::Set__pChainEntity)
        .endClass();
}