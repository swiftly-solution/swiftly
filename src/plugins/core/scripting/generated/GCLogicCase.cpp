#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicCase::GCLogicCase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicCase::GCLogicCase(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlSymbolLarge> GCLogicCase::GetCase() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicCase", "m_nCase"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCLogicCase::SetCase(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicCase", "m_nCase"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_nCase", false, outValue);
}
int32_t GCLogicCase::GetShuffleCases() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicCase", "m_nShuffleCases");
}
void GCLogicCase::SetShuffleCases(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicCase", "m_nShuffleCases", false, value);
}
int32_t GCLogicCase::GetLastShuffleCase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicCase", "m_nLastShuffleCase");
}
void GCLogicCase::SetLastShuffleCase(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicCase", "m_nLastShuffleCase", false, value);
}
std::vector<uint8_t> GCLogicCase::GetUchShuffleCaseMap() const {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CLogicCase", "m_uchShuffleCaseMap"); std::vector<uint8_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCLogicCase::SetUchShuffleCaseMap(std::vector<uint8_t> value) {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CLogicCase", "m_uchShuffleCaseMap"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_uchShuffleCaseMap", false, outValue);
}
std::vector<GCEntityIOOutput> GCLogicCase::GetOnCase() const {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CLogicCase", "m_OnCase"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCLogicCase::SetOnCase(std::vector<GCEntityIOOutput> value) {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CLogicCase", "m_OnCase"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_OnCase", false, outValue);
}
std::string GCLogicCase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicCase::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicCase::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicCase::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicCase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCase>("CLogicCase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Case", &GCLogicCase::GetCase, &GCLogicCase::SetCase)
        .addProperty("ShuffleCases", &GCLogicCase::GetShuffleCases, &GCLogicCase::SetShuffleCases)
        .addProperty("LastShuffleCase", &GCLogicCase::GetLastShuffleCase, &GCLogicCase::SetLastShuffleCase)
        .addProperty("UchShuffleCaseMap", &GCLogicCase::GetUchShuffleCaseMap, &GCLogicCase::SetUchShuffleCaseMap)
        .addProperty("OnCase", &GCLogicCase::GetOnCase, &GCLogicCase::SetOnCase)
        .addProperty("Parent", &GCLogicCase::GetParent, &GCLogicCase::SetParent)
        .addFunction("ToPtr", &GCLogicCase::ToPtr)
        .addFunction("IsValid", &GCLogicCase::IsValid)
        .endClass();
}