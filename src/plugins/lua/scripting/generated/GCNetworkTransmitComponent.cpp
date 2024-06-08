#include "../../../core/scripting/generated/classes/GCNetworkTransmitComponent.h"
#include "../core.h"

void SetupLuaClassGCNetworkTransmitComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkTransmitComponent>("CNetworkTransmitComponent")
        .addProperty("TransmitStateOwnedCounter", &GCNetworkTransmitComponent::GetTransmitStateOwnedCounter, &GCNetworkTransmitComponent::SetTransmitStateOwnedCounter)
        .endClass();
}