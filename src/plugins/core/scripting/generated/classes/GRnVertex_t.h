class GRnVertex_t;

#ifndef _gcrnvertex_t_h
#define _gcrnvertex_t_h

#include "../../../scripting.h"




class GRnVertex_t
{
private:
    void *m_ptr;

public:
    GRnVertex_t() {}
    GRnVertex_t(void *ptr) : m_ptr(ptr) {}

    uint8_t GetEdge() const { return GetSchemaValue<uint8_t>(m_ptr, "RnVertex_t", "m_nEdge"); }
    void SetEdge(uint8_t value) { SetSchemaValue(m_ptr, "RnVertex_t", "m_nEdge", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif