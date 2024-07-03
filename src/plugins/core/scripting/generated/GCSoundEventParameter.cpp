#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventParameter::GCSoundEventParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventParameter::GCSoundEventParameter(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundEventParameter::GetParamName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventParameter", "m_iszParamName").String();
}
void GCSoundEventParameter::SetParamName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundEventParameter", "m_iszParamName", false, CUtlSymbolLarge(value.c_str()));
}
float GCSoundEventParameter::GetFloatValue() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventParameter", "m_flFloatValue");
}
void GCSoundEventParameter::SetFloatValue(float value) {
    SetSchemaValue(m_ptr, "CSoundEventParameter", "m_flFloatValue", false, value);
}
std::string GCSoundEventParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSoundEventParameter::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSoundEventParameter::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventParameter>("CSoundEventParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParamName", &GCSoundEventParameter::GetParamName, &GCSoundEventParameter::SetParamName)
        .addProperty("FloatValue", &GCSoundEventParameter::GetFloatValue, &GCSoundEventParameter::SetFloatValue)
        .addProperty("Parent", &GCSoundEventParameter::GetParent, &GCSoundEventParameter::SetParent)
        .addFunction("ToPtr", &GCSoundEventParameter::ToPtr)
        .addFunction("IsValid", &GCSoundEventParameter::IsValid)
        .endClass();
}