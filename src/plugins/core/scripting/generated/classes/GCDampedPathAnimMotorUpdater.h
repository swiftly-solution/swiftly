class GCDampedPathAnimMotorUpdater;

#ifndef _gccdampedpathanimmotorupdater_h
#define _gccdampedpathanimmotorupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCDampedPathAnimMotorUpdater
{
private:
    void *m_ptr;

public:
    GCDampedPathAnimMotorUpdater() {}
    GCDampedPathAnimMotorUpdater(void *ptr) : m_ptr(ptr) {}

    float GetAnticipationTime() const { return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flAnticipationTime"); }
    void SetAnticipationTime(float value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flAnticipationTime", false, value); }
    float GetMinSpeedScale() const { return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpeedScale"); }
    void SetMinSpeedScale(float value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpeedScale", false, value); }
    GCAnimParamHandle GetAnticipationPosParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationPosParam"); }
    void SetAnticipationPosParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationPosParam", false, value); }
    GCAnimParamHandle GetAnticipationHeadingParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationHeadingParam"); }
    void SetAnticipationHeadingParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationHeadingParam", false, value); }
    float GetSpringConstant() const { return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flSpringConstant"); }
    void SetSpringConstant(float value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flSpringConstant", false, value); }
    float GetMinSpringTension() const { return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpringTension"); }
    void SetMinSpringTension(float value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpringTension", false, value); }
    float GetMaxSpringTension() const { return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMaxSpringTension"); }
    void SetMaxSpringTension(float value) { SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMaxSpringTension", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif