#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundStackSave::GCSoundStackSave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundStackSave::GCSoundStackSave(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundStackSave::GetStackName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundStackSave", "m_iszStackName").String();
}
void GCSoundStackSave::SetStackName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundStackSave", "m_iszStackName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundStackSave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundStackSave::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCSoundStackSave::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCSoundStackSave::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundStackSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundStackSave>("CSoundStackSave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StackName", &GCSoundStackSave::GetStackName, &GCSoundStackSave::SetStackName)
        .addProperty("Parent", &GCSoundStackSave::GetParent, &GCSoundStackSave::SetParent)
        .addFunction("ToPtr", &GCSoundStackSave::ToPtr)
        .addFunction("IsValid", &GCSoundStackSave::IsValid)
        .endClass();
}