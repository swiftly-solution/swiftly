class GC_INIT_CreateAlongPath;

#ifndef _gcc_init_createalongpath_h
#define _gcc_init_createalongpath_h

#include "../../../scripting.h"


#include "GCPathParameters.h"

class GC_INIT_CreateAlongPath
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateAlongPath() {}
    GC_INIT_CreateAlongPath(void *ptr) : m_ptr(ptr) {}

    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateAlongPath", "m_fMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateAlongPath", "m_fMaxDistance", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_INIT_CreateAlongPath", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_INIT_CreateAlongPath", "m_PathParams", false, value); }
    bool GetUseRandomCPs() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateAlongPath", "m_bUseRandomCPs"); }
    void SetUseRandomCPs(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateAlongPath", "m_bUseRandomCPs", false, value); }
    Vector GetEndOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_CreateAlongPath", "m_vEndOffset"); }
    void SetEndOffset(Vector value) { SetSchemaValue(m_ptr, "C_INIT_CreateAlongPath", "m_vEndOffset", false, value); }
    bool GetSaveOffset() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateAlongPath", "m_bSaveOffset"); }
    void SetSaveOffset(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateAlongPath", "m_bSaveOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif