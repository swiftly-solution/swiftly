#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCExampleSchemaVData_PolymorphicDerivedB::GCExampleSchemaVData_PolymorphicDerivedB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCExampleSchemaVData_PolymorphicDerivedB::GCExampleSchemaVData_PolymorphicDerivedB(void *ptr) {
    m_ptr = ptr;
}
int32_t GCExampleSchemaVData_PolymorphicDerivedB::GetDerivedB() const {
    return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicDerivedB", "m_nDerivedB");
}
void GCExampleSchemaVData_PolymorphicDerivedB::SetDerivedB(int32_t value) {
    SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicDerivedB", "m_nDerivedB", false, value);
}
std::string GCExampleSchemaVData_PolymorphicDerivedB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCExampleSchemaVData_PolymorphicDerivedB::IsValid() {
    return (m_ptr != nullptr);
}
GCExampleSchemaVData_PolymorphicBase GCExampleSchemaVData_PolymorphicDerivedB::GetParent() const {
    GCExampleSchemaVData_PolymorphicBase value(m_ptr);
    return value;
}
void GCExampleSchemaVData_PolymorphicDerivedB::SetParent(GCExampleSchemaVData_PolymorphicBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCExampleSchemaVData_PolymorphicDerivedB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicDerivedB>("CExampleSchemaVData_PolymorphicDerivedB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DerivedB", &GCExampleSchemaVData_PolymorphicDerivedB::GetDerivedB, &GCExampleSchemaVData_PolymorphicDerivedB::SetDerivedB)
        .addProperty("Parent", &GCExampleSchemaVData_PolymorphicDerivedB::GetParent, &GCExampleSchemaVData_PolymorphicDerivedB::SetParent)
        .addFunction("ToPtr", &GCExampleSchemaVData_PolymorphicDerivedB::ToPtr)
        .addFunction("IsValid", &GCExampleSchemaVData_PolymorphicDerivedB::IsValid)
        .endClass();
}