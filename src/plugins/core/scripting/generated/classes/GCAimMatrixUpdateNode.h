class GCAimMatrixUpdateNode;

#ifndef _gccaimmatrixupdatenode_h
#define _gccaimmatrixupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimVectorSource.h"
#include "GAimMatrixOpFixedSettings_t.h"
#include "GCAnimParamHandle.h"

class GCAimMatrixUpdateNode
{
private:
    void *m_ptr;

public:
    GCAimMatrixUpdateNode() {}
    GCAimMatrixUpdateNode(void *ptr) : m_ptr(ptr) {}

    GAimMatrixOpFixedSettings_t GetOpFixedSettings() const { return GetSchemaValue<GAimMatrixOpFixedSettings_t>(m_ptr, "CAimMatrixUpdateNode", "m_opFixedSettings"); }
    void SetOpFixedSettings(GAimMatrixOpFixedSettings_t value) { SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_opFixedSettings", false, value); }
    AnimVectorSource GetTarget() const { return GetSchemaValue<AnimVectorSource>(m_ptr, "CAimMatrixUpdateNode", "m_target"); }
    void SetTarget(AnimVectorSource value) { SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_target", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimMatrixUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_paramIndex", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CAimMatrixUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_bResetChild", false, value); }
    bool GetLockWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CAimMatrixUpdateNode", "m_bLockWhenWaning"); }
    void SetLockWhenWaning(bool value) { SetSchemaValue(m_ptr, "CAimMatrixUpdateNode", "m_bLockWhenWaning", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif