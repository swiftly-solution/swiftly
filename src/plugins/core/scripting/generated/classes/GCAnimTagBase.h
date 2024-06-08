class GCAnimTagBase;

#ifndef _gccanimtagbase_h
#define _gccanimtagbase_h

#include "../../../scripting.h"


#include "GAnimTagID.h"

class GCAnimTagBase
{
private:
    void *m_ptr;

public:
    GCAnimTagBase() {}
    GCAnimTagBase(void *ptr) : m_ptr(ptr) {}

    CUtlString GetComment() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimTagBase", "m_sComment"); }
    void SetComment(CUtlString value) { SetSchemaValue(m_ptr, "CAnimTagBase", "m_sComment", false, value); }
    GAnimTagID GetTagID() const { return GetSchemaValue<GAnimTagID>(m_ptr, "CAnimTagBase", "m_tagID"); }
    void SetTagID(GAnimTagID value) { SetSchemaValue(m_ptr, "CAnimTagBase", "m_tagID", false, value); }
    bool GetIsReferenced() const { return GetSchemaValue<bool>(m_ptr, "CAnimTagBase", "m_bIsReferenced"); }
    void SetIsReferenced(bool value) { SetSchemaValue(m_ptr, "CAnimTagBase", "m_bIsReferenced", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif