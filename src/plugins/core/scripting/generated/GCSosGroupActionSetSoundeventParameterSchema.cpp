#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionSetSoundeventParameterSchema::GCSosGroupActionSetSoundeventParameterSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionSetSoundeventParameterSchema::GCSosGroupActionSetSoundeventParameterSchema(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSosGroupActionSetSoundeventParameterSchema::GetMaxCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nMaxCount");
}
void GCSosGroupActionSetSoundeventParameterSchema::SetMaxCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nMaxCount", false, value);
}
float GCSosGroupActionSetSoundeventParameterSchema::GetMinValue() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMinValue");
}
void GCSosGroupActionSetSoundeventParameterSchema::SetMinValue(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMinValue", false, value);
}
float GCSosGroupActionSetSoundeventParameterSchema::GetMaxValue() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMaxValue");
}
void GCSosGroupActionSetSoundeventParameterSchema::SetMaxValue(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMaxValue", false, value);
}
std::string GCSosGroupActionSetSoundeventParameterSchema::GetOpvarName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_opvarName").Get();
}
void GCSosGroupActionSetSoundeventParameterSchema::SetOpvarName(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_opvarName", false, CUtlString(value.c_str()));
}
uint64_t GCSosGroupActionSetSoundeventParameterSchema::GetSortType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nSortType");
}
void GCSosGroupActionSetSoundeventParameterSchema::SetSortType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nSortType", false, value);
}
std::string GCSosGroupActionSetSoundeventParameterSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionSetSoundeventParameterSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionSetSoundeventParameterSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionSetSoundeventParameterSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionSetSoundeventParameterSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSetSoundeventParameterSchema>("CSosGroupActionSetSoundeventParameterSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxCount", &GCSosGroupActionSetSoundeventParameterSchema::GetMaxCount, &GCSosGroupActionSetSoundeventParameterSchema::SetMaxCount)
        .addProperty("MinValue", &GCSosGroupActionSetSoundeventParameterSchema::GetMinValue, &GCSosGroupActionSetSoundeventParameterSchema::SetMinValue)
        .addProperty("MaxValue", &GCSosGroupActionSetSoundeventParameterSchema::GetMaxValue, &GCSosGroupActionSetSoundeventParameterSchema::SetMaxValue)
        .addProperty("OpvarName", &GCSosGroupActionSetSoundeventParameterSchema::GetOpvarName, &GCSosGroupActionSetSoundeventParameterSchema::SetOpvarName)
        .addProperty("SortType", &GCSosGroupActionSetSoundeventParameterSchema::GetSortType, &GCSosGroupActionSetSoundeventParameterSchema::SetSortType)
        .addProperty("Parent", &GCSosGroupActionSetSoundeventParameterSchema::GetParent, &GCSosGroupActionSetSoundeventParameterSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionSetSoundeventParameterSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionSetSoundeventParameterSchema::IsValid)
        .endClass();
}