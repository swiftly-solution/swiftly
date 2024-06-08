class GCLogicBranch;

#ifndef _gcclogicbranch_h
#define _gcclogicbranch_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicBranch
{
private:
    void *m_ptr;

public:
    GCLogicBranch() {}
    GCLogicBranch(void *ptr) : m_ptr(ptr) {}

    bool GetInValue() const { return GetSchemaValue<bool>(m_ptr, "CLogicBranch", "m_bInValue"); }
    void SetInValue(bool value) { SetSchemaValue(m_ptr, "CLogicBranch", "m_bInValue", false, value); }
    GCEntityIOOutput GetOnTrue() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicBranch", "m_OnTrue"); }
    void SetOnTrue(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicBranch", "m_OnTrue", false, value); }
    GCEntityIOOutput GetOnFalse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicBranch", "m_OnFalse"); }
    void SetOnFalse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicBranch", "m_OnFalse", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif