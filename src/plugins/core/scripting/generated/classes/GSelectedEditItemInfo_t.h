class GSelectedEditItemInfo_t;

#ifndef _gcselectededititeminfo_t_h
#define _gcselectededititeminfo_t_h

#include "../../../scripting.h"


#include "GSosEditItemInfo_t.h"

class GSelectedEditItemInfo_t
{
private:
    void *m_ptr;

public:
    GSelectedEditItemInfo_t() {}
    GSelectedEditItemInfo_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GSosEditItemInfo_t> GetEditItems() const { CUtlVector<GSosEditItemInfo_t>* vec = GetSchemaValue<CUtlVector<GSosEditItemInfo_t>*>(m_ptr, "SelectedEditItemInfo_t", "m_EditItems"); std::vector<GSosEditItemInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEditItems(std::vector<GSosEditItemInfo_t> value) { SetSchemaValueCUtlVector<GSosEditItemInfo_t>(m_ptr, "SelectedEditItemInfo_t", "m_EditItems", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif