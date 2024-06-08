class GPermModelInfo_t;

#ifndef _gcpermmodelinfo_t_h
#define _gcpermmodelinfo_t_h

#include "../../../scripting.h"




class GPermModelInfo_t
{
private:
    void *m_ptr;

public:
    GPermModelInfo_t() {}
    GPermModelInfo_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "PermModelInfo_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_nFlags", true, value); }
    Vector GetHullMin() const { return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vHullMin"); }
    void SetHullMin(Vector value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vHullMin", true, value); }
    Vector GetHullMax() const { return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vHullMax"); }
    void SetHullMax(Vector value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vHullMax", true, value); }
    Vector GetViewMin() const { return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vViewMin"); }
    void SetViewMin(Vector value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vViewMin", true, value); }
    Vector GetViewMax() const { return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vViewMax"); }
    void SetViewMax(Vector value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vViewMax", true, value); }
    float GetMass() const { return GetSchemaValue<float>(m_ptr, "PermModelInfo_t", "m_flMass"); }
    void SetMass(float value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_flMass", true, value); }
    Vector GetEyePosition() const { return GetSchemaValue<Vector>(m_ptr, "PermModelInfo_t", "m_vEyePosition"); }
    void SetEyePosition(Vector value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_vEyePosition", true, value); }
    float GetMaxEyeDeflection() const { return GetSchemaValue<float>(m_ptr, "PermModelInfo_t", "m_flMaxEyeDeflection"); }
    void SetMaxEyeDeflection(float value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_flMaxEyeDeflection", true, value); }
    CUtlString GetSurfaceProperty() const { return GetSchemaValue<CUtlString>(m_ptr, "PermModelInfo_t", "m_sSurfaceProperty"); }
    void SetSurfaceProperty(CUtlString value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_sSurfaceProperty", true, value); }
    CUtlString GetKeyValueText() const { return GetSchemaValue<CUtlString>(m_ptr, "PermModelInfo_t", "m_keyValueText"); }
    void SetKeyValueText(CUtlString value) { SetSchemaValue(m_ptr, "PermModelInfo_t", "m_keyValueText", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif