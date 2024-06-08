class GCEnvCubemap;

#ifndef _gccenvcubemap_h
#define _gccenvcubemap_h

#include "../../../scripting.h"




class GCEnvCubemap
{
private:
    void *m_ptr;

public:
    GCEnvCubemap() {}
    GCEnvCubemap(void *ptr) : m_ptr(ptr) {}

    bool GetEntity_bCustomCubemapTexture() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bCustomCubemapTexture"); }
    void SetEntity_bCustomCubemapTexture(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bCustomCubemapTexture", false, value); }
    float GetEntity_flInfluenceRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flInfluenceRadius"); }
    void SetEntity_flInfluenceRadius(float value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flInfluenceRadius", false, value); }
    Vector GetEntity_vBoxProjectMins() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMins"); }
    void SetEntity_vBoxProjectMins(Vector value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMins", false, value); }
    Vector GetEntity_vBoxProjectMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMaxs"); }
    void SetEntity_vBoxProjectMaxs(Vector value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMaxs", false, value); }
    bool GetEntity_bMoveable() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bMoveable"); }
    void SetEntity_bMoveable(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bMoveable", false, value); }
    int32_t GetEntity_nHandshake() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nHandshake"); }
    void SetEntity_nHandshake(int32_t value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nHandshake", false, value); }
    int32_t GetEntity_nEnvCubeMapArrayIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nEnvCubeMapArrayIndex"); }
    void SetEntity_nEnvCubeMapArrayIndex(int32_t value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nEnvCubeMapArrayIndex", false, value); }
    int32_t GetEntity_nPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nPriority"); }
    void SetEntity_nPriority(int32_t value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nPriority", false, value); }
    float GetEntity_flEdgeFadeDist() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flEdgeFadeDist"); }
    void SetEntity_flEdgeFadeDist(float value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flEdgeFadeDist", false, value); }
    Vector GetEntity_vEdgeFadeDists() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vEdgeFadeDists"); }
    void SetEntity_vEdgeFadeDists(Vector value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vEdgeFadeDists", false, value); }
    float GetEntity_flDiffuseScale() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flDiffuseScale"); }
    void SetEntity_flDiffuseScale(float value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flDiffuseScale", false, value); }
    bool GetEntity_bStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bStartDisabled"); }
    void SetEntity_bStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bStartDisabled", false, value); }
    bool GetEntity_bDefaultEnvMap() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bDefaultEnvMap"); }
    void SetEntity_bDefaultEnvMap(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bDefaultEnvMap", false, value); }
    bool GetEntity_bDefaultSpecEnvMap() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bDefaultSpecEnvMap"); }
    void SetEntity_bDefaultSpecEnvMap(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bDefaultSpecEnvMap", false, value); }
    bool GetEntity_bIndoorCubeMap() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bIndoorCubeMap"); }
    void SetEntity_bIndoorCubeMap(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bIndoorCubeMap", false, value); }
    bool GetEntity_bCopyDiffuseFromDefaultCubemap() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bCopyDiffuseFromDefaultCubemap"); }
    void SetEntity_bCopyDiffuseFromDefaultCubemap(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bCopyDiffuseFromDefaultCubemap", false, value); }
    bool GetEntity_bEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bEnabled"); }
    void SetEntity_bEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif