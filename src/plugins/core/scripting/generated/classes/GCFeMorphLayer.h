class GCFeMorphLayer;

#ifndef _gccfemorphlayer_h
#define _gccfemorphlayer_h

#include "../../../scripting.h"




class GCFeMorphLayer
{
private:
    void *m_ptr;

public:
    GCFeMorphLayer() {}
    GCFeMorphLayer(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFeMorphLayer", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CFeMorphLayer", "m_Name", false, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CFeMorphLayer", "m_nNameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "CFeMorphLayer", "m_nNameHash", false, value); }
    std::vector<uint16> GetNodes() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CFeMorphLayer", "m_Nodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodes(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "CFeMorphLayer", "m_Nodes", false, value); }
    std::vector<Vector> GetInitPos() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFeMorphLayer", "m_InitPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInitPos(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CFeMorphLayer", "m_InitPos", false, value); }
    std::vector<float32> GetGravity() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_Gravity"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGravity(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_Gravity", false, value); }
    std::vector<float32> GetGoalStrength() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_GoalStrength"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGoalStrength(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_GoalStrength", false, value); }
    std::vector<float32> GetGoalDamping() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_GoalDamping"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGoalDamping(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_GoalDamping", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif