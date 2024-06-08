class GWorldBuilderParams_t;

#ifndef _gcworldbuilderparams_t_h
#define _gcworldbuilderparams_t_h

#include "../../../scripting.h"


#include "GBakedLightingInfo_t.h"

class GWorldBuilderParams_t
{
private:
    void *m_ptr;

public:
    GWorldBuilderParams_t() {}
    GWorldBuilderParams_t(void *ptr) : m_ptr(ptr) {}

    float GetMinDrawVolumeSize() const { return GetSchemaValue<float>(m_ptr, "WorldBuilderParams_t", "m_flMinDrawVolumeSize"); }
    void SetMinDrawVolumeSize(float value) { SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_flMinDrawVolumeSize", true, value); }
    bool GetBuildBakedLighting() const { return GetSchemaValue<bool>(m_ptr, "WorldBuilderParams_t", "m_bBuildBakedLighting"); }
    void SetBuildBakedLighting(bool value) { SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_bBuildBakedLighting", true, value); }
    GBakedLightingInfo_t GetBakedLightingInfo() const { return GetSchemaValue<GBakedLightingInfo_t>(m_ptr, "WorldBuilderParams_t", "m_bakedLightingInfo"); }
    void SetBakedLightingInfo(GBakedLightingInfo_t value) { SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_bakedLightingInfo", true, value); }
    uint64_t GetCompileTimestamp() const { return GetSchemaValue<uint64_t>(m_ptr, "WorldBuilderParams_t", "m_nCompileTimestamp"); }
    void SetCompileTimestamp(uint64_t value) { SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_nCompileTimestamp", true, value); }
    uint64_t GetCompileFingerprint() const { return GetSchemaValue<uint64_t>(m_ptr, "WorldBuilderParams_t", "m_nCompileFingerprint"); }
    void SetCompileFingerprint(uint64_t value) { SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_nCompileFingerprint", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif