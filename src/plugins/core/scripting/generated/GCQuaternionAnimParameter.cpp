#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCQuaternionAnimParameter::GCQuaternionAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCQuaternionAnimParameter::GCQuaternionAnimParameter(void *ptr) {
    m_ptr = ptr;
}
Quaternion GCQuaternionAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CQuaternionAnimParameter", "m_defaultValue");
}
void GCQuaternionAnimParameter::SetDefaultValue(Quaternion value) {
    SetSchemaValue(m_ptr, "CQuaternionAnimParameter", "m_defaultValue", false, value);
}
bool GCQuaternionAnimParameter::GetInterpolate() const {
    return GetSchemaValue<bool>(m_ptr, "CQuaternionAnimParameter", "m_bInterpolate");
}
void GCQuaternionAnimParameter::SetInterpolate(bool value) {
    SetSchemaValue(m_ptr, "CQuaternionAnimParameter", "m_bInterpolate", false, value);
}
std::string GCQuaternionAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCQuaternionAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCQuaternionAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCQuaternionAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCQuaternionAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCQuaternionAnimParameter>("CQuaternionAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCQuaternionAnimParameter::GetDefaultValue, &GCQuaternionAnimParameter::SetDefaultValue)
        .addProperty("Interpolate", &GCQuaternionAnimParameter::GetInterpolate, &GCQuaternionAnimParameter::SetInterpolate)
        .addProperty("Parent", &GCQuaternionAnimParameter::GetParent, &GCQuaternionAnimParameter::SetParent)
        .addFunction("ToPtr", &GCQuaternionAnimParameter::ToPtr)
        .addFunction("IsValid", &GCQuaternionAnimParameter::IsValid)
        .endClass();
}