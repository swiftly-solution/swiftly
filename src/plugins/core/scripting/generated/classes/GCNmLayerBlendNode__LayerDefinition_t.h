class GCNmLayerBlendNode__LayerDefinition_t;

#ifndef _gccnmlayerblendnode__layerdefinition_t_h
#define _gccnmlayerblendnode__layerdefinition_t_h

#include "../../../scripting.h"

#include "../types/GNmPoseBlendMode_t.h"


class GCNmLayerBlendNode__LayerDefinition_t
{
private:
    void *m_ptr;

public:
    GCNmLayerBlendNode__LayerDefinition_t() {}
    GCNmLayerBlendNode__LayerDefinition_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetInputNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nInputNodeIdx"); }
    void SetInputNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nInputNodeIdx", true, value); }
    int16_t GetWeightValueNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nWeightValueNodeIdx"); }
    void SetWeightValueNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nWeightValueNodeIdx", true, value); }
    int16_t GetBoneMaskValueNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nBoneMaskValueNodeIdx"); }
    void SetBoneMaskValueNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nBoneMaskValueNodeIdx", true, value); }
    int16_t GetRootMotionWeightValueNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nRootMotionWeightValueNodeIdx"); }
    void SetRootMotionWeightValueNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nRootMotionWeightValueNodeIdx", true, value); }
    bool GetIsSynchronized() const { return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsSynchronized"); }
    void SetIsSynchronized(bool value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsSynchronized", true, value); }
    bool GetIgnoreEvents() const { return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIgnoreEvents"); }
    void SetIgnoreEvents(bool value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIgnoreEvents", true, value); }
    bool GetIsStateMachineLayer() const { return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsStateMachineLayer"); }
    void SetIsStateMachineLayer(bool value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsStateMachineLayer", true, value); }
    NmPoseBlendMode_t GetBlendMode() const { return GetSchemaValue<NmPoseBlendMode_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_blendMode"); }
    void SetBlendMode(NmPoseBlendMode_t value) { SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_blendMode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif