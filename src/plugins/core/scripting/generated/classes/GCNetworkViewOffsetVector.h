class GCNetworkViewOffsetVector;

#ifndef _gccnetworkviewoffsetvector_h
#define _gccnetworkviewoffsetvector_h

#include "../../../scripting.h"




class GCNetworkViewOffsetVector
{
private:
    void *m_ptr;

public:
    GCNetworkViewOffsetVector() {}
    GCNetworkViewOffsetVector(void *ptr) : m_ptr(ptr) {}

    float GetX() const { return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecX"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecX", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecY"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecY", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecZ"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif