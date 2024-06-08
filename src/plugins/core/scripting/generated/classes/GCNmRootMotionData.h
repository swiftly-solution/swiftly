class GCNmRootMotionData;

#ifndef _gccnmrootmotiondata_h
#define _gccnmrootmotiondata_h

#include "../../../scripting.h"




class GCNmRootMotionData
{
private:
    void *m_ptr;

public:
    GCNmRootMotionData() {}
    GCNmRootMotionData(void *ptr) : m_ptr(ptr) {}

    int32_t GetNumFrames() const { return GetSchemaValue<int32_t>(m_ptr, "CNmRootMotionData", "m_nNumFrames"); }
    void SetNumFrames(int32_t value) { SetSchemaValue(m_ptr, "CNmRootMotionData", "m_nNumFrames", false, value); }
    float GetAverageLinearVelocity() const { return GetSchemaValue<float>(m_ptr, "CNmRootMotionData", "m_flAverageLinearVelocity"); }
    void SetAverageLinearVelocity(float value) { SetSchemaValue(m_ptr, "CNmRootMotionData", "m_flAverageLinearVelocity", false, value); }
    float GetAverageAngularVelocityRadians() const { return GetSchemaValue<float>(m_ptr, "CNmRootMotionData", "m_flAverageAngularVelocityRadians"); }
    void SetAverageAngularVelocityRadians(float value) { SetSchemaValue(m_ptr, "CNmRootMotionData", "m_flAverageAngularVelocityRadians", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif