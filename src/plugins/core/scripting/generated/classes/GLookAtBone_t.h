class GLookAtBone_t;

#ifndef _gclookatbone_t_h
#define _gclookatbone_t_h

#include "../../../scripting.h"




class GLookAtBone_t
{
private:
    void *m_ptr;

public:
    GLookAtBone_t() {}
    GLookAtBone_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetIndex() const { return GetSchemaValue<int32_t>(m_ptr, "LookAtBone_t", "m_index"); }
    void SetIndex(int32_t value) { SetSchemaValue(m_ptr, "LookAtBone_t", "m_index", true, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "LookAtBone_t", "m_weight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "LookAtBone_t", "m_weight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif