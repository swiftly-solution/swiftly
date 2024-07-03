#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnumAnimParameter::GCEnumAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnumAnimParameter::GCEnumAnimParameter(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCEnumAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEnumAnimParameter", "m_defaultValue");
}
void GCEnumAnimParameter::SetDefaultValue(uint8_t value) {
    SetSchemaValue(m_ptr, "CEnumAnimParameter", "m_defaultValue", false, value);
}
std::vector<CUtlString> GCEnumAnimParameter::GetEnumOptions() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CEnumAnimParameter", "m_enumOptions"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCEnumAnimParameter::SetEnumOptions(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CEnumAnimParameter", "m_enumOptions", false, value);
}
std::vector<uint64> GCEnumAnimParameter::GetEnumReferenced() const {
    CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CEnumAnimParameter", "m_vecEnumReferenced"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCEnumAnimParameter::SetEnumReferenced(std::vector<uint64> value) {
    SetSchemaValueCUtlVector<uint64>(m_ptr, "CEnumAnimParameter", "m_vecEnumReferenced", false, value);
}
std::string GCEnumAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnumAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCEnumAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCEnumAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnumAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnumAnimParameter>("CEnumAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCEnumAnimParameter::GetDefaultValue, &GCEnumAnimParameter::SetDefaultValue)
        .addProperty("EnumOptions", &GCEnumAnimParameter::GetEnumOptions, &GCEnumAnimParameter::SetEnumOptions)
        .addProperty("EnumReferenced", &GCEnumAnimParameter::GetEnumReferenced, &GCEnumAnimParameter::SetEnumReferenced)
        .addProperty("Parent", &GCEnumAnimParameter::GetParent, &GCEnumAnimParameter::SetParent)
        .addFunction("ToPtr", &GCEnumAnimParameter::ToPtr)
        .addFunction("IsValid", &GCEnumAnimParameter::IsValid)
        .endClass();
}