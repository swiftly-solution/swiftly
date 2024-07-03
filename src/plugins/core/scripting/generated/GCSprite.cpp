#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSprite::GCSprite(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSprite::GCSprite(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCSprite::GetAttachedToEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSprite", "m_hAttachedToEntity"));
    return value;
}
void GCSprite::SetAttachedToEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedToEntity' is not possible.\n");
}
float GCSprite::GetSpriteFramerate() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flSpriteFramerate");
}
void GCSprite::SetSpriteFramerate(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flSpriteFramerate", false, value);
}
float GCSprite::GetFrame() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flFrame");
}
void GCSprite::SetFrame(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flFrame", false, value);
}
float GCSprite::GetDieTime() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flDieTime");
}
void GCSprite::SetDieTime(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flDieTime", false, value);
}
uint32_t GCSprite::GetBrightness() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CSprite", "m_nBrightness");
}
void GCSprite::SetBrightness(uint32_t value) {
    SetSchemaValue(m_ptr, "CSprite", "m_nBrightness", false, value);
}
float GCSprite::GetBrightnessDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flBrightnessDuration");
}
void GCSprite::SetBrightnessDuration(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flBrightnessDuration", false, value);
}
float GCSprite::GetSpriteScale() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flSpriteScale");
}
void GCSprite::SetSpriteScale(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flSpriteScale", false, value);
}
float GCSprite::GetScaleDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flScaleDuration");
}
void GCSprite::SetScaleDuration(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flScaleDuration", false, value);
}
bool GCSprite::GetWorldSpaceScale() const {
    return GetSchemaValue<bool>(m_ptr, "CSprite", "m_bWorldSpaceScale");
}
void GCSprite::SetWorldSpaceScale(bool value) {
    SetSchemaValue(m_ptr, "CSprite", "m_bWorldSpaceScale", false, value);
}
float GCSprite::GetGlowProxySize() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flGlowProxySize");
}
void GCSprite::SetGlowProxySize(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flGlowProxySize", false, value);
}
float GCSprite::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flHDRColorScale");
}
void GCSprite::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flHDRColorScale", false, value);
}
float GCSprite::GetLastTime() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flLastTime");
}
void GCSprite::SetLastTime(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flLastTime", false, value);
}
float GCSprite::GetMaxFrame() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flMaxFrame");
}
void GCSprite::SetMaxFrame(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flMaxFrame", false, value);
}
float GCSprite::GetStartScale() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flStartScale");
}
void GCSprite::SetStartScale(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flStartScale", false, value);
}
float GCSprite::GetDestScale() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flDestScale");
}
void GCSprite::SetDestScale(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flDestScale", false, value);
}
float GCSprite::GetScaleTimeStart() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flScaleTimeStart");
}
void GCSprite::SetScaleTimeStart(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flScaleTimeStart", false, value);
}
int32_t GCSprite::GetStartBrightness() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nStartBrightness");
}
void GCSprite::SetStartBrightness(int32_t value) {
    SetSchemaValue(m_ptr, "CSprite", "m_nStartBrightness", false, value);
}
int32_t GCSprite::GetDestBrightness() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nDestBrightness");
}
void GCSprite::SetDestBrightness(int32_t value) {
    SetSchemaValue(m_ptr, "CSprite", "m_nDestBrightness", false, value);
}
float GCSprite::GetBrightnessTimeStart() const {
    return GetSchemaValue<float>(m_ptr, "CSprite", "m_flBrightnessTimeStart");
}
void GCSprite::SetBrightnessTimeStart(float value) {
    SetSchemaValue(m_ptr, "CSprite", "m_flBrightnessTimeStart", false, value);
}
int32_t GCSprite::GetSpriteWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nSpriteWidth");
}
void GCSprite::SetSpriteWidth(int32_t value) {
    SetSchemaValue(m_ptr, "CSprite", "m_nSpriteWidth", false, value);
}
int32_t GCSprite::GetSpriteHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nSpriteHeight");
}
void GCSprite::SetSpriteHeight(int32_t value) {
    SetSchemaValue(m_ptr, "CSprite", "m_nSpriteHeight", false, value);
}
std::string GCSprite::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSprite::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCSprite::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCSprite::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSprite>("CSprite")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttachedToEntity", &GCSprite::GetAttachedToEntity, &GCSprite::SetAttachedToEntity)
        .addProperty("SpriteFramerate", &GCSprite::GetSpriteFramerate, &GCSprite::SetSpriteFramerate)
        .addProperty("Frame", &GCSprite::GetFrame, &GCSprite::SetFrame)
        .addProperty("DieTime", &GCSprite::GetDieTime, &GCSprite::SetDieTime)
        .addProperty("Brightness", &GCSprite::GetBrightness, &GCSprite::SetBrightness)
        .addProperty("BrightnessDuration", &GCSprite::GetBrightnessDuration, &GCSprite::SetBrightnessDuration)
        .addProperty("SpriteScale", &GCSprite::GetSpriteScale, &GCSprite::SetSpriteScale)
        .addProperty("ScaleDuration", &GCSprite::GetScaleDuration, &GCSprite::SetScaleDuration)
        .addProperty("WorldSpaceScale", &GCSprite::GetWorldSpaceScale, &GCSprite::SetWorldSpaceScale)
        .addProperty("GlowProxySize", &GCSprite::GetGlowProxySize, &GCSprite::SetGlowProxySize)
        .addProperty("HDRColorScale", &GCSprite::GetHDRColorScale, &GCSprite::SetHDRColorScale)
        .addProperty("LastTime", &GCSprite::GetLastTime, &GCSprite::SetLastTime)
        .addProperty("MaxFrame", &GCSprite::GetMaxFrame, &GCSprite::SetMaxFrame)
        .addProperty("StartScale", &GCSprite::GetStartScale, &GCSprite::SetStartScale)
        .addProperty("DestScale", &GCSprite::GetDestScale, &GCSprite::SetDestScale)
        .addProperty("ScaleTimeStart", &GCSprite::GetScaleTimeStart, &GCSprite::SetScaleTimeStart)
        .addProperty("StartBrightness", &GCSprite::GetStartBrightness, &GCSprite::SetStartBrightness)
        .addProperty("DestBrightness", &GCSprite::GetDestBrightness, &GCSprite::SetDestBrightness)
        .addProperty("BrightnessTimeStart", &GCSprite::GetBrightnessTimeStart, &GCSprite::SetBrightnessTimeStart)
        .addProperty("SpriteWidth", &GCSprite::GetSpriteWidth, &GCSprite::SetSpriteWidth)
        .addProperty("SpriteHeight", &GCSprite::GetSpriteHeight, &GCSprite::SetSpriteHeight)
        .addProperty("Parent", &GCSprite::GetParent, &GCSprite::SetParent)
        .addFunction("ToPtr", &GCSprite::ToPtr)
        .addFunction("IsValid", &GCSprite::IsValid)
        .endClass();
}