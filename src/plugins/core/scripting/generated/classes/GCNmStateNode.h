class GCNmStateNode;

#ifndef _gccnmstatenode_h
#define _gccnmstatenode_h

#include "../../../scripting.h"




class GCNmStateNode
{
private:
    void *m_ptr;

public:
    GCNmStateNode() {}
    GCNmStateNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetChildNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nChildNodeIdx"); }
    void SetChildNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateNode", "m_nChildNodeIdx", false, value); }
    int16_t GetLayerWeightNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerWeightNodeIdx"); }
    void SetLayerWeightNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerWeightNodeIdx", false, value); }
    int16_t GetLayerRootMotionWeightNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerRootMotionWeightNodeIdx"); }
    void SetLayerRootMotionWeightNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerRootMotionWeightNodeIdx", false, value); }
    int16_t GetLayerBoneMaskNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmStateNode", "m_nLayerBoneMaskNodeIdx"); }
    void SetLayerBoneMaskNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmStateNode", "m_nLayerBoneMaskNodeIdx", false, value); }
    bool GetIsOffState() const { return GetSchemaValue<bool>(m_ptr, "CNmStateNode", "m_bIsOffState"); }
    void SetIsOffState(bool value) { SetSchemaValue(m_ptr, "CNmStateNode", "m_bIsOffState", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif