class GCNetworkVelocityVector;

#ifndef _gccnetworkvelocityvector_h
#define _gccnetworkvelocityvector_h

#include "../../../scripting.h"




class GCNetworkVelocityVector
{
private:
    void *m_ptr;

public:
    GCNetworkVelocityVector() {}
    GCNetworkVelocityVector(void *ptr) : m_ptr(ptr) {}

    float GetX() const { return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecX"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecX", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecY"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecY", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecZ"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif