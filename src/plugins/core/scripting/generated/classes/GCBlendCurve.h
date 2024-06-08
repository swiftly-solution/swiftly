class GCBlendCurve;

#ifndef _gccblendcurve_h
#define _gccblendcurve_h

#include "../../../scripting.h"




class GCBlendCurve
{
private:
    void *m_ptr;

public:
    GCBlendCurve() {}
    GCBlendCurve(void *ptr) : m_ptr(ptr) {}

    float GetControlPoint1() const { return GetSchemaValue<float>(m_ptr, "CBlendCurve", "m_flControlPoint1"); }
    void SetControlPoint1(float value) { SetSchemaValue(m_ptr, "CBlendCurve", "m_flControlPoint1", false, value); }
    float GetControlPoint2() const { return GetSchemaValue<float>(m_ptr, "CBlendCurve", "m_flControlPoint2"); }
    void SetControlPoint2(float value) { SetSchemaValue(m_ptr, "CBlendCurve", "m_flControlPoint2", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif