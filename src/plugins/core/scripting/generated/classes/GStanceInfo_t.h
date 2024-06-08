class GStanceInfo_t;

#ifndef _gcstanceinfo_t_h
#define _gcstanceinfo_t_h

#include "../../../scripting.h"




class GStanceInfo_t
{
private:
    void *m_ptr;

public:
    GStanceInfo_t() {}
    GStanceInfo_t(void *ptr) : m_ptr(ptr) {}

    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "StanceInfo_t", "m_vPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "StanceInfo_t", "m_vPosition", true, value); }
    float GetDirection() const { return GetSchemaValue<float>(m_ptr, "StanceInfo_t", "m_flDirection"); }
    void SetDirection(float value) { SetSchemaValue(m_ptr, "StanceInfo_t", "m_flDirection", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif