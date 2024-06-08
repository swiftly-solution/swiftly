class GCAnimDecoder;

#ifndef _gccanimdecoder_h
#define _gccanimdecoder_h

#include "../../../scripting.h"




class GCAnimDecoder
{
private:
    void *m_ptr;

public:
    GCAnimDecoder() {}
    GCAnimDecoder(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDecoder", "m_szName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDecoder", "m_szName", false, value); }
    int32_t GetVersion() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimDecoder", "m_nVersion"); }
    void SetVersion(int32_t value) { SetSchemaValue(m_ptr, "CAnimDecoder", "m_nVersion", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimDecoder", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CAnimDecoder", "m_nType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif