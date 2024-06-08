class GClutterTile_t;

#ifndef _gccluttertile_t_h
#define _gccluttertile_t_h

#include "../../../scripting.h"


#include "GAABB_t.h"

class GClutterTile_t
{
private:
    void *m_ptr;

public:
    GClutterTile_t() {}
    GClutterTile_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFirstInstance() const { return GetSchemaValue<uint32_t>(m_ptr, "ClutterTile_t", "m_nFirstInstance"); }
    void SetFirstInstance(uint32_t value) { SetSchemaValue(m_ptr, "ClutterTile_t", "m_nFirstInstance", true, value); }
    uint32_t GetLastInstance() const { return GetSchemaValue<uint32_t>(m_ptr, "ClutterTile_t", "m_nLastInstance"); }
    void SetLastInstance(uint32_t value) { SetSchemaValue(m_ptr, "ClutterTile_t", "m_nLastInstance", true, value); }
    GAABB_t GetBoundsWs() const { return GetSchemaValue<GAABB_t>(m_ptr, "ClutterTile_t", "m_BoundsWs"); }
    void SetBoundsWs(GAABB_t value) { SetSchemaValue(m_ptr, "ClutterTile_t", "m_BoundsWs", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif