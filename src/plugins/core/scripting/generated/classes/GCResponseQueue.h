class GCResponseQueue;

#ifndef _gccresponsequeue_h
#define _gccresponsequeue_h

#include "../../../scripting.h"


#include "GCAI_Expresser.h"

class GCResponseQueue
{
private:
    void *m_ptr;

public:
    GCResponseQueue() {}
    GCResponseQueue(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAI_Expresser*> GetExpresserTargets() const { CUtlVector<GCAI_Expresser*>* vec = GetSchemaValue<CUtlVector<GCAI_Expresser*>*>(m_ptr, "CResponseQueue", "m_ExpresserTargets"); std::vector<GCAI_Expresser*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExpresserTargets(std::vector<GCAI_Expresser*> value) { SetSchemaValueCUtlVector<GCAI_Expresser*>(m_ptr, "CResponseQueue", "m_ExpresserTargets", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif