#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvEntityMaker::GCEnvEntityMaker(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvEntityMaker::GCEnvEntityMaker(void *ptr) {
    m_ptr = ptr;
}
Vector GCEnvEntityMaker::GetEntityMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecEntityMins");
}
void GCEnvEntityMaker::SetEntityMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecEntityMins", false, value);
}
Vector GCEnvEntityMaker::GetEntityMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecEntityMaxs");
}
void GCEnvEntityMaker::SetEntityMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecEntityMaxs", false, value);
}
GCBaseEntity GCEnvEntityMaker::GetCurrentInstance() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvEntityMaker", "m_hCurrentInstance"));
    return value;
}
void GCEnvEntityMaker::SetCurrentInstance(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentInstance' is not possible.\n");
}
GCBaseEntity GCEnvEntityMaker::GetCurrentBlocker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvEntityMaker", "m_hCurrentBlocker"));
    return value;
}
void GCEnvEntityMaker::SetCurrentBlocker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentBlocker' is not possible.\n");
}
Vector GCEnvEntityMaker::GetBlockerOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvEntityMaker", "m_vecBlockerOrigin");
}
void GCEnvEntityMaker::SetBlockerOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_vecBlockerOrigin", false, value);
}
QAngle GCEnvEntityMaker::GetPostSpawnDirection() const {
    return GetSchemaValue<QAngle>(m_ptr, "CEnvEntityMaker", "m_angPostSpawnDirection");
}
void GCEnvEntityMaker::SetPostSpawnDirection(QAngle value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_angPostSpawnDirection", false, value);
}
float GCEnvEntityMaker::GetPostSpawnDirectionVariance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvEntityMaker", "m_flPostSpawnDirectionVariance");
}
void GCEnvEntityMaker::SetPostSpawnDirectionVariance(float value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_flPostSpawnDirectionVariance", false, value);
}
float GCEnvEntityMaker::GetPostSpawnSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvEntityMaker", "m_flPostSpawnSpeed");
}
void GCEnvEntityMaker::SetPostSpawnSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_flPostSpawnSpeed", false, value);
}
bool GCEnvEntityMaker::GetPostSpawnUseAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvEntityMaker", "m_bPostSpawnUseAngles");
}
void GCEnvEntityMaker::SetPostSpawnUseAngles(bool value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_bPostSpawnUseAngles", false, value);
}
std::string GCEnvEntityMaker::GetTemplate() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvEntityMaker", "m_iszTemplate").String();
}
void GCEnvEntityMaker::SetTemplate(std::string value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_iszTemplate", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCEnvEntityMaker::GetOutputOnSpawned() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvEntityMaker", "m_pOutputOnSpawned"));
    return value;
}
void GCEnvEntityMaker::SetOutputOnSpawned(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_pOutputOnSpawned", false, value);
}
GCEntityIOOutput GCEnvEntityMaker::GetOutputOnFailedSpawn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvEntityMaker", "m_pOutputOnFailedSpawn"));
    return value;
}
void GCEnvEntityMaker::SetOutputOnFailedSpawn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvEntityMaker", "m_pOutputOnFailedSpawn", false, value);
}
std::string GCEnvEntityMaker::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvEntityMaker::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvEntityMaker::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvEntityMaker::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvEntityMaker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvEntityMaker>("CEnvEntityMaker")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntityMins", &GCEnvEntityMaker::GetEntityMins, &GCEnvEntityMaker::SetEntityMins)
        .addProperty("EntityMaxs", &GCEnvEntityMaker::GetEntityMaxs, &GCEnvEntityMaker::SetEntityMaxs)
        .addProperty("CurrentInstance", &GCEnvEntityMaker::GetCurrentInstance, &GCEnvEntityMaker::SetCurrentInstance)
        .addProperty("CurrentBlocker", &GCEnvEntityMaker::GetCurrentBlocker, &GCEnvEntityMaker::SetCurrentBlocker)
        .addProperty("BlockerOrigin", &GCEnvEntityMaker::GetBlockerOrigin, &GCEnvEntityMaker::SetBlockerOrigin)
        .addProperty("PostSpawnDirection", &GCEnvEntityMaker::GetPostSpawnDirection, &GCEnvEntityMaker::SetPostSpawnDirection)
        .addProperty("PostSpawnDirectionVariance", &GCEnvEntityMaker::GetPostSpawnDirectionVariance, &GCEnvEntityMaker::SetPostSpawnDirectionVariance)
        .addProperty("PostSpawnSpeed", &GCEnvEntityMaker::GetPostSpawnSpeed, &GCEnvEntityMaker::SetPostSpawnSpeed)
        .addProperty("PostSpawnUseAngles", &GCEnvEntityMaker::GetPostSpawnUseAngles, &GCEnvEntityMaker::SetPostSpawnUseAngles)
        .addProperty("Template", &GCEnvEntityMaker::GetTemplate, &GCEnvEntityMaker::SetTemplate)
        .addProperty("OutputOnSpawned", &GCEnvEntityMaker::GetOutputOnSpawned, &GCEnvEntityMaker::SetOutputOnSpawned)
        .addProperty("OutputOnFailedSpawn", &GCEnvEntityMaker::GetOutputOnFailedSpawn, &GCEnvEntityMaker::SetOutputOnFailedSpawn)
        .addProperty("Parent", &GCEnvEntityMaker::GetParent, &GCEnvEntityMaker::SetParent)
        .addFunction("ToPtr", &GCEnvEntityMaker::ToPtr)
        .addFunction("IsValid", &GCEnvEntityMaker::IsValid)
        .endClass();
}