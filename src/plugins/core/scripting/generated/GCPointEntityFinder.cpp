#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointEntityFinder::GCPointEntityFinder(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointEntityFinder::GCPointEntityFinder(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPointEntityFinder::GetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointEntityFinder", "m_hEntity"));
    return value;
}
void GCPointEntityFinder::SetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
std::string GCPointEntityFinder::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointEntityFinder", "m_iFilterName").String();
}
void GCPointEntityFinder::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CPointEntityFinder", "m_iFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCPointEntityFinder::GetFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CPointEntityFinder", "m_hFilter"));
    return value;
}
void GCPointEntityFinder::SetFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
std::string GCPointEntityFinder::GetRefName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointEntityFinder", "m_iRefName").String();
}
void GCPointEntityFinder::SetRefName(std::string value) {
    SetSchemaValue(m_ptr, "CPointEntityFinder", "m_iRefName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPointEntityFinder::GetReference() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointEntityFinder", "m_hReference"));
    return value;
}
void GCPointEntityFinder::SetReference(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Reference' is not possible.\n");
}
uint64_t GCPointEntityFinder::GetFindMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointEntityFinder", "m_FindMethod");
}
void GCPointEntityFinder::SetFindMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointEntityFinder", "m_FindMethod", false, value);
}
GCEntityIOOutput GCPointEntityFinder::GetOnFoundEntity() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointEntityFinder", "m_OnFoundEntity"));
    return value;
}
void GCPointEntityFinder::SetOnFoundEntity(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointEntityFinder", "m_OnFoundEntity", false, value);
}
std::string GCPointEntityFinder::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointEntityFinder::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPointEntityFinder::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPointEntityFinder::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointEntityFinder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointEntityFinder>("CPointEntityFinder")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity", &GCPointEntityFinder::GetEntity, &GCPointEntityFinder::SetEntity)
        .addProperty("FilterName", &GCPointEntityFinder::GetFilterName, &GCPointEntityFinder::SetFilterName)
        .addProperty("Filter", &GCPointEntityFinder::GetFilter, &GCPointEntityFinder::SetFilter)
        .addProperty("RefName", &GCPointEntityFinder::GetRefName, &GCPointEntityFinder::SetRefName)
        .addProperty("Reference", &GCPointEntityFinder::GetReference, &GCPointEntityFinder::SetReference)
        .addProperty("FindMethod", &GCPointEntityFinder::GetFindMethod, &GCPointEntityFinder::SetFindMethod)
        .addProperty("OnFoundEntity", &GCPointEntityFinder::GetOnFoundEntity, &GCPointEntityFinder::SetOnFoundEntity)
        .addProperty("Parent", &GCPointEntityFinder::GetParent, &GCPointEntityFinder::SetParent)
        .addFunction("ToPtr", &GCPointEntityFinder::ToPtr)
        .addFunction("IsValid", &GCPointEntityFinder::IsValid)
        .endClass();
}