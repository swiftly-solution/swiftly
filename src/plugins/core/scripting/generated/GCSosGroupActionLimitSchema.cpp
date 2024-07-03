#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionLimitSchema::GCSosGroupActionLimitSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionLimitSchema::GCSosGroupActionLimitSchema(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSosGroupActionLimitSchema::GetMaxCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nMaxCount");
}
void GCSosGroupActionLimitSchema::SetMaxCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nMaxCount", false, value);
}
uint64_t GCSosGroupActionLimitSchema::GetStopType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nStopType");
}
void GCSosGroupActionLimitSchema::SetStopType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nStopType", false, value);
}
uint64_t GCSosGroupActionLimitSchema::GetSortType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nSortType");
}
void GCSosGroupActionLimitSchema::SetSortType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nSortType", false, value);
}
std::string GCSosGroupActionLimitSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionLimitSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionLimitSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionLimitSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionLimitSchema>("CSosGroupActionLimitSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxCount", &GCSosGroupActionLimitSchema::GetMaxCount, &GCSosGroupActionLimitSchema::SetMaxCount)
        .addProperty("StopType", &GCSosGroupActionLimitSchema::GetStopType, &GCSosGroupActionLimitSchema::SetStopType)
        .addProperty("SortType", &GCSosGroupActionLimitSchema::GetSortType, &GCSosGroupActionLimitSchema::SetSortType)
        .addProperty("Parent", &GCSosGroupActionLimitSchema::GetParent, &GCSosGroupActionLimitSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionLimitSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionLimitSchema::IsValid)
        .endClass();
}