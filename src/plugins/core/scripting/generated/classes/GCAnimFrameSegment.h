class GCAnimFrameSegment;

#ifndef _gccanimframesegment_h
#define _gccanimframesegment_h

#include "../../../scripting.h"




class GCAnimFrameSegment
{
private:
    void *m_ptr;

public:
    GCAnimFrameSegment() {}
    GCAnimFrameSegment(void *ptr) : m_ptr(ptr) {}

    int32_t GetUniqueFrameIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameSegment", "m_nUniqueFrameIndex"); }
    void SetUniqueFrameIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nUniqueFrameIndex", false, value); }
    uint32_t GetLocalElementMasks() const { return GetSchemaValue<uint32_t>(m_ptr, "CAnimFrameSegment", "m_nLocalElementMasks"); }
    void SetLocalElementMasks(uint32_t value) { SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nLocalElementMasks", false, value); }
    int32_t GetLocalChannel() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameSegment", "m_nLocalChannel"); }
    void SetLocalChannel(int32_t value) { SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nLocalChannel", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif