class GCCSGOViewModel;

#ifndef _gcccsgoviewmodel_h
#define _gcccsgoviewmodel_h

#include "../../../scripting.h"




class GCCSGOViewModel
{
private:
    void *m_ptr;

public:
    GCCSGOViewModel() {}
    GCCSGOViewModel(void *ptr) : m_ptr(ptr) {}

    bool GetShouldIgnoreOffsetAndAccuracy() const { return GetSchemaValue<bool>(m_ptr, "CCSGOViewModel", "m_bShouldIgnoreOffsetAndAccuracy"); }
    void SetShouldIgnoreOffsetAndAccuracy(bool value) { SetSchemaValue(m_ptr, "CCSGOViewModel", "m_bShouldIgnoreOffsetAndAccuracy", false, value); }
    uint32_t GetWeaponParity() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGOViewModel", "m_nWeaponParity"); }
    void SetWeaponParity(uint32_t value) { SetSchemaValue(m_ptr, "CCSGOViewModel", "m_nWeaponParity", false, value); }
    uint32_t GetOldWeaponParity() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSGOViewModel", "m_nOldWeaponParity"); }
    void SetOldWeaponParity(uint32_t value) { SetSchemaValue(m_ptr, "CCSGOViewModel", "m_nOldWeaponParity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif