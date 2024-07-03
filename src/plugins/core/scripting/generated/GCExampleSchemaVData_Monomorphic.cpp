#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCExampleSchemaVData_Monomorphic::GCExampleSchemaVData_Monomorphic(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCExampleSchemaVData_Monomorphic::GCExampleSchemaVData_Monomorphic(void *ptr) {
    m_ptr = ptr;
}
int32_t GCExampleSchemaVData_Monomorphic::GetExample1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample1");
}
void GCExampleSchemaVData_Monomorphic::SetExample1(int32_t value) {
    SetSchemaValue(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample1", false, value);
}
int32_t GCExampleSchemaVData_Monomorphic::GetExample2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample2");
}
void GCExampleSchemaVData_Monomorphic::SetExample2(int32_t value) {
    SetSchemaValue(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample2", false, value);
}
std::string GCExampleSchemaVData_Monomorphic::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCExampleSchemaVData_Monomorphic::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCExampleSchemaVData_Monomorphic(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_Monomorphic>("CExampleSchemaVData_Monomorphic")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Example1", &GCExampleSchemaVData_Monomorphic::GetExample1, &GCExampleSchemaVData_Monomorphic::SetExample1)
        .addProperty("Example2", &GCExampleSchemaVData_Monomorphic::GetExample2, &GCExampleSchemaVData_Monomorphic::SetExample2)
        .addFunction("ToPtr", &GCExampleSchemaVData_Monomorphic::ToPtr)
        .addFunction("IsValid", &GCExampleSchemaVData_Monomorphic::IsValid)
        .endClass();
}