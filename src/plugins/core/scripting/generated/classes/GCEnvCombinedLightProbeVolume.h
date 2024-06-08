class GCEnvCombinedLightProbeVolume;

#ifndef _gccenvcombinedlightprobevolume_h
#define _gccenvcombinedlightprobevolume_h

#include "../../../scripting.h"




class GCEnvCombinedLightProbeVolume
{
private:
    void *m_ptr;

public:
    GCEnvCombinedLightProbeVolume() {}
    GCEnvCombinedLightProbeVolume(void *ptr) : m_ptr(ptr) {}

    Color GetEntity_Color() const { return GetSchemaValue<Color>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_Color"); }
    void SetEntity_Color(Color value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_Color", false, value); }
    float GetEntity_flBrightness() const { return GetSchemaValue<float>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flBrightness"); }
    void SetEntity_flBrightness(float value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flBrightness", false, value); }
    bool GetEntity_bCustomCubemapTexture() const { return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bCustomCubemapTexture"); }
    void SetEntity_bCustomCubemapTexture(bool value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bCustomCubemapTexture", false, value); }
    Vector GetEntity_vBoxMins() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMins"); }
    void SetEntity_vBoxMins(Vector value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMins", false, value); }
    Vector GetEntity_vBoxMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMaxs"); }
    void SetEntity_vBoxMaxs(Vector value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMaxs", false, value); }
    bool GetEntity_bMoveable() const { return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bMoveable"); }
    void SetEntity_bMoveable(bool value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bMoveable", false, value); }
    int32_t GetEntity_nHandshake() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nHandshake"); }
    void SetEntity_nHandshake(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nHandshake", false, value); }
    int32_t GetEntity_nEnvCubeMapArrayIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nEnvCubeMapArrayIndex"); }
    void SetEntity_nEnvCubeMapArrayIndex(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nEnvCubeMapArrayIndex", false, value); }
    int32_t GetEntity_nPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nPriority"); }
    void SetEntity_nPriority(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nPriority", false, value); }
    bool GetEntity_bStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bStartDisabled"); }
    void SetEntity_bStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bStartDisabled", false, value); }
    float GetEntity_flEdgeFadeDist() const { return GetSchemaValue<float>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flEdgeFadeDist"); }
    void SetEntity_flEdgeFadeDist(float value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flEdgeFadeDist", false, value); }
    Vector GetEntity_vEdgeFadeDists() const { return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vEdgeFadeDists"); }
    void SetEntity_vEdgeFadeDists(Vector value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vEdgeFadeDists", false, value); }
    int32_t GetEntity_nLightProbeSizeX() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeX"); }
    void SetEntity_nLightProbeSizeX(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeX", false, value); }
    int32_t GetEntity_nLightProbeSizeY() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeY"); }
    void SetEntity_nLightProbeSizeY(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeY", false, value); }
    int32_t GetEntity_nLightProbeSizeZ() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeZ"); }
    void SetEntity_nLightProbeSizeZ(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeZ", false, value); }
    int32_t GetEntity_nLightProbeAtlasX() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasX"); }
    void SetEntity_nLightProbeAtlasX(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasX", false, value); }
    int32_t GetEntity_nLightProbeAtlasY() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasY"); }
    void SetEntity_nLightProbeAtlasY(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasY", false, value); }
    int32_t GetEntity_nLightProbeAtlasZ() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasZ"); }
    void SetEntity_nLightProbeAtlasZ(int32_t value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasZ", false, value); }
    bool GetEntity_bEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bEnabled"); }
    void SetEntity_bEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif