class Gragdoll_t;

#ifndef _gcragdoll_t_h
#define _gcragdoll_t_h

#include "../../../scripting.h"


#include "Gragdollelement_t.h"

class Gragdoll_t
{
private:
    void *m_ptr;

public:
    Gragdoll_t() {}
    Gragdoll_t(void *ptr) : m_ptr(ptr) {}

    std::vector<Gragdollelement_t> GetList() const { CUtlVector<Gragdollelement_t>* vec = GetSchemaValue<CUtlVector<Gragdollelement_t>*>(m_ptr, "ragdoll_t", "list"); std::vector<Gragdollelement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetList(std::vector<Gragdollelement_t> value) { SetSchemaValueCUtlVector<Gragdollelement_t>(m_ptr, "ragdoll_t", "list", true, value); }
    std::vector<int32> GetBoneIndex() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ragdoll_t", "boneIndex"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneIndex(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "ragdoll_t", "boneIndex", true, value); }
    bool GetAllowStretch() const { return GetSchemaValue<bool>(m_ptr, "ragdoll_t", "allowStretch"); }
    void SetAllowStretch(bool value) { SetSchemaValue(m_ptr, "ragdoll_t", "allowStretch", true, value); }
    bool GetUnused() const { return GetSchemaValue<bool>(m_ptr, "ragdoll_t", "unused"); }
    void SetUnused(bool value) { SetSchemaValue(m_ptr, "ragdoll_t", "unused", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif