#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemAssaultSuit::GCItemAssaultSuit(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemAssaultSuit::GCItemAssaultSuit(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemAssaultSuit::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemAssaultSuit::IsValid() {
    return (m_ptr != nullptr);
}
GCItem GCItemAssaultSuit::GetParent() const {
    GCItem value(m_ptr);
    return value;
}
void GCItemAssaultSuit::SetParent(GCItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemAssaultSuit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemAssaultSuit>("CItemAssaultSuit")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemAssaultSuit::GetParent, &GCItemAssaultSuit::SetParent)
        .addFunction("ToPtr", &GCItemAssaultSuit::ToPtr)
        .addFunction("IsValid", &GCItemAssaultSuit::IsValid)
        .endClass();
}