class GCMoodVData;

#ifndef _gccmoodvdata_h
#define _gccmoodvdata_h

#include "../../../scripting.h"

#include "../types/GMoodType_t.h"


class GCMoodVData
{
private:
    void *m_ptr;

public:
    GCMoodVData() {}
    GCMoodVData(void *ptr) : m_ptr(ptr) {}

    MoodType_t GetMoodType() const { return GetSchemaValue<MoodType_t>(m_ptr, "CMoodVData", "m_nMoodType"); }
    void SetMoodType(MoodType_t value) { SetSchemaValue(m_ptr, "CMoodVData", "m_nMoodType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif