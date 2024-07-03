#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParam_t::GMaterialParam_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParam_t::GMaterialParam_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialParam_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialParam_t", "m_name").Get();
}
void GMaterialParam_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "MaterialParam_t", "m_name", true, CUtlString(value.c_str()));
}
std::string GMaterialParam_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParam_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMaterialParam_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParam_t>("MaterialParam_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GMaterialParam_t::GetName, &GMaterialParam_t::SetName)
        .addFunction("ToPtr", &GMaterialParam_t::ToPtr)
        .addFunction("IsValid", &GMaterialParam_t::IsValid)
        .endClass();
}