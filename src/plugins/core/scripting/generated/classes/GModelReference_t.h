class GModelReference_t;

#ifndef _gcmodelreference_t_h
#define _gcmodelreference_t_h

#include "../../../scripting.h"




class GModelReference_t
{
private:
    void *m_ptr;

public:
    GModelReference_t() {}
    GModelReference_t(void *ptr) : m_ptr(ptr) {}

    float GetRelativeProbabilityOfSpawn() const { return GetSchemaValue<float>(m_ptr, "ModelReference_t", "m_flRelativeProbabilityOfSpawn"); }
    void SetRelativeProbabilityOfSpawn(float value) { SetSchemaValue(m_ptr, "ModelReference_t", "m_flRelativeProbabilityOfSpawn", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif