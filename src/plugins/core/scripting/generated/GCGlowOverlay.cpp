#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGlowOverlay::GCGlowOverlay(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGlowOverlay::GCGlowOverlay(void *ptr) {
    m_ptr = ptr;
}
Vector GCGlowOverlay::GetPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlowOverlay", "m_vPos");
}
void GCGlowOverlay::SetPos(Vector value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_vPos", false, value);
}
bool GCGlowOverlay::GetDirectional() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bDirectional");
}
void GCGlowOverlay::SetDirectional(bool value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_bDirectional", false, value);
}
Vector GCGlowOverlay::GetDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlowOverlay", "m_vDirection");
}
void GCGlowOverlay::SetDirection(Vector value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_vDirection", false, value);
}
bool GCGlowOverlay::GetInSky() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bInSky");
}
void GCGlowOverlay::SetInSky(bool value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_bInSky", false, value);
}
float GCGlowOverlay::GetSkyObstructionScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_skyObstructionScale");
}
void GCGlowOverlay::SetSkyObstructionScale(float value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_skyObstructionScale", false, value);
}
std::vector<GCGlowSprite> GCGlowOverlay::GetSprites() const {
    GCGlowSprite* outValue = GetSchemaValue<GCGlowSprite*>(m_ptr, "CGlowOverlay", "m_Sprites"); std::vector<GCGlowSprite> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCGlowOverlay::SetSprites(std::vector<GCGlowSprite> value) {
    GCGlowSprite* outValue = GetSchemaValue<GCGlowSprite*>(m_ptr, "CGlowOverlay", "m_Sprites"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CGlowOverlay", "m_Sprites", false, outValue);
}
int32_t GCGlowOverlay::GetSprites1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowOverlay", "m_nSprites");
}
void GCGlowOverlay::SetSprites1(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_nSprites", false, value);
}
float GCGlowOverlay::GetProxyRadius() const {
    return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flProxyRadius");
}
void GCGlowOverlay::SetProxyRadius(float value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_flProxyRadius", false, value);
}
float GCGlowOverlay::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flHDRColorScale");
}
void GCGlowOverlay::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_flHDRColorScale", false, value);
}
float GCGlowOverlay::GetGlowObstructionScale() const {
    return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flGlowObstructionScale");
}
void GCGlowOverlay::SetGlowObstructionScale(float value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_flGlowObstructionScale", false, value);
}
bool GCGlowOverlay::GetCacheGlowObstruction() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bCacheGlowObstruction");
}
void GCGlowOverlay::SetCacheGlowObstruction(bool value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_bCacheGlowObstruction", false, value);
}
bool GCGlowOverlay::GetCacheSkyObstruction() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bCacheSkyObstruction");
}
void GCGlowOverlay::SetCacheSkyObstruction(bool value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_bCacheSkyObstruction", false, value);
}
int16_t GCGlowOverlay::GetActivated() const {
    return GetSchemaValue<int16_t>(m_ptr, "CGlowOverlay", "m_bActivated");
}
void GCGlowOverlay::SetActivated(int16_t value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_bActivated", false, value);
}
uint16_t GCGlowOverlay::GetListIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CGlowOverlay", "m_ListIndex");
}
void GCGlowOverlay::SetListIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_ListIndex", false, value);
}
int32_t GCGlowOverlay::GetQueryHandle() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowOverlay", "m_queryHandle");
}
void GCGlowOverlay::SetQueryHandle(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowOverlay", "m_queryHandle", false, value);
}
std::string GCGlowOverlay::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGlowOverlay::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGlowOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowOverlay>("CGlowOverlay")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Pos", &GCGlowOverlay::GetPos, &GCGlowOverlay::SetPos)
        .addProperty("Directional", &GCGlowOverlay::GetDirectional, &GCGlowOverlay::SetDirectional)
        .addProperty("Direction", &GCGlowOverlay::GetDirection, &GCGlowOverlay::SetDirection)
        .addProperty("InSky", &GCGlowOverlay::GetInSky, &GCGlowOverlay::SetInSky)
        .addProperty("SkyObstructionScale", &GCGlowOverlay::GetSkyObstructionScale, &GCGlowOverlay::SetSkyObstructionScale)
        .addProperty("Sprites", &GCGlowOverlay::GetSprites, &GCGlowOverlay::SetSprites)
        .addProperty("Sprites1", &GCGlowOverlay::GetSprites1, &GCGlowOverlay::SetSprites1)
        .addProperty("ProxyRadius", &GCGlowOverlay::GetProxyRadius, &GCGlowOverlay::SetProxyRadius)
        .addProperty("HDRColorScale", &GCGlowOverlay::GetHDRColorScale, &GCGlowOverlay::SetHDRColorScale)
        .addProperty("GlowObstructionScale", &GCGlowOverlay::GetGlowObstructionScale, &GCGlowOverlay::SetGlowObstructionScale)
        .addProperty("CacheGlowObstruction", &GCGlowOverlay::GetCacheGlowObstruction, &GCGlowOverlay::SetCacheGlowObstruction)
        .addProperty("CacheSkyObstruction", &GCGlowOverlay::GetCacheSkyObstruction, &GCGlowOverlay::SetCacheSkyObstruction)
        .addProperty("Activated", &GCGlowOverlay::GetActivated, &GCGlowOverlay::SetActivated)
        .addProperty("ListIndex", &GCGlowOverlay::GetListIndex, &GCGlowOverlay::SetListIndex)
        .addProperty("QueryHandle", &GCGlowOverlay::GetQueryHandle, &GCGlowOverlay::SetQueryHandle)
        .addFunction("ToPtr", &GCGlowOverlay::ToPtr)
        .addFunction("IsValid", &GCGlowOverlay::IsValid)
        .endClass();
}