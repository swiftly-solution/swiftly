#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionTimeBlockLimitSchema::GCSosGroupActionTimeBlockLimitSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionTimeBlockLimitSchema::GCSosGroupActionTimeBlockLimitSchema(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSosGroupActionTimeBlockLimitSchema::GetMaxCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_nMaxCount");
}
void GCSosGroupActionTimeBlockLimitSchema::SetMaxCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_nMaxCount", false, value);
}
float GCSosGroupActionTimeBlockLimitSchema::GetMaxDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_flMaxDuration");
}
void GCSosGroupActionTimeBlockLimitSchema::SetMaxDuration(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_flMaxDuration", false, value);
}
std::string GCSosGroupActionTimeBlockLimitSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionTimeBlockLimitSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionTimeBlockLimitSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionTimeBlockLimitSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionTimeBlockLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionTimeBlockLimitSchema>("CSosGroupActionTimeBlockLimitSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxCount", &GCSosGroupActionTimeBlockLimitSchema::GetMaxCount, &GCSosGroupActionTimeBlockLimitSchema::SetMaxCount)
        .addProperty("MaxDuration", &GCSosGroupActionTimeBlockLimitSchema::GetMaxDuration, &GCSosGroupActionTimeBlockLimitSchema::SetMaxDuration)
        .addProperty("Parent", &GCSosGroupActionTimeBlockLimitSchema::GetParent, &GCSosGroupActionTimeBlockLimitSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionTimeBlockLimitSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionTimeBlockLimitSchema::IsValid)
        .endClass();
}