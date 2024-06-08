class GC_OP_MaintainSequentialPath;

#ifndef _gcc_op_maintainsequentialpath_h
#define _gcc_op_maintainsequentialpath_h

#include "../../../scripting.h"


#include "GCPathParameters.h"

class GC_OP_MaintainSequentialPath
{
private:
    void *m_ptr;

public:
    GC_OP_MaintainSequentialPath() {}
    GC_OP_MaintainSequentialPath(void *ptr) : m_ptr(ptr) {}

    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainSequentialPath", "m_fMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_fMaxDistance", false, value); }
    float GetNumToAssign() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainSequentialPath", "m_flNumToAssign"); }
    void SetNumToAssign(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_flNumToAssign", false, value); }
    float GetCohesionStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainSequentialPath", "m_flCohesionStrength"); }
    void SetCohesionStrength(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_flCohesionStrength", false, value); }
    float GetTolerance() const { return GetSchemaValue<float>(m_ptr, "C_OP_MaintainSequentialPath", "m_flTolerance"); }
    void SetTolerance(float value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_flTolerance", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MaintainSequentialPath", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_bLoop", false, value); }
    bool GetUseParticleCount() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MaintainSequentialPath", "m_bUseParticleCount"); }
    void SetUseParticleCount(bool value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_bUseParticleCount", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_OP_MaintainSequentialPath", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_OP_MaintainSequentialPath", "m_PathParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif