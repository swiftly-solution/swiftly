class GCHitReactUpdateNode;

#ifndef _gcchitreactupdatenode_h
#define _gcchitreactupdatenode_h

#include "../../../scripting.h"


#include "GHitReactFixedSettings_t.h"
#include "GCAnimParamHandle.h"

class GCHitReactUpdateNode
{
private:
    void *m_ptr;

public:
    GCHitReactUpdateNode() {}
    GCHitReactUpdateNode(void *ptr) : m_ptr(ptr) {}

    GHitReactFixedSettings_t GetOpFixedSettings() const { return GetSchemaValue<GHitReactFixedSettings_t>(m_ptr, "CHitReactUpdateNode", "m_opFixedSettings"); }
    void SetOpFixedSettings(GHitReactFixedSettings_t value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_opFixedSettings", false, value); }
    GCAnimParamHandle GetTriggerParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CHitReactUpdateNode", "m_triggerParam"); }
    void SetTriggerParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_triggerParam", false, value); }
    GCAnimParamHandle GetHitBoneParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CHitReactUpdateNode", "m_hitBoneParam"); }
    void SetHitBoneParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitBoneParam", false, value); }
    GCAnimParamHandle GetHitOffsetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CHitReactUpdateNode", "m_hitOffsetParam"); }
    void SetHitOffsetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitOffsetParam", false, value); }
    GCAnimParamHandle GetHitDirectionParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CHitReactUpdateNode", "m_hitDirectionParam"); }
    void SetHitDirectionParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitDirectionParam", false, value); }
    GCAnimParamHandle GetHitStrengthParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CHitReactUpdateNode", "m_hitStrengthParam"); }
    void SetHitStrengthParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_hitStrengthParam", false, value); }
    float GetMinDelayBetweenHits() const { return GetSchemaValue<float>(m_ptr, "CHitReactUpdateNode", "m_flMinDelayBetweenHits"); }
    void SetMinDelayBetweenHits(float value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_flMinDelayBetweenHits", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CHitReactUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CHitReactUpdateNode", "m_bResetChild", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif