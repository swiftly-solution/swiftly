#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameModeRules::GCCSGameModeRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameModeRules::GCCSGameModeRules(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCCSGameModeRules::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CCSGameModeRules", "__m_pChainEntity"));
    return value;
}
void GCCSGameModeRules::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CCSGameModeRules", "__m_pChainEntity", false, value);
}
std::string GCCSGameModeRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameModeRules::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSGameModeRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules>("CCSGameModeRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCCSGameModeRules::Get__pChainEntity, &GCCSGameModeRules::Set__pChainEntity)
        .addFunction("ToPtr", &GCCSGameModeRules::ToPtr)
        .addFunction("IsValid", &GCCSGameModeRules::IsValid)
        .endClass();
}