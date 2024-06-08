class GCPhysPulley;

#ifndef _gccphyspulley_h
#define _gccphyspulley_h

#include "../../../scripting.h"




class GCPhysPulley
{
private:
    void *m_ptr;

public:
    GCPhysPulley() {}
    GCPhysPulley(void *ptr) : m_ptr(ptr) {}

    Vector GetPosition2() const { return GetSchemaValue<Vector>(m_ptr, "CPhysPulley", "m_position2"); }
    void SetPosition2(Vector value) { SetSchemaValue(m_ptr, "CPhysPulley", "m_position2", false, value); }
    std::vector<Vector> GetOffset() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysPulley", "m_offset"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOffset(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysPulley", "m_offset"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPhysPulley", "m_offset", false, outValue); }
    float GetAddLength() const { return GetSchemaValue<float>(m_ptr, "CPhysPulley", "m_addLength"); }
    void SetAddLength(float value) { SetSchemaValue(m_ptr, "CPhysPulley", "m_addLength", false, value); }
    float GetGearRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysPulley", "m_gearRatio"); }
    void SetGearRatio(float value) { SetSchemaValue(m_ptr, "CPhysPulley", "m_gearRatio", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif