class GRelationship_t;

#ifndef _gcrelationship_t_h
#define _gcrelationship_t_h

#include "../../../scripting.h"

#include "../types/GDisposition_t.h"


class GRelationship_t
{
private:
    void *m_ptr;

public:
    GRelationship_t() {}
    GRelationship_t(void *ptr) : m_ptr(ptr) {}

    Disposition_t GetDisposition() const { return GetSchemaValue<Disposition_t>(m_ptr, "Relationship_t", "disposition"); }
    void SetDisposition(Disposition_t value) { SetSchemaValue(m_ptr, "Relationship_t", "disposition", true, value); }
    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "Relationship_t", "priority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "Relationship_t", "priority", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif