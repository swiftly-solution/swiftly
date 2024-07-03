#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParamSpan_t::GParamSpan_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParamSpan_t::GParamSpan_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GParamSpanSample_t> GParamSpan_t::GetSamples() const {
    CUtlVector<GParamSpanSample_t>* vec = GetSchemaValue<CUtlVector<GParamSpanSample_t>*>(m_ptr, "ParamSpan_t", "m_samples"); std::vector<GParamSpanSample_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GParamSpan_t::SetSamples(std::vector<GParamSpanSample_t> value) {
    SetSchemaValueCUtlVector<GParamSpanSample_t>(m_ptr, "ParamSpan_t", "m_samples", true, value);
}
GCAnimParamHandle GParamSpan_t::GetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "ParamSpan_t", "m_hParam"));
    return value;
}
void GParamSpan_t::SetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "ParamSpan_t", "m_hParam", true, value);
}
uint64_t GParamSpan_t::GetParamType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParamSpan_t", "m_eParamType");
}
void GParamSpan_t::SetParamType(uint64_t value) {
    SetSchemaValue(m_ptr, "ParamSpan_t", "m_eParamType", true, value);
}
float GParamSpan_t::GetStartCycle() const {
    return GetSchemaValue<float>(m_ptr, "ParamSpan_t", "m_flStartCycle");
}
void GParamSpan_t::SetStartCycle(float value) {
    SetSchemaValue(m_ptr, "ParamSpan_t", "m_flStartCycle", true, value);
}
float GParamSpan_t::GetEndCycle() const {
    return GetSchemaValue<float>(m_ptr, "ParamSpan_t", "m_flEndCycle");
}
void GParamSpan_t::SetEndCycle(float value) {
    SetSchemaValue(m_ptr, "ParamSpan_t", "m_flEndCycle", true, value);
}
std::string GParamSpan_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParamSpan_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParamSpan_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParamSpan_t>("ParamSpan_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Samples", &GParamSpan_t::GetSamples, &GParamSpan_t::SetSamples)
        .addProperty("Param", &GParamSpan_t::GetParam, &GParamSpan_t::SetParam)
        .addProperty("ParamType", &GParamSpan_t::GetParamType, &GParamSpan_t::SetParamType)
        .addProperty("StartCycle", &GParamSpan_t::GetStartCycle, &GParamSpan_t::SetStartCycle)
        .addProperty("EndCycle", &GParamSpan_t::GetEndCycle, &GParamSpan_t::SetEndCycle)
        .addFunction("ToPtr", &GParamSpan_t::ToPtr)
        .addFunction("IsValid", &GParamSpan_t::IsValid)
        .endClass();
}