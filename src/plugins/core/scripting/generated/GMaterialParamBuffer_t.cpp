#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamBuffer_t::GMaterialParamBuffer_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamBuffer_t::GMaterialParamBuffer_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialParamBuffer_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamBuffer_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamBuffer_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamBuffer_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamBuffer_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamBuffer_t>("MaterialParamBuffer_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GMaterialParamBuffer_t::GetParent, &GMaterialParamBuffer_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamBuffer_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamBuffer_t::IsValid)
        .endClass();
}