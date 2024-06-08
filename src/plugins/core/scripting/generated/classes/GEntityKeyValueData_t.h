class GEntityKeyValueData_t;

#ifndef _gcentitykeyvaluedata_t_h
#define _gcentitykeyvaluedata_t_h

#include "../../../scripting.h"


#include "GEntityIOConnectionData_t.h"

class GEntityKeyValueData_t
{
private:
    void *m_ptr;

public:
    GEntityKeyValueData_t() {}
    GEntityKeyValueData_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GEntityIOConnectionData_t> GetConnections() const { CUtlVector<GEntityIOConnectionData_t>* vec = GetSchemaValue<CUtlVector<GEntityIOConnectionData_t>*>(m_ptr, "EntityKeyValueData_t", "m_connections"); std::vector<GEntityIOConnectionData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConnections(std::vector<GEntityIOConnectionData_t> value) { SetSchemaValueCUtlVector<GEntityIOConnectionData_t>(m_ptr, "EntityKeyValueData_t", "m_connections", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif