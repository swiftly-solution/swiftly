#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemHeavyAssaultSuit::GCItemHeavyAssaultSuit(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemHeavyAssaultSuit::GCItemHeavyAssaultSuit(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemHeavyAssaultSuit::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemHeavyAssaultSuit::IsValid() {
    return (m_ptr != nullptr);
}
GCItemAssaultSuit GCItemHeavyAssaultSuit::GetParent() const {
    GCItemAssaultSuit value(m_ptr);
    return value;
}
void GCItemHeavyAssaultSuit::SetParent(GCItemAssaultSuit value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemHeavyAssaultSuit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemHeavyAssaultSuit>("CItemHeavyAssaultSuit")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemHeavyAssaultSuit::GetParent, &GCItemHeavyAssaultSuit::SetParent)
        .addFunction("ToPtr", &GCItemHeavyAssaultSuit::ToPtr)
        .addFunction("IsValid", &GCItemHeavyAssaultSuit::IsValid)
        .endClass();
}