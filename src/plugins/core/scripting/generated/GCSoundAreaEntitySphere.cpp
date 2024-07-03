#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundAreaEntitySphere::GCSoundAreaEntitySphere(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundAreaEntitySphere::GCSoundAreaEntitySphere(void *ptr) {
    m_ptr = ptr;
}
float GCSoundAreaEntitySphere::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CSoundAreaEntitySphere", "m_flRadius");
}
void GCSoundAreaEntitySphere::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntitySphere", "m_flRadius", false, value);
}
std::string GCSoundAreaEntitySphere::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundAreaEntitySphere::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundAreaEntityBase GCSoundAreaEntitySphere::GetParent() const {
    GCSoundAreaEntityBase value(m_ptr);
    return value;
}
void GCSoundAreaEntitySphere::SetParent(GCSoundAreaEntityBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundAreaEntitySphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntitySphere>("CSoundAreaEntitySphere")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCSoundAreaEntitySphere::GetRadius, &GCSoundAreaEntitySphere::SetRadius)
        .addProperty("Parent", &GCSoundAreaEntitySphere::GetParent, &GCSoundAreaEntitySphere::SetParent)
        .addFunction("ToPtr", &GCSoundAreaEntitySphere::ToPtr)
        .addFunction("IsValid", &GCSoundAreaEntitySphere::IsValid)
        .endClass();
}