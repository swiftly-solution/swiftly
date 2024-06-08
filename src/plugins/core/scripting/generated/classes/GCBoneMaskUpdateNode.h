class GCBoneMaskUpdateNode;

#ifndef _gccbonemaskupdatenode_h
#define _gccbonemaskupdatenode_h

#include "../../../scripting.h"

#include "../types/GBoneMaskBlendSpace.h"
#include "../types/GBinaryNodeChildOption.h"
#include "../types/GAnimValueSource.h"
#include "GCAnimParamHandle.h"

class GCBoneMaskUpdateNode
{
private:
    void *m_ptr;

public:
    GCBoneMaskUpdateNode() {}
    GCBoneMaskUpdateNode(void *ptr) : m_ptr(ptr) {}

    int32_t GetWeightListIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBoneMaskUpdateNode", "m_nWeightListIndex"); }
    void SetWeightListIndex(int32_t value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_nWeightListIndex", false, value); }
    float GetRootMotionBlend() const { return GetSchemaValue<float>(m_ptr, "CBoneMaskUpdateNode", "m_flRootMotionBlend"); }
    void SetRootMotionBlend(float value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_flRootMotionBlend", false, value); }
    BoneMaskBlendSpace GetBlendSpace() const { return GetSchemaValue<BoneMaskBlendSpace>(m_ptr, "CBoneMaskUpdateNode", "m_blendSpace"); }
    void SetBlendSpace(BoneMaskBlendSpace value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_blendSpace", false, value); }
    BinaryNodeChildOption GetFootMotionTiming() const { return GetSchemaValue<BinaryNodeChildOption>(m_ptr, "CBoneMaskUpdateNode", "m_footMotionTiming"); }
    void SetFootMotionTiming(BinaryNodeChildOption value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_footMotionTiming", false, value); }
    bool GetUseBlendScale() const { return GetSchemaValue<bool>(m_ptr, "CBoneMaskUpdateNode", "m_bUseBlendScale"); }
    void SetUseBlendScale(bool value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_bUseBlendScale", false, value); }
    AnimValueSource GetBlendValueSource() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CBoneMaskUpdateNode", "m_blendValueSource"); }
    void SetBlendValueSource(AnimValueSource value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_blendValueSource", false, value); }
    GCAnimParamHandle GetBlendParameter() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CBoneMaskUpdateNode", "m_hBlendParameter"); }
    void SetBlendParameter(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_hBlendParameter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif