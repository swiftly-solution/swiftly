class GCAnimActivity;

#ifndef _gccanimactivity_h
#define _gccanimactivity_h

#include "../../../scripting.h"




class GCAnimActivity
{
private:
    void *m_ptr;

public:
    GCAnimActivity() {}
    GCAnimActivity(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimActivity", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimActivity", "m_name", false, value); }
    int32_t GetActivity() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nActivity"); }
    void SetActivity(int32_t value) { SetSchemaValue(m_ptr, "CAnimActivity", "m_nActivity", false, value); }
    int32_t GetFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nFlags"); }
    void SetFlags(int32_t value) { SetSchemaValue(m_ptr, "CAnimActivity", "m_nFlags", false, value); }
    int32_t GetWeight() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nWeight"); }
    void SetWeight(int32_t value) { SetSchemaValue(m_ptr, "CAnimActivity", "m_nWeight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif