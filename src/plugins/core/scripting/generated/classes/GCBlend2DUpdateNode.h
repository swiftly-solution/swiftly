class GCBlend2DUpdateNode;

#ifndef _gccblend2dupdatenode_h
#define _gccblend2dupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "../types/GBlend2DMode.h"
#include "GBlendItem_t.h"
#include "GTagSpan_t.h"
#include "GCParamSpanUpdater.h"
#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCBlend2DUpdateNode
{
private:
    void *m_ptr;

public:
    GCBlend2DUpdateNode() {}
    GCBlend2DUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GBlendItem_t> GetItems() const { CUtlVector<GBlendItem_t>* vec = GetSchemaValue<CUtlVector<GBlendItem_t>*>(m_ptr, "CBlend2DUpdateNode", "m_items"); std::vector<GBlendItem_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetItems(std::vector<GBlendItem_t> value) { SetSchemaValueCUtlVector<GBlendItem_t>(m_ptr, "CBlend2DUpdateNode", "m_items", false, value); }
    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CBlend2DUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CBlend2DUpdateNode", "m_tags", false, value); }
    GCParamSpanUpdater GetParamSpans() const { return GetSchemaValue<GCParamSpanUpdater>(m_ptr, "CBlend2DUpdateNode", "m_paramSpans"); }
    void SetParamSpans(GCParamSpanUpdater value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramSpans", false, value); }
    std::vector<int32> GetNodeItemIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CBlend2DUpdateNode", "m_nodeItemIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodeItemIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CBlend2DUpdateNode", "m_nodeItemIndices", false, value); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CBlend2DUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_damping", false, value); }
    AnimValueSource GetBlendSourceX() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CBlend2DUpdateNode", "m_blendSourceX"); }
    void SetBlendSourceX(AnimValueSource value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_blendSourceX", false, value); }
    GCAnimParamHandle GetParamX() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CBlend2DUpdateNode", "m_paramX"); }
    void SetParamX(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramX", false, value); }
    AnimValueSource GetBlendSourceY() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CBlend2DUpdateNode", "m_blendSourceY"); }
    void SetBlendSourceY(AnimValueSource value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_blendSourceY", false, value); }
    GCAnimParamHandle GetParamY() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CBlend2DUpdateNode", "m_paramY"); }
    void SetParamY(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramY", false, value); }
    Blend2DMode GetBlendMode() const { return GetSchemaValue<Blend2DMode>(m_ptr, "CBlend2DUpdateNode", "m_eBlendMode"); }
    void SetBlendMode(Blend2DMode value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_eBlendMode", false, value); }
    float GetPlaybackSpeed() const { return GetSchemaValue<float>(m_ptr, "CBlend2DUpdateNode", "m_playbackSpeed"); }
    void SetPlaybackSpeed(float value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_playbackSpeed", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLoop", false, value); }
    bool GetLockBlendOnReset() const { return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLockBlendOnReset"); }
    void SetLockBlendOnReset(bool value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLockBlendOnReset", false, value); }
    bool GetLockWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLockWhenWaning"); }
    void SetLockWhenWaning(bool value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLockWhenWaning", false, value); }
    bool GetAnimEventsAndTagsOnMostWeightedOnly() const { return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bAnimEventsAndTagsOnMostWeightedOnly"); }
    void SetAnimEventsAndTagsOnMostWeightedOnly(bool value) { SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bAnimEventsAndTagsOnMostWeightedOnly", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif