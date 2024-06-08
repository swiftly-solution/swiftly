class GCLookComponentUpdater;

#ifndef _gcclookcomponentupdater_h
#define _gcclookcomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCLookComponentUpdater
{
private:
    void *m_ptr;

public:
    GCLookComponentUpdater() {}
    GCLookComponentUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetLookHeading() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookHeading"); }
    void SetLookHeading(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookHeading", false, value); }
    GCAnimParamHandle GetLookHeadingVelocity() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookHeadingVelocity"); }
    void SetLookHeadingVelocity(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookHeadingVelocity", false, value); }
    GCAnimParamHandle GetLookPitch() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookPitch"); }
    void SetLookPitch(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookPitch", false, value); }
    GCAnimParamHandle GetLookDistance() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookDistance"); }
    void SetLookDistance(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookDistance", false, value); }
    GCAnimParamHandle GetLookDirection() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookDirection"); }
    void SetLookDirection(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookDirection", false, value); }
    GCAnimParamHandle GetLookTarget() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookTarget"); }
    void SetLookTarget(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookTarget", false, value); }
    GCAnimParamHandle GetLookTargetWorldSpace() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLookComponentUpdater", "m_hLookTargetWorldSpace"); }
    void SetLookTargetWorldSpace(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_hLookTargetWorldSpace", false, value); }
    bool GetNetworkLookTarget() const { return GetSchemaValue<bool>(m_ptr, "CLookComponentUpdater", "m_bNetworkLookTarget"); }
    void SetNetworkLookTarget(bool value) { SetSchemaValue(m_ptr, "CLookComponentUpdater", "m_bNetworkLookTarget", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif