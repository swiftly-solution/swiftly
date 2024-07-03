#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialParamTexture_t::GMaterialParamTexture_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialParamTexture_t::GMaterialParamTexture_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialParamTexture_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialParamTexture_t::IsValid() {
    return (m_ptr != nullptr);
}
GMaterialParam_t GMaterialParamTexture_t::GetParent() const {
    GMaterialParam_t value(m_ptr);
    return value;
}
void GMaterialParamTexture_t::SetParent(GMaterialParam_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialParamTexture_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamTexture_t>("MaterialParamTexture_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GMaterialParamTexture_t::GetParent, &GMaterialParamTexture_t::SetParent)
        .addFunction("ToPtr", &GMaterialParamTexture_t::ToPtr)
        .addFunction("IsValid", &GMaterialParamTexture_t::IsValid)
        .endClass();
}