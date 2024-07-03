#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAggregateLODSetup_t::GAggregateLODSetup_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAggregateLODSetup_t::GAggregateLODSetup_t(void *ptr) {
    m_ptr = ptr;
}
Vector GAggregateLODSetup_t::GetLODOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "AggregateLODSetup_t", "m_vLODOrigin");
}
void GAggregateLODSetup_t::SetLODOrigin(Vector value) {
    SetSchemaValue(m_ptr, "AggregateLODSetup_t", "m_vLODOrigin", true, value);
}
float GAggregateLODSetup_t::GetMaxObjectScale() const {
    return GetSchemaValue<float>(m_ptr, "AggregateLODSetup_t", "m_fMaxObjectScale");
}
void GAggregateLODSetup_t::SetMaxObjectScale(float value) {
    SetSchemaValue(m_ptr, "AggregateLODSetup_t", "m_fMaxObjectScale", true, value);
}
std::vector<float32> GAggregateLODSetup_t::GetSwitchDistances() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "AggregateLODSetup_t", "m_fSwitchDistances"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAggregateLODSetup_t::SetSwitchDistances(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "AggregateLODSetup_t", "m_fSwitchDistances", true, value);
}
std::string GAggregateLODSetup_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAggregateLODSetup_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAggregateLODSetup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateLODSetup_t>("AggregateLODSetup_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LODOrigin", &GAggregateLODSetup_t::GetLODOrigin, &GAggregateLODSetup_t::SetLODOrigin)
        .addProperty("MaxObjectScale", &GAggregateLODSetup_t::GetMaxObjectScale, &GAggregateLODSetup_t::SetMaxObjectScale)
        .addProperty("SwitchDistances", &GAggregateLODSetup_t::GetSwitchDistances, &GAggregateLODSetup_t::SetSwitchDistances)
        .addFunction("ToPtr", &GAggregateLODSetup_t::ToPtr)
        .addFunction("IsValid", &GAggregateLODSetup_t::IsValid)
        .endClass();
}