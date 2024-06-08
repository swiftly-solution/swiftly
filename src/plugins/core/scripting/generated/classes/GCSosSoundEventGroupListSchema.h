class GCSosSoundEventGroupListSchema;

#ifndef _gccsossoundeventgrouplistschema_h
#define _gccsossoundeventgrouplistschema_h

#include "../../../scripting.h"


#include "GCSosSoundEventGroupSchema.h"

class GCSosSoundEventGroupListSchema
{
private:
    void *m_ptr;

public:
    GCSosSoundEventGroupListSchema() {}
    GCSosSoundEventGroupListSchema(void *ptr) : m_ptr(ptr) {}

    std::vector<GCSosSoundEventGroupSchema> GetGroupList() const { CUtlVector<GCSosSoundEventGroupSchema>* vec = GetSchemaValue<CUtlVector<GCSosSoundEventGroupSchema>*>(m_ptr, "CSosSoundEventGroupListSchema", "m_groupList"); std::vector<GCSosSoundEventGroupSchema> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGroupList(std::vector<GCSosSoundEventGroupSchema> value) { SetSchemaValueCUtlVector<GCSosSoundEventGroupSchema>(m_ptr, "CSosSoundEventGroupListSchema", "m_groupList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif