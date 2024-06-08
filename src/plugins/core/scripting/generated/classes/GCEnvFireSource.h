class GCEnvFireSource;

#ifndef _gccenvfiresource_h
#define _gccenvfiresource_h

#include "../../../scripting.h"




class GCEnvFireSource
{
private:
    void *m_ptr;

public:
    GCEnvFireSource() {}
    GCEnvFireSource(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvFireSource", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvFireSource", "m_bEnabled", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSource", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvFireSource", "m_radius", false, value); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSource", "m_damage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CEnvFireSource", "m_damage", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif