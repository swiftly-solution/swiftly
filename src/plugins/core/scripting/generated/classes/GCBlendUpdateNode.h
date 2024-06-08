class GCBlendUpdateNode;

#ifndef _gccblendupdatenode_h
#define _gccblendupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "../types/GBlendKeyType.h"
#include "GCAnimUpdateNodeRef.h"
#include "GCAnimParamHandle.h"
#include "GCAnimInputDamping.h"

class GCBlendUpdateNode
{
private:
    void *m_ptr;

public:
    GCBlendUpdateNode() {}
    GCBlendUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimUpdateNodeRef> GetChildren() const { CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CBlendUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildren(std::vector<GCAnimUpdateNodeRef> value) { SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CBlendUpdateNode", "m_children", false, value); }
    std::vector<uint8> GetSortedOrder() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CBlendUpdateNode", "m_sortedOrder"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSortedOrder(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CBlendUpdateNode", "m_sortedOrder", false, value); }
    std::vector<float32> GetTargetValues() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBlendUpdateNode", "m_targetValues"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTargetValues(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CBlendUpdateNode", "m_targetValues", false, value); }
    AnimValueSource GetBlendValueSource() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CBlendUpdateNode", "m_blendValueSource"); }
    void SetBlendValueSource(AnimValueSource value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_blendValueSource", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CBlendUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_paramIndex", false, value); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CBlendUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_damping", false, value); }
    BlendKeyType GetBlendKeyType() const { return GetSchemaValue<BlendKeyType>(m_ptr, "CBlendUpdateNode", "m_blendKeyType"); }
    void SetBlendKeyType(BlendKeyType value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_blendKeyType", false, value); }
    bool GetLockBlendOnReset() const { return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLockBlendOnReset"); }
    void SetLockBlendOnReset(bool value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLockBlendOnReset", false, value); }
    bool GetSyncCycles() const { return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bSyncCycles"); }
    void SetSyncCycles(bool value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bSyncCycles", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLoop", false, value); }
    bool GetLockWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLockWhenWaning"); }
    void SetLockWhenWaning(bool value) { SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLockWhenWaning", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif