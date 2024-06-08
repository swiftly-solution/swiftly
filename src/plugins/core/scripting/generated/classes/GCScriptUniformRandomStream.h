class GCScriptUniformRandomStream;

#ifndef _gccscriptuniformrandomstream_h
#define _gccscriptuniformrandomstream_h

#include "../../../scripting.h"




class GCScriptUniformRandomStream
{
private:
    void *m_ptr;

public:
    GCScriptUniformRandomStream() {}
    GCScriptUniformRandomStream(void *ptr) : m_ptr(ptr) {}

    int32_t GetInitialSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptUniformRandomStream", "m_nInitialSeed"); }
    void SetInitialSeed(int32_t value) { SetSchemaValue(m_ptr, "CScriptUniformRandomStream", "m_nInitialSeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif