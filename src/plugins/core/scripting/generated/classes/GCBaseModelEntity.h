class GCBaseModelEntity;

#ifndef _gccbasemodelentity_h
#define _gccbasemodelentity_h

#include "../../../scripting.h"


#include "GCRenderComponent.h"
#include "GCHitboxComponent.h"
#include "GCEntityIOOutput.h"
#include "GEntityRenderAttribute_t.h"
#include "GCCollisionProperty.h"
#include "GCGlowProperty.h"
#include "GCBaseModelEntity.h"
#include "GCNetworkViewOffsetVector.h"

class GCBaseModelEntity
{
private:
    void *m_ptr;

public:
    GCBaseModelEntity() {}
    GCBaseModelEntity(void *ptr) : m_ptr(ptr) {}

    GCRenderComponent* GetCRenderComponent() const { return GetSchemaValue<GCRenderComponent*>(m_ptr, "CBaseModelEntity", "m_CRenderComponent"); }
    void SetCRenderComponent(GCRenderComponent* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CRenderComponent' is not possible.\n"); }
    GCHitboxComponent GetCHitboxComponent() const { return GetSchemaValue<GCHitboxComponent>(m_ptr, "CBaseModelEntity", "m_CHitboxComponent"); }
    void SetCHitboxComponent(GCHitboxComponent value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_CHitboxComponent", false, value); }
    GCEntityIOOutput GetOnIgnite() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseModelEntity", "m_OnIgnite"); }
    void SetOnIgnite(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_OnIgnite", false, value); }
    RenderMode_t GetRenderMode() const { return GetSchemaValue<RenderMode_t>(m_ptr, "CBaseModelEntity", "m_nRenderMode"); }
    void SetRenderMode(RenderMode_t value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nRenderMode", false, value); }
    RenderFx_t GetRenderFX() const { return GetSchemaValue<RenderFx_t>(m_ptr, "CBaseModelEntity", "m_nRenderFX"); }
    void SetRenderFX(RenderFx_t value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nRenderFX", false, value); }
    bool GetAllowFadeInView() const { return GetSchemaValue<bool>(m_ptr, "CBaseModelEntity", "m_bAllowFadeInView"); }
    void SetAllowFadeInView(bool value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_bAllowFadeInView", false, value); }
    Color GetRender() const { return GetSchemaValue<Color>(m_ptr, "CBaseModelEntity", "m_clrRender"); }
    void SetRender(Color value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_clrRender", false, value); }
    std::vector<GEntityRenderAttribute_t> GetRenderAttributes() const { CUtlVector<GEntityRenderAttribute_t>* vec = GetSchemaValue<CUtlVector<GEntityRenderAttribute_t>*>(m_ptr, "CBaseModelEntity", "m_vecRenderAttributes"); std::vector<GEntityRenderAttribute_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRenderAttributes(std::vector<GEntityRenderAttribute_t> value) { SetSchemaValueCUtlVector<GEntityRenderAttribute_t>(m_ptr, "CBaseModelEntity", "m_vecRenderAttributes", false, value); }
    bool GetRenderToCubemaps() const { return GetSchemaValue<bool>(m_ptr, "CBaseModelEntity", "m_bRenderToCubemaps"); }
    void SetRenderToCubemaps(bool value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_bRenderToCubemaps", false, value); }
    GCCollisionProperty GetCollision() const { return GetSchemaValue<GCCollisionProperty>(m_ptr, "CBaseModelEntity", "m_Collision"); }
    void SetCollision(GCCollisionProperty value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_Collision", false, value); }
    GCGlowProperty GetGlow() const { return GetSchemaValue<GCGlowProperty>(m_ptr, "CBaseModelEntity", "m_Glow"); }
    void SetGlow(GCGlowProperty value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_Glow", false, value); }
    float GetGlowBackfaceMult() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flGlowBackfaceMult"); }
    void SetGlowBackfaceMult(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flGlowBackfaceMult", false, value); }
    float GetFadeMinDist() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_fadeMinDist"); }
    void SetFadeMinDist(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_fadeMinDist", false, value); }
    float GetFadeMaxDist() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_fadeMaxDist"); }
    void SetFadeMaxDist(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_fadeMaxDist", false, value); }
    float GetFadeScale() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flFadeScale"); }
    void SetFadeScale(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flFadeScale", false, value); }
    float GetShadowStrength() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flShadowStrength"); }
    void SetShadowStrength(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flShadowStrength", false, value); }
    uint8_t GetObjectCulling() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseModelEntity", "m_nObjectCulling"); }
    void SetObjectCulling(uint8_t value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nObjectCulling", false, value); }
    int32_t GetAddDecal() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseModelEntity", "m_nAddDecal"); }
    void SetAddDecal(int32_t value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_nAddDecal", false, value); }
    Vector GetDecalPosition() const { return GetSchemaValue<Vector>(m_ptr, "CBaseModelEntity", "m_vDecalPosition"); }
    void SetDecalPosition(Vector value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vDecalPosition", false, value); }
    Vector GetDecalForwardAxis() const { return GetSchemaValue<Vector>(m_ptr, "CBaseModelEntity", "m_vDecalForwardAxis"); }
    void SetDecalForwardAxis(Vector value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vDecalForwardAxis", false, value); }
    float GetDecalHealBloodRate() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flDecalHealBloodRate"); }
    void SetDecalHealBloodRate(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flDecalHealBloodRate", false, value); }
    float GetDecalHealHeightRate() const { return GetSchemaValue<float>(m_ptr, "CBaseModelEntity", "m_flDecalHealHeightRate"); }
    void SetDecalHealHeightRate(float value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_flDecalHealHeightRate", false, value); }
    GCBaseModelEntity* GetConfigEntitiesToPropagateMaterialDecalsTo() const { return GetSchemaValue<GCBaseModelEntity*>(m_ptr, "CBaseModelEntity", "m_ConfigEntitiesToPropagateMaterialDecalsTo"); }
    void SetConfigEntitiesToPropagateMaterialDecalsTo(GCBaseModelEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ConfigEntitiesToPropagateMaterialDecalsTo' is not possible.\n"); }
    GCNetworkViewOffsetVector GetViewOffset() const { return GetSchemaValue<GCNetworkViewOffsetVector>(m_ptr, "CBaseModelEntity", "m_vecViewOffset"); }
    void SetViewOffset(GCNetworkViewOffsetVector value) { SetSchemaValue(m_ptr, "CBaseModelEntity", "m_vecViewOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif