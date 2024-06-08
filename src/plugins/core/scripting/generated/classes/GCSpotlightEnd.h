class GCSpotlightEnd;

#ifndef _gccspotlightend_h
#define _gccspotlightend_h

#include "../../../scripting.h"




class GCSpotlightEnd
{
private:
    void *m_ptr;

public:
    GCSpotlightEnd() {}
    GCSpotlightEnd(void *ptr) : m_ptr(ptr) {}

    float GetLightScale() const { return GetSchemaValue<float>(m_ptr, "CSpotlightEnd", "m_flLightScale"); }
    void SetLightScale(float value) { SetSchemaValue(m_ptr, "CSpotlightEnd", "m_flLightScale", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CSpotlightEnd", "m_Radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CSpotlightEnd", "m_Radius", false, value); }
    Vector GetSpotlightDir() const { return GetSchemaValue<Vector>(m_ptr, "CSpotlightEnd", "m_vSpotlightDir"); }
    void SetSpotlightDir(Vector value) { SetSchemaValue(m_ptr, "CSpotlightEnd", "m_vSpotlightDir", false, value); }
    Vector GetSpotlightOrg() const { return GetSchemaValue<Vector>(m_ptr, "CSpotlightEnd", "m_vSpotlightOrg"); }
    void SetSpotlightOrg(Vector value) { SetSchemaValue(m_ptr, "CSpotlightEnd", "m_vSpotlightOrg", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif