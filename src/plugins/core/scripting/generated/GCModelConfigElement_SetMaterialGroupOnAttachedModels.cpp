#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_SetMaterialGroupOnAttachedModels::GCModelConfigElement_SetMaterialGroupOnAttachedModels(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_SetMaterialGroupOnAttachedModels::GCModelConfigElement_SetMaterialGroupOnAttachedModels(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_SetMaterialGroupOnAttachedModels::GetMaterialGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetMaterialGroupOnAttachedModels", "m_MaterialGroupName").Get();
}
void GCModelConfigElement_SetMaterialGroupOnAttachedModels::SetMaterialGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetMaterialGroupOnAttachedModels", "m_MaterialGroupName", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_SetMaterialGroupOnAttachedModels::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_SetMaterialGroupOnAttachedModels::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_SetMaterialGroupOnAttachedModels::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_SetMaterialGroupOnAttachedModels::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_SetMaterialGroupOnAttachedModels(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetMaterialGroupOnAttachedModels>("CModelConfigElement_SetMaterialGroupOnAttachedModels")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaterialGroupName", &GCModelConfigElement_SetMaterialGroupOnAttachedModels::GetMaterialGroupName, &GCModelConfigElement_SetMaterialGroupOnAttachedModels::SetMaterialGroupName)
        .addProperty("Parent", &GCModelConfigElement_SetMaterialGroupOnAttachedModels::GetParent, &GCModelConfigElement_SetMaterialGroupOnAttachedModels::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_SetMaterialGroupOnAttachedModels::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_SetMaterialGroupOnAttachedModels::IsValid)
        .endClass();
}