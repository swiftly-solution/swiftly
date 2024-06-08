class GCLookAtUpdateNode;

#ifndef _gcclookatupdatenode_h
#define _gcclookatupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimVectorSource.h"
#include "GLookAtOpFixedSettings_t.h"
#include "GCAnimParamHandle.h"

class GCLookAtUpdateNode
{
private:
    void *m_ptr;

public:
    GCLookAtUpdateNode() {}
    GCLookAtUpdateNode(void *ptr) : m_ptr(ptr) {}

    GLookAtOpFixedSettings_t GetOpFixedSettings() const { return GetSchemaValue<GLookAtOpFixedSettings_t>(m_ptr, "CLookAtUpdateNode", "m_opFixedSettings"); }
    void SetOpFixedSettings(GLookAtOpFixedSettings_t value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_opFixedSettings", false, value); }
    AnimVectorSource GetTarget() const { return GetSchemaValue<AnimVectorSource>(m_ptr, "CLookAtUpdateNode", "m_target"); }
    void SetTarget(AnimVectorSource value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_target", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookAtUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_paramIndex", false, value); }
    GCAnimParamHandle GetWeightParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookAtUpdateNode", "m_weightParamIndex"); }
    void SetWeightParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_weightParamIndex", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CLookAtUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_bResetChild", false, value); }
    bool GetLockWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CLookAtUpdateNode", "m_bLockWhenWaning"); }
    void SetLockWhenWaning(bool value) { SetSchemaValue(m_ptr, "CLookAtUpdateNode", "m_bLockWhenWaning", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif