class GCAnimUpdateSharedData;

#ifndef _gccanimupdateshareddata_h
#define _gccanimupdateshareddata_h

#include "../../../scripting.h"


#include "GCAnimGraphSettingsManager.h"
#include "GCAnimNodePath.h"

class GCAnimUpdateSharedData
{
private:
    void *m_ptr;

public:
    GCAnimUpdateSharedData() {}
    GCAnimUpdateSharedData(void *ptr) : m_ptr(ptr) {}

    GCAnimGraphSettingsManager GetSettings() const { return GetSchemaValue<GCAnimGraphSettingsManager>(m_ptr, "CAnimUpdateSharedData", "m_settings"); }
    void SetSettings(GCAnimGraphSettingsManager value) { SetSchemaValue(m_ptr, "CAnimUpdateSharedData", "m_settings", false, value); }
    GCAnimNodePath GetRootNodePath() const { return GetSchemaValue<GCAnimNodePath>(m_ptr, "CAnimUpdateSharedData", "m_rootNodePath"); }
    void SetRootNodePath(GCAnimNodePath value) { SetSchemaValue(m_ptr, "CAnimUpdateSharedData", "m_rootNodePath", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif