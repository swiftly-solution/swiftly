class GCFootPinningUpdateNode;

#ifndef _gccfootpinningupdatenode_h
#define _gccfootpinningupdatenode_h

#include "../../../scripting.h"

#include "../types/GFootPinningTimingSource.h"
#include "GFootPinningPoseOpFixedData_t.h"
#include "GCAnimParamHandle.h"

class GCFootPinningUpdateNode
{
private:
    void *m_ptr;

public:
    GCFootPinningUpdateNode() {}
    GCFootPinningUpdateNode(void *ptr) : m_ptr(ptr) {}

    GFootPinningPoseOpFixedData_t GetPoseOpFixedData() const { return GetSchemaValue<GFootPinningPoseOpFixedData_t>(m_ptr, "CFootPinningUpdateNode", "m_poseOpFixedData"); }
    void SetPoseOpFixedData(GFootPinningPoseOpFixedData_t value) { SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_poseOpFixedData", false, value); }
    FootPinningTimingSource GetTimingSource() const { return GetSchemaValue<FootPinningTimingSource>(m_ptr, "CFootPinningUpdateNode", "m_eTimingSource"); }
    void SetTimingSource(FootPinningTimingSource value) { SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_eTimingSource", false, value); }
    std::vector<GCAnimParamHandle> GetParams() const { CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "CFootPinningUpdateNode", "m_params"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParams(std::vector<GCAnimParamHandle> value) { SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "CFootPinningUpdateNode", "m_params", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CFootPinningUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_bResetChild", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif