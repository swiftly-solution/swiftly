class GSceneObject_t;

#ifndef _gcsceneobject_t_h
#define _gcsceneobject_t_h

#include "../../../scripting.h"

#include "../types/GObjectTypeFlags_t.h"


class GSceneObject_t
{
private:
    void *m_ptr;

public:
    GSceneObject_t() {}
    GSceneObject_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetObjectID() const { return GetSchemaValue<uint32_t>(m_ptr, "SceneObject_t", "m_nObjectID"); }
    void SetObjectID(uint32_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nObjectID", true, value); }
    std::vector<Vector4D> GetTransform() const { Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "SceneObject_t", "m_vTransform"); std::vector<Vector4D> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTransform(std::vector<Vector4D> value) { Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "SceneObject_t", "m_vTransform"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SceneObject_t", "m_vTransform", true, outValue); }
    float GetFadeStartDistance() const { return GetSchemaValue<float>(m_ptr, "SceneObject_t", "m_flFadeStartDistance"); }
    void SetFadeStartDistance(float value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_flFadeStartDistance", true, value); }
    float GetFadeEndDistance() const { return GetSchemaValue<float>(m_ptr, "SceneObject_t", "m_flFadeEndDistance"); }
    void SetFadeEndDistance(float value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_flFadeEndDistance", true, value); }
    Vector4D GetTintColor() const { return GetSchemaValue<Vector4D>(m_ptr, "SceneObject_t", "m_vTintColor"); }
    void SetTintColor(Vector4D value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_vTintColor", true, value); }
    CUtlString GetSkin() const { return GetSchemaValue<CUtlString>(m_ptr, "SceneObject_t", "m_skin"); }
    void SetSkin(CUtlString value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_skin", true, value); }
    ObjectTypeFlags_t GetObjectTypeFlags() const { return GetSchemaValue<ObjectTypeFlags_t>(m_ptr, "SceneObject_t", "m_nObjectTypeFlags"); }
    void SetObjectTypeFlags(ObjectTypeFlags_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nObjectTypeFlags", true, value); }
    Vector GetLightingOrigin() const { return GetSchemaValue<Vector>(m_ptr, "SceneObject_t", "m_vLightingOrigin"); }
    void SetLightingOrigin(Vector value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_vLightingOrigin", true, value); }
    int16_t GetOverlayRenderOrder() const { return GetSchemaValue<int16_t>(m_ptr, "SceneObject_t", "m_nOverlayRenderOrder"); }
    void SetOverlayRenderOrder(int16_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nOverlayRenderOrder", true, value); }
    int16_t GetLODOverride() const { return GetSchemaValue<int16_t>(m_ptr, "SceneObject_t", "m_nLODOverride"); }
    void SetLODOverride(int16_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nLODOverride", true, value); }
    int32_t GetCubeMapPrecomputedHandshake() const { return GetSchemaValue<int32_t>(m_ptr, "SceneObject_t", "m_nCubeMapPrecomputedHandshake"); }
    void SetCubeMapPrecomputedHandshake(int32_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nCubeMapPrecomputedHandshake", true, value); }
    int32_t GetLightProbeVolumePrecomputedHandshake() const { return GetSchemaValue<int32_t>(m_ptr, "SceneObject_t", "m_nLightProbeVolumePrecomputedHandshake"); }
    void SetLightProbeVolumePrecomputedHandshake(int32_t value) { SetSchemaValue(m_ptr, "SceneObject_t", "m_nLightProbeVolumePrecomputedHandshake", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif