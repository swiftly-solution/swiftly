#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerPawnComponent::GCPlayerPawnComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerPawnComponent::GCPlayerPawnComponent(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCPlayerPawnComponent::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CPlayerPawnComponent", "__m_pChainEntity"));
    return value;
}
void GCPlayerPawnComponent::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CPlayerPawnComponent", "__m_pChainEntity", false, value);
}
std::string GCPlayerPawnComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerPawnComponent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPlayerPawnComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerPawnComponent>("CPlayerPawnComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCPlayerPawnComponent::Get__pChainEntity, &GCPlayerPawnComponent::Set__pChainEntity)
        .addFunction("ToPtr", &GCPlayerPawnComponent::ToPtr)
        .addFunction("IsValid", &GCPlayerPawnComponent::IsValid)
        .endClass();
}