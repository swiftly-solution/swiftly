#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionSoundeventPrioritySchema::GCSosGroupActionSoundeventPrioritySchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionSoundeventPrioritySchema::GCSosGroupActionSoundeventPrioritySchema(void *ptr) {
    m_ptr = ptr;
}
std::string GCSosGroupActionSoundeventPrioritySchema::GetPriorityValue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityValue").Get();
}
void GCSosGroupActionSoundeventPrioritySchema::SetPriorityValue(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityValue", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventPrioritySchema::GetPriorityVolumeScalar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityVolumeScalar").Get();
}
void GCSosGroupActionSoundeventPrioritySchema::SetPriorityVolumeScalar(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityVolumeScalar", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventPrioritySchema::GetPriorityContributeButDontRead() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityContributeButDontRead").Get();
}
void GCSosGroupActionSoundeventPrioritySchema::SetPriorityContributeButDontRead(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityContributeButDontRead", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventPrioritySchema::GetPriorityReadButDontContribute() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_bPriorityReadButDontContribute").Get();
}
void GCSosGroupActionSoundeventPrioritySchema::SetPriorityReadButDontContribute(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_bPriorityReadButDontContribute", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventPrioritySchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionSoundeventPrioritySchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionSoundeventPrioritySchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionSoundeventPrioritySchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionSoundeventPrioritySchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSoundeventPrioritySchema>("CSosGroupActionSoundeventPrioritySchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PriorityValue", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityValue, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityValue)
        .addProperty("PriorityVolumeScalar", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityVolumeScalar, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityVolumeScalar)
        .addProperty("PriorityContributeButDontRead", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityContributeButDontRead, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityContributeButDontRead)
        .addProperty("PriorityReadButDontContribute", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityReadButDontContribute, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityReadButDontContribute)
        .addProperty("Parent", &GCSosGroupActionSoundeventPrioritySchema::GetParent, &GCSosGroupActionSoundeventPrioritySchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionSoundeventPrioritySchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionSoundeventPrioritySchema::IsValid)
        .endClass();
}