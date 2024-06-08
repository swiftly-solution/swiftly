class GCSequenceFinishedAnimTag;

#ifndef _gccsequencefinishedanimtag_h
#define _gccsequencefinishedanimtag_h

#include "../../../scripting.h"




class GCSequenceFinishedAnimTag
{
private:
    void *m_ptr;

public:
    GCSequenceFinishedAnimTag() {}
    GCSequenceFinishedAnimTag(void *ptr) : m_ptr(ptr) {}

    CUtlString GetSequenceName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSequenceFinishedAnimTag", "m_sequenceName"); }
    void SetSequenceName(CUtlString value) { SetSchemaValue(m_ptr, "CSequenceFinishedAnimTag", "m_sequenceName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif