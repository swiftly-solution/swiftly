#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFilterDamageType::GFilterDamageType(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFilterDamageType::GFilterDamageType(void *ptr) {
    m_ptr = ptr;
}
int32_t GFilterDamageType::GetDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "FilterDamageType", "m_iDamageType");
}
void GFilterDamageType::SetDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "FilterDamageType", "m_iDamageType", false, value);
}
std::string GFilterDamageType::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFilterDamageType::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GFilterDamageType::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GFilterDamageType::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFilterDamageType(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterDamageType>("FilterDamageType")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DamageType", &GFilterDamageType::GetDamageType, &GFilterDamageType::SetDamageType)
        .addProperty("Parent", &GFilterDamageType::GetParent, &GFilterDamageType::SetParent)
        .addFunction("ToPtr", &GFilterDamageType::ToPtr)
        .addFunction("IsValid", &GFilterDamageType::IsValid)
        .endClass();
}