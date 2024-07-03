#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GScriptInfo_t::GScriptInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GScriptInfo_t::GScriptInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::string GScriptInfo_t::GetCode() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ScriptInfo_t", "m_code").Get();
}
void GScriptInfo_t::SetCode(std::string value) {
    SetSchemaValue(m_ptr, "ScriptInfo_t", "m_code", true, CUtlString(value.c_str()));
}
std::vector<GCAnimParamHandle> GScriptInfo_t::GetParamsModified() const {
    CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "ScriptInfo_t", "m_paramsModified"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GScriptInfo_t::SetParamsModified(std::vector<GCAnimParamHandle> value) {
    SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "ScriptInfo_t", "m_paramsModified", true, value);
}
std::vector<int32> GScriptInfo_t::GetProxyReadParams() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ScriptInfo_t", "m_proxyReadParams"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GScriptInfo_t::SetProxyReadParams(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "ScriptInfo_t", "m_proxyReadParams", true, value);
}
std::vector<int32> GScriptInfo_t::GetProxyWriteParams() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ScriptInfo_t", "m_proxyWriteParams"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GScriptInfo_t::SetProxyWriteParams(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "ScriptInfo_t", "m_proxyWriteParams", true, value);
}
uint64_t GScriptInfo_t::GetScriptType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ScriptInfo_t", "m_eScriptType");
}
void GScriptInfo_t::SetScriptType(uint64_t value) {
    SetSchemaValue(m_ptr, "ScriptInfo_t", "m_eScriptType", true, value);
}
std::string GScriptInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GScriptInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassScriptInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GScriptInfo_t>("ScriptInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Code", &GScriptInfo_t::GetCode, &GScriptInfo_t::SetCode)
        .addProperty("ParamsModified", &GScriptInfo_t::GetParamsModified, &GScriptInfo_t::SetParamsModified)
        .addProperty("ProxyReadParams", &GScriptInfo_t::GetProxyReadParams, &GScriptInfo_t::SetProxyReadParams)
        .addProperty("ProxyWriteParams", &GScriptInfo_t::GetProxyWriteParams, &GScriptInfo_t::SetProxyWriteParams)
        .addProperty("ScriptType", &GScriptInfo_t::GetScriptType, &GScriptInfo_t::SetScriptType)
        .addFunction("ToPtr", &GScriptInfo_t::ToPtr)
        .addFunction("IsValid", &GScriptInfo_t::IsValid)
        .endClass();
}