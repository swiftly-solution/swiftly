class GCMotionGraphGroup;

#ifndef _gccmotiongraphgroup_h
#define _gccmotiongraphgroup_h

#include "../../../scripting.h"


#include "GCMotionSearchDB.h"
#include "GCMotionGraph.h"
#include "GCMotionGraphConfig.h"
#include "GAnimScriptHandle.h"

class GCMotionGraphGroup
{
private:
    void *m_ptr;

public:
    GCMotionGraphGroup() {}
    GCMotionGraphGroup(void *ptr) : m_ptr(ptr) {}

    GCMotionSearchDB GetSearchDB() const { return GetSchemaValue<GCMotionSearchDB>(m_ptr, "CMotionGraphGroup", "m_searchDB"); }
    void SetSearchDB(GCMotionSearchDB value) { SetSchemaValue(m_ptr, "CMotionGraphGroup", "m_searchDB", false, value); }
    std::vector<GCMotionGraphConfig> GetMotionGraphConfigs() const { CUtlVector<GCMotionGraphConfig>* vec = GetSchemaValue<CUtlVector<GCMotionGraphConfig>*>(m_ptr, "CMotionGraphGroup", "m_motionGraphConfigs"); std::vector<GCMotionGraphConfig> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMotionGraphConfigs(std::vector<GCMotionGraphConfig> value) { SetSchemaValueCUtlVector<GCMotionGraphConfig>(m_ptr, "CMotionGraphGroup", "m_motionGraphConfigs", false, value); }
    std::vector<int32> GetSampleToConfig() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CMotionGraphGroup", "m_sampleToConfig"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSampleToConfig(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CMotionGraphGroup", "m_sampleToConfig", false, value); }
    GAnimScriptHandle GetIsActiveScript() const { return GetSchemaValue<GAnimScriptHandle>(m_ptr, "CMotionGraphGroup", "m_hIsActiveScript"); }
    void SetIsActiveScript(GAnimScriptHandle value) { SetSchemaValue(m_ptr, "CMotionGraphGroup", "m_hIsActiveScript", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif