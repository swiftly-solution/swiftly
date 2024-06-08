class GFeFitMatrix_t;

#ifndef _gcfefitmatrix_t_h
#define _gcfefitmatrix_t_h

#include "../../../scripting.h"




class GFeFitMatrix_t
{
private:
    void *m_ptr;

public:
    GFeFitMatrix_t() {}
    GFeFitMatrix_t(void *ptr) : m_ptr(ptr) {}

    Vector GetCenter() const { return GetSchemaValue<Vector>(m_ptr, "FeFitMatrix_t", "vCenter"); }
    void SetCenter(Vector value) { SetSchemaValue(m_ptr, "FeFitMatrix_t", "vCenter", true, value); }
    uint16_t GetEnd() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nEnd"); }
    void SetEnd(uint16_t value) { SetSchemaValue(m_ptr, "FeFitMatrix_t", "nEnd", true, value); }
    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeFitMatrix_t", "nNode", true, value); }
    uint16_t GetBeginDynamic() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nBeginDynamic"); }
    void SetBeginDynamic(uint16_t value) { SetSchemaValue(m_ptr, "FeFitMatrix_t", "nBeginDynamic", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif