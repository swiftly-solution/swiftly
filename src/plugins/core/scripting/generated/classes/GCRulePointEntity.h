class GCRulePointEntity;

#ifndef _gccrulepointentity_h
#define _gccrulepointentity_h

#include "../../../scripting.h"




class GCRulePointEntity
{
private:
    void *m_ptr;

public:
    GCRulePointEntity() {}
    GCRulePointEntity(void *ptr) : m_ptr(ptr) {}

    int32_t GetScore() const { return GetSchemaValue<int32_t>(m_ptr, "CRulePointEntity", "m_Score"); }
    void SetScore(int32_t value) { SetSchemaValue(m_ptr, "CRulePointEntity", "m_Score", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif