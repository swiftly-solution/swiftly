class GRnCapsule_t;

#ifndef _gcrncapsule_t_h
#define _gcrncapsule_t_h

#include "../../../scripting.h"




class GRnCapsule_t
{
private:
    void *m_ptr;

public:
    GRnCapsule_t() {}
    GRnCapsule_t(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetCenter() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnCapsule_t", "m_vCenter"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetCenter(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnCapsule_t", "m_vCenter"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnCapsule_t", "m_vCenter", true, outValue); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "RnCapsule_t", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "RnCapsule_t", "m_flRadius", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif