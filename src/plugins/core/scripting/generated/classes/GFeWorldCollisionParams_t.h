class GFeWorldCollisionParams_t;

#ifndef _gcfeworldcollisionparams_t_h
#define _gcfeworldcollisionparams_t_h

#include "../../../scripting.h"




class GFeWorldCollisionParams_t
{
private:
    void *m_ptr;

public:
    GFeWorldCollisionParams_t() {}
    GFeWorldCollisionParams_t(void *ptr) : m_ptr(ptr) {}

    float GetWorldFriction() const { return GetSchemaValue<float>(m_ptr, "FeWorldCollisionParams_t", "flWorldFriction"); }
    void SetWorldFriction(float value) { SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "flWorldFriction", true, value); }
    float GetGroundFriction() const { return GetSchemaValue<float>(m_ptr, "FeWorldCollisionParams_t", "flGroundFriction"); }
    void SetGroundFriction(float value) { SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "flGroundFriction", true, value); }
    uint16_t GetListBegin() const { return GetSchemaValue<uint16_t>(m_ptr, "FeWorldCollisionParams_t", "nListBegin"); }
    void SetListBegin(uint16_t value) { SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "nListBegin", true, value); }
    uint16_t GetListEnd() const { return GetSchemaValue<uint16_t>(m_ptr, "FeWorldCollisionParams_t", "nListEnd"); }
    void SetListEnd(uint16_t value) { SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "nListEnd", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif