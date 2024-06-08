class GCPhysBallSocket;

#ifndef _gccphysballsocket_h
#define _gccphysballsocket_h

#include "../../../scripting.h"




class GCPhysBallSocket
{
private:
    void *m_ptr;

public:
    GCPhysBallSocket() {}
    GCPhysBallSocket(void *ptr) : m_ptr(ptr) {}

    float GetJointFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flJointFriction"); }
    void SetJointFriction(float value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flJointFriction", false, value); }
    bool GetEnableSwingLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysBallSocket", "m_bEnableSwingLimit"); }
    void SetEnableSwingLimit(bool value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_bEnableSwingLimit", false, value); }
    float GetSwingLimit() const { return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flSwingLimit"); }
    void SetSwingLimit(float value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flSwingLimit", false, value); }
    bool GetEnableTwistLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysBallSocket", "m_bEnableTwistLimit"); }
    void SetEnableTwistLimit(bool value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_bEnableTwistLimit", false, value); }
    float GetMinTwistAngle() const { return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flMinTwistAngle"); }
    void SetMinTwistAngle(float value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flMinTwistAngle", false, value); }
    float GetMaxTwistAngle() const { return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flMaxTwistAngle"); }
    void SetMaxTwistAngle(float value) { SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flMaxTwistAngle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif