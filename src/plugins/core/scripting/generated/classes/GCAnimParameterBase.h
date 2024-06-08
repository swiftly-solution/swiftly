class GCAnimParameterBase;

#ifndef _gccanimparameterbase_h
#define _gccanimparameterbase_h

#include "../../../scripting.h"


#include "GAnimParamID.h"

class GCAnimParameterBase
{
private:
    void *m_ptr;

public:
    GCAnimParameterBase() {}
    GCAnimParameterBase(void *ptr) : m_ptr(ptr) {}

    CUtlString GetComment() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_sComment"); }
    void SetComment(CUtlString value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_sComment", false, value); }
    CUtlString GetGroup() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_group"); }
    void SetGroup(CUtlString value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_group", false, value); }
    GAnimParamID GetId() const { return GetSchemaValue<GAnimParamID>(m_ptr, "CAnimParameterBase", "m_id"); }
    void SetId(GAnimParamID value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_id", false, value); }
    CUtlString GetComponentName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_componentName"); }
    void SetComponentName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_componentName", false, value); }
    bool GetNetworkingRequested() const { return GetSchemaValue<bool>(m_ptr, "CAnimParameterBase", "m_bNetworkingRequested"); }
    void SetNetworkingRequested(bool value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_bNetworkingRequested", false, value); }
    bool GetIsReferenced() const { return GetSchemaValue<bool>(m_ptr, "CAnimParameterBase", "m_bIsReferenced"); }
    void SetIsReferenced(bool value) { SetSchemaValue(m_ptr, "CAnimParameterBase", "m_bIsReferenced", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif