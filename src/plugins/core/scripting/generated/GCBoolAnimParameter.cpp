#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoolAnimParameter::GCBoolAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoolAnimParameter::GCBoolAnimParameter(void *ptr) {
    m_ptr = ptr;
}
bool GCBoolAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<bool>(m_ptr, "CBoolAnimParameter", "m_bDefaultValue");
}
void GCBoolAnimParameter::SetDefaultValue(bool value) {
    SetSchemaValue(m_ptr, "CBoolAnimParameter", "m_bDefaultValue", false, value);
}
std::string GCBoolAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoolAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCBoolAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCBoolAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoolAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoolAnimParameter>("CBoolAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCBoolAnimParameter::GetDefaultValue, &GCBoolAnimParameter::SetDefaultValue)
        .addProperty("Parent", &GCBoolAnimParameter::GetParent, &GCBoolAnimParameter::SetParent)
        .addFunction("ToPtr", &GCBoolAnimParameter::ToPtr)
        .addFunction("IsValid", &GCBoolAnimParameter::IsValid)
        .endClass();
}