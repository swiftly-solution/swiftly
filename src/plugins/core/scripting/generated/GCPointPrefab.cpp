#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointPrefab::GCPointPrefab(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointPrefab::GCPointPrefab(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointPrefab::GetTargetMapName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_targetMapName").String();
}
void GCPointPrefab::SetTargetMapName(std::string value) {
    SetSchemaValue(m_ptr, "CPointPrefab", "m_targetMapName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointPrefab::GetForceWorldGroupID() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_forceWorldGroupID").String();
}
void GCPointPrefab::SetForceWorldGroupID(std::string value) {
    SetSchemaValue(m_ptr, "CPointPrefab", "m_forceWorldGroupID", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointPrefab::GetAssociatedRelayTargetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPrefab", "m_associatedRelayTargetName").String();
}
void GCPointPrefab::SetAssociatedRelayTargetName(std::string value) {
    SetSchemaValue(m_ptr, "CPointPrefab", "m_associatedRelayTargetName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCPointPrefab::GetFixupNames() const {
    return GetSchemaValue<bool>(m_ptr, "CPointPrefab", "m_fixupNames");
}
void GCPointPrefab::SetFixupNames(bool value) {
    SetSchemaValue(m_ptr, "CPointPrefab", "m_fixupNames", false, value);
}
bool GCPointPrefab::GetLoadDynamic() const {
    return GetSchemaValue<bool>(m_ptr, "CPointPrefab", "m_bLoadDynamic");
}
void GCPointPrefab::SetLoadDynamic(bool value) {
    SetSchemaValue(m_ptr, "CPointPrefab", "m_bLoadDynamic", false, value);
}
GCPointPrefab GCPointPrefab::GetAssociatedRelayEntity() const {
    GCPointPrefab value(*GetSchemaValuePtr<void*>(m_ptr, "CPointPrefab", "m_associatedRelayEntity"));
    return value;
}
void GCPointPrefab::SetAssociatedRelayEntity(GCPointPrefab* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AssociatedRelayEntity' is not possible.\n");
}
std::string GCPointPrefab::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointPrefab::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyPointEntity GCPointPrefab::GetParent() const {
    GCServerOnlyPointEntity value(m_ptr);
    return value;
}
void GCPointPrefab::SetParent(GCServerOnlyPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointPrefab(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointPrefab>("CPointPrefab")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetMapName", &GCPointPrefab::GetTargetMapName, &GCPointPrefab::SetTargetMapName)
        .addProperty("ForceWorldGroupID", &GCPointPrefab::GetForceWorldGroupID, &GCPointPrefab::SetForceWorldGroupID)
        .addProperty("AssociatedRelayTargetName", &GCPointPrefab::GetAssociatedRelayTargetName, &GCPointPrefab::SetAssociatedRelayTargetName)
        .addProperty("FixupNames", &GCPointPrefab::GetFixupNames, &GCPointPrefab::SetFixupNames)
        .addProperty("LoadDynamic", &GCPointPrefab::GetLoadDynamic, &GCPointPrefab::SetLoadDynamic)
        .addProperty("AssociatedRelayEntity", &GCPointPrefab::GetAssociatedRelayEntity, &GCPointPrefab::SetAssociatedRelayEntity)
        .addProperty("Parent", &GCPointPrefab::GetParent, &GCPointPrefab::SetParent)
        .addFunction("ToPtr", &GCPointPrefab::ToPtr)
        .addFunction("IsValid", &GCPointPrefab::IsValid)
        .endClass();
}