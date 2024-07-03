#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityIdentity::GCEntityIdentity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityIdentity::GCEntityIdentity(void *ptr) {
    m_ptr = ptr;
}
int32_t GCEntityIdentity::GetNameStringableIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEntityIdentity", "m_nameStringableIndex");
}
void GCEntityIdentity::SetNameStringableIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_nameStringableIndex", false, value);
}
std::string GCEntityIdentity::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityIdentity", "m_name").String();
}
void GCEntityIdentity::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_name", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEntityIdentity::GetDesignerName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityIdentity", "m_designerName").String();
}
void GCEntityIdentity::SetDesignerName(std::string value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_designerName", false, CUtlSymbolLarge(value.c_str()));
}
uint32_t GCEntityIdentity::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEntityIdentity", "m_flags");
}
void GCEntityIdentity::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_flags", false, value);
}
WorldGroupId_t GCEntityIdentity::GetWorldGroupId() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "CEntityIdentity", "m_worldGroupId");
}
void GCEntityIdentity::SetWorldGroupId(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_worldGroupId", false, value);
}
uint32_t GCEntityIdentity::GetDataObjectTypes() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEntityIdentity", "m_fDataObjectTypes");
}
void GCEntityIdentity::SetDataObjectTypes(uint32_t value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_fDataObjectTypes", false, value);
}
GChangeAccessorFieldPathIndex_t GCEntityIdentity::GetPathIndex() const {
    GChangeAccessorFieldPathIndex_t value(GetSchemaPtr(m_ptr, "CEntityIdentity", "m_PathIndex"));
    return value;
}
void GCEntityIdentity::SetPathIndex(GChangeAccessorFieldPathIndex_t value) {
    SetSchemaValue(m_ptr, "CEntityIdentity", "m_PathIndex", false, value);
}
GCEntityIdentity GCEntityIdentity::GetPrev() const {
    GCEntityIdentity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityIdentity", "m_pPrev"));
    return value;
}
void GCEntityIdentity::SetPrev(GCEntityIdentity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n");
}
GCEntityIdentity GCEntityIdentity::GetNext() const {
    GCEntityIdentity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityIdentity", "m_pNext"));
    return value;
}
void GCEntityIdentity::SetNext(GCEntityIdentity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
GCEntityIdentity GCEntityIdentity::GetPrevByClass() const {
    GCEntityIdentity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityIdentity", "m_pPrevByClass"));
    return value;
}
void GCEntityIdentity::SetPrevByClass(GCEntityIdentity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevByClass' is not possible.\n");
}
GCEntityIdentity GCEntityIdentity::GetNextByClass() const {
    GCEntityIdentity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityIdentity", "m_pNextByClass"));
    return value;
}
void GCEntityIdentity::SetNextByClass(GCEntityIdentity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextByClass' is not possible.\n");
}
std::string GCEntityIdentity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityIdentity::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntityIdentity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityIdentity>("CEntityIdentity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NameStringableIndex", &GCEntityIdentity::GetNameStringableIndex, &GCEntityIdentity::SetNameStringableIndex)
        .addProperty("Name", &GCEntityIdentity::GetName, &GCEntityIdentity::SetName)
        .addProperty("DesignerName", &GCEntityIdentity::GetDesignerName, &GCEntityIdentity::SetDesignerName)
        .addProperty("Flags", &GCEntityIdentity::GetFlags, &GCEntityIdentity::SetFlags)
        .addProperty("WorldGroupId", &GCEntityIdentity::GetWorldGroupId, &GCEntityIdentity::SetWorldGroupId)
        .addProperty("DataObjectTypes", &GCEntityIdentity::GetDataObjectTypes, &GCEntityIdentity::SetDataObjectTypes)
        .addProperty("PathIndex", &GCEntityIdentity::GetPathIndex, &GCEntityIdentity::SetPathIndex)
        .addProperty("Prev", &GCEntityIdentity::GetPrev, &GCEntityIdentity::SetPrev)
        .addProperty("Next", &GCEntityIdentity::GetNext, &GCEntityIdentity::SetNext)
        .addProperty("PrevByClass", &GCEntityIdentity::GetPrevByClass, &GCEntityIdentity::SetPrevByClass)
        .addProperty("NextByClass", &GCEntityIdentity::GetNextByClass, &GCEntityIdentity::SetNextByClass)
        .addFunction("ToPtr", &GCEntityIdentity::ToPtr)
        .addFunction("IsValid", &GCEntityIdentity::IsValid)
        .endClass();
}