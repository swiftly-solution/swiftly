#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialOverride_t::GMaterialOverride_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialOverride_t::GMaterialOverride_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GMaterialOverride_t::GetSubSceneObject() const {
    return GetSchemaValue<uint32_t>(m_ptr, "MaterialOverride_t", "m_nSubSceneObject");
}
void GMaterialOverride_t::SetSubSceneObject(uint32_t value) {
    SetSchemaValue(m_ptr, "MaterialOverride_t", "m_nSubSceneObject", true, value);
}
uint32_t GMaterialOverride_t::GetDrawCallIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "MaterialOverride_t", "m_nDrawCallIndex");
}
void GMaterialOverride_t::SetDrawCallIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "MaterialOverride_t", "m_nDrawCallIndex", true, value);
}
std::string GMaterialOverride_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialOverride_t::IsValid() {
    return (m_ptr != nullptr);
}
GBaseSceneObjectOverride_t GMaterialOverride_t::GetParent() const {
    GBaseSceneObjectOverride_t value(m_ptr);
    return value;
}
void GMaterialOverride_t::SetParent(GBaseSceneObjectOverride_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassMaterialOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialOverride_t>("MaterialOverride_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SubSceneObject", &GMaterialOverride_t::GetSubSceneObject, &GMaterialOverride_t::SetSubSceneObject)
        .addProperty("DrawCallIndex", &GMaterialOverride_t::GetDrawCallIndex, &GMaterialOverride_t::SetDrawCallIndex)
        .addProperty("Parent", &GMaterialOverride_t::GetParent, &GMaterialOverride_t::SetParent)
        .addFunction("ToPtr", &GMaterialOverride_t::ToPtr)
        .addFunction("IsValid", &GMaterialOverride_t::IsValid)
        .endClass();
}