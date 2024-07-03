#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointProximitySensor::GCPointProximitySensor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointProximitySensor::GCPointProximitySensor(void *ptr) {
    m_ptr = ptr;
}
bool GCPointProximitySensor::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointProximitySensor", "m_bDisabled");
}
void GCPointProximitySensor::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPointProximitySensor", "m_bDisabled", false, value);
}
GCBaseEntity GCPointProximitySensor::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointProximitySensor", "m_hTargetEntity"));
    return value;
}
void GCPointProximitySensor::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
std::string GCPointProximitySensor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointProximitySensor::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointProximitySensor::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointProximitySensor::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointProximitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointProximitySensor>("CPointProximitySensor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCPointProximitySensor::GetDisabled, &GCPointProximitySensor::SetDisabled)
        .addProperty("TargetEntity", &GCPointProximitySensor::GetTargetEntity, &GCPointProximitySensor::SetTargetEntity)
        .addProperty("Parent", &GCPointProximitySensor::GetParent, &GCPointProximitySensor::SetParent)
        .addFunction("ToPtr", &GCPointProximitySensor::ToPtr)
        .addFunction("IsValid", &GCPointProximitySensor::IsValid)
        .endClass();
}