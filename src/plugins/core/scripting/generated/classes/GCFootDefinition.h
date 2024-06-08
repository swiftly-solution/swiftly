class GCFootDefinition;

#ifndef _gccfootdefinition_h
#define _gccfootdefinition_h

#include "../../../scripting.h"




class GCFootDefinition
{
private:
    void *m_ptr;

public:
    GCFootDefinition() {}
    GCFootDefinition(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_name", false, value); }
    CUtlString GetAnkleBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_ankleBoneName"); }
    void SetAnkleBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_ankleBoneName", false, value); }
    CUtlString GetToeBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_toeBoneName"); }
    void SetToeBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_toeBoneName", false, value); }
    Vector GetBallOffset() const { return GetSchemaValue<Vector>(m_ptr, "CFootDefinition", "m_vBallOffset"); }
    void SetBallOffset(Vector value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_vBallOffset", false, value); }
    Vector GetHeelOffset() const { return GetSchemaValue<Vector>(m_ptr, "CFootDefinition", "m_vHeelOffset"); }
    void SetHeelOffset(Vector value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_vHeelOffset", false, value); }
    float GetFootLength() const { return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flFootLength"); }
    void SetFootLength(float value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_flFootLength", false, value); }
    float GetBindPoseDirectionMS() const { return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flBindPoseDirectionMS"); }
    void SetBindPoseDirectionMS(float value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_flBindPoseDirectionMS", false, value); }
    float GetTraceHeight() const { return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flTraceHeight"); }
    void SetTraceHeight(float value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_flTraceHeight", false, value); }
    float GetTraceRadius() const { return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flTraceRadius"); }
    void SetTraceRadius(float value) { SetSchemaValue(m_ptr, "CFootDefinition", "m_flTraceRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif