#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetPointEntity::GCSoundOpvarSetPointEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetPointEntity::GCSoundOpvarSetPointEntity(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCSoundOpvarSetPointEntity::GetOnEnter() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSoundOpvarSetPointEntity", "m_OnEnter"));
    return value;
}
void GCSoundOpvarSetPointEntity::SetOnEnter(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_OnEnter", false, value);
}
GCEntityIOOutput GCSoundOpvarSetPointEntity::GetOnExit() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSoundOpvarSetPointEntity", "m_OnExit"));
    return value;
}
void GCSoundOpvarSetPointEntity::SetOnExit(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_OnExit", false, value);
}
bool GCSoundOpvarSetPointEntity::GetAutoDisable() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointEntity", "m_bAutoDisable");
}
void GCSoundOpvarSetPointEntity::SetAutoDisable(bool value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_bAutoDisable", false, value);
}
float GCSoundOpvarSetPointEntity::GetDistanceMin() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMin");
}
void GCSoundOpvarSetPointEntity::SetDistanceMin(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMin", false, value);
}
float GCSoundOpvarSetPointEntity::GetDistanceMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMax");
}
void GCSoundOpvarSetPointEntity::SetDistanceMax(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMax", false, value);
}
float GCSoundOpvarSetPointEntity::GetDistanceMapMin() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMin");
}
void GCSoundOpvarSetPointEntity::SetDistanceMapMin(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMin", false, value);
}
float GCSoundOpvarSetPointEntity::GetDistanceMapMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMax");
}
void GCSoundOpvarSetPointEntity::SetDistanceMapMax(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMax", false, value);
}
float GCSoundOpvarSetPointEntity::GetOcclusionRadius() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionRadius");
}
void GCSoundOpvarSetPointEntity::SetOcclusionRadius(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionRadius", false, value);
}
float GCSoundOpvarSetPointEntity::GetOcclusionMin() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMin");
}
void GCSoundOpvarSetPointEntity::SetOcclusionMin(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMin", false, value);
}
float GCSoundOpvarSetPointEntity::GetOcclusionMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMax");
}
void GCSoundOpvarSetPointEntity::SetOcclusionMax(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMax", false, value);
}
float GCSoundOpvarSetPointEntity::GetValSetOnDisable() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flValSetOnDisable");
}
void GCSoundOpvarSetPointEntity::SetValSetOnDisable(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flValSetOnDisable", false, value);
}
bool GCSoundOpvarSetPointEntity::GetSetValueOnDisable() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointEntity", "m_bSetValueOnDisable");
}
void GCSoundOpvarSetPointEntity::SetSetValueOnDisable(bool value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_bSetValueOnDisable", false, value);
}
int32_t GCSoundOpvarSetPointEntity::GetSimulationMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nSimulationMode");
}
void GCSoundOpvarSetPointEntity::SetSimulationMode(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nSimulationMode", false, value);
}
int32_t GCSoundOpvarSetPointEntity::GetVisibilitySamples() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nVisibilitySamples");
}
void GCSoundOpvarSetPointEntity::SetVisibilitySamples(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nVisibilitySamples", false, value);
}
Vector GCSoundOpvarSetPointEntity::GetDynamicProxyPoint() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vDynamicProxyPoint");
}
void GCSoundOpvarSetPointEntity::SetDynamicProxyPoint(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vDynamicProxyPoint", false, value);
}
float GCSoundOpvarSetPointEntity::GetDynamicMaximumOcclusion() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDynamicMaximumOcclusion");
}
void GCSoundOpvarSetPointEntity::SetDynamicMaximumOcclusion(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDynamicMaximumOcclusion", false, value);
}
GCEntityInstance GCSoundOpvarSetPointEntity::GetDynamicEntity() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CSoundOpvarSetPointEntity", "m_hDynamicEntity"));
    return value;
}
void GCSoundOpvarSetPointEntity::SetDynamicEntity(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DynamicEntity' is not possible.\n");
}
std::string GCSoundOpvarSetPointEntity::GetDynamicEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointEntity", "m_iszDynamicEntityName").String();
}
void GCSoundOpvarSetPointEntity::SetDynamicEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_iszDynamicEntityName", false, CUtlSymbolLarge(value.c_str()));
}
float GCSoundOpvarSetPointEntity::GetPathingDistanceNormFactor() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flPathingDistanceNormFactor");
}
void GCSoundOpvarSetPointEntity::SetPathingDistanceNormFactor(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flPathingDistanceNormFactor", false, value);
}
Vector GCSoundOpvarSetPointEntity::GetPathingSourcePos() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingSourcePos");
}
void GCSoundOpvarSetPointEntity::SetPathingSourcePos(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingSourcePos", false, value);
}
Vector GCSoundOpvarSetPointEntity::GetPathingListenerPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingListenerPos");
}
void GCSoundOpvarSetPointEntity::SetPathingListenerPos(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingListenerPos", false, value);
}
Vector GCSoundOpvarSetPointEntity::GetPathingDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingDirection");
}
void GCSoundOpvarSetPointEntity::SetPathingDirection(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingDirection", false, value);
}
int32_t GCSoundOpvarSetPointEntity::GetPathingSourceIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nPathingSourceIndex");
}
void GCSoundOpvarSetPointEntity::SetPathingSourceIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nPathingSourceIndex", false, value);
}
std::string GCSoundOpvarSetPointEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetPointEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetPointBase GCSoundOpvarSetPointEntity::GetParent() const {
    GCSoundOpvarSetPointBase value(m_ptr);
    return value;
}
void GCSoundOpvarSetPointEntity::SetParent(GCSoundOpvarSetPointBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPointEntity>("CSoundOpvarSetPointEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnEnter", &GCSoundOpvarSetPointEntity::GetOnEnter, &GCSoundOpvarSetPointEntity::SetOnEnter)
        .addProperty("OnExit", &GCSoundOpvarSetPointEntity::GetOnExit, &GCSoundOpvarSetPointEntity::SetOnExit)
        .addProperty("AutoDisable", &GCSoundOpvarSetPointEntity::GetAutoDisable, &GCSoundOpvarSetPointEntity::SetAutoDisable)
        .addProperty("DistanceMin", &GCSoundOpvarSetPointEntity::GetDistanceMin, &GCSoundOpvarSetPointEntity::SetDistanceMin)
        .addProperty("DistanceMax", &GCSoundOpvarSetPointEntity::GetDistanceMax, &GCSoundOpvarSetPointEntity::SetDistanceMax)
        .addProperty("DistanceMapMin", &GCSoundOpvarSetPointEntity::GetDistanceMapMin, &GCSoundOpvarSetPointEntity::SetDistanceMapMin)
        .addProperty("DistanceMapMax", &GCSoundOpvarSetPointEntity::GetDistanceMapMax, &GCSoundOpvarSetPointEntity::SetDistanceMapMax)
        .addProperty("OcclusionRadius", &GCSoundOpvarSetPointEntity::GetOcclusionRadius, &GCSoundOpvarSetPointEntity::SetOcclusionRadius)
        .addProperty("OcclusionMin", &GCSoundOpvarSetPointEntity::GetOcclusionMin, &GCSoundOpvarSetPointEntity::SetOcclusionMin)
        .addProperty("OcclusionMax", &GCSoundOpvarSetPointEntity::GetOcclusionMax, &GCSoundOpvarSetPointEntity::SetOcclusionMax)
        .addProperty("ValSetOnDisable", &GCSoundOpvarSetPointEntity::GetValSetOnDisable, &GCSoundOpvarSetPointEntity::SetValSetOnDisable)
        .addProperty("SetValueOnDisable", &GCSoundOpvarSetPointEntity::GetSetValueOnDisable, &GCSoundOpvarSetPointEntity::SetSetValueOnDisable)
        .addProperty("SimulationMode", &GCSoundOpvarSetPointEntity::GetSimulationMode, &GCSoundOpvarSetPointEntity::SetSimulationMode)
        .addProperty("VisibilitySamples", &GCSoundOpvarSetPointEntity::GetVisibilitySamples, &GCSoundOpvarSetPointEntity::SetVisibilitySamples)
        .addProperty("DynamicProxyPoint", &GCSoundOpvarSetPointEntity::GetDynamicProxyPoint, &GCSoundOpvarSetPointEntity::SetDynamicProxyPoint)
        .addProperty("DynamicMaximumOcclusion", &GCSoundOpvarSetPointEntity::GetDynamicMaximumOcclusion, &GCSoundOpvarSetPointEntity::SetDynamicMaximumOcclusion)
        .addProperty("DynamicEntity", &GCSoundOpvarSetPointEntity::GetDynamicEntity, &GCSoundOpvarSetPointEntity::SetDynamicEntity)
        .addProperty("DynamicEntityName", &GCSoundOpvarSetPointEntity::GetDynamicEntityName, &GCSoundOpvarSetPointEntity::SetDynamicEntityName)
        .addProperty("PathingDistanceNormFactor", &GCSoundOpvarSetPointEntity::GetPathingDistanceNormFactor, &GCSoundOpvarSetPointEntity::SetPathingDistanceNormFactor)
        .addProperty("PathingSourcePos", &GCSoundOpvarSetPointEntity::GetPathingSourcePos, &GCSoundOpvarSetPointEntity::SetPathingSourcePos)
        .addProperty("PathingListenerPos", &GCSoundOpvarSetPointEntity::GetPathingListenerPos, &GCSoundOpvarSetPointEntity::SetPathingListenerPos)
        .addProperty("PathingDirection", &GCSoundOpvarSetPointEntity::GetPathingDirection, &GCSoundOpvarSetPointEntity::SetPathingDirection)
        .addProperty("PathingSourceIndex", &GCSoundOpvarSetPointEntity::GetPathingSourceIndex, &GCSoundOpvarSetPointEntity::SetPathingSourceIndex)
        .addProperty("Parent", &GCSoundOpvarSetPointEntity::GetParent, &GCSoundOpvarSetPointEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetPointEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetPointEntity::IsValid)
        .endClass();
}