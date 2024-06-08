class GC_OP_ConstrainDistanceToUserSpecifiedPath;

#ifndef _gcc_op_constraindistancetouserspecifiedpath_h
#define _gcc_op_constraindistancetouserspecifiedpath_h

#include "../../../scripting.h"


#include "GPointDefinitionWithTimeValues_t.h"

class GC_OP_ConstrainDistanceToUserSpecifiedPath
{
private:
    void *m_ptr;

public:
    GC_OP_ConstrainDistanceToUserSpecifiedPath() {}
    GC_OP_ConstrainDistanceToUserSpecifiedPath(void *ptr) : m_ptr(ptr) {}

    float GetMinDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_fMinDistance"); }
    void SetMinDistance(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_fMinDistance", false, value); }
    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_flMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_flMaxDistance", false, value); }
    float GetTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_flTimeScale"); }
    void SetTimeScale(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_flTimeScale", false, value); }
    bool GetLoopedPath() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_bLoopedPath"); }
    void SetLoopedPath(bool value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_bLoopedPath", false, value); }
    std::vector<GPointDefinitionWithTimeValues_t> GetPointList() const { CUtlVector<GPointDefinitionWithTimeValues_t>* vec = GetSchemaValue<CUtlVector<GPointDefinitionWithTimeValues_t>*>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_pointList"); std::vector<GPointDefinitionWithTimeValues_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPointList(std::vector<GPointDefinitionWithTimeValues_t> value) { SetSchemaValueCUtlVector<GPointDefinitionWithTimeValues_t>(m_ptr, "C_OP_ConstrainDistanceToUserSpecifiedPath", "m_pointList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif