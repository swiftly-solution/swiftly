class GFeFitWeight_t;

#ifndef _gcfefitweight_t_h
#define _gcfefitweight_t_h

#include "../../../scripting.h"




class GFeFitWeight_t
{
private:
    void *m_ptr;

public:
    GFeFitWeight_t() {}
    GFeFitWeight_t(void *ptr) : m_ptr(ptr) {}

    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "FeFitWeight_t", "flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "FeFitWeight_t", "flWeight", true, value); }
    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFitWeight_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeFitWeight_t", "nNode", true, value); }
    uint16_t GetDummy() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFitWeight_t", "nDummy"); }
    void SetDummy(uint16_t value) { SetSchemaValue(m_ptr, "FeFitWeight_t", "nDummy", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif