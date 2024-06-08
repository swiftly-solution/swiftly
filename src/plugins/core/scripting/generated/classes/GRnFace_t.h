class GRnFace_t;

#ifndef _gcrnface_t_h
#define _gcrnface_t_h

#include "../../../scripting.h"




class GRnFace_t
{
private:
    void *m_ptr;

public:
    GRnFace_t() {}
    GRnFace_t(void *ptr) : m_ptr(ptr) {}

    uint8_t GetEdge() const { return GetSchemaValue<uint8_t>(m_ptr, "RnFace_t", "m_nEdge"); }
    void SetEdge(uint8_t value) { SetSchemaValue(m_ptr, "RnFace_t", "m_nEdge", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif