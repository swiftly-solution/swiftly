#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCIntAnimParameter::GCIntAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCIntAnimParameter::GCIntAnimParameter(void *ptr) {
    m_ptr = ptr;
}
int32_t GCIntAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_defaultValue");
}
void GCIntAnimParameter::SetDefaultValue(int32_t value) {
    SetSchemaValue(m_ptr, "CIntAnimParameter", "m_defaultValue", false, value);
}
int32_t GCIntAnimParameter::GetMinValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_minValue");
}
void GCIntAnimParameter::SetMinValue(int32_t value) {
    SetSchemaValue(m_ptr, "CIntAnimParameter", "m_minValue", false, value);
}
int32_t GCIntAnimParameter::GetMaxValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_maxValue");
}
void GCIntAnimParameter::SetMaxValue(int32_t value) {
    SetSchemaValue(m_ptr, "CIntAnimParameter", "m_maxValue", false, value);
}
std::string GCIntAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCIntAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCIntAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCIntAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCIntAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIntAnimParameter>("CIntAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCIntAnimParameter::GetDefaultValue, &GCIntAnimParameter::SetDefaultValue)
        .addProperty("MinValue", &GCIntAnimParameter::GetMinValue, &GCIntAnimParameter::SetMinValue)
        .addProperty("MaxValue", &GCIntAnimParameter::GetMaxValue, &GCIntAnimParameter::SetMaxValue)
        .addProperty("Parent", &GCIntAnimParameter::GetParent, &GCIntAnimParameter::SetParent)
        .addFunction("ToPtr", &GCIntAnimParameter::ToPtr)
        .addFunction("IsValid", &GCIntAnimParameter::IsValid)
        .endClass();
}