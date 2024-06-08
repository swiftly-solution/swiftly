class GVertexPositionNormal_t;

#ifndef _gcvertexpositionnormal_t_h
#define _gcvertexpositionnormal_t_h

#include "../../../scripting.h"




class GVertexPositionNormal_t
{
private:
    void *m_ptr;

public:
    GVertexPositionNormal_t() {}
    GVertexPositionNormal_t(void *ptr) : m_ptr(ptr) {}

    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "VertexPositionNormal_t", "m_vPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "VertexPositionNormal_t", "m_vPosition", true, value); }
    Vector GetNormal() const { return GetSchemaValue<Vector>(m_ptr, "VertexPositionNormal_t", "m_vNormal"); }
    void SetNormal(Vector value) { SetSchemaValue(m_ptr, "VertexPositionNormal_t", "m_vNormal", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif