class GRnHullDesc_t;

#ifndef _gcrnhulldesc_t_h
#define _gcrnhulldesc_t_h

#include "../../../scripting.h"

#include "../types/GHull_t.h"
#include "GRnHull_t.h"

class GRnHullDesc_t
{
private:
    void *m_ptr;

public:
    GRnHullDesc_t() {}
    GRnHullDesc_t(void *ptr) : m_ptr(ptr) {}

    GRnHull_t GetHull() const { return GetSchemaValue<GRnHull_t>(m_ptr, "RnHullDesc_t", "m_Hull"); }
    void SetHull(GRnHull_t value) { SetSchemaValue(m_ptr, "RnHullDesc_t", "m_Hull", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif