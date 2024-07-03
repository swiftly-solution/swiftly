#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuseSymbolTable::GCFuseSymbolTable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuseSymbolTable::GCFuseSymbolTable(void *ptr) {
    m_ptr = ptr;
}
std::vector<GConstantInfo_t> GCFuseSymbolTable::GetConstants() const {
    CUtlVector<GConstantInfo_t>* vec = GetSchemaValue<CUtlVector<GConstantInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_constants"); std::vector<GConstantInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseSymbolTable::SetConstants(std::vector<GConstantInfo_t> value) {
    SetSchemaValueCUtlVector<GConstantInfo_t>(m_ptr, "CFuseSymbolTable", "m_constants", false, value);
}
std::vector<GVariableInfo_t> GCFuseSymbolTable::GetVariables() const {
    CUtlVector<GVariableInfo_t>* vec = GetSchemaValue<CUtlVector<GVariableInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_variables"); std::vector<GVariableInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseSymbolTable::SetVariables(std::vector<GVariableInfo_t> value) {
    SetSchemaValueCUtlVector<GVariableInfo_t>(m_ptr, "CFuseSymbolTable", "m_variables", false, value);
}
std::vector<GFunctionInfo_t> GCFuseSymbolTable::GetFunctions() const {
    CUtlVector<GFunctionInfo_t>* vec = GetSchemaValue<CUtlVector<GFunctionInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_functions"); std::vector<GFunctionInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseSymbolTable::SetFunctions(std::vector<GFunctionInfo_t> value) {
    SetSchemaValueCUtlVector<GFunctionInfo_t>(m_ptr, "CFuseSymbolTable", "m_functions", false, value);
}
std::string GCFuseSymbolTable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuseSymbolTable::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFuseSymbolTable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuseSymbolTable>("CFuseSymbolTable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Constants", &GCFuseSymbolTable::GetConstants, &GCFuseSymbolTable::SetConstants)
        .addProperty("Variables", &GCFuseSymbolTable::GetVariables, &GCFuseSymbolTable::SetVariables)
        .addProperty("Functions", &GCFuseSymbolTable::GetFunctions, &GCFuseSymbolTable::SetFunctions)
        .addFunction("ToPtr", &GCFuseSymbolTable::ToPtr)
        .addFunction("IsValid", &GCFuseSymbolTable::IsValid)
        .endClass();
}