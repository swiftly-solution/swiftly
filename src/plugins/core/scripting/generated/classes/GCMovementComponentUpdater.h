class GCMovementComponentUpdater;

#ifndef _gccmovementcomponentupdater_h
#define _gccmovementcomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCMovementComponentUpdater
{
private:
    void *m_ptr;

public:
    GCMovementComponentUpdater() {}
    GCMovementComponentUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimInputDamping GetFacingDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CMovementComponentUpdater", "m_facingDamping"); }
    void SetFacingDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_facingDamping", false, value); }
    int32_t GetDefaultMotorIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CMovementComponentUpdater", "m_nDefaultMotorIndex"); }
    void SetDefaultMotorIndex(int32_t value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_nDefaultMotorIndex", false, value); }
    float GetDefaultRunSpeed() const { return GetSchemaValue<float>(m_ptr, "CMovementComponentUpdater", "m_flDefaultRunSpeed"); }
    void SetDefaultRunSpeed(float value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_flDefaultRunSpeed", false, value); }
    bool GetMoveVarsDisabled() const { return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bMoveVarsDisabled"); }
    void SetMoveVarsDisabled(bool value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bMoveVarsDisabled", false, value); }
    bool GetNetworkPath() const { return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bNetworkPath"); }
    void SetNetworkPath(bool value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bNetworkPath", false, value); }
    bool GetNetworkFacing() const { return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bNetworkFacing"); }
    void SetNetworkFacing(bool value) { SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bNetworkFacing", false, value); }
    std::vector<GCAnimParamHandle> GetParamHandles() const { GCAnimParamHandle* outValue = GetSchemaValue<GCAnimParamHandle*>(m_ptr, "CMovementComponentUpdater", "m_paramHandles"); std::vector<GCAnimParamHandle> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetParamHandles(std::vector<GCAnimParamHandle> value) { GCAnimParamHandle* outValue = GetSchemaValue<GCAnimParamHandle*>(m_ptr, "CMovementComponentUpdater", "m_paramHandles"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_paramHandles", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif