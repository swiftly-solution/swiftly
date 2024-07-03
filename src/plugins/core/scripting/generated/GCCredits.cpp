#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCredits::GCCredits(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCredits::GCCredits(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCCredits::GetOnCreditsDone() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CCredits", "m_OnCreditsDone"));
    return value;
}
void GCCredits::SetOnCreditsDone(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CCredits", "m_OnCreditsDone", false, value);
}
bool GCCredits::GetRolledOutroCredits() const {
    return GetSchemaValue<bool>(m_ptr, "CCredits", "m_bRolledOutroCredits");
}
void GCCredits::SetRolledOutroCredits(bool value) {
    SetSchemaValue(m_ptr, "CCredits", "m_bRolledOutroCredits", false, value);
}
float GCCredits::GetLogoLength() const {
    return GetSchemaValue<float>(m_ptr, "CCredits", "m_flLogoLength");
}
void GCCredits::SetLogoLength(float value) {
    SetSchemaValue(m_ptr, "CCredits", "m_flLogoLength", false, value);
}
std::string GCCredits::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCredits::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCCredits::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCCredits::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCredits(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCredits>("CCredits")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnCreditsDone", &GCCredits::GetOnCreditsDone, &GCCredits::SetOnCreditsDone)
        .addProperty("RolledOutroCredits", &GCCredits::GetRolledOutroCredits, &GCCredits::SetRolledOutroCredits)
        .addProperty("LogoLength", &GCCredits::GetLogoLength, &GCCredits::SetLogoLength)
        .addProperty("Parent", &GCCredits::GetParent, &GCCredits::SetParent)
        .addFunction("ToPtr", &GCCredits::ToPtr)
        .addFunction("IsValid", &GCCredits::IsValid)
        .endClass();
}