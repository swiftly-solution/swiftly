class GCAnimationGraphVisualizerPrimitiveBase;

#ifndef _gccanimationgraphvisualizerprimitivebase_h
#define _gccanimationgraphvisualizerprimitivebase_h

#include "../../../scripting.h"

#include "../types/GCAnimationGraphVisualizerPrimitiveType.h"
#include "GAnimNodeID.h"

class GCAnimationGraphVisualizerPrimitiveBase
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerPrimitiveBase() {}
    GCAnimationGraphVisualizerPrimitiveBase(void *ptr) : m_ptr(ptr) {}

    CAnimationGraphVisualizerPrimitiveType GetType() const { return GetSchemaValue<CAnimationGraphVisualizerPrimitiveType>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_Type"); }
    void SetType(CAnimationGraphVisualizerPrimitiveType value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_Type", false, value); }
    std::vector<GAnimNodeID> GetOwningAnimNodePaths() const { GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths"); std::vector<GAnimNodeID> ret; for(int i = 0; i < 11; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOwningAnimNodePaths(std::vector<GAnimNodeID> value) { GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths"); for(int i = 0; i < 11; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths", false, outValue); }
    int32_t GetOwningAnimNodePathCount() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_nOwningAnimNodePathCount"); }
    void SetOwningAnimNodePathCount(int32_t value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_nOwningAnimNodePathCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif