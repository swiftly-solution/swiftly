class GAggregateMeshInfo_t;

#ifndef _gcaggregatemeshinfo_t_h
#define _gcaggregatemeshinfo_t_h

#include "../../../scripting.h"

#include "../types/GObjectTypeFlags_t.h"


class GAggregateMeshInfo_t
{
private:
    void *m_ptr;

public:
    GAggregateMeshInfo_t() {}
    GAggregateMeshInfo_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetVisClusterMemberOffset() const { return GetSchemaValue<uint32_t>(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberOffset"); }
    void SetVisClusterMemberOffset(uint32_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberOffset", true, value); }
    uint8_t GetVisClusterMemberCount() const { return GetSchemaValue<uint8_t>(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberCount"); }
    void SetVisClusterMemberCount(uint8_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberCount", true, value); }
    bool GetHasTransform() const { return GetSchemaValue<bool>(m_ptr, "AggregateMeshInfo_t", "m_bHasTransform"); }
    void SetHasTransform(bool value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_bHasTransform", true, value); }
    int16_t GetDrawCallIndex() const { return GetSchemaValue<int16_t>(m_ptr, "AggregateMeshInfo_t", "m_nDrawCallIndex"); }
    void SetDrawCallIndex(int16_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nDrawCallIndex", true, value); }
    int16_t GetLODSetupIndex() const { return GetSchemaValue<int16_t>(m_ptr, "AggregateMeshInfo_t", "m_nLODSetupIndex"); }
    void SetLODSetupIndex(int16_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLODSetupIndex", true, value); }
    uint8_t GetLODGroupMask() const { return GetSchemaValue<uint8_t>(m_ptr, "AggregateMeshInfo_t", "m_nLODGroupMask"); }
    void SetLODGroupMask(uint8_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLODGroupMask", true, value); }
    Color GetTintColor() const { return GetSchemaValue<Color>(m_ptr, "AggregateMeshInfo_t", "m_vTintColor"); }
    void SetTintColor(Color value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_vTintColor", true, value); }
    ObjectTypeFlags_t GetObjectFlags() const { return GetSchemaValue<ObjectTypeFlags_t>(m_ptr, "AggregateMeshInfo_t", "m_objectFlags"); }
    void SetObjectFlags(ObjectTypeFlags_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_objectFlags", true, value); }
    int32_t GetLightProbeVolumePrecomputedHandshake() const { return GetSchemaValue<int32_t>(m_ptr, "AggregateMeshInfo_t", "m_nLightProbeVolumePrecomputedHandshake"); }
    void SetLightProbeVolumePrecomputedHandshake(int32_t value) { SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLightProbeVolumePrecomputedHandshake", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif