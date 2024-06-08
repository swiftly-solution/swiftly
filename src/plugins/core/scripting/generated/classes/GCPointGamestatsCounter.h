class GCPointGamestatsCounter;

#ifndef _gccpointgamestatscounter_h
#define _gccpointgamestatscounter_h

#include "../../../scripting.h"




class GCPointGamestatsCounter
{
private:
    void *m_ptr;

public:
    GCPointGamestatsCounter() {}
    GCPointGamestatsCounter(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStrStatisticName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointGamestatsCounter", "m_strStatisticName"); }
    void SetStrStatisticName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointGamestatsCounter", "m_strStatisticName", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPointGamestatsCounter", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CPointGamestatsCounter", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif