#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuseProgram::GCFuseProgram(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuseProgram::GCFuseProgram(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint8> GCFuseProgram::GetProgramBuffer() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CFuseProgram", "m_programBuffer"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseProgram::SetProgramBuffer(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CFuseProgram", "m_programBuffer", false, value);
}
std::vector<GFuseVariableIndex_t> GCFuseProgram::GetVariablesRead() const {
    CUtlVector<GFuseVariableIndex_t>* vec = GetSchemaValue<CUtlVector<GFuseVariableIndex_t>*>(m_ptr, "CFuseProgram", "m_variablesRead"); std::vector<GFuseVariableIndex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseProgram::SetVariablesRead(std::vector<GFuseVariableIndex_t> value) {
    SetSchemaValueCUtlVector<GFuseVariableIndex_t>(m_ptr, "CFuseProgram", "m_variablesRead", false, value);
}
std::vector<GFuseVariableIndex_t> GCFuseProgram::GetVariablesWritten() const {
    CUtlVector<GFuseVariableIndex_t>* vec = GetSchemaValue<CUtlVector<GFuseVariableIndex_t>*>(m_ptr, "CFuseProgram", "m_variablesWritten"); std::vector<GFuseVariableIndex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuseProgram::SetVariablesWritten(std::vector<GFuseVariableIndex_t> value) {
    SetSchemaValueCUtlVector<GFuseVariableIndex_t>(m_ptr, "CFuseProgram", "m_variablesWritten", false, value);
}
int32_t GCFuseProgram::GetMaxTempVarsUsed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuseProgram", "m_nMaxTempVarsUsed");
}
void GCFuseProgram::SetMaxTempVarsUsed(int32_t value) {
    SetSchemaValue(m_ptr, "CFuseProgram", "m_nMaxTempVarsUsed", false, value);
}
std::string GCFuseProgram::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuseProgram::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFuseProgram(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuseProgram>("CFuseProgram")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ProgramBuffer", &GCFuseProgram::GetProgramBuffer, &GCFuseProgram::SetProgramBuffer)
        .addProperty("VariablesRead", &GCFuseProgram::GetVariablesRead, &GCFuseProgram::SetVariablesRead)
        .addProperty("VariablesWritten", &GCFuseProgram::GetVariablesWritten, &GCFuseProgram::SetVariablesWritten)
        .addProperty("MaxTempVarsUsed", &GCFuseProgram::GetMaxTempVarsUsed, &GCFuseProgram::SetMaxTempVarsUsed)
        .addFunction("ToPtr", &GCFuseProgram::ToPtr)
        .addFunction("IsValid", &GCFuseProgram::IsValid)
        .endClass();
}