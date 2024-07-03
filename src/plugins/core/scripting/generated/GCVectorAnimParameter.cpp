#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVectorAnimParameter::GCVectorAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVectorAnimParameter::GCVectorAnimParameter(void *ptr) {
    m_ptr = ptr;
}
Vector GCVectorAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<Vector>(m_ptr, "CVectorAnimParameter", "m_defaultValue");
}
void GCVectorAnimParameter::SetDefaultValue(Vector value) {
    SetSchemaValue(m_ptr, "CVectorAnimParameter", "m_defaultValue", false, value);
}
bool GCVectorAnimParameter::GetInterpolate() const {
    return GetSchemaValue<bool>(m_ptr, "CVectorAnimParameter", "m_bInterpolate");
}
void GCVectorAnimParameter::SetInterpolate(bool value) {
    SetSchemaValue(m_ptr, "CVectorAnimParameter", "m_bInterpolate", false, value);
}
std::string GCVectorAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVectorAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCVectorAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCVectorAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVectorAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVectorAnimParameter>("CVectorAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCVectorAnimParameter::GetDefaultValue, &GCVectorAnimParameter::SetDefaultValue)
        .addProperty("Interpolate", &GCVectorAnimParameter::GetInterpolate, &GCVectorAnimParameter::SetInterpolate)
        .addProperty("Parent", &GCVectorAnimParameter::GetParent, &GCVectorAnimParameter::SetParent)
        .addFunction("ToPtr", &GCVectorAnimParameter::ToPtr)
        .addFunction("IsValid", &GCVectorAnimParameter::IsValid)
        .endClass();
}