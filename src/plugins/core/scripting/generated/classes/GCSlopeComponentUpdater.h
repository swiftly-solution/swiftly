class GCSlopeComponentUpdater;

#ifndef _gccslopecomponentupdater_h
#define _gccslopecomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCSlopeComponentUpdater
{
private:
    void *m_ptr;

public:
    GCSlopeComponentUpdater() {}
    GCSlopeComponentUpdater(void *ptr) : m_ptr(ptr) {}

    float GetTraceDistance() const { return GetSchemaValue<float>(m_ptr, "CSlopeComponentUpdater", "m_flTraceDistance"); }
    void SetTraceDistance(float value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_flTraceDistance", false, value); }
    GCAnimParamHandle GetSlopeAngle() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngle"); }
    void SetSlopeAngle(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngle", false, value); }
    GCAnimParamHandle GetSlopeAngleFront() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleFront"); }
    void SetSlopeAngleFront(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleFront", false, value); }
    GCAnimParamHandle GetSlopeAngleSide() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleSide"); }
    void SetSlopeAngleSide(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeAngleSide", false, value); }
    GCAnimParamHandle GetSlopeHeading() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeHeading"); }
    void SetSlopeHeading(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeHeading", false, value); }
    GCAnimParamHandle GetSlopeNormal() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal"); }
    void SetSlopeNormal(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal", false, value); }
    GCAnimParamHandle GetSlopeNormal_WorldSpace() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal_WorldSpace"); }
    void SetSlopeNormal_WorldSpace(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSlopeComponentUpdater", "m_hSlopeNormal_WorldSpace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif