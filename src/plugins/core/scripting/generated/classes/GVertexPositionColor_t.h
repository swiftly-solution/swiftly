class GVertexPositionColor_t;

#ifndef _gcvertexpositioncolor_t_h
#define _gcvertexpositioncolor_t_h

#include "../../../scripting.h"




class GVertexPositionColor_t
{
private:
    void *m_ptr;

public:
    GVertexPositionColor_t() {}
    GVertexPositionColor_t(void *ptr) : m_ptr(ptr) {}

    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "VertexPositionColor_t", "m_vPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "VertexPositionColor_t", "m_vPosition", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif