class GC_INIT_PointList;

#ifndef _gcc_init_pointlist_h
#define _gcc_init_pointlist_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GPointDefinition_t.h"

class GC_INIT_PointList
{
private:
    void *m_ptr;

public:
    GC_INIT_PointList() {}
    GC_INIT_PointList(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_PointList", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_PointList", "m_nFieldOutput", false, value); }
    std::vector<GPointDefinition_t> GetPointList() const { CUtlVector<GPointDefinition_t>* vec = GetSchemaValue<CUtlVector<GPointDefinition_t>*>(m_ptr, "C_INIT_PointList", "m_pointList"); std::vector<GPointDefinition_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPointList(std::vector<GPointDefinition_t> value) { SetSchemaValueCUtlVector<GPointDefinition_t>(m_ptr, "C_INIT_PointList", "m_pointList", false, value); }
    bool GetPlaceAlongPath() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PointList", "m_bPlaceAlongPath"); }
    void SetPlaceAlongPath(bool value) { SetSchemaValue(m_ptr, "C_INIT_PointList", "m_bPlaceAlongPath", false, value); }
    bool GetClosedLoop() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PointList", "m_bClosedLoop"); }
    void SetClosedLoop(bool value) { SetSchemaValue(m_ptr, "C_INIT_PointList", "m_bClosedLoop", false, value); }
    int32_t GetNumPointsAlongPath() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PointList", "m_nNumPointsAlongPath"); }
    void SetNumPointsAlongPath(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PointList", "m_nNumPointsAlongPath", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif