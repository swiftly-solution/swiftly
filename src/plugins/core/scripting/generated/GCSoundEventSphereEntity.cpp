#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventSphereEntity::GCSoundEventSphereEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventSphereEntity::GCSoundEventSphereEntity(void *ptr) {
    m_ptr = ptr;
}
float GCSoundEventSphereEntity::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventSphereEntity", "m_flRadius");
}
void GCSoundEventSphereEntity::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CSoundEventSphereEntity", "m_flRadius", false, value);
}
std::string GCSoundEventSphereEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventSphereEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundEventEntity GCSoundEventSphereEntity::GetParent() const {
    GCSoundEventEntity value(m_ptr);
    return value;
}
void GCSoundEventSphereEntity::SetParent(GCSoundEventEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventSphereEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventSphereEntity>("CSoundEventSphereEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCSoundEventSphereEntity::GetRadius, &GCSoundEventSphereEntity::SetRadius)
        .addProperty("Parent", &GCSoundEventSphereEntity::GetParent, &GCSoundEventSphereEntity::SetParent)
        .addFunction("ToPtr", &GCSoundEventSphereEntity::ToPtr)
        .addFunction("IsValid", &GCSoundEventSphereEntity::IsValid)
        .endClass();
}