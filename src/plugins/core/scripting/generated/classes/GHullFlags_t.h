class GHullFlags_t;

#ifndef _gchullflags_t_h
#define _gchullflags_t_h

#include "../../../scripting.h"




class GHullFlags_t
{
private:
    void *m_ptr;

public:
    GHullFlags_t() {}
    GHullFlags_t(void *ptr) : m_ptr(ptr) {}

    bool GetHull_Human() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Human"); }
    void SetHull_Human(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Human", true, value); }
    bool GetHull_SmallCentered() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_SmallCentered"); }
    void SetHull_SmallCentered(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_SmallCentered", true, value); }
    bool GetHull_WideHuman() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_WideHuman"); }
    void SetHull_WideHuman(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_WideHuman", true, value); }
    bool GetHull_Tiny() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Tiny"); }
    void SetHull_Tiny(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Tiny", true, value); }
    bool GetHull_Medium() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Medium"); }
    void SetHull_Medium(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Medium", true, value); }
    bool GetHull_TinyCentered() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_TinyCentered"); }
    void SetHull_TinyCentered(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_TinyCentered", true, value); }
    bool GetHull_Large() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Large"); }
    void SetHull_Large(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Large", true, value); }
    bool GetHull_LargeCentered() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_LargeCentered"); }
    void SetHull_LargeCentered(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_LargeCentered", true, value); }
    bool GetHull_MediumTall() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_MediumTall"); }
    void SetHull_MediumTall(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_MediumTall", true, value); }
    bool GetHull_Small() const { return GetSchemaValue<bool>(m_ptr, "HullFlags_t", "m_bHull_Small"); }
    void SetHull_Small(bool value) { SetSchemaValue(m_ptr, "HullFlags_t", "m_bHull_Small", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif