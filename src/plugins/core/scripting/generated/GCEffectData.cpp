#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEffectData::GCEffectData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEffectData::GCEffectData(void *ptr) {
    m_ptr = ptr;
}
Vector GCEffectData::GetOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vOrigin");
}
void GCEffectData::SetOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_vOrigin", false, value);
}
Vector GCEffectData::GetStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vStart");
}
void GCEffectData::SetStart(Vector value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_vStart", false, value);
}
Vector GCEffectData::GetNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vNormal");
}
void GCEffectData::SetNormal(Vector value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_vNormal", false, value);
}
QAngle GCEffectData::GetAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CEffectData", "m_vAngles");
}
void GCEffectData::SetAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_vAngles", false, value);
}
GCEntityInstance GCEffectData::GetEntity() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CEffectData", "m_hEntity"));
    return value;
}
void GCEffectData::SetEntity(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
GCEntityInstance GCEffectData::GetOtherEntity() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CEffectData", "m_hOtherEntity"));
    return value;
}
void GCEffectData::SetOtherEntity(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OtherEntity' is not possible.\n");
}
float GCEffectData::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flScale");
}
void GCEffectData::SetScale(float value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_flScale", false, value);
}
float GCEffectData::GetMagnitude() const {
    return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flMagnitude");
}
void GCEffectData::SetMagnitude(float value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_flMagnitude", false, value);
}
float GCEffectData::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flRadius");
}
void GCEffectData::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_flRadius", false, value);
}
CUtlStringToken GCEffectData::GetSurfaceProp() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CEffectData", "m_nSurfaceProp");
}
void GCEffectData::SetSurfaceProp(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nSurfaceProp", false, value);
}
uint32_t GCEffectData::GetDamageType() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEffectData", "m_nDamageType");
}
void GCEffectData::SetDamageType(uint32_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nDamageType", false, value);
}
uint8_t GCEffectData::GetPenetrate() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nPenetrate");
}
void GCEffectData::SetPenetrate(uint8_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nPenetrate", false, value);
}
uint16_t GCEffectData::GetMaterial() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_nMaterial");
}
void GCEffectData::SetMaterial(uint16_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nMaterial", false, value);
}
uint16_t GCEffectData::GetHitBox() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_nHitBox");
}
void GCEffectData::SetHitBox(uint16_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nHitBox", false, value);
}
uint8_t GCEffectData::GetColor() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nColor");
}
void GCEffectData::SetColor(uint8_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nColor", false, value);
}
uint8_t GCEffectData::GetFlags() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_fFlags");
}
void GCEffectData::SetFlags(uint8_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_fFlags", false, value);
}
CUtlStringToken GCEffectData::GetAttachmentName() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CEffectData", "m_nAttachmentName");
}
void GCEffectData::SetAttachmentName(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nAttachmentName", false, value);
}
uint16_t GCEffectData::GetEffectName() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_iEffectName");
}
void GCEffectData::SetEffectName(uint16_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_iEffectName", false, value);
}
uint8_t GCEffectData::GetExplosionType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nExplosionType");
}
void GCEffectData::SetExplosionType(uint8_t value) {
    SetSchemaValue(m_ptr, "CEffectData", "m_nExplosionType", false, value);
}
std::string GCEffectData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEffectData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEffectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEffectData>("CEffectData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Origin", &GCEffectData::GetOrigin, &GCEffectData::SetOrigin)
        .addProperty("Start", &GCEffectData::GetStart, &GCEffectData::SetStart)
        .addProperty("Normal", &GCEffectData::GetNormal, &GCEffectData::SetNormal)
        .addProperty("Angles", &GCEffectData::GetAngles, &GCEffectData::SetAngles)
        .addProperty("Entity", &GCEffectData::GetEntity, &GCEffectData::SetEntity)
        .addProperty("OtherEntity", &GCEffectData::GetOtherEntity, &GCEffectData::SetOtherEntity)
        .addProperty("Scale", &GCEffectData::GetScale, &GCEffectData::SetScale)
        .addProperty("Magnitude", &GCEffectData::GetMagnitude, &GCEffectData::SetMagnitude)
        .addProperty("Radius", &GCEffectData::GetRadius, &GCEffectData::SetRadius)
        .addProperty("SurfaceProp", &GCEffectData::GetSurfaceProp, &GCEffectData::SetSurfaceProp)
        .addProperty("DamageType", &GCEffectData::GetDamageType, &GCEffectData::SetDamageType)
        .addProperty("Penetrate", &GCEffectData::GetPenetrate, &GCEffectData::SetPenetrate)
        .addProperty("Material", &GCEffectData::GetMaterial, &GCEffectData::SetMaterial)
        .addProperty("HitBox", &GCEffectData::GetHitBox, &GCEffectData::SetHitBox)
        .addProperty("Color", &GCEffectData::GetColor, &GCEffectData::SetColor)
        .addProperty("Flags", &GCEffectData::GetFlags, &GCEffectData::SetFlags)
        .addProperty("AttachmentName", &GCEffectData::GetAttachmentName, &GCEffectData::SetAttachmentName)
        .addProperty("EffectName", &GCEffectData::GetEffectName, &GCEffectData::SetEffectName)
        .addProperty("ExplosionType", &GCEffectData::GetExplosionType, &GCEffectData::SetExplosionType)
        .addFunction("ToPtr", &GCEffectData::ToPtr)
        .addFunction("IsValid", &GCEffectData::IsValid)
        .endClass();
}