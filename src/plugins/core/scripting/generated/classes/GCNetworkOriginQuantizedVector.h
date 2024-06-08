class GCNetworkOriginQuantizedVector;

#ifndef _gccnetworkoriginquantizedvector_h
#define _gccnetworkoriginquantizedvector_h

#include "../../../scripting.h"




class GCNetworkOriginQuantizedVector
{
private:
    void *m_ptr;

public:
    GCNetworkOriginQuantizedVector() {}
    GCNetworkOriginQuantizedVector(void *ptr) : m_ptr(ptr) {}

    float GetX() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecX"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecX", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecY"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecY", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecZ"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif