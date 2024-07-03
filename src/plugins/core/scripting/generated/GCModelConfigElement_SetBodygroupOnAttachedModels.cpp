#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_SetBodygroupOnAttachedModels::GCModelConfigElement_SetBodygroupOnAttachedModels(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_SetBodygroupOnAttachedModels::GCModelConfigElement_SetBodygroupOnAttachedModels(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_SetBodygroupOnAttachedModels::GetGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_GroupName").Get();
}
void GCModelConfigElement_SetBodygroupOnAttachedModels::SetGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_GroupName", false, CUtlString(value.c_str()));
}
int32_t GCModelConfigElement_SetBodygroupOnAttachedModels::GetChoice() const {
    return GetSchemaValue<int32_t>(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_nChoice");
}
void GCModelConfigElement_SetBodygroupOnAttachedModels::SetChoice(int32_t value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_nChoice", false, value);
}
std::string GCModelConfigElement_SetBodygroupOnAttachedModels::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_SetBodygroupOnAttachedModels::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_SetBodygroupOnAttachedModels::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_SetBodygroupOnAttachedModels::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_SetBodygroupOnAttachedModels(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetBodygroupOnAttachedModels>("CModelConfigElement_SetBodygroupOnAttachedModels")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GroupName", &GCModelConfigElement_SetBodygroupOnAttachedModels::GetGroupName, &GCModelConfigElement_SetBodygroupOnAttachedModels::SetGroupName)
        .addProperty("Choice", &GCModelConfigElement_SetBodygroupOnAttachedModels::GetChoice, &GCModelConfigElement_SetBodygroupOnAttachedModels::SetChoice)
        .addProperty("Parent", &GCModelConfigElement_SetBodygroupOnAttachedModels::GetParent, &GCModelConfigElement_SetBodygroupOnAttachedModels::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_SetBodygroupOnAttachedModels::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_SetBodygroupOnAttachedModels::IsValid)
        .endClass();
}