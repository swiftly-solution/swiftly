#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetAutoRoomEntity::GCSoundOpvarSetAutoRoomEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetAutoRoomEntity::GCSoundOpvarSetAutoRoomEntity(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSoundOpvarTraceResult_t> GCSoundOpvarSetAutoRoomEntity::GetTraceResults() const {
    CUtlVector<GSoundOpvarTraceResult_t>* vec = GetSchemaValue<CUtlVector<GSoundOpvarTraceResult_t>*>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_traceResults"); std::vector<GSoundOpvarTraceResult_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSoundOpvarSetAutoRoomEntity::SetTraceResults(std::vector<GSoundOpvarTraceResult_t> value) {
    SetSchemaValueCUtlVector<GSoundOpvarTraceResult_t>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_traceResults", false, value);
}
float GCSoundOpvarSetAutoRoomEntity::GetSize() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSize");
}
void GCSoundOpvarSetAutoRoomEntity::SetSize(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSize", false, value);
}
float GCSoundOpvarSetAutoRoomEntity::GetHeightTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flHeightTolerance");
}
void GCSoundOpvarSetAutoRoomEntity::SetHeightTolerance(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flHeightTolerance", false, value);
}
float GCSoundOpvarSetAutoRoomEntity::GetSizeSqr() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSizeSqr");
}
void GCSoundOpvarSetAutoRoomEntity::SetSizeSqr(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSizeSqr", false, value);
}
std::string GCSoundOpvarSetAutoRoomEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetAutoRoomEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetPointEntity GCSoundOpvarSetAutoRoomEntity::GetParent() const {
    GCSoundOpvarSetPointEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetAutoRoomEntity::SetParent(GCSoundOpvarSetPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetAutoRoomEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetAutoRoomEntity>("CSoundOpvarSetAutoRoomEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TraceResults", &GCSoundOpvarSetAutoRoomEntity::GetTraceResults, &GCSoundOpvarSetAutoRoomEntity::SetTraceResults)
        .addProperty("Size", &GCSoundOpvarSetAutoRoomEntity::GetSize, &GCSoundOpvarSetAutoRoomEntity::SetSize)
        .addProperty("HeightTolerance", &GCSoundOpvarSetAutoRoomEntity::GetHeightTolerance, &GCSoundOpvarSetAutoRoomEntity::SetHeightTolerance)
        .addProperty("SizeSqr", &GCSoundOpvarSetAutoRoomEntity::GetSizeSqr, &GCSoundOpvarSetAutoRoomEntity::SetSizeSqr)
        .addProperty("Parent", &GCSoundOpvarSetAutoRoomEntity::GetParent, &GCSoundOpvarSetAutoRoomEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetAutoRoomEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetAutoRoomEntity::IsValid)
        .endClass();
}