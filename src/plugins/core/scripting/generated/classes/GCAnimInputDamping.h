class GCAnimInputDamping;

#ifndef _gccaniminputdamping_h
#define _gccaniminputdamping_h

#include "../../../scripting.h"

#include "../types/GDampingSpeedFunction.h"


class GCAnimInputDamping
{
private:
    void *m_ptr;

public:
    GCAnimInputDamping() {}
    GCAnimInputDamping(void *ptr) : m_ptr(ptr) {}

    DampingSpeedFunction GetSpeedFunction() const { return GetSchemaValue<DampingSpeedFunction>(m_ptr, "CAnimInputDamping", "m_speedFunction"); }
    void SetSpeedFunction(DampingSpeedFunction value) { SetSchemaValue(m_ptr, "CAnimInputDamping", "m_speedFunction", false, value); }
    float GetSpeedScale() const { return GetSchemaValue<float>(m_ptr, "CAnimInputDamping", "m_fSpeedScale"); }
    void SetSpeedScale(float value) { SetSchemaValue(m_ptr, "CAnimInputDamping", "m_fSpeedScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif