class GVariableInfo_t;

#ifndef _gcvariableinfo_t_h
#define _gcvariableinfo_t_h

#include "../../../scripting.h"

#include "../types/GFuseVariableType_t.h"
#include "../types/GFuseVariableAccess_t.h"
#include "GFuseVariableIndex_t.h"

class GVariableInfo_t
{
private:
    void *m_ptr;

public:
    GVariableInfo_t() {}
    GVariableInfo_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "VariableInfo_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_name", true, value); }
    CUtlStringToken GetNameToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "VariableInfo_t", "m_nameToken"); }
    void SetNameToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_nameToken", true, value); }
    GFuseVariableIndex_t GetIndex() const { return GetSchemaValue<GFuseVariableIndex_t>(m_ptr, "VariableInfo_t", "m_nIndex"); }
    void SetIndex(GFuseVariableIndex_t value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_nIndex", true, value); }
    uint8_t GetNumComponents() const { return GetSchemaValue<uint8_t>(m_ptr, "VariableInfo_t", "m_nNumComponents"); }
    void SetNumComponents(uint8_t value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_nNumComponents", true, value); }
    FuseVariableType_t GetVarType() const { return GetSchemaValue<FuseVariableType_t>(m_ptr, "VariableInfo_t", "m_eVarType"); }
    void SetVarType(FuseVariableType_t value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_eVarType", true, value); }
    FuseVariableAccess_t GetAccess() const { return GetSchemaValue<FuseVariableAccess_t>(m_ptr, "VariableInfo_t", "m_eAccess"); }
    void SetAccess(FuseVariableAccess_t value) { SetSchemaValue(m_ptr, "VariableInfo_t", "m_eAccess", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif