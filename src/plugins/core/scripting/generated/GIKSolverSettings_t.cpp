#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIKSolverSettings_t::GIKSolverSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIKSolverSettings_t::GIKSolverSettings_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GIKSolverSettings_t::GetSolverType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "IKSolverSettings_t", "m_SolverType");
}
void GIKSolverSettings_t::SetSolverType(uint64_t value) {
    SetSchemaValue(m_ptr, "IKSolverSettings_t", "m_SolverType", true, value);
}
int32_t GIKSolverSettings_t::GetNumIterations() const {
    return GetSchemaValue<int32_t>(m_ptr, "IKSolverSettings_t", "m_nNumIterations");
}
void GIKSolverSettings_t::SetNumIterations(int32_t value) {
    SetSchemaValue(m_ptr, "IKSolverSettings_t", "m_nNumIterations", true, value);
}
std::string GIKSolverSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIKSolverSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIKSolverSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKSolverSettings_t>("IKSolverSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SolverType", &GIKSolverSettings_t::GetSolverType, &GIKSolverSettings_t::SetSolverType)
        .addProperty("NumIterations", &GIKSolverSettings_t::GetNumIterations, &GIKSolverSettings_t::SetNumIterations)
        .addFunction("ToPtr", &GIKSolverSettings_t::ToPtr)
        .addFunction("IsValid", &GIKSolverSettings_t::IsValid)
        .endClass();
}