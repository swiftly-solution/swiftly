class GCNmLayerBlendNode;

#ifndef _gccnmlayerblendnode_h
#define _gccnmlayerblendnode_h

#include "../../../scripting.h"




class GCNmLayerBlendNode
{
private:
    void *m_ptr;

public:
    GCNmLayerBlendNode() {}
    GCNmLayerBlendNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetBaseNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode", "m_nBaseNodeIdx"); }
    void SetBaseNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode", "m_nBaseNodeIdx", false, value); }
    bool GetOnlySampleBaseRootMotion() const { return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode", "m_bOnlySampleBaseRootMotion"); }
    void SetOnlySampleBaseRootMotion(bool value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode", "m_bOnlySampleBaseRootMotion", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif