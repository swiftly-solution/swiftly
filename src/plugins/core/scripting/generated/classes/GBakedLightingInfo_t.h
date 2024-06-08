class GBakedLightingInfo_t;

#ifndef _gcbakedlightinginfo_t_h
#define _gcbakedlightinginfo_t_h

#include "../../../scripting.h"




class GBakedLightingInfo_t
{
private:
    void *m_ptr;

public:
    GBakedLightingInfo_t() {}
    GBakedLightingInfo_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetLightmapVersionNumber() const { return GetSchemaValue<uint32_t>(m_ptr, "BakedLightingInfo_t", "m_nLightmapVersionNumber"); }
    void SetLightmapVersionNumber(uint32_t value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nLightmapVersionNumber", true, value); }
    uint32_t GetLightmapGameVersionNumber() const { return GetSchemaValue<uint32_t>(m_ptr, "BakedLightingInfo_t", "m_nLightmapGameVersionNumber"); }
    void SetLightmapGameVersionNumber(uint32_t value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nLightmapGameVersionNumber", true, value); }
    Vector2D GetLightmapUvScale() const { return GetSchemaValue<Vector2D>(m_ptr, "BakedLightingInfo_t", "m_vLightmapUvScale"); }
    void SetLightmapUvScale(Vector2D value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_vLightmapUvScale", true, value); }
    bool GetHasLightmaps() const { return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bHasLightmaps"); }
    void SetHasLightmaps(bool value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bHasLightmaps", true, value); }
    bool GetBakedShadowsGamma20() const { return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bBakedShadowsGamma20"); }
    void SetBakedShadowsGamma20(bool value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bBakedShadowsGamma20", true, value); }
    bool GetCompressionEnabled() const { return GetSchemaValue<bool>(m_ptr, "BakedLightingInfo_t", "m_bCompressionEnabled"); }
    void SetCompressionEnabled(bool value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_bCompressionEnabled", true, value); }
    uint8_t GetChartPackIterations() const { return GetSchemaValue<uint8_t>(m_ptr, "BakedLightingInfo_t", "m_nChartPackIterations"); }
    void SetChartPackIterations(uint8_t value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nChartPackIterations", true, value); }
    uint8_t GetVradQuality() const { return GetSchemaValue<uint8_t>(m_ptr, "BakedLightingInfo_t", "m_nVradQuality"); }
    void SetVradQuality(uint8_t value) { SetSchemaValue(m_ptr, "BakedLightingInfo_t", "m_nVradQuality", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif