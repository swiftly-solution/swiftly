class GCLightGlow;

#ifndef _gcclightglow_h
#define _gcclightglow_h

#include "../../../scripting.h"




class GCLightGlow
{
private:
    void *m_ptr;

public:
    GCLightGlow() {}
    GCLightGlow(void *ptr) : m_ptr(ptr) {}

    uint32_t GetHorizontalSize() const { return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nHorizontalSize"); }
    void SetHorizontalSize(uint32_t value) { SetSchemaValue(m_ptr, "CLightGlow", "m_nHorizontalSize", false, value); }
    uint32_t GetVerticalSize() const { return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nVerticalSize"); }
    void SetVerticalSize(uint32_t value) { SetSchemaValue(m_ptr, "CLightGlow", "m_nVerticalSize", false, value); }
    uint32_t GetMinDist() const { return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nMinDist"); }
    void SetMinDist(uint32_t value) { SetSchemaValue(m_ptr, "CLightGlow", "m_nMinDist", false, value); }
    uint32_t GetMaxDist() const { return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nMaxDist"); }
    void SetMaxDist(uint32_t value) { SetSchemaValue(m_ptr, "CLightGlow", "m_nMaxDist", false, value); }
    uint32_t GetOuterMaxDist() const { return GetSchemaValue<uint32_t>(m_ptr, "CLightGlow", "m_nOuterMaxDist"); }
    void SetOuterMaxDist(uint32_t value) { SetSchemaValue(m_ptr, "CLightGlow", "m_nOuterMaxDist", false, value); }
    float GetGlowProxySize() const { return GetSchemaValue<float>(m_ptr, "CLightGlow", "m_flGlowProxySize"); }
    void SetGlowProxySize(float value) { SetSchemaValue(m_ptr, "CLightGlow", "m_flGlowProxySize", false, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "CLightGlow", "m_flHDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "CLightGlow", "m_flHDRColorScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif