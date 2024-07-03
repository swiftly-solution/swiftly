#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointTemplate::GCPointTemplate(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointTemplate::GCPointTemplate(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointTemplate::GetWorldName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszWorldName").String();
}
void GCPointTemplate::SetWorldName(std::string value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_iszWorldName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointTemplate::GetSource2EntityLumpName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszSource2EntityLumpName").String();
}
void GCPointTemplate::SetSource2EntityLumpName(std::string value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_iszSource2EntityLumpName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointTemplate::GetEntityFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointTemplate", "m_iszEntityFilterName").String();
}
void GCPointTemplate::SetEntityFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_iszEntityFilterName", false, CUtlSymbolLarge(value.c_str()));
}
float GCPointTemplate::GetTimeoutInterval() const {
    return GetSchemaValue<float>(m_ptr, "CPointTemplate", "m_flTimeoutInterval");
}
void GCPointTemplate::SetTimeoutInterval(float value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_flTimeoutInterval", false, value);
}
bool GCPointTemplate::GetAsynchronouslySpawnEntities() const {
    return GetSchemaValue<bool>(m_ptr, "CPointTemplate", "m_bAsynchronouslySpawnEntities");
}
void GCPointTemplate::SetAsynchronouslySpawnEntities(bool value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_bAsynchronouslySpawnEntities", false, value);
}
GCEntityIOOutput GCPointTemplate::GetOutputOnSpawned() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointTemplate", "m_pOutputOnSpawned"));
    return value;
}
void GCPointTemplate::SetOutputOnSpawned(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_pOutputOnSpawned", false, value);
}
uint64_t GCPointTemplate::GetClientOnlyEntityBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointTemplate", "m_clientOnlyEntityBehavior");
}
void GCPointTemplate::SetClientOnlyEntityBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_clientOnlyEntityBehavior", false, value);
}
uint64_t GCPointTemplate::GetOwnerSpawnGroupType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointTemplate", "m_ownerSpawnGroupType");
}
void GCPointTemplate::SetOwnerSpawnGroupType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointTemplate", "m_ownerSpawnGroupType", false, value);
}
std::vector<uint32> GCPointTemplate::GetCreatedSpawnGroupHandles() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CPointTemplate", "m_createdSpawnGroupHandles"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPointTemplate::SetCreatedSpawnGroupHandles(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CPointTemplate", "m_createdSpawnGroupHandles", false, value);
}
std::vector<GCEntityInstance*> GCPointTemplate::GetSpawnedEntityHandles() const {
    CUtlVector<GCEntityInstance*>* vec = GetSchemaValue<CUtlVector<GCEntityInstance*>*>(m_ptr, "CPointTemplate", "m_SpawnedEntityHandles"); std::vector<GCEntityInstance*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPointTemplate::SetSpawnedEntityHandles(std::vector<GCEntityInstance*> value) {
    SetSchemaValueCUtlVector<GCEntityInstance*>(m_ptr, "CPointTemplate", "m_SpawnedEntityHandles", false, value);
}
std::string GCPointTemplate::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointTemplate::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCPointTemplate::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCPointTemplate::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointTemplate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTemplate>("CPointTemplate")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WorldName", &GCPointTemplate::GetWorldName, &GCPointTemplate::SetWorldName)
        .addProperty("Source2EntityLumpName", &GCPointTemplate::GetSource2EntityLumpName, &GCPointTemplate::SetSource2EntityLumpName)
        .addProperty("EntityFilterName", &GCPointTemplate::GetEntityFilterName, &GCPointTemplate::SetEntityFilterName)
        .addProperty("TimeoutInterval", &GCPointTemplate::GetTimeoutInterval, &GCPointTemplate::SetTimeoutInterval)
        .addProperty("AsynchronouslySpawnEntities", &GCPointTemplate::GetAsynchronouslySpawnEntities, &GCPointTemplate::SetAsynchronouslySpawnEntities)
        .addProperty("OutputOnSpawned", &GCPointTemplate::GetOutputOnSpawned, &GCPointTemplate::SetOutputOnSpawned)
        .addProperty("ClientOnlyEntityBehavior", &GCPointTemplate::GetClientOnlyEntityBehavior, &GCPointTemplate::SetClientOnlyEntityBehavior)
        .addProperty("OwnerSpawnGroupType", &GCPointTemplate::GetOwnerSpawnGroupType, &GCPointTemplate::SetOwnerSpawnGroupType)
        .addProperty("CreatedSpawnGroupHandles", &GCPointTemplate::GetCreatedSpawnGroupHandles, &GCPointTemplate::SetCreatedSpawnGroupHandles)
        .addProperty("SpawnedEntityHandles", &GCPointTemplate::GetSpawnedEntityHandles, &GCPointTemplate::SetSpawnedEntityHandles)
        .addProperty("Parent", &GCPointTemplate::GetParent, &GCPointTemplate::SetParent)
        .addFunction("ToPtr", &GCPointTemplate::ToPtr)
        .addFunction("IsValid", &GCPointTemplate::IsValid)
        .endClass();
}