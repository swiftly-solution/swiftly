class GCRagdollManager;

#ifndef _gccragdollmanager_h
#define _gccragdollmanager_h

#include "../../../scripting.h"




class GCRagdollManager
{
private:
    void *m_ptr;

public:
    GCRagdollManager() {}
    GCRagdollManager(void *ptr) : m_ptr(ptr) {}

    int8_t GetCurrentMaxRagdollCount() const { return GetSchemaValue<int8_t>(m_ptr, "CRagdollManager", "m_iCurrentMaxRagdollCount"); }
    void SetCurrentMaxRagdollCount(int8_t value) { SetSchemaValue(m_ptr, "CRagdollManager", "m_iCurrentMaxRagdollCount", false, value); }
    int32_t GetMaxRagdollCount() const { return GetSchemaValue<int32_t>(m_ptr, "CRagdollManager", "m_iMaxRagdollCount"); }
    void SetMaxRagdollCount(int32_t value) { SetSchemaValue(m_ptr, "CRagdollManager", "m_iMaxRagdollCount", false, value); }
    bool GetSaveImportant() const { return GetSchemaValue<bool>(m_ptr, "CRagdollManager", "m_bSaveImportant"); }
    void SetSaveImportant(bool value) { SetSchemaValue(m_ptr, "CRagdollManager", "m_bSaveImportant", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif