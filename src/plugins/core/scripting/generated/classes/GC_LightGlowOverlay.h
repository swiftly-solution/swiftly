class GC_LightGlowOverlay;

#ifndef _gcc_lightglowoverlay_h
#define _gcc_lightglowoverlay_h

#include "../../../scripting.h"




class GC_LightGlowOverlay
{
private:
    void *m_ptr;

public:
    GC_LightGlowOverlay() {}
    GC_LightGlowOverlay(void *ptr) : m_ptr(ptr) {}

    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "C_LightGlowOverlay", "m_vecOrigin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_vecOrigin", false, value); }
    Vector GetDirection() const { return GetSchemaValue<Vector>(m_ptr, "C_LightGlowOverlay", "m_vecDirection"); }
    void SetDirection(Vector value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_vecDirection", false, value); }
    int32_t GetMinDist() const { return GetSchemaValue<int32_t>(m_ptr, "C_LightGlowOverlay", "m_nMinDist"); }
    void SetMinDist(int32_t value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_nMinDist", false, value); }
    int32_t GetMaxDist() const { return GetSchemaValue<int32_t>(m_ptr, "C_LightGlowOverlay", "m_nMaxDist"); }
    void SetMaxDist(int32_t value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_nMaxDist", false, value); }
    int32_t GetOuterMaxDist() const { return GetSchemaValue<int32_t>(m_ptr, "C_LightGlowOverlay", "m_nOuterMaxDist"); }
    void SetOuterMaxDist(int32_t value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_nOuterMaxDist", false, value); }
    bool GetOneSided() const { return GetSchemaValue<bool>(m_ptr, "C_LightGlowOverlay", "m_bOneSided"); }
    void SetOneSided(bool value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_bOneSided", false, value); }
    bool GetModulateByDot() const { return GetSchemaValue<bool>(m_ptr, "C_LightGlowOverlay", "m_bModulateByDot"); }
    void SetModulateByDot(bool value) { SetSchemaValue(m_ptr, "C_LightGlowOverlay", "m_bModulateByDot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif