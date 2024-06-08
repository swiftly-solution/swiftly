class GFeFitInfluence_t;

#ifndef _gcfefitinfluence_t_h
#define _gcfefitinfluence_t_h

#include "../../../scripting.h"




class GFeFitInfluence_t
{
private:
    void *m_ptr;

public:
    GFeFitInfluence_t() {}
    GFeFitInfluence_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetVertexNode() const { return GetSchemaValue<uint32_t>(m_ptr, "FeFitInfluence_t", "nVertexNode"); }
    void SetVertexNode(uint32_t value) { SetSchemaValue(m_ptr, "FeFitInfluence_t", "nVertexNode", true, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "FeFitInfluence_t", "flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "FeFitInfluence_t", "flWeight", true, value); }
    uint32_t GetMatrixNode() const { return GetSchemaValue<uint32_t>(m_ptr, "FeFitInfluence_t", "nMatrixNode"); }
    void SetMatrixNode(uint32_t value) { SetSchemaValue(m_ptr, "FeFitInfluence_t", "nMatrixNode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif