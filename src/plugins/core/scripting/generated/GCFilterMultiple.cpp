#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterMultiple::GCFilterMultiple(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterMultiple::GCFilterMultiple(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFilterMultiple::GetFilterType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFilterMultiple", "m_nFilterType");
}
void GCFilterMultiple::SetFilterType(uint64_t value) {
    SetSchemaValue(m_ptr, "CFilterMultiple", "m_nFilterType", false, value);
}
std::vector<CUtlSymbolLarge> GCFilterMultiple::GetFilterName() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CFilterMultiple", "m_iFilterName"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCFilterMultiple::SetFilterName(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CFilterMultiple", "m_iFilterName"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFilterMultiple", "m_iFilterName", false, outValue);
}
std::vector<GCBaseEntity*> GCFilterMultiple::GetFilter() const {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CFilterMultiple", "m_hFilter"); std::vector<GCBaseEntity*> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCFilterMultiple::SetFilter(std::vector<GCBaseEntity*> value) {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CFilterMultiple", "m_hFilter"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFilterMultiple", "m_hFilter", false, outValue);
}
int32_t GCFilterMultiple::GetFilterCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFilterMultiple", "m_nFilterCount");
}
void GCFilterMultiple::SetFilterCount(int32_t value) {
    SetSchemaValue(m_ptr, "CFilterMultiple", "m_nFilterCount", false, value);
}
std::string GCFilterMultiple::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterMultiple::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterMultiple::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterMultiple::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterMultiple>("CFilterMultiple")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterType", &GCFilterMultiple::GetFilterType, &GCFilterMultiple::SetFilterType)
        .addProperty("FilterName", &GCFilterMultiple::GetFilterName, &GCFilterMultiple::SetFilterName)
        .addProperty("Filter", &GCFilterMultiple::GetFilter, &GCFilterMultiple::SetFilter)
        .addProperty("FilterCount", &GCFilterMultiple::GetFilterCount, &GCFilterMultiple::SetFilterCount)
        .addProperty("Parent", &GCFilterMultiple::GetParent, &GCFilterMultiple::SetParent)
        .addFunction("ToPtr", &GCFilterMultiple::ToPtr)
        .addFunction("IsValid", &GCFilterMultiple::IsValid)
        .endClass();
}