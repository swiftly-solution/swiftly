#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseModelEntity::GCBaseModelEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseModelEntity::GCBaseModelEntity(void *ptr) {
    m_ptr = ptr;
}
void GCBaseModelEntity::SetModel(std::string model) {
    ((CBaseModelEntity*)m_ptr)->SetModel(model.c_str());
}
GCRenderComponent GCBaseModelEntity::GetCRenderComponent() const {
    GCRenderComponent value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseModelEntity", "m_CRenderComponent"));
    return value;
}
void GCBaseModelEntity::SetCRenderComponent(GCRenderComponent* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CRenderComponent' is not possible.\n");
}
GCHitboxComponent GCBaseModelEntity::GetCHitboxComponent() const {
    GCHitboxComponent value(GetSchemaPtr(m_ptr, "CBaseModelEntity", "m_CHitboxComponent"));
    return value;
}
void GCBaseModelEntity::SetCHitboxComponent(GCHitboxComponent value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_CHitboxComponent", false, value);
}
float GCBaseModelEntity::GetDissolveStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flDissolveStartTime");
}
void GCBaseModelEntity::SetDissolveStartTime(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flDissolveStartTime", false, value);
}
GCEntityIOOutput GCBaseModelEntity::GetOnIgnite() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseModelEntity", "m_OnIgnite"));
    return value;
}
void GCBaseModelEntity::SetOnIgnite(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_OnIgnite", false, value);
}
uint64_t GCBaseModelEntity::GetRenderMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseModelEntity", "m_nRenderMode");
}
void GCBaseModelEntity::SetRenderMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nRenderMode", false, value);
}
uint64_t GCBaseModelEntity::GetRenderFX() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseModelEntity", "m_nRenderFX");
}
void GCBaseModelEntity::SetRenderFX(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nRenderFX", false, value);
}
bool GCBaseModelEntity::GetAllowFadeInView() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseModelEntity", "m_bAllowFadeInView");
}
void GCBaseModelEntity::SetAllowFadeInView(bool value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_bAllowFadeInView", false, value);
}
Color GCBaseModelEntity::GetRender() const {
    return GetSchemaValue<Color>(m_ptr, "CBaseModelEntity", "m_clrRender");
}
void GCBaseModelEntity::SetRender(Color value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_clrRender", false, value);
}
std::vector<GEntityRenderAttribute_t> GCBaseModelEntity::GetRenderAttributes() const {
    CUtlVector<GEntityRenderAttribute_t>* vec = GetSchemaValue<CUtlVector<GEntityRenderAttribute_t>*>(m_ptr, "CBaseModelEntity", "m_vecRenderAttributes"); std::vector<GEntityRenderAttribute_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseModelEntity::SetRenderAttributes(std::vector<GEntityRenderAttribute_t> value) {
    SetSchemaValueCUtlVector<GEntityRenderAttribute_t>(m_ptr, "CBaseModelEntity", "m_vecRenderAttributes", false, value);
}
bool GCBaseModelEntity::GetRenderToCubemaps() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseModelEntity", "m_bRenderToCubemaps");
}
void GCBaseModelEntity::SetRenderToCubemaps(bool value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_bRenderToCubemaps", false, value);
}
GCCollisionProperty GCBaseModelEntity::GetCollision() const {
    GCCollisionProperty value(GetSchemaPtr(m_ptr, "CBaseModelEntity", "m_Collision"));
    return value;
}
void GCBaseModelEntity::SetCollision(GCCollisionProperty value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_Collision", false, value);
}
GCGlowProperty GCBaseModelEntity::GetGlow() const {
    GCGlowProperty value(GetSchemaPtr(m_ptr, "CBaseModelEntity", "m_Glow"));
    return value;
}
void GCBaseModelEntity::SetGlow(GCGlowProperty value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_Glow", false, value);
}
float GCBaseModelEntity::GetGlowBackfaceMult() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flGlowBackfaceMult");
}
void GCBaseModelEntity::SetGlowBackfaceMult(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flGlowBackfaceMult", false, value);
}
float GCBaseModelEntity::GetFadeMinDist() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_fadeMinDist");
}
void GCBaseModelEntity::SetFadeMinDist(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_fadeMinDist", false, value);
}
float GCBaseModelEntity::GetFadeMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_fadeMaxDist");
}
void GCBaseModelEntity::SetFadeMaxDist(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_fadeMaxDist", false, value);
}
float GCBaseModelEntity::GetFadeScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flFadeScale");
}
void GCBaseModelEntity::SetFadeScale(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flFadeScale", false, value);
}
float GCBaseModelEntity::GetShadowStrength() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flShadowStrength");
}
void GCBaseModelEntity::SetShadowStrength(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flShadowStrength", false, value);
}
uint8_t GCBaseModelEntity::GetObjectCulling() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBaseModelEntity", "m_nObjectCulling");
}
void GCBaseModelEntity::SetObjectCulling(uint8_t value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nObjectCulling", false, value);
}
int32_t GCBaseModelEntity::GetAddDecal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseModelEntity", "m_nAddDecal");
}
void GCBaseModelEntity::SetAddDecal(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nAddDecal", false, value);
}
Vector GCBaseModelEntity::GetDecalPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseModelEntity", "m_vDecalPosition");
}
void GCBaseModelEntity::SetDecalPosition(Vector value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vDecalPosition", false, value);
}
Vector GCBaseModelEntity::GetDecalForwardAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseModelEntity", "m_vDecalForwardAxis");
}
void GCBaseModelEntity::SetDecalForwardAxis(Vector value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vDecalForwardAxis", false, value);
}
float GCBaseModelEntity::GetDecalHealBloodRate() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flDecalHealBloodRate");
}
void GCBaseModelEntity::SetDecalHealBloodRate(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flDecalHealBloodRate", false, value);
}
float GCBaseModelEntity::GetDecalHealHeightRate() const {
    return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flDecalHealHeightRate");
}
void GCBaseModelEntity::SetDecalHealHeightRate(float value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flDecalHealHeightRate", false, value);
}
std::vector<GCBaseModelEntity*> GCBaseModelEntity::GetConfigEntitiesToPropagateMaterialDecalsTo() const {
    CUtlVector<GCBaseModelEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseModelEntity*>*>(m_ptr, "CBaseModelEntity", "m_ConfigEntitiesToPropagateMaterialDecalsTo"); std::vector<GCBaseModelEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseModelEntity::SetConfigEntitiesToPropagateMaterialDecalsTo(std::vector<GCBaseModelEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseModelEntity*>(m_ptr, "CBaseModelEntity", "m_ConfigEntitiesToPropagateMaterialDecalsTo", false, value);
}
GCNetworkViewOffsetVector GCBaseModelEntity::GetViewOffset() const {
    GCNetworkViewOffsetVector value(GetSchemaPtr(m_ptr, "CBaseModelEntity", "m_vecViewOffset"));
    return value;
}
void GCBaseModelEntity::SetViewOffset(GCNetworkViewOffsetVector value) {
    SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vecViewOffset", false, value);
}
std::string GCBaseModelEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseModelEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCBaseModelEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCBaseModelEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseModelEntity>("CBaseModelEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CRenderComponent", &GCBaseModelEntity::GetCRenderComponent, &GCBaseModelEntity::SetCRenderComponent)
        .addProperty("CHitboxComponent", &GCBaseModelEntity::GetCHitboxComponent, &GCBaseModelEntity::SetCHitboxComponent)
        .addProperty("DissolveStartTime", &GCBaseModelEntity::GetDissolveStartTime, &GCBaseModelEntity::SetDissolveStartTime)
        .addProperty("OnIgnite", &GCBaseModelEntity::GetOnIgnite, &GCBaseModelEntity::SetOnIgnite)
        .addProperty("RenderMode", &GCBaseModelEntity::GetRenderMode, &GCBaseModelEntity::SetRenderMode)
        .addProperty("RenderFX", &GCBaseModelEntity::GetRenderFX, &GCBaseModelEntity::SetRenderFX)
        .addProperty("AllowFadeInView", &GCBaseModelEntity::GetAllowFadeInView, &GCBaseModelEntity::SetAllowFadeInView)
        .addProperty("Render", &GCBaseModelEntity::GetRender, &GCBaseModelEntity::SetRender)
        .addProperty("RenderAttributes", &GCBaseModelEntity::GetRenderAttributes, &GCBaseModelEntity::SetRenderAttributes)
        .addProperty("RenderToCubemaps", &GCBaseModelEntity::GetRenderToCubemaps, &GCBaseModelEntity::SetRenderToCubemaps)
        .addProperty("Collision", &GCBaseModelEntity::GetCollision, &GCBaseModelEntity::SetCollision)
        .addProperty("Glow", &GCBaseModelEntity::GetGlow, &GCBaseModelEntity::SetGlow)
        .addProperty("GlowBackfaceMult", &GCBaseModelEntity::GetGlowBackfaceMult, &GCBaseModelEntity::SetGlowBackfaceMult)
        .addProperty("FadeMinDist", &GCBaseModelEntity::GetFadeMinDist, &GCBaseModelEntity::SetFadeMinDist)
        .addProperty("FadeMaxDist", &GCBaseModelEntity::GetFadeMaxDist, &GCBaseModelEntity::SetFadeMaxDist)
        .addProperty("FadeScale", &GCBaseModelEntity::GetFadeScale, &GCBaseModelEntity::SetFadeScale)
        .addProperty("ShadowStrength", &GCBaseModelEntity::GetShadowStrength, &GCBaseModelEntity::SetShadowStrength)
        .addProperty("ObjectCulling", &GCBaseModelEntity::GetObjectCulling, &GCBaseModelEntity::SetObjectCulling)
        .addProperty("AddDecal", &GCBaseModelEntity::GetAddDecal, &GCBaseModelEntity::SetAddDecal)
        .addProperty("DecalPosition", &GCBaseModelEntity::GetDecalPosition, &GCBaseModelEntity::SetDecalPosition)
        .addProperty("DecalForwardAxis", &GCBaseModelEntity::GetDecalForwardAxis, &GCBaseModelEntity::SetDecalForwardAxis)
        .addProperty("DecalHealBloodRate", &GCBaseModelEntity::GetDecalHealBloodRate, &GCBaseModelEntity::SetDecalHealBloodRate)
        .addProperty("DecalHealHeightRate", &GCBaseModelEntity::GetDecalHealHeightRate, &GCBaseModelEntity::SetDecalHealHeightRate)
        .addProperty("ConfigEntitiesToPropagateMaterialDecalsTo", &GCBaseModelEntity::GetConfigEntitiesToPropagateMaterialDecalsTo, &GCBaseModelEntity::SetConfigEntitiesToPropagateMaterialDecalsTo)
        .addProperty("ViewOffset", &GCBaseModelEntity::GetViewOffset, &GCBaseModelEntity::SetViewOffset)
        .addProperty("Parent", &GCBaseModelEntity::GetParent, &GCBaseModelEntity::SetParent)
        .addFunction("SetModel", &GCBaseModelEntity::SetModel)
        .addFunction("ToPtr", &GCBaseModelEntity::ToPtr)
        .addFunction("IsValid", &GCBaseModelEntity::IsValid)
        .endClass();
}