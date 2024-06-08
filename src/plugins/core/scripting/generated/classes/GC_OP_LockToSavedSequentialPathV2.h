class GC_OP_LockToSavedSequentialPathV2;

#ifndef _gcc_op_locktosavedsequentialpathv2_h
#define _gcc_op_locktosavedsequentialpathv2_h

#include "../../../scripting.h"


#include "GCPathParameters.h"

class GC_OP_LockToSavedSequentialPathV2
{
private:
    void *m_ptr;

public:
    GC_OP_LockToSavedSequentialPathV2() {}
    GC_OP_LockToSavedSequentialPathV2(void *ptr) : m_ptr(ptr) {}

    float GetFadeStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_flFadeStart"); }
    void SetFadeStart(float value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_flFadeStart", false, value); }
    float GetFadeEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_flFadeEnd"); }
    void SetFadeEnd(float value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_flFadeEnd", false, value); }
    bool GetCPPairs() const { return GetSchemaValue<bool>(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_bCPPairs"); }
    void SetCPPairs(bool value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_bCPPairs", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_OP_LockToSavedSequentialPathV2", "m_PathParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif