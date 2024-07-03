#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_ItemServices::GCCSPlayer_ItemServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_ItemServices::GCCSPlayer_ItemServices(void *ptr) {
    m_ptr = ptr;
}
bool GCCSPlayer_ItemServices::GetHasDefuser() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasDefuser");
}
void GCCSPlayer_ItemServices::SetHasDefuser(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasDefuser", false, value);
}
bool GCCSPlayer_ItemServices::GetHasHelmet() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasHelmet");
}
void GCCSPlayer_ItemServices::SetHasHelmet(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasHelmet", false, value);
}
bool GCCSPlayer_ItemServices::GetHasHeavyArmor() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasHeavyArmor");
}
void GCCSPlayer_ItemServices::SetHasHeavyArmor(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasHeavyArmor", false, value);
}
std::string GCCSPlayer_ItemServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_ItemServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_ItemServices GCCSPlayer_ItemServices::GetParent() const {
    GCPlayer_ItemServices value(m_ptr);
    return value;
}
void GCCSPlayer_ItemServices::SetParent(GCPlayer_ItemServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_ItemServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ItemServices>("CCSPlayer_ItemServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HasDefuser", &GCCSPlayer_ItemServices::GetHasDefuser, &GCCSPlayer_ItemServices::SetHasDefuser)
        .addProperty("HasHelmet", &GCCSPlayer_ItemServices::GetHasHelmet, &GCCSPlayer_ItemServices::SetHasHelmet)
        .addProperty("HasHeavyArmor", &GCCSPlayer_ItemServices::GetHasHeavyArmor, &GCCSPlayer_ItemServices::SetHasHeavyArmor)
        .addProperty("Parent", &GCCSPlayer_ItemServices::GetParent, &GCCSPlayer_ItemServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_ItemServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_ItemServices::IsValid)
        .endClass();
}