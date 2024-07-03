#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialGroup_t::GMaterialGroup_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialGroup_t::GMaterialGroup_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialGroup_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialGroup_t", "m_name").Get();
}
void GMaterialGroup_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "MaterialGroup_t", "m_name", true, CUtlString(value.c_str()));
}
std::string GMaterialGroup_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialGroup_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMaterialGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialGroup_t>("MaterialGroup_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GMaterialGroup_t::GetName, &GMaterialGroup_t::SetName)
        .addFunction("ToPtr", &GMaterialGroup_t::ToPtr)
        .addFunction("IsValid", &GMaterialGroup_t::IsValid)
        .endClass();
}