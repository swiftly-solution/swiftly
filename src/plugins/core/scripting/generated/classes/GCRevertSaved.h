class GCRevertSaved;

#ifndef _gccrevertsaved_h
#define _gccrevertsaved_h

#include "../../../scripting.h"




class GCRevertSaved
{
private:
    void *m_ptr;

public:
    GCRevertSaved() {}
    GCRevertSaved(void *ptr) : m_ptr(ptr) {}

    float GetLoadTime() const { return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_loadTime"); }
    void SetLoadTime(float value) { SetSchemaValue(m_ptr, "CRevertSaved", "m_loadTime", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_Duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CRevertSaved", "m_Duration", false, value); }
    float GetHoldTime() const { return GetSchemaValue<float>(m_ptr, "CRevertSaved", "m_HoldTime"); }
    void SetHoldTime(float value) { SetSchemaValue(m_ptr, "CRevertSaved", "m_HoldTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif