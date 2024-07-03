#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlashlightEffect::GCFlashlightEffect(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlashlightEffect::GCFlashlightEffect(void *ptr) {
    m_ptr = ptr;
}
bool GCFlashlightEffect::GetIsOn() const {
    return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bIsOn");
}
void GCFlashlightEffect::SetIsOn(bool value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bIsOn", false, value);
}
bool GCFlashlightEffect::GetMuzzleFlashEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bMuzzleFlashEnabled");
}
void GCFlashlightEffect::SetMuzzleFlashEnabled(bool value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bMuzzleFlashEnabled", false, value);
}
float GCFlashlightEffect::GetMuzzleFlashBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flMuzzleFlashBrightness");
}
void GCFlashlightEffect::SetMuzzleFlashBrightness(float value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flMuzzleFlashBrightness", false, value);
}
Quaternion GCFlashlightEffect::GetQuatMuzzleFlashOrientation() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CFlashlightEffect", "m_quatMuzzleFlashOrientation");
}
void GCFlashlightEffect::SetQuatMuzzleFlashOrientation(Quaternion value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_quatMuzzleFlashOrientation", false, value);
}
Vector GCFlashlightEffect::GetMuzzleFlashOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CFlashlightEffect", "m_vecMuzzleFlashOrigin");
}
void GCFlashlightEffect::SetMuzzleFlashOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_vecMuzzleFlashOrigin", false, value);
}
float GCFlashlightEffect::GetFov() const {
    return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flFov");
}
void GCFlashlightEffect::SetFov(float value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flFov", false, value);
}
float GCFlashlightEffect::GetFarZ() const {
    return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flFarZ");
}
void GCFlashlightEffect::SetFarZ(float value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flFarZ", false, value);
}
float GCFlashlightEffect::GetLinearAtten() const {
    return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flLinearAtten");
}
void GCFlashlightEffect::SetLinearAtten(float value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flLinearAtten", false, value);
}
bool GCFlashlightEffect::GetCastsShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bCastsShadows");
}
void GCFlashlightEffect::SetCastsShadows(bool value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bCastsShadows", false, value);
}
float GCFlashlightEffect::GetCurrentPullBackDist() const {
    return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flCurrentPullBackDist");
}
void GCFlashlightEffect::SetCurrentPullBackDist(float value) {
    SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flCurrentPullBackDist", false, value);
}
std::string GCFlashlightEffect::GetTextureName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CFlashlightEffect", "m_textureName");
}
void GCFlashlightEffect::SetTextureName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CFlashlightEffect", "m_textureName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
std::string GCFlashlightEffect::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlashlightEffect::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFlashlightEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashlightEffect>("CFlashlightEffect")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsOn", &GCFlashlightEffect::GetIsOn, &GCFlashlightEffect::SetIsOn)
        .addProperty("MuzzleFlashEnabled", &GCFlashlightEffect::GetMuzzleFlashEnabled, &GCFlashlightEffect::SetMuzzleFlashEnabled)
        .addProperty("MuzzleFlashBrightness", &GCFlashlightEffect::GetMuzzleFlashBrightness, &GCFlashlightEffect::SetMuzzleFlashBrightness)
        .addProperty("QuatMuzzleFlashOrientation", &GCFlashlightEffect::GetQuatMuzzleFlashOrientation, &GCFlashlightEffect::SetQuatMuzzleFlashOrientation)
        .addProperty("MuzzleFlashOrigin", &GCFlashlightEffect::GetMuzzleFlashOrigin, &GCFlashlightEffect::SetMuzzleFlashOrigin)
        .addProperty("Fov", &GCFlashlightEffect::GetFov, &GCFlashlightEffect::SetFov)
        .addProperty("FarZ", &GCFlashlightEffect::GetFarZ, &GCFlashlightEffect::SetFarZ)
        .addProperty("LinearAtten", &GCFlashlightEffect::GetLinearAtten, &GCFlashlightEffect::SetLinearAtten)
        .addProperty("CastsShadows", &GCFlashlightEffect::GetCastsShadows, &GCFlashlightEffect::SetCastsShadows)
        .addProperty("CurrentPullBackDist", &GCFlashlightEffect::GetCurrentPullBackDist, &GCFlashlightEffect::SetCurrentPullBackDist)
        .addProperty("TextureName", &GCFlashlightEffect::GetTextureName, &GCFlashlightEffect::SetTextureName)
        .addFunction("ToPtr", &GCFlashlightEffect::ToPtr)
        .addFunction("IsValid", &GCFlashlightEffect::IsValid)
        .endClass();
}