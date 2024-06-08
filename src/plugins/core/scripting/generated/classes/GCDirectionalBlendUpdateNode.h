class GCDirectionalBlendUpdateNode;

#ifndef _gccdirectionalblendupdatenode_h
#define _gccdirectionalblendupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCDirectionalBlendUpdateNode
{
private:
    void *m_ptr;

public:
    GCDirectionalBlendUpdateNode() {}
    GCDirectionalBlendUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CDirectionalBlendUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_damping", false, value); }
    AnimValueSource GetBlendValueSource() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CDirectionalBlendUpdateNode", "m_blendValueSource"); }
    void SetBlendValueSource(AnimValueSource value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_blendValueSource", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CDirectionalBlendUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_paramIndex", false, value); }
    float GetPlaybackSpeed() const { return GetSchemaValue<float>(m_ptr, "CDirectionalBlendUpdateNode", "m_playbackSpeed"); }
    void SetPlaybackSpeed(float value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_playbackSpeed", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CDirectionalBlendUpdateNode", "m_duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_duration", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CDirectionalBlendUpdateNode", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_bLoop", false, value); }
    bool GetLockBlendOnReset() const { return GetSchemaValue<bool>(m_ptr, "CDirectionalBlendUpdateNode", "m_bLockBlendOnReset"); }
    void SetLockBlendOnReset(bool value) { SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_bLockBlendOnReset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif