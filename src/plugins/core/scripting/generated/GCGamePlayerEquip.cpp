#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGamePlayerEquip::GCGamePlayerEquip(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGamePlayerEquip::GCGamePlayerEquip(void *ptr) {
    m_ptr = ptr;
}
std::string GCGamePlayerEquip::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGamePlayerEquip::IsValid() {
    return (m_ptr != nullptr);
}
GCRulePointEntity GCGamePlayerEquip::GetParent() const {
    GCRulePointEntity value(m_ptr);
    return value;
}
void GCGamePlayerEquip::SetParent(GCRulePointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGamePlayerEquip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGamePlayerEquip>("CGamePlayerEquip")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCGamePlayerEquip::GetParent, &GCGamePlayerEquip::SetParent)
        .addFunction("ToPtr", &GCGamePlayerEquip::ToPtr)
        .addFunction("IsValid", &GCGamePlayerEquip::IsValid)
        .endClass();
}