class GCBaseFlex;

#ifndef _gccbaseflex_h
#define _gccbaseflex_h

#include "../../../scripting.h"


#include "GSceneEventId_t.h"

class GCBaseFlex
{
private:
    void *m_ptr;

public:
    GCBaseFlex() {}
    GCBaseFlex(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetFlexWeight() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBaseFlex", "m_flexWeight"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexWeight(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CBaseFlex", "m_flexWeight", false, value); }
    Vector GetLookTargetPosition() const { return GetSchemaValue<Vector>(m_ptr, "CBaseFlex", "m_vLookTargetPosition"); }
    void SetLookTargetPosition(Vector value) { SetSchemaValue(m_ptr, "CBaseFlex", "m_vLookTargetPosition", false, value); }
    bool GetBlinktoggle() const { return GetSchemaValue<bool>(m_ptr, "CBaseFlex", "m_blinktoggle"); }
    void SetBlinktoggle(bool value) { SetSchemaValue(m_ptr, "CBaseFlex", "m_blinktoggle", false, value); }
    GSceneEventId_t GetNextSceneEventId() const { return GetSchemaValue<GSceneEventId_t>(m_ptr, "CBaseFlex", "m_nNextSceneEventId"); }
    void SetNextSceneEventId(GSceneEventId_t value) { SetSchemaValue(m_ptr, "CBaseFlex", "m_nNextSceneEventId", false, value); }
    bool GetUpdateLayerPriorities() const { return GetSchemaValue<bool>(m_ptr, "CBaseFlex", "m_bUpdateLayerPriorities"); }
    void SetUpdateLayerPriorities(bool value) { SetSchemaValue(m_ptr, "CBaseFlex", "m_bUpdateLayerPriorities", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif