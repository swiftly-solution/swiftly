class GVPhysXCollisionAttributes_t;

#ifndef _gcvphysxcollisionattributes_t_h
#define _gcvphysxcollisionattributes_t_h

#include "../../../scripting.h"




class GVPhysXCollisionAttributes_t
{
private:
    void *m_ptr;

public:
    GVPhysXCollisionAttributes_t() {}
    GVPhysXCollisionAttributes_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetCollisionGroup() const { return GetSchemaValue<uint32_t>(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroup"); }
    void SetCollisionGroup(uint32_t value) { SetSchemaValue(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroup", true, value); }
    std::vector<uint32> GetInteractAs() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAs"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractAs(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAs", true, value); }
    std::vector<uint32> GetInteractWith() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWith"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractWith(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWith", true, value); }
    std::vector<uint32> GetInteractExclude() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExclude"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractExclude(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExclude", true, value); }
    CUtlString GetCollisionGroupString() const { return GetSchemaValue<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroupString"); }
    void SetCollisionGroupString(CUtlString value) { SetSchemaValue(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroupString", true, value); }
    std::vector<CUtlString> GetInteractAsStrings() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAsStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractAsStrings(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAsStrings", true, value); }
    std::vector<CUtlString> GetInteractWithStrings() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWithStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractWithStrings(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWithStrings", true, value); }
    std::vector<CUtlString> GetInteractExcludeStrings() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExcludeStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInteractExcludeStrings(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExcludeStrings", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif