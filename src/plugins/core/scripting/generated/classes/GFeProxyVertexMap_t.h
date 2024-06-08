class GFeProxyVertexMap_t;

#ifndef _gcfeproxyvertexmap_t_h
#define _gcfeproxyvertexmap_t_h

#include "../../../scripting.h"




class GFeProxyVertexMap_t
{
private:
    void *m_ptr;

public:
    GFeProxyVertexMap_t() {}
    GFeProxyVertexMap_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "FeProxyVertexMap_t", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "FeProxyVertexMap_t", "m_Name", true, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "FeProxyVertexMap_t", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "FeProxyVertexMap_t", "m_flWeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif