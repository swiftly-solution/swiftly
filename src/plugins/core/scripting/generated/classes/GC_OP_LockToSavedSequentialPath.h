class GC_OP_LockToSavedSequentialPath;

#ifndef _gcc_op_locktosavedsequentialpath_h
#define _gcc_op_locktosavedsequentialpath_h

#include "../../../scripting.h"


#include "GCPathParameters.h"

class GC_OP_LockToSavedSequentialPath
{
private:
    void *m_ptr;

public:
    GC_OP_LockToSavedSequentialPath() {}
    GC_OP_LockToSavedSequentialPath(void *ptr) : m_ptr(ptr) {}

    float GetFadeStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToSavedSequentialPath", "m_flFadeStart"); }
    void SetFadeStart(float value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPath", "m_flFadeStart", false, value); }
    float GetFadeEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToSavedSequentialPath", "m_flFadeEnd"); }
    void SetFadeEnd(float value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPath", "m_flFadeEnd", false, value); }
    bool GetCPPairs() const { return GetSchemaValue<bool>(m_ptr, "C_OP_LockToSavedSequentialPath", "m_bCPPairs"); }
    void SetCPPairs(bool value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPath", "m_bCPPairs", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_OP_LockToSavedSequentialPath", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPath", "m_PathParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif