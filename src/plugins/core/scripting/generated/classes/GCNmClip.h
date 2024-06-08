class GCNmClip;

#ifndef _gccnmclip_h
#define _gccnmclip_h

#include "../../../scripting.h"


#include "GNmCompressionSettings_t.h"
#include "GCNmSyncTrack.h"
#include "GCNmRootMotionData.h"

class GCNmClip
{
private:
    void *m_ptr;

public:
    GCNmClip() {}
    GCNmClip(void *ptr) : m_ptr(ptr) {}

    uint32_t GetNumFrames() const { return GetSchemaValue<uint32_t>(m_ptr, "CNmClip", "m_nNumFrames"); }
    void SetNumFrames(uint32_t value) { SetSchemaValue(m_ptr, "CNmClip", "m_nNumFrames", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CNmClip", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CNmClip", "m_flDuration", false, value); }
    std::vector<GNmCompressionSettings_t> GetTrackCompressionSettings() const { CUtlVector<GNmCompressionSettings_t>* vec = GetSchemaValue<CUtlVector<GNmCompressionSettings_t>*>(m_ptr, "CNmClip", "m_trackCompressionSettings"); std::vector<GNmCompressionSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTrackCompressionSettings(std::vector<GNmCompressionSettings_t> value) { SetSchemaValueCUtlVector<GNmCompressionSettings_t>(m_ptr, "CNmClip", "m_trackCompressionSettings", false, value); }
    std::vector<uint32> GetCompressedPoseOffsets() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CNmClip", "m_compressedPoseOffsets"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCompressedPoseOffsets(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CNmClip", "m_compressedPoseOffsets", false, value); }
    GCNmSyncTrack GetSyncTrack() const { return GetSchemaValue<GCNmSyncTrack>(m_ptr, "CNmClip", "m_syncTrack"); }
    void SetSyncTrack(GCNmSyncTrack value) { SetSchemaValue(m_ptr, "CNmClip", "m_syncTrack", false, value); }
    GCNmRootMotionData GetRootMotion() const { return GetSchemaValue<GCNmRootMotionData>(m_ptr, "CNmClip", "m_rootMotion"); }
    void SetRootMotion(GCNmRootMotionData value) { SetSchemaValue(m_ptr, "CNmClip", "m_rootMotion", false, value); }
    bool GetIsAdditive() const { return GetSchemaValue<bool>(m_ptr, "CNmClip", "m_bIsAdditive"); }
    void SetIsAdditive(bool value) { SetSchemaValue(m_ptr, "CNmClip", "m_bIsAdditive", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif