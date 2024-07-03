#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHitBox::GCHitBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHitBox::GCHitBox(void *ptr) {
    m_ptr = ptr;
}
std::string GCHitBox::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_name").Get();
}
void GCHitBox::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_name", false, CUtlString(value.c_str()));
}
std::string GCHitBox::GetSurfaceProperty() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_sSurfaceProperty").Get();
}
void GCHitBox::SetSurfaceProperty(std::string value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_sSurfaceProperty", false, CUtlString(value.c_str()));
}
std::string GCHitBox::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_sBoneName").Get();
}
void GCHitBox::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_sBoneName", false, CUtlString(value.c_str()));
}
Vector GCHitBox::GetMinBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CHitBox", "m_vMinBounds");
}
void GCHitBox::SetMinBounds(Vector value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_vMinBounds", false, value);
}
Vector GCHitBox::GetMaxBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CHitBox", "m_vMaxBounds");
}
void GCHitBox::SetMaxBounds(Vector value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_vMaxBounds", false, value);
}
float GCHitBox::GetShapeRadius() const {
    return GetSchemaValue<float>(m_ptr, "CHitBox", "m_flShapeRadius");
}
void GCHitBox::SetShapeRadius(float value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_flShapeRadius", false, value);
}
uint32_t GCHitBox::GetBoneNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CHitBox", "m_nBoneNameHash");
}
void GCHitBox::SetBoneNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_nBoneNameHash", false, value);
}
int32_t GCHitBox::GetGroupId() const {
    return GetSchemaValue<int32_t>(m_ptr, "CHitBox", "m_nGroupId");
}
void GCHitBox::SetGroupId(int32_t value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_nGroupId", false, value);
}
uint8_t GCHitBox::GetShapeType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CHitBox", "m_nShapeType");
}
void GCHitBox::SetShapeType(uint8_t value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_nShapeType", false, value);
}
bool GCHitBox::GetTranslationOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CHitBox", "m_bTranslationOnly");
}
void GCHitBox::SetTranslationOnly(bool value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_bTranslationOnly", false, value);
}
uint32_t GCHitBox::GetCRC() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CHitBox", "m_CRC");
}
void GCHitBox::SetCRC(uint32_t value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_CRC", false, value);
}
Color GCHitBox::GetCRenderColor() const {
    return GetSchemaValue<Color>(m_ptr, "CHitBox", "m_cRenderColor");
}
void GCHitBox::SetCRenderColor(Color value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_cRenderColor", false, value);
}
uint16_t GCHitBox::GetHitBoxIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CHitBox", "m_nHitBoxIndex");
}
void GCHitBox::SetHitBoxIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CHitBox", "m_nHitBoxIndex", false, value);
}
std::string GCHitBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHitBox::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCHitBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBox>("CHitBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCHitBox::GetName, &GCHitBox::SetName)
        .addProperty("SurfaceProperty", &GCHitBox::GetSurfaceProperty, &GCHitBox::SetSurfaceProperty)
        .addProperty("BoneName", &GCHitBox::GetBoneName, &GCHitBox::SetBoneName)
        .addProperty("MinBounds", &GCHitBox::GetMinBounds, &GCHitBox::SetMinBounds)
        .addProperty("MaxBounds", &GCHitBox::GetMaxBounds, &GCHitBox::SetMaxBounds)
        .addProperty("ShapeRadius", &GCHitBox::GetShapeRadius, &GCHitBox::SetShapeRadius)
        .addProperty("BoneNameHash", &GCHitBox::GetBoneNameHash, &GCHitBox::SetBoneNameHash)
        .addProperty("GroupId", &GCHitBox::GetGroupId, &GCHitBox::SetGroupId)
        .addProperty("ShapeType", &GCHitBox::GetShapeType, &GCHitBox::SetShapeType)
        .addProperty("TranslationOnly", &GCHitBox::GetTranslationOnly, &GCHitBox::SetTranslationOnly)
        .addProperty("CRC", &GCHitBox::GetCRC, &GCHitBox::SetCRC)
        .addProperty("CRenderColor", &GCHitBox::GetCRenderColor, &GCHitBox::SetCRenderColor)
        .addProperty("HitBoxIndex", &GCHitBox::GetHitBoxIndex, &GCHitBox::SetHitBoxIndex)
        .addFunction("ToPtr", &GCHitBox::ToPtr)
        .addFunction("IsValid", &GCHitBox::IsValid)
        .endClass();
}