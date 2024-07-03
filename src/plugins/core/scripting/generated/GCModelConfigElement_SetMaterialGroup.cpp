#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_SetMaterialGroup::GCModelConfigElement_SetMaterialGroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_SetMaterialGroup::GCModelConfigElement_SetMaterialGroup(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_SetMaterialGroup::GetMaterialGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetMaterialGroup", "m_MaterialGroupName").Get();
}
void GCModelConfigElement_SetMaterialGroup::SetMaterialGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetMaterialGroup", "m_MaterialGroupName", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_SetMaterialGroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_SetMaterialGroup::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_SetMaterialGroup::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_SetMaterialGroup::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_SetMaterialGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetMaterialGroup>("CModelConfigElement_SetMaterialGroup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaterialGroupName", &GCModelConfigElement_SetMaterialGroup::GetMaterialGroupName, &GCModelConfigElement_SetMaterialGroup::SetMaterialGroupName)
        .addProperty("Parent", &GCModelConfigElement_SetMaterialGroup::GetParent, &GCModelConfigElement_SetMaterialGroup::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_SetMaterialGroup::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_SetMaterialGroup::IsValid)
        .endClass();
}