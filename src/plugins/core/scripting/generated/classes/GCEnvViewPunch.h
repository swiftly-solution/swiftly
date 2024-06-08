class GCEnvViewPunch;

#ifndef _gccenvviewpunch_h
#define _gccenvviewpunch_h

#include "../../../scripting.h"




class GCEnvViewPunch
{
private:
    void *m_ptr;

public:
    GCEnvViewPunch() {}
    GCEnvViewPunch(void *ptr) : m_ptr(ptr) {}

    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvViewPunch", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvViewPunch", "m_flRadius", false, value); }
    QAngle GetViewPunch() const { return GetSchemaValue<QAngle>(m_ptr, "CEnvViewPunch", "m_angViewPunch"); }
    void SetViewPunch(QAngle value) { SetSchemaValue(m_ptr, "CEnvViewPunch", "m_angViewPunch", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif