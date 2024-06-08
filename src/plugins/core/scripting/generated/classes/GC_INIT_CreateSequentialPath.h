class GC_INIT_CreateSequentialPath;

#ifndef _gcc_init_createsequentialpath_h
#define _gcc_init_createsequentialpath_h

#include "../../../scripting.h"


#include "GCPathParameters.h"

class GC_INIT_CreateSequentialPath
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateSequentialPath() {}
    GC_INIT_CreateSequentialPath(void *ptr) : m_ptr(ptr) {}

    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateSequentialPath", "m_fMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_fMaxDistance", false, value); }
    float GetNumToAssign() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateSequentialPath", "m_flNumToAssign"); }
    void SetNumToAssign(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_flNumToAssign", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPath", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_bLoop", false, value); }
    bool GetCPPairs() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPath", "m_bCPPairs"); }
    void SetCPPairs(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_bCPPairs", false, value); }
    bool GetSaveOffset() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPath", "m_bSaveOffset"); }
    void SetSaveOffset(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_bSaveOffset", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_INIT_CreateSequentialPath", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPath", "m_PathParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif