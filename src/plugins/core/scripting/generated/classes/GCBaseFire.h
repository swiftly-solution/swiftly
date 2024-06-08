class GCBaseFire;

#ifndef _gccbasefire_h
#define _gccbasefire_h

#include "../../../scripting.h"




class GCBaseFire
{
private:
    void *m_ptr;

public:
    GCBaseFire() {}
    GCBaseFire(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CBaseFire", "m_flScale", false, value); }
    float GetStartScale() const { return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flStartScale"); }
    void SetStartScale(float value) { SetSchemaValue(m_ptr, "CBaseFire", "m_flStartScale", false, value); }
    float GetScaleTime() const { return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flScaleTime"); }
    void SetScaleTime(float value) { SetSchemaValue(m_ptr, "CBaseFire", "m_flScaleTime", false, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseFire", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CBaseFire", "m_nFlags", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif