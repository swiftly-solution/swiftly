class GCFollowTargetUpdateNode;

#ifndef _gccfollowtargetupdatenode_h
#define _gccfollowtargetupdatenode_h

#include "../../../scripting.h"


#include "GFollowTargetOpFixedSettings_t.h"
#include "GCAnimParamHandle.h"

class GCFollowTargetUpdateNode
{
private:
    void *m_ptr;

public:
    GCFollowTargetUpdateNode() {}
    GCFollowTargetUpdateNode(void *ptr) : m_ptr(ptr) {}

    GFollowTargetOpFixedSettings_t GetOpFixedData() const { return GetSchemaValue<GFollowTargetOpFixedSettings_t>(m_ptr, "CFollowTargetUpdateNode", "m_opFixedData"); }
    void SetOpFixedData(GFollowTargetOpFixedSettings_t value) { SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_opFixedData", false, value); }
    GCAnimParamHandle GetParameterPosition() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CFollowTargetUpdateNode", "m_hParameterPosition"); }
    void SetParameterPosition(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_hParameterPosition", false, value); }
    GCAnimParamHandle GetParameterOrientation() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CFollowTargetUpdateNode", "m_hParameterOrientation"); }
    void SetParameterOrientation(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_hParameterOrientation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif