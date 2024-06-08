class GFilterTeam;

#ifndef _gcfilterteam_h
#define _gcfilterteam_h

#include "../../../scripting.h"




class GFilterTeam
{
private:
    void *m_ptr;

public:
    GFilterTeam() {}
    GFilterTeam(void *ptr) : m_ptr(ptr) {}

    int32_t GetFilterTeam() const { return GetSchemaValue<int32_t>(m_ptr, "FilterTeam", "m_iFilterTeam"); }
    void SetFilterTeam(int32_t value) { SetSchemaValue(m_ptr, "FilterTeam", "m_iFilterTeam", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif