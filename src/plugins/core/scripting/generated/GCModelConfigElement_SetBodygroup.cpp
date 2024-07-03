#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_SetBodygroup::GCModelConfigElement_SetBodygroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_SetBodygroup::GCModelConfigElement_SetBodygroup(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_SetBodygroup::GetGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetBodygroup", "m_GroupName").Get();
}
void GCModelConfigElement_SetBodygroup::SetGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroup", "m_GroupName", false, CUtlString(value.c_str()));
}
int32_t GCModelConfigElement_SetBodygroup::GetChoice() const {
    return GetSchemaValue<int32_t>(m_ptr, "CModelConfigElement_SetBodygroup", "m_nChoice");
}
void GCModelConfigElement_SetBodygroup::SetChoice(int32_t value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroup", "m_nChoice", false, value);
}
std::string GCModelConfigElement_SetBodygroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_SetBodygroup::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_SetBodygroup::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_SetBodygroup::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_SetBodygroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetBodygroup>("CModelConfigElement_SetBodygroup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GroupName", &GCModelConfigElement_SetBodygroup::GetGroupName, &GCModelConfigElement_SetBodygroup::SetGroupName)
        .addProperty("Choice", &GCModelConfigElement_SetBodygroup::GetChoice, &GCModelConfigElement_SetBodygroup::SetChoice)
        .addProperty("Parent", &GCModelConfigElement_SetBodygroup::GetParent, &GCModelConfigElement_SetBodygroup::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_SetBodygroup::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_SetBodygroup::IsValid)
        .endClass();
}