#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvBeam::GCEnvBeam(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvBeam::GCEnvBeam(void *ptr) {
    m_ptr = ptr;
}
int32_t GCEnvBeam::GetActive() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_active");
}
void GCEnvBeam::SetActive(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_active", false, value);
}
std::string GCEnvBeam::GetStartEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszStartEntity").String();
}
void GCEnvBeam::SetStartEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_iszStartEntity", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvBeam::GetEndEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszEndEntity").String();
}
void GCEnvBeam::SetEndEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_iszEndEntity", false, CUtlSymbolLarge(value.c_str()));
}
float GCEnvBeam::GetLife() const {
    return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_life");
}
void GCEnvBeam::SetLife(float value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_life", false, value);
}
float GCEnvBeam::GetBoltWidth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_boltWidth");
}
void GCEnvBeam::SetBoltWidth(float value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_boltWidth", false, value);
}
float GCEnvBeam::GetNoiseAmplitude() const {
    return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_noiseAmplitude");
}
void GCEnvBeam::SetNoiseAmplitude(float value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_noiseAmplitude", false, value);
}
int32_t GCEnvBeam::GetSpeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_speed");
}
void GCEnvBeam::SetSpeed(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_speed", false, value);
}
float GCEnvBeam::GetRestrike() const {
    return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_restrike");
}
void GCEnvBeam::SetRestrike(float value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_restrike", false, value);
}
std::string GCEnvBeam::GetSpriteName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszSpriteName").String();
}
void GCEnvBeam::SetSpriteName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_iszSpriteName", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvBeam::GetFrameStart() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_frameStart");
}
void GCEnvBeam::SetFrameStart(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_frameStart", false, value);
}
Vector GCEnvBeam::GetEndPointWorld() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvBeam", "m_vEndPointWorld");
}
void GCEnvBeam::SetEndPointWorld(Vector value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_vEndPointWorld", false, value);
}
Vector GCEnvBeam::GetEndPointRelative() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvBeam", "m_vEndPointRelative");
}
void GCEnvBeam::SetEndPointRelative(Vector value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_vEndPointRelative", false, value);
}
float GCEnvBeam::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_radius");
}
void GCEnvBeam::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_radius", false, value);
}
uint64_t GCEnvBeam::GetTouchType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEnvBeam", "m_TouchType");
}
void GCEnvBeam::SetTouchType(uint64_t value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_TouchType", false, value);
}
std::string GCEnvBeam::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iFilterName").String();
}
void GCEnvBeam::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_iFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCEnvBeam::GetFilter() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvBeam", "m_hFilter"));
    return value;
}
void GCEnvBeam::SetFilter(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
std::string GCEnvBeam::GetDecal() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszDecal").String();
}
void GCEnvBeam::SetDecal(std::string value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_iszDecal", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCEnvBeam::GetOnTouchedByEntity() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvBeam", "m_OnTouchedByEntity"));
    return value;
}
void GCEnvBeam::SetOnTouchedByEntity(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvBeam", "m_OnTouchedByEntity", false, value);
}
std::string GCEnvBeam::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvBeam::IsValid() {
    return (m_ptr != nullptr);
}
GCBeam GCEnvBeam::GetParent() const {
    GCBeam value(m_ptr);
    return value;
}
void GCEnvBeam::SetParent(GCBeam value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvBeam>("CEnvBeam")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Active", &GCEnvBeam::GetActive, &GCEnvBeam::SetActive)
        .addProperty("StartEntity", &GCEnvBeam::GetStartEntity, &GCEnvBeam::SetStartEntity)
        .addProperty("EndEntity", &GCEnvBeam::GetEndEntity, &GCEnvBeam::SetEndEntity)
        .addProperty("Life", &GCEnvBeam::GetLife, &GCEnvBeam::SetLife)
        .addProperty("BoltWidth", &GCEnvBeam::GetBoltWidth, &GCEnvBeam::SetBoltWidth)
        .addProperty("NoiseAmplitude", &GCEnvBeam::GetNoiseAmplitude, &GCEnvBeam::SetNoiseAmplitude)
        .addProperty("Speed", &GCEnvBeam::GetSpeed, &GCEnvBeam::SetSpeed)
        .addProperty("Restrike", &GCEnvBeam::GetRestrike, &GCEnvBeam::SetRestrike)
        .addProperty("SpriteName", &GCEnvBeam::GetSpriteName, &GCEnvBeam::SetSpriteName)
        .addProperty("FrameStart", &GCEnvBeam::GetFrameStart, &GCEnvBeam::SetFrameStart)
        .addProperty("EndPointWorld", &GCEnvBeam::GetEndPointWorld, &GCEnvBeam::SetEndPointWorld)
        .addProperty("EndPointRelative", &GCEnvBeam::GetEndPointRelative, &GCEnvBeam::SetEndPointRelative)
        .addProperty("Radius", &GCEnvBeam::GetRadius, &GCEnvBeam::SetRadius)
        .addProperty("TouchType", &GCEnvBeam::GetTouchType, &GCEnvBeam::SetTouchType)
        .addProperty("FilterName", &GCEnvBeam::GetFilterName, &GCEnvBeam::SetFilterName)
        .addProperty("Filter", &GCEnvBeam::GetFilter, &GCEnvBeam::SetFilter)
        .addProperty("Decal", &GCEnvBeam::GetDecal, &GCEnvBeam::SetDecal)
        .addProperty("OnTouchedByEntity", &GCEnvBeam::GetOnTouchedByEntity, &GCEnvBeam::SetOnTouchedByEntity)
        .addProperty("Parent", &GCEnvBeam::GetParent, &GCEnvBeam::SetParent)
        .addFunction("ToPtr", &GCEnvBeam::ToPtr)
        .addFunction("IsValid", &GCEnvBeam::IsValid)
        .endClass();
}