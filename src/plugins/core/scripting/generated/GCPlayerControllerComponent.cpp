#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerControllerComponent::GCPlayerControllerComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerControllerComponent::GCPlayerControllerComponent(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCPlayerControllerComponent::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CPlayerControllerComponent", "__m_pChainEntity"));
    return value;
}
void GCPlayerControllerComponent::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CPlayerControllerComponent", "__m_pChainEntity", false, value);
}
std::string GCPlayerControllerComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerControllerComponent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPlayerControllerComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerControllerComponent>("CPlayerControllerComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCPlayerControllerComponent::Get__pChainEntity, &GCPlayerControllerComponent::Set__pChainEntity)
        .addFunction("ToPtr", &GCPlayerControllerComponent::ToPtr)
        .addFunction("IsValid", &GCPlayerControllerComponent::IsValid)
        .endClass();
}