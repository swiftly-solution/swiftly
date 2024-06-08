class GVPhysXAggregateData_t;

#ifndef _gcvphysxaggregatedata_t_h
#define _gcvphysxaggregatedata_t_h

#include "../../../scripting.h"


#include "GVPhysXBodyPart_t.h"
#include "GVPhysXConstraint2_t.h"
#include "GVPhysXJoint_t.h"
#include "GPhysFeModelDesc_t.h"
#include "GVPhysXCollisionAttributes_t.h"

class GVPhysXAggregateData_t
{
private:
    void *m_ptr;

public:
    GVPhysXAggregateData_t() {}
    GVPhysXAggregateData_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXAggregateData_t", "m_nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_nFlags", true, value); }
    uint16_t GetRefCounter() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXAggregateData_t", "m_nRefCounter"); }
    void SetRefCounter(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_nRefCounter", true, value); }
    std::vector<uint32> GetBonesHash() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXAggregateData_t", "m_bonesHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBonesHash(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXAggregateData_t", "m_bonesHash", true, value); }
    std::vector<CUtlString> GetBoneNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXAggregateData_t", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_boneNames", true, value); }
    std::vector<uint16> GetIndexNames() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_indexNames"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIndexNames(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_indexNames", true, value); }
    std::vector<uint16> GetIndexHash() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_indexHash"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIndexHash(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_indexHash", true, value); }
    std::vector<matrix3x4a_t> GetBindPose() const { CUtlVector<matrix3x4a_t>* vec = GetSchemaValue<CUtlVector<matrix3x4a_t>*>(m_ptr, "VPhysXAggregateData_t", "m_bindPose"); std::vector<matrix3x4a_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBindPose(std::vector<matrix3x4a_t> value) { SetSchemaValueCUtlVector<matrix3x4a_t>(m_ptr, "VPhysXAggregateData_t", "m_bindPose", true, value); }
    std::vector<GVPhysXBodyPart_t> GetParts() const { CUtlVector<GVPhysXBodyPart_t>* vec = GetSchemaValue<CUtlVector<GVPhysXBodyPart_t>*>(m_ptr, "VPhysXAggregateData_t", "m_parts"); std::vector<GVPhysXBodyPart_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParts(std::vector<GVPhysXBodyPart_t> value) { SetSchemaValueCUtlVector<GVPhysXBodyPart_t>(m_ptr, "VPhysXAggregateData_t", "m_parts", true, value); }
    std::vector<GVPhysXConstraint2_t> GetConstraints2() const { CUtlVector<GVPhysXConstraint2_t>* vec = GetSchemaValue<CUtlVector<GVPhysXConstraint2_t>*>(m_ptr, "VPhysXAggregateData_t", "m_constraints2"); std::vector<GVPhysXConstraint2_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConstraints2(std::vector<GVPhysXConstraint2_t> value) { SetSchemaValueCUtlVector<GVPhysXConstraint2_t>(m_ptr, "VPhysXAggregateData_t", "m_constraints2", true, value); }
    std::vector<GVPhysXJoint_t> GetJoints() const { CUtlVector<GVPhysXJoint_t>* vec = GetSchemaValue<CUtlVector<GVPhysXJoint_t>*>(m_ptr, "VPhysXAggregateData_t", "m_joints"); std::vector<GVPhysXJoint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetJoints(std::vector<GVPhysXJoint_t> value) { SetSchemaValueCUtlVector<GVPhysXJoint_t>(m_ptr, "VPhysXAggregateData_t", "m_joints", true, value); }
    GPhysFeModelDesc_t* GetFeModel() const { return GetSchemaValue<GPhysFeModelDesc_t*>(m_ptr, "VPhysXAggregateData_t", "m_pFeModel"); }
    void SetFeModel(GPhysFeModelDesc_t* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'FeModel' is not possible.\n"); }
    std::vector<uint16> GetBoneParents() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_boneParents"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneParents(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_boneParents", true, value); }
    std::vector<uint32> GetSurfacePropertyHashes() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXAggregateData_t", "m_surfacePropertyHashes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSurfacePropertyHashes(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXAggregateData_t", "m_surfacePropertyHashes", true, value); }
    std::vector<GVPhysXCollisionAttributes_t> GetCollisionAttributes() const { CUtlVector<GVPhysXCollisionAttributes_t>* vec = GetSchemaValue<CUtlVector<GVPhysXCollisionAttributes_t>*>(m_ptr, "VPhysXAggregateData_t", "m_collisionAttributes"); std::vector<GVPhysXCollisionAttributes_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCollisionAttributes(std::vector<GVPhysXCollisionAttributes_t> value) { SetSchemaValueCUtlVector<GVPhysXCollisionAttributes_t>(m_ptr, "VPhysXAggregateData_t", "m_collisionAttributes", true, value); }
    std::vector<CUtlString> GetDebugPartNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXAggregateData_t", "m_debugPartNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDebugPartNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_debugPartNames", true, value); }
    CUtlString GetEmbeddedKeyvalues() const { return GetSchemaValue<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_embeddedKeyvalues"); }
    void SetEmbeddedKeyvalues(CUtlString value) { SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_embeddedKeyvalues", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif