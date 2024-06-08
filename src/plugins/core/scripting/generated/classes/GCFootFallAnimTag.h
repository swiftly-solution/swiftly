class GCFootFallAnimTag;

#ifndef _gccfootfallanimtag_h
#define _gccfootfallanimtag_h

#include "../../../scripting.h"

#include "../types/GFootFallTagFoot_t.h"


class GCFootFallAnimTag
{
private:
    void *m_ptr;

public:
    GCFootFallAnimTag() {}
    GCFootFallAnimTag(void *ptr) : m_ptr(ptr) {}

    FootFallTagFoot_t GetFoot() const { return GetSchemaValue<FootFallTagFoot_t>(m_ptr, "CFootFallAnimTag", "m_foot"); }
    void SetFoot(FootFallTagFoot_t value) { SetSchemaValue(m_ptr, "CFootFallAnimTag", "m_foot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif