class GResponseParams;

#ifndef _gcresponseparams_h
#define _gcresponseparams_h

#include "../../../scripting.h"


#include "GResponseFollowup.h"

class GResponseParams
{
private:
    void *m_ptr;

public:
    GResponseParams() {}
    GResponseParams(void *ptr) : m_ptr(ptr) {}

    int16_t GetOdds() const { return GetSchemaValue<int16_t>(m_ptr, "ResponseParams", "odds"); }
    void SetOdds(int16_t value) { SetSchemaValue(m_ptr, "ResponseParams", "odds", false, value); }
    int16_t GetFlags() const { return GetSchemaValue<int16_t>(m_ptr, "ResponseParams", "flags"); }
    void SetFlags(int16_t value) { SetSchemaValue(m_ptr, "ResponseParams", "flags", false, value); }
    GResponseFollowup* GetFollowup() const { return GetSchemaValue<GResponseFollowup*>(m_ptr, "ResponseParams", "m_pFollowup"); }
    void SetFollowup(GResponseFollowup* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Followup' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif