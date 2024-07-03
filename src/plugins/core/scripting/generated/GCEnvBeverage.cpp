#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvBeverage::GCEnvBeverage(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvBeverage::GCEnvBeverage(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvBeverage::GetCanInDispenser() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvBeverage", "m_CanInDispenser");
}
void GCEnvBeverage::SetCanInDispenser(bool value) {
    SetSchemaValue(m_ptr, "CEnvBeverage", "m_CanInDispenser", false, value);
}
int32_t GCEnvBeverage::GetBeverageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvBeverage", "m_nBeverageType");
}
void GCEnvBeverage::SetBeverageType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvBeverage", "m_nBeverageType", false, value);
}
std::string GCEnvBeverage::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvBeverage::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvBeverage::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvBeverage::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvBeverage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvBeverage>("CEnvBeverage")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CanInDispenser", &GCEnvBeverage::GetCanInDispenser, &GCEnvBeverage::SetCanInDispenser)
        .addProperty("BeverageType", &GCEnvBeverage::GetBeverageType, &GCEnvBeverage::SetBeverageType)
        .addProperty("Parent", &GCEnvBeverage::GetParent, &GCEnvBeverage::SetParent)
        .addFunction("ToPtr", &GCEnvBeverage::ToPtr)
        .addFunction("IsValid", &GCEnvBeverage::IsValid)
        .endClass();
}