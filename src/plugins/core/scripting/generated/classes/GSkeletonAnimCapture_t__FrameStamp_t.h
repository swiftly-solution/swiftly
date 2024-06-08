class GSkeletonAnimCapture_t__FrameStamp_t;

#ifndef _gcskeletonanimcapture_t__framestamp_t_h
#define _gcskeletonanimcapture_t__framestamp_t_h

#include "../../../scripting.h"




class GSkeletonAnimCapture_t__FrameStamp_t
{
private:
    void *m_ptr;

public:
    GSkeletonAnimCapture_t__FrameStamp_t() {}
    GSkeletonAnimCapture_t__FrameStamp_t(void *ptr) : m_ptr(ptr) {}

    float GetTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flTime"); }
    void SetTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flTime", true, value); }
    float GetEntitySimTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flEntitySimTime"); }
    void SetEntitySimTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flEntitySimTime", true, value); }
    bool GetTeleportTick() const { return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bTeleportTick"); }
    void SetTeleportTick(bool value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bTeleportTick", true, value); }
    bool GetPredicted() const { return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bPredicted"); }
    void SetPredicted(bool value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bPredicted", true, value); }
    float GetCurTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flCurTime"); }
    void SetCurTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flCurTime", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flRealTime", true, value); }
    int32_t GetFrameCount() const { return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nFrameCount"); }
    void SetFrameCount(int32_t value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nFrameCount", true, value); }
    int32_t GetTickCount() const { return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nTickCount"); }
    void SetTickCount(int32_t value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nTickCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif