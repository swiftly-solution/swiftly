#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCExampleSchemaVData_PolymorphicDerivedA::GCExampleSchemaVData_PolymorphicDerivedA(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCExampleSchemaVData_PolymorphicDerivedA::GCExampleSchemaVData_PolymorphicDerivedA(void *ptr) {
    m_ptr = ptr;
}
int32_t GCExampleSchemaVData_PolymorphicDerivedA::GetDerivedA() const {
    return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicDerivedA", "m_nDerivedA");
}
void GCExampleSchemaVData_PolymorphicDerivedA::SetDerivedA(int32_t value) {
    SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicDerivedA", "m_nDerivedA", false, value);
}
std::string GCExampleSchemaVData_PolymorphicDerivedA::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCExampleSchemaVData_PolymorphicDerivedA::IsValid() {
    return (m_ptr != nullptr);
}
GCExampleSchemaVData_PolymorphicBase GCExampleSchemaVData_PolymorphicDerivedA::GetParent() const {
    GCExampleSchemaVData_PolymorphicBase value(m_ptr);
    return value;
}
void GCExampleSchemaVData_PolymorphicDerivedA::SetParent(GCExampleSchemaVData_PolymorphicBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCExampleSchemaVData_PolymorphicDerivedA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicDerivedA>("CExampleSchemaVData_PolymorphicDerivedA")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DerivedA", &GCExampleSchemaVData_PolymorphicDerivedA::GetDerivedA, &GCExampleSchemaVData_PolymorphicDerivedA::SetDerivedA)
        .addProperty("Parent", &GCExampleSchemaVData_PolymorphicDerivedA::GetParent, &GCExampleSchemaVData_PolymorphicDerivedA::SetParent)
        .addFunction("ToPtr", &GCExampleSchemaVData_PolymorphicDerivedA::ToPtr)
        .addFunction("IsValid", &GCExampleSchemaVData_PolymorphicDerivedA::IsValid)
        .endClass();
}