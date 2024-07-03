#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCResponseCriteriaSet::GCResponseCriteriaSet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCResponseCriteriaSet::GCResponseCriteriaSet(void *ptr) {
    m_ptr = ptr;
}
int32_t GCResponseCriteriaSet::GetNumPrefixedContexts() const {
    return GetSchemaValue<int32_t>(m_ptr, "CResponseCriteriaSet", "m_nNumPrefixedContexts");
}
void GCResponseCriteriaSet::SetNumPrefixedContexts(int32_t value) {
    SetSchemaValue(m_ptr, "CResponseCriteriaSet", "m_nNumPrefixedContexts", false, value);
}
bool GCResponseCriteriaSet::GetOverrideOnAppend() const {
    return GetSchemaValue<bool>(m_ptr, "CResponseCriteriaSet", "m_bOverrideOnAppend");
}
void GCResponseCriteriaSet::SetOverrideOnAppend(bool value) {
    SetSchemaValue(m_ptr, "CResponseCriteriaSet", "m_bOverrideOnAppend", false, value);
}
std::string GCResponseCriteriaSet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCResponseCriteriaSet::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCResponseCriteriaSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCResponseCriteriaSet>("CResponseCriteriaSet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NumPrefixedContexts", &GCResponseCriteriaSet::GetNumPrefixedContexts, &GCResponseCriteriaSet::SetNumPrefixedContexts)
        .addProperty("OverrideOnAppend", &GCResponseCriteriaSet::GetOverrideOnAppend, &GCResponseCriteriaSet::SetOverrideOnAppend)
        .addFunction("ToPtr", &GCResponseCriteriaSet::ToPtr)
        .addFunction("IsValid", &GCResponseCriteriaSet::IsValid)
        .endClass();
}