#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkTransmitComponent::GCNetworkTransmitComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkTransmitComponent::GCNetworkTransmitComponent(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCNetworkTransmitComponent::GetTransmitStateOwnedCounter() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CNetworkTransmitComponent", "m_nTransmitStateOwnedCounter");
}
void GCNetworkTransmitComponent::SetTransmitStateOwnedCounter(uint8_t value) {
    SetSchemaValue(m_ptr, "CNetworkTransmitComponent", "m_nTransmitStateOwnedCounter", false, value);
}
std::string GCNetworkTransmitComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkTransmitComponent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkTransmitComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkTransmitComponent>("CNetworkTransmitComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TransmitStateOwnedCounter", &GCNetworkTransmitComponent::GetTransmitStateOwnedCounter, &GCNetworkTransmitComponent::SetTransmitStateOwnedCounter)
        .addFunction("ToPtr", &GCNetworkTransmitComponent::ToPtr)
        .addFunction("IsValid", &GCNetworkTransmitComponent::IsValid)
        .endClass();
}