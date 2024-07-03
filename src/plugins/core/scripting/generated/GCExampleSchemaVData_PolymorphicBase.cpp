#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCExampleSchemaVData_PolymorphicBase::GCExampleSchemaVData_PolymorphicBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCExampleSchemaVData_PolymorphicBase::GCExampleSchemaVData_PolymorphicBase(void *ptr) {
    m_ptr = ptr;
}
int32_t GCExampleSchemaVData_PolymorphicBase::GetBase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicBase", "m_nBase");
}
void GCExampleSchemaVData_PolymorphicBase::SetBase(int32_t value) {
    SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicBase", "m_nBase", false, value);
}
std::string GCExampleSchemaVData_PolymorphicBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCExampleSchemaVData_PolymorphicBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCExampleSchemaVData_PolymorphicBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExampleSchemaVData_PolymorphicBase>("CExampleSchemaVData_PolymorphicBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Base", &GCExampleSchemaVData_PolymorphicBase::GetBase, &GCExampleSchemaVData_PolymorphicBase::SetBase)
        .addFunction("ToPtr", &GCExampleSchemaVData_PolymorphicBase::ToPtr)
        .addFunction("IsValid", &GCExampleSchemaVData_PolymorphicBase::IsValid)
        .endClass();
}