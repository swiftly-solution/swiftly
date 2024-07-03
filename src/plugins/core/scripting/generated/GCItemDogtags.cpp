#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemDogtags::GCItemDogtags(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemDogtags::GCItemDogtags(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayerPawn GCItemDogtags::GetOwningPlayer() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CItemDogtags", "m_OwningPlayer"));
    return value;
}
void GCItemDogtags::SetOwningPlayer(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwningPlayer' is not possible.\n");
}
GCCSPlayerPawn GCItemDogtags::GetKillingPlayer() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CItemDogtags", "m_KillingPlayer"));
    return value;
}
void GCItemDogtags::SetKillingPlayer(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'KillingPlayer' is not possible.\n");
}
std::string GCItemDogtags::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemDogtags::IsValid() {
    return (m_ptr != nullptr);
}
GCItem GCItemDogtags::GetParent() const {
    GCItem value(m_ptr);
    return value;
}
void GCItemDogtags::SetParent(GCItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemDogtags(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDogtags>("CItemDogtags")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OwningPlayer", &GCItemDogtags::GetOwningPlayer, &GCItemDogtags::SetOwningPlayer)
        .addProperty("KillingPlayer", &GCItemDogtags::GetKillingPlayer, &GCItemDogtags::SetKillingPlayer)
        .addProperty("Parent", &GCItemDogtags::GetParent, &GCItemDogtags::SetParent)
        .addFunction("ToPtr", &GCItemDogtags::ToPtr)
        .addFunction("IsValid", &GCItemDogtags::IsValid)
        .endClass();
}