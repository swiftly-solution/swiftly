class GCEnvDecal;

#ifndef _gccenvdecal_h
#define _gccenvdecal_h

#include "../../../scripting.h"




class GCEnvDecal
{
private:
    void *m_ptr;

public:
    GCEnvDecal() {}
    GCEnvDecal(void *ptr) : m_ptr(ptr) {}

    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_flWidth", false, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flHeight"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_flHeight", false, value); }
    float GetDepth() const { return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flDepth"); }
    void SetDepth(float value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_flDepth", false, value); }
    uint32_t GetRenderOrder() const { return GetSchemaValue<uint32_t>(m_ptr, "CEnvDecal", "m_nRenderOrder"); }
    void SetRenderOrder(uint32_t value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_nRenderOrder", false, value); }
    bool GetProjectOnWorld() const { return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnWorld"); }
    void SetProjectOnWorld(bool value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnWorld", false, value); }
    bool GetProjectOnCharacters() const { return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnCharacters"); }
    void SetProjectOnCharacters(bool value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnCharacters", false, value); }
    bool GetProjectOnWater() const { return GetSchemaValue<bool>(m_ptr, "CEnvDecal", "m_bProjectOnWater"); }
    void SetProjectOnWater(bool value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_bProjectOnWater", false, value); }
    float GetDepthSortBias() const { return GetSchemaValue<float>(m_ptr, "CEnvDecal", "m_flDepthSortBias"); }
    void SetDepthSortBias(float value) { SetSchemaValue(m_ptr, "CEnvDecal", "m_flDepthSortBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif